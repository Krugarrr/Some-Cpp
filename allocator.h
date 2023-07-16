#ifndef INC_5LAB_CPP_ALLOCATOR_H
#define INC_5LAB_CPP_ALLOCATOR_H
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>

template<typename T, unsigned Size>
class Custom_allocator {
public:
    using value_type =          T;
    using pointer =             value_type*;
    using size_type =           size_t;
    using difference_type =     typename std::pointer_traits<pointer>::difference_type;

public:
    Custom_allocator();
    ~Custom_allocator() noexcept;

    pointer allocate(size_type);
    void deallocate(pointer, size_type);

    template<class U>
    struct rebind {
        using other = Custom_allocator<U, Size>;
    };

private:
    size_t BASIC_SIZE = Size;
    std::vector<pointer> pool = std::vector<pointer>(BASIC_SIZE);
    std::vector<std::pair<pointer, size_t>> cur_pool = std::vector<std::pair<pointer, size_t>>(BASIC_SIZE);
};

template<typename T, unsigned Size>
Custom_allocator<T, Size>::Custom_allocator() {
    for (int i = 0; i < BASIC_SIZE; ++i) {
        size_type size = pow(2, i + 1) * sizeof(value_type);
        auto ptr = (pointer) malloc(size);
        pool[i] = ptr;
        cur_pool[i] = {ptr, size};
    }
}

template<typename T, unsigned Size>
Custom_allocator<T, Size>::~Custom_allocator() noexcept {
    for (auto ptr : pool)
        free(ptr);
}

template<typename T, unsigned Size>
T* Custom_allocator<T, Size>::allocate(size_type n) {
    pointer ptr = nullptr;
    for (int i = 0; i < cur_pool.size(); ++i) {
        if (cur_pool[i].second >= n) {
            ptr = cur_pool[i].first;
            size_type new_size = cur_pool[i].second - n;
            auto new_p = ptr + n;
            cur_pool[i] = {new_p, new_size};
        }
    }
    if (ptr == nullptr)
        throw "Error";
    return ptr;
}

template<typename T, unsigned Size>
void Custom_allocator<T, Size>::deallocate(pointer ptr, size_type n) {
    cur_pool.push_back({ptr, n});
}

#endif //INC_5LAB_CPP_ALLOCATOR_H
