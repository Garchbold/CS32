//
//  eval.cpp
//  eval
//
//  Created by George Archbold on 4/26/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

void removeSpaces(string& infix);
bool countBraces(string &infix);
bool checkOperators(string& infix);
bool checkForBinary(string& infix);
bool charToBoolEval( char c1, char c2, char op);
char boolToChar(bool b);

int evaluate(string infix, string& postfix, bool& result);


void removeSpaces(string& infix){
    
    
    infix.erase(remove(infix.begin(), infix.end(), ' '), infix.end());
    
    }

bool countBraces(string &infix){
    
    int counter;
    
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            counter++;
        if (infix[i] == ')')
            counter--;
        if (counter < 0)
            return false;
    }
    
    if (counter < 0)
        return false;
    else
        return true;
}

bool checkOperators(string& infix){
    
    for (int i = 0; i < infix.length(); i++) {
        if(infix[i] == '&' || infix[i] == '|' || infix[i] == '!' || infix[i] == 'T' || infix[i] == 'F' || infix[i] == '(' || infix[i] == ')')
            continue;
        else
            return false;
    }
    return true;
}

bool checkForBinary(string& infix){
    
    for (int i = 0; i < infix.length(); i++) {
        
        if(infix[i] != '&' && infix[i] != '|')
            continue;
        
        if(infix[i] == '&' || infix[i] == '|'){
            if((infix[i-1]== 'T' || infix[i-1]== 'F'  || infix[i-1]== ')') && (infix[i+1]== 'T' || infix[i+1]== 'F' || infix[i+1]== '(' || infix[i+1]== '!')){
                continue;
            }
            else
                return false;
        }
       
    }
    return true;
}


int precedence ( char c){
    switch (c) {
        case '!':
            return 3;
            break;
        case '&':
            return 2;
            break;
        case '|':
            return 1;
            break;
            
        default:
            assert(false);
    }
}

bool isValidOperand(char c) {
    return c == 'T' || c == 'F';
}

bool charToBoolEval( char c1, char c2, char op){
    bool b1;
    bool b2;
    
    if( c1 == 'T')
        b1 = true;
    else
        b1 = false;
    
    if( c2 == 'T')
        b2 = true;
    else
        b2 = false;
    
    if( op == '&')
        return (b1&b2);
    
    else if( op == '|')
        return (b1 | b2);
    else
        assert(false);
    
    return true;
}

char boolToChar(bool b) {
    if (b) {
        return 'T';
    } else {
        return 'F';
    }
}

int evaluate(string infix, string& postfix, bool& result){
    
    //VALIDITY CHECK
    
    removeSpaces(infix);
    
    if(!countBraces(infix))
        return 1;
    
    if(!checkOperators(infix))
        return 1;
    
    if(!checkForBinary(infix))
        return 1;
    
    //CONVERSION
    
    postfix = "";
    stack<char> op;
    
    for (int i = 0; i < infix.length(); i++) {
      
        switch (infix[i]) {
                
            case 'T':
                postfix = postfix + infix[i];
                break;
                
            case 'F':
                postfix = postfix + infix[i];
                break;
                
            case '(':
                op.push('(');
                break;
                
            case ')':
                while (op.top() != '(') {
                    postfix = postfix + op.top();
                    op.pop();
                }
                op.pop();
                break;
                
            case '!':
                
                while (!op.empty() && op.top() != '(' && precedence('!') <  precedence(op.top())) {
                    
                    postfix += op.top();
                    op.pop();
                }
                
                op.push('!');
                break;
                
            case '&':
                
                while (!op.empty() && op.top() != '(' && precedence('&') <= precedence(op.top())) {
                    
                    postfix += op.top();
                    op.pop();
                }
                
                op.push('&');
                break;
                
            case '|':
                
                while (!op.empty() && op.top() != '(' && precedence('|') <= precedence(op.top())) {
                    
                    postfix += op.top();
                    op.pop();
                    
                }
                op.push('|');
                break;
                
            default:
                break;
                
        }//end of switch
        
        
    }//end of for
    
    while (!op.empty()) {
        postfix = postfix + op.top();
        op.pop();
        
    }
    
    //EVALUATION
    
    for (int i = 0; i < postfix.length(); i++) {
        
        char op2;
        char op1;
        char temp;
        
        if( postfix[i] == 'T' || postfix[i] == 'F')
            op.push(postfix[i]);
        else
        {
            if (op.empty()) {
                return 1;
            }
            op2 = op.top();
            op.pop();
            
            if(postfix[i] != '!'){
                if (op.empty()) {
                    return 1;
                }
                op1 = op.top();
                op.pop();
                if (!(isValidOperand(op1) && isValidOperand(op2))) {
                    return 1;
                }
                temp = boolToChar(charToBoolEval(op1, op2, postfix[i]));
                op.push(temp);
            }
            else{
                if(op2 == 'T')
                    op.push('F');
                else
                    op.push('T');
            }//end of else
        }//end of if
        
        
    }
    if (op.empty()) {
        return 1;
    }
    
    if(op.top() == 'T')
        result = true;
    else
        result = false;
    
    op.pop();
    if (!op.empty()) {
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    string a = "T&!(F|T&T|F)|!!!(F&T&F)";
    string b = "";
    bool res;
    cout << "1: "  << a <<endl;
    evaluate(a, b, res);
    cout << "2: "  << b <<endl;
    cout << "3: "  << res <<endl;
    
    
    
    string pf;
    bool answer;
    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0 &&  pf == "FF!TF&&|"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    cout << "Passed all tests" << endl;
    
}
















