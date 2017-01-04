//
//  Dictionary.cpp
//  Dictionary
//
//  Created by George Archbold on 5/27/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include "Dictionary.h"
// Dictionary.cpp

// This is a correct but horribly inefficient implementation of Dictionary
// functionality.  Your job is to change DictionaryImpl to a more efficient
// correct implementation.  You can change it any way you like, subject to
// restrictions in the spec (e.g., that the only C++ library container you
// are allowed to use are vector, list, stack, and queue (and string); if you
// want anything fancier, implement it yourself).

#include "Dictionary.h"
#include <string>
#include <list>
#include <vector>
#include <cctype>
#include <algorithm>  // for swap
using namespace std;


void removeNonLetters(string& s);
void generateNextPermutation(string& permutation);

// This class does the real work of the implementation.

class word
{
public:
    word (string s);
    string value;
    string sorted;
    
};

word::word(string s){
    value = s;
    sorted = s;
    sort(sorted.begin(), sorted.end());
}


class bucket
{
public:
    
    vector<word> m_bucket;
    
    void addWord(string s){
        word temp(s);
        m_bucket.push_back(temp);
    }
    
    
};


class DictionaryImpl
{
public:
    static const int NUM_BUCKETS = 49999;
    DictionaryImpl() {}
    ~DictionaryImpl() {}
    void    insert(string word);
    int     hash(string word) const;
    void    lookup(string letters, void callback(string)) const;

private:
    bucket table[NUM_BUCKETS];
    
};

int DictionaryImpl::hash(string s) const{

    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned int hash = 0;
    
    for(std::size_t i = 0; i < s.length(); i++)
    {
        hash = hash * a + s[i];
        a    = a * b;
    }
    
    return (hash & 0x7FFFFFFF) % NUM_BUCKETS;

    
}


void DictionaryImpl::insert(string s)
{
    
    word temp(s);
    
    removeNonLetters(s);
    if ( ! s.empty() )
        table[hash(temp.sorted)].addWord(s);
}

void DictionaryImpl::lookup(string letters, void callback(string)) const
{
    if (callback == nullptr)
        return;
    
    removeNonLetters(letters);
    if (letters.empty())
        return;
    
    word temp(letters);
    bucket curr = table[hash(temp.sorted)];
    string input = temp.sorted;

    
    
        for (vector<word> :: iterator  b = curr.m_bucket.begin(); b != curr.m_bucket.end(); b++) {
            
            string tablevalue = (*b).sorted;
            string output = (*b).value;
            
            if (tablevalue == input  ) {
                callback(output);
            }
        }
}


void removeNonLetters(string& s)
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop off everything from "to" to end.
}

// Each successive call to this function generates the next permutation of the
// characters in the parameter.  For example,
//    string s = "eel";
//    generateNextPermutation(s);  // now s == "ele"
//    generateNextPermutation(s);  // now s == "lee"
//    generateNextPermutation(s);  // now s == "eel"
// You don't have to understand this function's implementation.

void generateNextPermutation(string& permutation)
{
    string::iterator last = permutation.end() - 1;
    string::iterator p;
    
    for (p = last; p != permutation.begin()  &&  *p <= *(p-1); p--)
        ;
    if (p != permutation.begin())
    {
        string::iterator q;
        for (q = p+1; q <= last  &&  *q > *(p-1); q++)
            ;
        swap(*(p-1), *(q-1));
    }
    for ( ; p < last; p++, last--)
        swap(*p, *last);
}

//******************** Dictionary functions **********************************

// These functions simply delegate to DictionaryImpl's functions.
// You probably don't want to change any of this code.

Dictionary::Dictionary()
{
    m_impl = new DictionaryImpl;
}

Dictionary::~Dictionary()
{
    delete m_impl;
}

void Dictionary::insert(string word)
{
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
    m_impl->lookup(letters, callback);
}
