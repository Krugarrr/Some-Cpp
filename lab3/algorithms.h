//
// Created by tttee on 01.09.2022.
//

#ifndef MAIN_CPP_ALGORITHMS_H
#define MAIN_CPP_ALGORITHMS_H

namespace algo {

    template<class InputIt, class UnaryPredicate>
    constexpr InputIt find_not(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (!p(*first)) {
                return first;
            }
        }
        return last;
    }

    template<class InputIt, class UnaryPredicate>
    constexpr InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
    {
        for (; first != last; ++first) {
            if (p(*first)) {
                return first;
            }
        }
        return last;
    }


    template<class InputIt, class UnaryPredicate>
    bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
        return find_not(first, last, p) == last;
    }


    template<class InputIterator, class UnaryPredicate>
    bool any_of(InputIterator first, InputIterator last, UnaryPredicate p) {
        return algo::find_if(first, last, p) != last;
    }

    template<class InputIt, class Predicate>
    bool none_of(InputIt first, InputIt last, Predicate p) {
        return !algo::all_of(first, last, p);
    }

    template<class InputIterator, class Predicate>
    bool one_of(InputIterator begin, InputIterator end, Predicate predicate) {
        int counter = 0;
        for (; begin != end; ++begin) {
            if (predicate(*begin)) {
                counter++;
                if (counter > 2) return false;
            }
        }
        return (counter == 1);
    }

    template <class ForwardIt, class Compare>
    constexpr ForwardIt is_sorted_until(ForwardIt first, ForwardIt last, Compare comp)
    {
        if (first != last) {
            ForwardIt next = first;
            while (++next != last) {
                if (comp(*next, *first))
                    return next;
                first = next;
            }
        }
        return last;
    }

    template<class ForwardIt>
    constexpr ForwardIt is_sorted_until(ForwardIt first, ForwardIt last)
    {
        return algo::is_sorted_until(first, last, std::less<>());
    }

    template<class InputIt>
    bool is_sorted(InputIt first, InputIt last) {
        return algo::is_sorted_until(first, last) == last;
    }

    template< class InputIt, class UnaryPredicate >
    bool is_partitioned(InputIt first, InputIt last, UnaryPredicate p)
    {
        for (; first != last; ++first)
            if (!p(*first))
                break;
        for (; first != last; ++first)
            if (p(*first))
                return false;
        return true;
    }

    template<typename BidiIter, typename T>
    BidiIter find_backward(BidiIter first, BidiIter last, const T& x) {
        last--;
        BidiIter end = last;
        for (auto it = last; it > first; --it) {
            if (*it == x) {
                return it;
            }
        }
        if (*first == x) {
            return first;
        }
        return end;
    }


    template<class BidIter, class Predicate>
    bool is_palindrome(BidIter first, BidIter last, Predicate p) {
        if (first == last) {
            return true;
        }
        for (--last; first < last; --last, ++first) {
            if (!p(*first, *last)) {
                return false;
            }
        }
        return true;
    }
}
#endif //MAIN_CPP_ALGORITHMS_H
