#include <iostream>
#include "algos.h"
#include <array>
#include <vector>
using namespace std;

int main()
{
    //Point<int> p(2, 3);
    vector<double> vec = {3.0, 4.1, 3.4, 1.9};
    //array<Point<int>, 2> parr = {};
    array<int, 8> foo = {3,5,7,11,13,17,19,23};

    if (all_of(foo.begin(), foo.end(), [](int i){return i % 2;}) )
        cout << "All the elements are odd numbers.\n";
    if (all_of(foo.begin(), foo.end(), [](int i){return i < 20;}) )
        cout << "All the elements are less than 20.\n";
    else
        cout << "Not all the elements are less then 20.\n";
    if (all_of(vec.begin(), vec.end(), [](double i){return i > 1.8 ;}) )
        cout << "All the elements are more than 1.8.\n";
    //////////////////////////////////
    cout << "\n";
    array<int,7> neg = { -7, 2,-1,3,-3,5,-5};

    if (any_of(neg.begin(), neg.end(), [](int i){return i < 0;}) )
        cout << "There are negative elements in the range.\n";
    if (any_of(neg.begin(), neg.end(), [](int i){return i > 0;}) )
        cout << "There are also positive in the range.\n";
    if (any_of(neg.begin(), neg.end(), [](int i){return i % 2 == 0;}) )
        cout << "There are even elements in the range.\n";
    else
        cout << "There are only odd elements in the range.\n";

    ////////////////////////////////////
    cout << "\n";
    array<int,8> power = {-1,2,4,8,16,32,64,128};

    if ( none_of(power.begin(), power.end(), [](int i){return i<0;}) )
        cout << "There are no negative elements in the range.\n";
    else
        cout << "There are negative elements in the range\n";
    ///////////////////////////
    array<int,8> poly = {4, 4, 4, 4, 4, 4, 4, 4};
    cout << "\n";
    if (is_palindrome(poly.begin(), poly.end(), [](int x, int y) { return x == y; }) )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    ///////////////////////////
    cout << "\n";
    array<int,3> srt = {1, 2, 3};
    array<int,3> not_srt = {2, 1, 3};
    if (is_sorted(srt.begin(), srt.end()) )
        cout << "Yes" << endl;
    if (!is_sorted(not_srt.begin(), not_srt.end()) )
        cout << "No" << endl;

    ///////////////////////////
    cout << "\n";
    array<int, 7> prt = {1, 2, 3, 4, 5, 6, 7};
    array<int, 7> prtn = {1, 7, 3, 5, 4, 6, 2};
    if (is_partitioned(prt.begin(), prt.end(), [](int i) { return (i%2) == 1; }) )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    if (is_partitioned(prtn.begin(), prtn.end(), [](int i) { return (i%2) == 1; }) )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    ///////////////////////////
    cout << "\n";
    array<int, 4> fn = {1, 2, 3, 4};
    array<int, 5>::iterator it = find_not(fn.begin(), fn.end(), [](int i) {return i == 3;});
       cout <<  "The first not 3 value is " << *it << endl;

    ///////////////////////////
    cout << "\n";
    array<int, 4> fnb = {1, 2, 3, 4};
    array<int, 5>::iterator itb = find_backward(fnb.begin(), fnb.end(), 3);
       cout << *itb << endl;

    return 0;
}
