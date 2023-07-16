#ifndef MAIN_CPP_ITERATOR_H
#define MAIN_CPP_ITERATOR_H

#include <iterator>

using namespace std;

template <class Buffer, typename T>
class random_access_iter :
        public iterator<random_access_iterator_tag, T>
{
public:
    typedef random_access_iterator_tag iterator_category;

            typedef  T value_type;
            typedef  ptrdiff_t difference_type;
            typedef  T* pointer;
            typedef  T& reference;

private:
    const Buffer* _buffer;
    pointer ptr;

public:
    random_access_iter() : _buffer(0), ptr(0) {}

    random_access_iter(const Buffer* other_buffer, const pointer other_ptr)
                : _buffer(other_buffer), ptr(other_ptr) {}

    random_access_iter(const random_access_iter& other)
                : _buffer(other._buffer), ptr(other.ptr) {}

    random_access_iter& operator=(const random_access_iter& other) {
        if (this == &other)
            return *this;
        _buffer = other._buffer;
        ptr = other.ptr;
        return *this;
    }

    reference operator*() const {
        return *ptr;
    }
    reference operator->() const {
        return &(operator*());
    }

    reference operator[](difference_type other) const {
        return *(*this + other);
    }

    difference_type operator - (const random_access_iter<Buffer, T>& it) const {
        return stabilise(*this) - stabilise(it);
    }

    random_access_iter& operator++() {
        if (++ptr == _buffer->buffer_end) {
            ptr = _buffer->buffer;
        }

        if (ptr == _buffer->buffer_last) {
            ptr = 0;
        }
        return *this;
    }

    random_access_iter& operator--() {
        if (ptr == 0) {
            ptr = _buffer->buffer_last;
        }
        if (ptr == _buffer->buffer) {
            ptr = _buffer->buffer_end;
        }
        --ptr;
        return *this;
    }

    random_access_iter operator++(int) {
        random_access_iter<Buffer, T> tmp = *this;
        ++(*this);
        return tmp;
    }

    random_access_iter operator--(int) {
        random_access_iter<Buffer, T> tmp = *this;
        --(*this);
        return tmp;
    }

    random_access_iter& operator+=(difference_type dist) {
        if (dist > 0) {
            ptr = _buffer->add(ptr, dist);
            if (ptr == _buffer->buffer_last) {
                ptr = 0;
            }
        }
        else if (dist < 0) {
            *this -= -dist;
        }
        return *this;
    }

    random_access_iter operator+(difference_type dist) const {
        return random_access_iter<Buffer, T>(*this) += dist;
    }

    random_access_iter& operator-=(difference_type dist) {
        if (dist > 0) {
            ptr = _buffer->sub(ptr == 0 ? _buffer->buffer_last : ptr, dist);

        }
        else if (dist < 0) {
            *this += -dist;
        }
        return *this;
    }

    random_access_iter operator-(difference_type dist) const {
        return random_access_iter<Buffer, T>(*this) -= dist;;
    }

    bool operator ==(const random_access_iter<Buffer, T>& other) const {
        return ptr == other.ptr;
    }

    bool operator !=(const random_access_iter<Buffer, T>& other) const {
        return ptr != other.ptr;
    }

    bool operator <(const random_access_iter<Buffer, T>& other) const {
        return stabilise(*this) < stabilise(other);
    }

    bool operator >(const random_access_iter<Buffer, T>& other) const {
        return other < *this;
    }

    bool operator >=(const random_access_iter<Buffer, T>& other) const {
        return !(*this < other);
    }

    bool operator <=(const random_access_iter<Buffer, T>& other) const {
        return !(*this > other);
    }

private:
    pointer stabilise(const random_access_iter<Buffer, T>& it) const {
        if (it.ptr == 0) {
            return _buffer->buffer + _buffer->size();
        }
        else if (it.ptr < _buffer->buffer_first) {
            return it.ptr + (_buffer->buffer_end - _buffer->buffer_first);
        }
        else {
            return _buffer->buffer + (it.ptr - _buffer->buffer_first);
        }
    }
};

#endif //MAIN_CPP_ITERATOR_H
