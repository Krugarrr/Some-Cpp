#ifndef RING_H_INCLUDED
#define RING_H_INCLUDED

#include <iostream>
#include <iterator>
#include <algorithm>
#include "rand_iter.h"

using namespace std;

template<typename T>
class circular_buffer{
private:
    T* buffer;
    size_t capacity;
    size_t number_count;
    size_t head;
    size_t tail;
public:
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type& reference;
    typedef const value_type & const_reference;
    typedef value_type * pointer;
    typedef const value_type * const_pointer;

    typedef rand_iterator<T> iterator;
    typedef const rand_iterator<T> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    iterator begin() { return iterator(buffer); }
    iterator end() { return iterator(buffer + number_count); }
    constexpr circular_buffer(size_t _size): buffer(nullptr), capacity(_size), number_count(0), head(0), tail(0){
        buffer = new T[_size];
    }

    constexpr size_t _capacity(){
        return capacity;
    }

    constexpr void push_head(T value){
        if (tail == capacity) {
            buffer[head] = value;
        }
        else {
            T* tmp = new T[capacity];
            for (int i = 0; i < capacity; ++i) {
                tmp[i] = buffer[i];
        }
        for (int i = head; i < tail + 1; ++i) {
            buffer[i + 1] = tmp[i];
        }
        buffer[head] = value;
        tail++;
        if (number_count < capacity)
            number_count++;
        delete[] tmp;
        }
    }

    constexpr void pop_head(){
        buffer[head] = 0;
        head++;
        number_count--;
    }

    constexpr void push_tail(T value){
        if (tail >= capacity) {
            buffer[tail] = value;
            tail = capacity;
        }
        else {
            buffer[tail] = value;
            tail++;
        }
        if (number_count < capacity)
            number_count++;
    }

    constexpr void pop_tail(){
        buffer[tail] = 0;
        tail--;
        number_count--;
    }


    constexpr void resize(size_t new_capacity){
        if (new_capacity < capacity){
            T* tmp = new T[new_capacity];
            for (size_t i = 0; i < new_capacity; i++){
                    tmp[i] = buffer[i];
            }
            buffer = new T[new_capacity];
            capacity = new_capacity;
            for (size_t i = 0; i < new_capacity; i++){
                    buffer[i] = tmp[i];
            }

            delete[] tmp;
        }

        else{
            T* tmp = new T[capacity];
            for (size_t i = 0; i < capacity; i++){
                    tmp[i] = buffer[i];
            }
            buffer = new T[new_capacity];
            for (size_t i = 0; i < capacity; i++){
                    buffer[i] = tmp[i];
            }
            capacity = new_capacity;
            delete[] tmp;
        }
        if (number_count > new_capacity)
            number_count = new_capacity;
        head = 0;
        tail = number_count;

    }

    constexpr T& get(size_t i){
        return buffer[i];
    }

    circular_buffer operator[](int i) {
        return buffer[i];
    }
};


#endif // RING_H_INCLUDED
