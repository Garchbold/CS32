//
//  main.cpp
//  tree
//
//  Created by George Archbold on 5/4/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include <iostream>
using namespace std;

// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then for this value of a2            the function must return
//    "stan" "kenny" "cartman"                      1
//    "stan" "cartman" "butters"                    2
//    "kenny" "stan" "cartman"                      0
//    "kyle" "cartman" "butters"                    3


int countIncludes(const string a1[], int n1, const string a2[], int n2)
{
    
    if (n1 == 0 && n2 != 0){
        
        return 0;
        
    }
    else if(n1 == 0 && n2 == 0){
        return 1;
    }
    
    if (n2 == 0){
        
        return 1;
        
    }
    
    if ( a2[n2-1] != a1[n1-1] ){
        
        return countIncludes(a1, n1-1, a2, n2);
    }
    else{
        
        return countIncludes(a1, n1-1, a2, n2-1) + countIncludes(a1, n1-1, a2, n2);
    }

}

//----------------------------------------------------------------------------------



// Exchange two strings
void exchange(string& x, string& y)
{
    string t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is < divider come before all the other elements,
// and all the elements whose value is > divider come after all
// the other elements.  Upon return, firstNotLess is set to the
// index of the first element in the rearranged array that is
// >= divider, or n if there is no such element, and firstGreater is
// set to the index of the first element that is > divider, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotLess, a[i] < divider
//   * for firstNotLess <= i < firstGreater, a[i] == divider
//   * for firstGreater <= i < n, a[i] > divider
// All the elements < divider end up in no particular order.
// All the elements > divider end up in no particular order.
void divide(string a[], int n, string divider,
            int& firstNotLess, int& firstGreater)
{
    if (n < 0)
        n = 0;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
    //  Every element earlier than position firstNotLess is < divider
    //  Every element from position firstNotLess to firstUnknown-1 is
    //    == divider
    //  Every element from firstUnknown to firstGreater-1 is not known yet
    //  Every element at position firstGreater or later is > divider
    
    firstNotLess = 0;
    firstGreater = n;
    int firstUnknown = 0;
    while (firstUnknown < firstGreater)
    {
        if (a[firstUnknown] > divider)
        {
            firstGreater--;
            exchange(a[firstUnknown], a[firstGreater]);
        }
        else
        {
            if (a[firstUnknown] < divider)
            {
                exchange(a[firstNotLess], a[firstUnknown]);
                firstNotLess++;
            }
            firstUnknown++;
        }
    }
}

// Rearrange the elements of the array so that
// a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
// If n <= 1, do nothing.
void order(string a[], int n)
{
    int firstNotLeast;
    int firstGreater;
    
    if(n <= 1){
        return;
    }
    
    
    divide(a, n, a[n-1], firstNotLeast, firstGreater);
    
    order(a, firstNotLeast);
    order(a + firstGreater, n - firstGreater);
//    order(a, )
//    order(a, firstNotLeast-1);
//    order(a + firstNotLeast, firstGreater-1);

}

int main(){
    
    string a1[6] = { "a","a", "a", "a", "a", "a"};
    
    string a2[2] = {"a", "a"};
    
    cout << countIncludes(a1,  6, a2, 2);
}
