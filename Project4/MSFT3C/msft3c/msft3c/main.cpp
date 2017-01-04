//
//  main.cpp
//  msft3c
//
//  Created by George Archbold on 10/14/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include <iostream>
#include <tgmath.h>
using namespace std;


int inRadixToDec(char* in, int radix){
    
    radix = radix - 1;
    
    char dec = 'a';
    
    int value = 0;
    int exp = 0;
    
    int length = strlen(in);
    
    for (int i = length; i > 0; i--) {
        
        int input = (double)in[length];
        value = pow(input , exp);
        exp++;
    }
    
    return value;
    
    
}

//int decToOutRadix(int in, int radix){
//    
//    char dec = 'a' - 87;
//    
//    int check = 2;
//    int highest = 0;
//    int n = 0;
//    char *out;
//    int next = 0;
//    
//    for (n = 0; check > 1; n++) {
//        check = in/pow(radix, n);
//        highest = pow(radix, n);
//    }
//    
//    
//    return highest;
//    
//}

void convert10toR(int in, int radix)
{
    
    char dec = 'a';

    if (in == 0)
        return;
    int x = in % radix;
    in /= radix;
    if (x < 0)
        in += 1;
    convert10toR(in, radix);
    
    if ( x > 9 ){
        
        dec = dec + (x-10);
        cout << dec;
    }
    else
    {
        cout << ((x < 0) ? x + (radix * -1) : x);
    }
        return;
}


int main(int argc, const char * argv[]) {
    
    
    char c[10] = "342";
    
    
    cout << inRadixToDec(c, 10);
    convert10toR(inRadixToDec(c, 16), 10);

}