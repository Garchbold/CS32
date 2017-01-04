//
//  main.cpp
//  animal
//
//  Created by George Archbold on 4/28/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include <iostream>

using namespace std;

class Animal{
public:
    
    Animal(string name){
        m_name = name;
    }
    
    string name() const{
        return  m_name;
    }
    
    virtual void speak() const = 0;
    virtual string moveAction() const = 0 ;


    virtual ~Animal(){};
    
private:
    string m_name;
    
};


//PIG
class Pig : public Animal{
    
public:
    Pig(string pig_name, int weight): Animal (pig_name){
        m_weight = weight;
    }
    
    
    void speak() const{
        
        if (m_weight < 180)
            cout << "Oink";
        
        else if (m_weight >= 180)
            cout <<  "Grunt";
        
    }

    string moveAction() const{
        return "walk";
    }
    
    ~Pig(){
        cout << "Destroying " << name() << " the pig"<<endl;
    };

    
private:
    int m_weight;
    

};

//DUCK
class Duck : public Animal{
    
public:
    Duck(string duck_name): Animal (duck_name){
        
    }
    
    
    void speak() const{
        cout << "Quack";
    }
    
    string moveAction() const{
        return "swim";
    }

    ~Duck(){
        cout << "Destroying " << name() << " the duck"<<endl;
    };
};

//CAT
class Cat : public Animal{
    
public:
    Cat(string cat_name): Animal (cat_name){
        
    }
    
     void speak() const{
        cout << "Meow";
    }
    
      string moveAction() const{
        return "walk";
    }

    ~Cat(){
        cout << "Destroying " << name() << " the cat"<<endl;
    };
    
};


void animate(const Animal* a)
{
    a->speak();
    cout << "!  My name is " << a->name() << ".  Watch me " << a->moveAction() << "!\n";
}

int main()
{
    
    Pig("Snowball", 170);
    
    
    Animal* animals[4];
    animals[0] = new Cat("Fluffy");
    animals[1] = new Pig("Napoleon", 190);
    animals[2] = new Pig("Wilbur", 50);
    animals[3] = new Duck("Daffy");

//    cout << animals[0]->speak() << endl;
    
    cout << "Here are the animals." << endl;
    for (int k = 0; k < 4; k++)
        animate(animals[k]);
    
    // Clean up the animals before exiting
    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
        delete animals[k];
}