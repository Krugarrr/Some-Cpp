#ifndef ALPHA1_0_MYITERATOR_H
#define ALPHA1_0_MYITERATOR_H

#include <iostream>
#include <iterator>
using namespace std;

template <typename T>
class rand_iterator : public std::iterator<std::random_access_iterator_tag, T>{
public:
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T * pointer;
    typedef T & reference;

    rand_iterator(){
        ptr = nullptr;
    }
    rand_iterator(pointer p){
        ptr = p;
    }
    rand_iterator(const rand_iterator<T> & other) = default;
    rand_iterator & operator=(const rand_iterator<T> & other) = default;
    ~rand_iterator() = default;
    rand_iterator & operator+=(difference_type other){
        ptr += other;
    }
    rand_iterator & operator-=(difference_type other){
        ptr -= other;
    }
    T & operator*() const{
        return *ptr;
    }
    T & operator->() const{
        return ptr;
    }
    T & operator[](difference_type other) const {
        return ptr[other];
    }

    rand_iterator& operator++() {
        ++ptr;
        return *this;
    }
    rand_iterator& operator--() {
        --ptr;
        return *this;
    }
    rand_iterator operator++(int) const {
        rand_iterator res(*this);
        ++ptr;
        return res;
    }
    rand_iterator operator--(int) const {
        rand_iterator res(*this);
        --ptr;
        return res;
    }

    difference_type operator-(const rand_iterator& other) const {
        return ptr - other.ptr;
    }
    rand_iterator operator+(difference_type other) const {
        return rand_iterator(ptr + other);
    }
    rand_iterator operator-(difference_type other) const {
         return rand_iterator(ptr-other);
    }
    friend rand_iterator operator+(difference_type left, const rand_iterator& other) {
        return rand_iterator(left+other.ptr);
    }
    friend rand_iterator operator-(difference_type left, const rand_iterator& other) {
        return rand_iterator(left-other.ptr);
    }

    bool operator ==(const rand_iterator& other) const {
        return ptr == other.ptr;
    }
    bool operator !=(const rand_iterator& other) const {
        return ptr != other.ptr;
    }
    bool operator >(const rand_iterator& other) const {
        return ptr > other.ptr;
    }
    bool operator <(const rand_iterator& other) const {
        return ptr < other.ptr;
    }
    bool operator >=(const rand_iterator& other) const {
        return ptr >= other.ptr;
    }
    bool operator <=(const rand_iterator& other) const {
        return ptr <= other.ptr;
    }
private:
    T * ptr;
};

#endif //ALPHA1_0_MYITERATOR_H
