//
//  main.cpp
//  linear
//
//  Created by George Archbold on 4/29/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


bool somePredicate(string s)
{
    bool t = s.empty();
    return t;
}



// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const string a[], int n)
{
    
    if (n == 0) {
        return true;
    }
    
    
    if( !somePredicate(a[--n])){
        return false;
    }
    
    allTrue(a, n);
    
    return true;
    
    
    //return somePredicate(a[n--]);
    
    
}


// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{

    
    if (n == 0) {
        return 0;
    }
    
    
    if( !somePredicate(a[n-1])){
        //cout << "n = " << n <<  endl;
        return countFalse(a, n-1)+1;
    }
    else{
        return countFalse(a, n-1);
    }
    


}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.

int firstFalse(const string a[], int n)
{
    if (n == 0){
        return -1;
    }
    
    int x = firstFalse(a, n-1);
    
    if (x != -1) {
        return x;
    }
    if (!somePredicate(a[n-1])) {
        return n-1;
    }
    return -1;
}


// Return the subscript of the least string in the array (i.e.,
// the smallest subscript m such that a[m] <= a[k] for all
// k from 0 to n-1).  If the array has no elements to examine,
// return -1.
int indexOfLeast(const string a[], int n)
{
    if (n == 0){
        return -1;
    }
    
    int x = indexOfLeast(a, n-1);
    
    if(x == -1){
        return n-1;
    }
    
    if (a[n-1] < a[x]) {
        return n-1;
    }
    else
        return x;
    
    }


// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "stan" "kyle" "cartman" "kenny" "kyle" "cartman" "butters"
// then the function should return true if a2 is
//    "kyle" "kenny" "butters"
// or
//    "kyle" "cartman" "cartman"
// and it should return false if a2 is
//    "kyle" "butters" "kenny"
// or
//    "stan" "kenny" "kenny"
bool includes(const string a1[], int n1, const string a2[], int n2)
{
    
    if (n1 == 0 && n2 != 0){
        return false;
    }
    else if( n1 == 0 && n2 == 0){
        return true;
    }
    
    if (n2 == 0){
        return true;
    }
    
    if ( a2[n2-1] != a1[n1-1] ){
        
        return includes(a1, n1-1, a2, n2);
    }
    else{
        return includes(a1, n1-1, a2, n2-1);
    }
    
}













