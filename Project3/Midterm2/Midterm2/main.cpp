//
//  main.cpp
//  Midterm2
//
//  Created by George Archbold on 5/19/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include <iostream>

using namespace std;

//void printArrayInOrder(const double a[], int n) {
//    if (n == 0)
//        return;
//    
//    cout << a[n-1] << endl;
//    printArrayInOrder(a, n - 1);
//}
//
//int gcd(int m, int n)
//{
//    
//    if (n == m)
//        return m;
//    
//    if (m < n)
//        return gcd(m, n-m);
//    
//    return gcd(n, m);
//
//    }
//
//int powerOfTwo(int x)
//{
//    if (x == 0) {
//        return 1;
//    }
//    
//    
//    return powerOfTwo(x-1) + powerOfTwo(x-1);
//}
//    
//int main(int argc, const char * argv[]) {
//    double array[5] = { 0,1,2,3,4 };
//    printArrayInOrder(array, 5);
//    cout<< gcd( 8, 20);
//    cout << powerOfTwo(10);
//}

//class A {
//public:
//    A() : m_msg("Apple") {}
//    A(string msg) : m_msg(msg) {}
//    virtual ~A()
//    {
//        message(); }
//    
//     void message() const
//    {
//        cout << m_msg << endl;
//    }
//    
//private:
//    string m_msg;
//};
//
//class B : public A {
//
//public:
//    B() : A("Orange") {}
//    B(string msg) : A(msg), m_a(msg) {}
//    void message() const
//    {
//        m_a.message();
//    }
//private:
//    A m_a;
//};
//
//
//int main() {
//    A *b1 = new B;
//    B *b2 = new B;
//    A *b3 = new B("Banana");
//    b1->message();
//    b2->message();
//    b3->message();
//    delete b1;
//    delete b2;
//    delete b3;
//}
