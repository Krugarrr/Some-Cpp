#include <iostream>
#include <vector>
#include "circular_buffer.h"
#include "algorithms.h"

using namespace std;

int main()
{
    circular_buffer<int> a;
    cout << a.size() << " " << a.capacity() << '\n';
    //a.pop_front();

    circular_buffer<int> b(30);
    b.push_back(1111);
    b.push_back(4);

    cout << b.size() << " " << b.capacity() << '\n';
    cout << '\n';
    b.push_back(5);
    sort(b.begin(), b.end());

    cout << b[0] << '\n';
    cout << b << '\n';
    cout << b[2] << '\n';
    cout << '\n';

    b.change_capacity(31);
    b.change_capacity(4);
    b.push_back(3);
    cout << b.size() << " " << b.capacity() << '\n';
    cout << b << '\n';
    cout << '\n';

    b.push_front(6);
    b.push_front(22);

    cout << b << '\n';
    sort(b.begin(), b.end());
    cout << b << '\n';
    cout << '\n';

    b.push_back(2);
    b.change_capacity(6);

    b.push_back(12);
    b.push_back(14);

    cout << b << '\n';
    sort(b.begin(), b.end());
    cout << b << '\n';
    cout << '\n';

    vector<int> c = {22, 6, 4, 2, 14, 12};
    for (auto i : c) std::cout << i << ' ';
    cout << "Find if not 22?   " << *find_if_not(c.begin(), c.end(), [](int i){ return i == 22; }) << '\n';
    cout << b << "Find if not 22?   " << *find_if_not(b.begin(), b.end(), [](int i){ return i == 22; }) << '\n';
    cout << b << "Find if not 22?   " << *algo::find_not(b.begin(), b.end(), [](int i){ return i == 22; }) << '\n';
    cout << '\n';

    if (algo::all_of(c.begin(), c.end(), [](int i){ return i >= 0; })) {
        for (auto i : c) std::cout << i << ' ';
        cout << "All numbers are even\n";
    }

    if (algo::all_of(b.begin(), b.end(), [](int i){ return i >= 0; })) {
        cout << b << "All numbers are even\n\n";
    }

    if (algo::any_of(c.begin(), c.end(), [](int i){ return i == 6; })) {
        for (auto i : c) std::cout << i << ' ';
        cout << "At least one of them is 6\n";
    }

    if (algo::any_of(b.begin(), b.end(), [](int i){ return i == 6; })) {
        cout << b << "At least one of them is 6\n\n";
    }

    if (algo::none_of(c.begin(), c.end(), [](int i){ return i < 0; })) {
        for (auto i : c) std::cout << i << ' ';
        cout << "None of them are less than 0\n";
    }

    if (algo::none_of(b.begin(), b.end(), [](int i){ return i < 0; })) {
        cout << b << "None of them are less than 0\n\n";
    }

    struct DivisibleBy
    {
        const int d;
        DivisibleBy(int n) : d(n) {}
        bool operator()(int n) const { return n % d == 0; }
    };

    if (any_of(c.begin(), c.end(), DivisibleBy(7))) {
        cout << "At least one number is divisible by 7\n";
    }

    if (any_of(b.begin(), b.end(), DivisibleBy(7))) {
        cout << "At least one number is divisible by 7\n\n";
    }

    for (auto i : c) std::cout << i << ' ';
    cout << ": is_sorted: " << std::boolalpha
              << algo::is_sorted(c.begin(), c.end()) << '\n';

    cout << b << ": std::is_sorted: " << std::boolalpha
              << is_sorted(b.begin(), b.end()) << '\n';

    cout << b << ": algo::is_sorted: " << std::boolalpha
              << algo::is_sorted(b.begin(), b.end()) << '\n';
    cout << '\n';

    partition(b.begin(), b.end(), [](int i){ return i > 10; });
    cout << b << ": std::is_partitioned: " << is_partitioned(b.begin(), b.end(), [](int i){ return i > 10; }) << '\n';
    cout << b << ": algo::is_partitioned: " <<  algo::is_partitioned(b.begin(), b.end(), [](int i){ return i > 10; }) << '\n';
    cout << '\n';

    cout << b <<  "backward == 31?   " << *algo::find_backward(c.begin(), c.end(), 31) << '\n';
    cout << b <<  "backward == 31?   " << *algo::find_backward(b.begin(), b. end(), 31) << '\n';
    cout << b <<  "backward == 6?    " << *algo::find_backward(b.begin(), b. end(), 6) << '\n';
    cout << '\n';

    a.change_capacity(4);
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);
    a.push_back(1);
    cout << a << '\n';
    cout << algo::is_palindrome(a.begin(), a.end(), [](int i, int j){ return i == j; });

    return 0;
}
