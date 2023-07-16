#ifndef INC_3LAB_CPP_CIRCULAR_BUFFER_H
#define INC_3LAB_CPP_CIRCULAR_BUFFER_H


#include <iostream>
#include <algorithm>
#include "iterator.h"
#include <type_traits>
#include <memory>
#include <limits>
#include <cassert>
#include <stdexcept>


using namespace std;

template<typename T, class Allocator = std::allocator<T>>
class circular_buffer {
public:
    //Basic types
    typedef circular_buffer<T, Allocator> this_type;
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type &reference;
    typedef value_type *pointer;
    typedef size_type capacity_type;
    typedef const value_type &const_reference;
    typedef const value_type *const_pointer;

    //Allocator types
    typedef Allocator allocator_type;

    //Random access iterator types
    typedef random_access_iterator_tag iterator_category;
    typedef const random_access_iter<circular_buffer<T, Allocator>, T> const_iterator;
    typedef random_access_iter<circular_buffer<T, Allocator>,T> iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;

private:
    //Variables
    allocator_type alloc;
    pointer buffer;
    pointer buffer_end;
    pointer buffer_first;
    pointer buffer_last;
    size_t buffer_size;
    friend iterator;
    friend const_iterator;

public:
      //-------------------//
     // CAPACITY AND SIZE //
    //-------------------//
    capacity_type capacity() const {
        return (buffer_end - buffer);
    }

    size_type size() const {
        return buffer_size;
    }

    bool empty() const {
        return size() == 0;
    }

    bool full() const {
        return (size() == capacity());
    }

    void change_capacity(capacity_type new_capacity) {
        if (new_capacity == capacity()) {
            return;
        }
        pointer buff = allocator_traits<Allocator>::allocate(alloc, new_capacity);
        iterator beg = begin();
        iterator fin = begin() + min(new_capacity, size());
        pointer dist = buffer;

        try {
            auto last = alloc_move(beg, beg + (min)(new_capacity, size()), buff, alloc);
            allocator_traits<Allocator>::deallocate(alloc, buffer, capacity());
            buffer_size = last - buff;
            buffer_first = buffer = buff;
            buffer_end = buffer + new_capacity;
            buffer_last = last == buffer_end ? buffer : last;
        }
        catch (...) {
            allocator_traits<Allocator>::deallocate(alloc, buff, new_capacity);
        }
    }

      //---------------------//
     // R.A. Iterator stuff //
    //---------------------//
    iterator begin() noexcept {
        return iterator(this, empty() ? 0 : buffer_first);
    }

    iterator end() noexcept {
        return iterator(this, 0);
    }

    const_iterator begin() const noexcept {
        return iterator(this, empty() ? 0 : buffer_first);
    }

    const_iterator end() const noexcept {
        return iterator(this, 0);
    }

    reverse_iterator rbegin() noexcept {
        return reverse_iterator(end());
    }

    reverse_iterator rend() noexcept {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rbegin() const noexcept {
        return reverse_iterator(end());
    }

    const_reverse_iterator rend() const noexcept {
        return reverse_iterator(begin());
    }

    reference operator[](size_type index) {
        CheckOutOfBuffer(index);
        return *add(buffer_first, index);
    }

    const_reference operator[](size_type index) const {
        CheckOutOfBuffer(index);
        return *add(buffer_first, index);
    }

    reference front() {
        CheckForEmptyBuffer();
        return *buffer_first;
    }

    reference back() {
        CheckForEmptyBuffer();
        return *((buffer_last == buffer ? buffer_end : buffer_last) - 1);
    }

    const_reference front() const {
        CheckForEmptyBuffer();
        return *buffer_first;
    }

    const_reference back() const {
        CheckForEmptyBuffer();
        return *((buffer_last == buffer ? buffer_end : buffer_last) - 1);
    }


    //Constructors and destructor
    circular_buffer(const allocator_type &alloc_ = allocator_type())
                : alloc(alloc_), buffer(0), buffer_end(0), buffer_first(0), buffer_last(0), buffer_size(0) {}

    circular_buffer(capacity_type capacity_, const allocator_type &alloc_ = allocator_type())
                : alloc(alloc_), buffer_size(0) {

        buffer = allocator_traits<Allocator>::allocate(alloc, capacity_);
        buffer_end = buffer + capacity_;
        buffer_first = buffer_last = buffer;
    }

    ~circular_buffer()  {
        for (size_type i = 0; i < size(); ++i, increment(buffer_first)) {
            allocator_traits<Allocator>::destroy(alloc, to_address(buffer_first));
        }

        allocator_traits<Allocator>::deallocate(alloc, buffer, capacity());

        buffer = nullptr;
        buffer_first = nullptr;
        buffer_end = nullptr;
        buffer_last = nullptr;
        buffer_size = 0;
    }


    void push_back(const_reference item) {
        if (full()) {
            if (empty()) {
                return;
            }
            *buffer_last = move(item);
            increment(buffer_last);
            buffer_first = buffer_last;
        } else {
            allocator_traits<Allocator>::construct(alloc, to_address(buffer_last), item);
            increment(buffer_last);
            ++buffer_size;
        }
    }

    void push_front(const_reference item) {
        try {
            if (full()) {
                if (empty()) {
                    return;
                }
                decrement(buffer_first);
                *buffer_first = move(item);
                buffer_last = buffer_first;

                buffer_first = buffer_last;
            } else {
                decrement(buffer_first);
                allocator_traits<Allocator>::construct(alloc, to_address(buffer_first), item);
                ++buffer_size;
            }
        }
        catch(...) {
            increment(buffer_first);
        }
    }

    void pop_back() {
        CheckForEmptyBuffer();
        if (buffer_last == buffer) {
            buffer_last = buffer_end;
        }
        buffer_last--;
        allocator_traits<Allocator>::destroy(alloc, to_address(buffer_last));
        buffer_size--;
    }

    void pop_front() {
        CheckForEmptyBuffer();
        allocator_traits<Allocator>::destroy(alloc, to_address(buffer_first));
        if (++buffer_first == buffer_end) {
            buffer_first = buffer;
        }
        buffer_size--;
    }

    friend ostream& operator<< (ostream& out, const circular_buffer<T, Allocator>& buff) {
        for (iterator it = buff.begin(); it < buff.end(); ++it) {
            out << *it << " ";
        }
        return out;
    }

private:
    void CheckOutOfBuffer(size_type index) {
        if (!(index < size())){
            throw out_of_range("This element is out of range");
        }
    }
    void CheckForEmptyBuffer() {
        if (empty()){
            throw logic_error("This operation is not available because buffer is empty");
        }
    }

    template<class InputIterator, class ForwardIterator, class Alloc>
    ForwardIterator alloc_move(InputIterator first, InputIterator last, ForwardIterator dist, Alloc& a) {
        for (; first != last; ++first, ++dist)
            allocator_traits<Alloc>::construct(a, addressof(*dist), move(*first));
        return dist;
    }

    pointer add(pointer ptr, difference_type dist) const {
        if (dist < (buffer_end - ptr)) {
            return ptr + dist;
        }
        return ptr + dist - (buffer_end - buffer);
    }


    pointer sub(pointer ptr, difference_type dist) const {
        if (dist > (ptr - buffer)) {
            return ptr - dist - (buffer_end - buffer);
        }
        return ptr - dist;
    }

    template<class Pointer>
    void increment(Pointer &p) const {
        if (++p == buffer_end)
            p = buffer;
    }

    template <class Pointer>
    void decrement(Pointer& p) const {
        if (p == buffer)
            p = buffer_end;
        --p;
    }
};


#endif //INC_3LAB_CPP_CIRCULAR_BUFFER_H
