#include <iostream>
#include "circular_buffer.h"
#include <algorithm>
#include "rand_iter.h"
#include <typeinfo>

using namespace std;

int main()
{
    circular_buffer<int>buf(6);

    buf.push_head(3);
    buf.push_head(9);
    buf.push_tail(4);
    buf.push_tail(1);
    buf.push_tail(2);
    buf.push_tail(5);

    cout << "Capacity: " << buf._capacity() << endl;
    for (auto item : buf){
        cout << item << " ";
    }
    cout << endl;
    sort(buf.begin(), buf.end());
    for (auto item : buf){
        cout << item << " ";
    }
    cout << endl;




    cout << "-------------------" << endl;
    buf.resize(9);
    cout << "New capacity: " << buf._capacity() << endl;
    for (auto item : buf){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
