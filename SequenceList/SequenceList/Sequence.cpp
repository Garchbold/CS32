//
//  Sequence.cpp
//  SequenceList
//
//  Created by George Archbold on 4/15/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include "Sequence.h"


Sequence:: Sequence(){
    
    //initialize the sequence to be empty with null head and tail
    m_head = nullptr;
    m_tail = nullptr;
}

Sequence::~Sequence(){
    
    //start at the head
    node* current = m_head;
    
    for (int i=0; i<size();i++){    // loop until the whole thing is empty
        
        current = m_head;
        m_head = current->m_next;   // shift over to the next node
        delete current;             //delete the previous
        
    }

}

Sequence& Sequence::operator=(const Sequence& other){
    
    //same code as destructor
    //deletes all contents of this array
    
    node* current = m_head;
    for (int i = 0; i < size();  i++){
        current = m_head;
        m_head = current->m_next;
        delete current;
    }
    
    //start at the head of the sequnce that is to be copied
    node* temp = other.m_head;
    int counter = 0;
    
    //loop to check if your at the end of other
    while ( temp != nullptr){
        
        //insert each node from other incrementally
        insert(counter, temp->m_data);
        temp = temp->m_next;
        counter++;
    }
    return *this;   //return reference to the new Sequence
}


Sequence::Sequence(const Sequence& other){
    
    //start with an empty sequence
    m_head = nullptr;
    m_tail = nullptr;
    
    //same method for filling as the operator=
    node* temp = other.m_head;
    int counter = 0;
    
    while(temp != nullptr) {
        insert(counter, temp->m_data);
        temp = temp->m_next;
        counter++;
    }
    
}



bool Sequence::empty() const{
    //check the head pointer
    if (m_head == nullptr) {
        return true;
    }
    else
        return false;
}

int Sequence::size() const{
    
    int counter = 0;
    node* current = m_head;
    
    //check if sequence is empty
    if (current == nullptr) {
        return counter;
    }
    
    //iterate throught list keeping track of each node in a counter
    while(current != nullptr){
        current = current->m_next;
        counter++;
    }
    
    return counter;
}

bool Sequence::insert(int pos, const ItemType& value){
    
    if( pos < 0 || pos > size())
        return false;
    
    //iteration pointers
    node* current;
    node* prev;
    
    //check if the list is empty then insert a new node
    if( m_head == nullptr && pos == 0){
    
        node* first = new node;
    
        first->m_data = value;
        first->m_prev = nullptr;
        first->m_next = nullptr;
    
        m_tail = first;
        m_head = first;
        return true;
    }
    
    //start at the head so then prev will be null
    current = m_head;
    prev = nullptr;
    
    int i;
    
    //iterate to the location pos while adjusting the pointers
    for (i = 0; i< pos; i++){
        
        if(current != nullptr){
            prev = current;
            current = current->m_next;
        }
        else
            break;
    }
    //if not found return false
    if (i != pos)
        return false;

    //create a new node and set its pointers to be located at pos
    node* newnode = new node;
    newnode->m_next = current;
    newnode->m_prev = prev;
    newnode->m_data = value;
    
    //inserting in the beginning, change head
    if (prev == nullptr){
        m_head = newnode;
        current->m_prev = newnode;
        return true;
    }
    
    //inserting in the end, change tail
    if (current == nullptr) {
        m_tail = newnode;
        prev->m_next = newnode;
        return true;
    }
    
    //change the pointers of the two nodes on either side of new inserted node
    current->m_prev = newnode;
    prev->m_next = newnode;
    
    return true;

}

bool Sequence::insert(const ItemType& value){
    
    //new pointer and counter to iterate through list
    int counter = 0;
    node* current = m_head;
    
    for (int i = 0; i< size(); i++){
        
        //if the sorted location is found insert using previous function
        if(current->m_data > value){
            return ( insert(counter, value) );
        }
        //if not found add one to counter and move to next node
        counter++;
        current = current->m_next;
    }
    
    return (insert(counter, value));
}


bool Sequence::erase(int pos){
    
    //check for valid loc
    if( pos < 0 || pos > size())
        return false;
    
    //set iterator pointers
    node* current = m_head;
    node* prev = nullptr;

    //find node at pos
    int i;
    for (int i = 0; i < pos; i++){
        
        if(current != nullptr){
            prev = current;
            current = current->m_next;
        }
        else
            return false;
    }
    
    node* next = current->m_next;
    
    // if not found - false
    if (i != pos)
        return false;
    
    //if deleting the head reassign head to "next" node
    if (pos == 0){
        next->m_prev = nullptr;
        m_head = next;
        delete current;
        return true;
    }
    
    //if deleting tail reassign tail to "prev" node
    if (pos == size() - 1){
        prev->m_next = nullptr;
        m_tail = prev;
        delete current;
        return true;
    }
    
    //change the pointers of two nodes around current to skip over it
    next->m_prev = prev;
    prev->m_next = next;
    //then delete it
    delete current;
    
    return true;
    
}

int Sequence::remove(const ItemType& value){
    
    //vars to keep track of list poisition and nodes deleted
    int counter = 0;
    int counter_removed = 0;
    node* current = m_head;
    
    for (int i = 0; i < size(); i++){
        
        //iterate through and delete every instance of value
        if(current->m_data == value){
            erase(counter);
            counter_removed++;
        }
        //move to next node
        counter++;
        current = current->m_next;

    }

    return counter_removed;
}

bool Sequence::get(int pos, ItemType& value) const{
    
    //check for valide positions
    if( pos < 0 || pos > size())
        return false;
    
    node *current = m_head;
    
    //find node at pos and set its node to current
    for (int i = 0; i < pos; i++){
        current = current->m_next;
    }
    //set value to that nodes data
    value = current->m_data;
    return true;
}

bool Sequence::set(int pos, const ItemType& value){
    
    //check for valide positions
    if( pos < 0 || pos > size())
        return false;

    node *current = new node;
    
    //find node at pos and set its node to current
    for (int i = 0; i < pos; i++){
        current = current->m_next;
    }
    //set nodes data to value
    current->m_data = value;
    return true;
}

int Sequence::find(const ItemType& value) const{
    
    int counter = 0;
    node* current = m_head;
    
    for (int i = 0; i < size(); i++){
        //iterate through and if found return pos
        if(current->m_data == value){
            return counter;
        }
        //move to next node
        current = current->m_next;
        counter++;
    }
    return -1;
}

void Sequence::swap(Sequence& other){
    node* temp_head;
    node* temp_tail;
    
    //swap head pointers
    temp_head = m_head;
    m_head = other.m_head;
    other.m_head = temp_head;
    
    //swap tail pointers
    temp_tail = m_tail;
    m_tail = other.m_head;
    other.m_tail = temp_tail;

    
    
}


int subsequence(const Sequence& seq1, const Sequence& seq2){
    
    //avoid changing seq1
    Sequence copy(seq1);
    
    //variables to keep track of positions and values
    int num_erased = 0;
    
    ItemType value1 = 0;
    ItemType value2 = 0;
    int pos1;
    int pos2;
    
    //loop until signalled otherwise
    while (true) {
        
        bool shouldcontinue = false;
    
         pos1 = 0;
         pos2 = 0;
        
        //look in seq 2 for first node in seq1
        seq2.get(pos1, value2);
        value1 = value2;
    
        //if found store the location in seq1
        if(copy.find(value2) != -1)
            pos1 = copy.find(value2);
        else
            return -1;
        
        //while the values are the same
        while (value1 == value2 && pos2 < seq2.size()-1) {
        
            //move to the next two values
            pos1++;
            pos2++;

            //check values at pos+1
            copy.get(pos1, value1);
            seq2.get(pos2, value2);
        
            //if they arent still the same then erase the first instance and continue
            if  (value1 != value2){
                copy.erase(pos1 - 1);
                num_erased++;           //keep track of erased instances
                shouldcontinue = true;
                break;
            }
        
        }
        
        //when to break loop
        if(!shouldcontinue)
            break;
    }
    
    //add erased instances subtract the size of seq2 (b/c pos2 has gone to the end of it)
    //add one because pos starts at 0
    pos1 = pos1 + num_erased - seq2.size() + 1;
    return pos1;
}



void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result){
    //copy seq1 and 2 to avoid changing them
    Sequence copy1 (seq1);
    Sequence copy2 (seq2);
    int size_first;
    
    //storage and iterator variables
    ItemType value1;
    ItemType value2;
    int i = 0;
    int k = 0;

    //check which list is longer store shortes length
    if(copy1.size() < copy2.size())
        size_first = seq1.size();
    
    else if(copy2.size() < copy1.size())
        size_first = seq2.size();
    
    else if(copy2.size() == copy1.size())
        size_first = seq1.size();
    
    //iterate to shortest length
    while (i < size_first) {
        
        //get respective values
        copy1.get(i, value1);
        copy2.get(i, value2);
        
        //add values consequtively
        result.insert(k, value1);
        result.insert(k+1, value2);
        
        i++;
        k += 2;
    }
    
    // check if copy2 is longer
    if(copy1.size() < copy2.size()){
        
        //add in the rest of copy 2 to result
        while (k < copy2.size()+size_first) {
            copy2.get(k, value2);
            result.insert(k - size_first, value2);
            k++;
        }
    }
    
    //check if copy 1 is longer
    if(copy2.size() < copy1.size())
        while (k < copy1.size()+size_first) {
            
            //add in the rest of copy1
            copy1.get(k - size_first, value1);
            result.insert(k, value1);
            k++;
        }
        
}









