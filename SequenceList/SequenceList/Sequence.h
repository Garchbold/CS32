
//
//  Sequence.h
//  SequenceList
//
//  Created by George Archbold on 4/15/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#ifndef __SequenceList__Sequence__
#define __SequenceList__Sequence__




#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

typedef std::string ItemType;


class Sequence
{
public:
    Sequence();
    
    ~Sequence();
    
    Sequence& operator=(const Sequence& rhs);
    Sequence(const Sequence& other);
    
    bool empty() const;
    int size() const;
    bool insert(int pos, const ItemType& value);
    bool insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    
private:
    
    struct node
    {
        ItemType m_data;
        struct node *m_next;
        struct node *m_prev;
    };
    
    node* m_head;
    node* m_tail;
    
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);


#endif /* defined(__SequenceList__Sequence__) */
