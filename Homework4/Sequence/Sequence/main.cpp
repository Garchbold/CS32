//
//  main.cpp
//  Sequence
//
//  Created by George Archbold on 5/6/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include <iostream>
#include "Sequence.h"
#include <string>
#include <assert.h>

using namespace std;

void test()
{
    Sequence<int> si;
    Sequence<string> ss;
    assert(ss.empty());
    assert(ss.size() == 0);
    assert(ss.insert("Hello"));
    assert(si.insert(10));
    assert(si.erase(0));
    assert(ss.remove("Goodbye") == 0);
    assert(ss.find("Hello") == 0);
    string s;
    assert(ss.get(0, s));
    assert(ss.set(0, "Hello"));
    Sequence<string> ss2(ss);
    ss2.swap(ss);
    ss2 = ss;
    assert(subsequence(ss,ss2) == 0);
    assert(subsequence(si,si) == -1);
    interleave(ss,ss2,ss);
    interleave(si,si,si);
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}