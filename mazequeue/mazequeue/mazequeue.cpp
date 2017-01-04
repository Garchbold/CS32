//
//  mazequeue.cpp
//  mazequeue
//
//  Created by George Archbold on 4/23/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include <queue>
#include <iostream>
#include <stdio.h>

using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec);



bool pathExists(char maze[][10], int sr, int sc, int er, int ec){
    
    queue<Coord> coordQueue;     // declare a stack of Coords
    
    Coord coordCurr(sr, sc);
    Coord coordEnd(er, ec);
    
    
    coordQueue.push(coordCurr);
    maze[sr][sc] = 'O';
    
    while (!coordQueue.empty()) {
        coordCurr = coordQueue.front();
        cout << coordCurr.r() <<  " " << coordCurr.c() << endl;
        coordQueue.pop();
        
        if (coordCurr.r() == coordEnd.r() && coordCurr.c() == coordEnd.c())
            return true;
        
        //North
        if( maze[coordCurr.r()-1][coordCurr.c()] == '.' )
        {
            coordQueue.push(Coord(coordCurr.r()-1,coordCurr.c()));
            maze[coordCurr.r()-1][coordCurr.c()] = 'O';
        }
        
        //East
        if( maze[coordCurr.r()][coordCurr.c()+1] == '.' )
        {
            coordQueue.push(Coord(coordCurr.r(), coordCurr.c()+1));
            maze[coordCurr.r()][coordCurr.c()+1] = 'O';
            
        }
        
        //South
        if( maze[coordCurr.r()+1][coordCurr.c()] == '.' )
        {
            coordQueue.push(Coord(coordCurr.r()+1, coordCurr.c()));
            maze[coordCurr.r()+1][coordCurr.c()] = 'O';
            
        }
        
        //West
        if( maze[coordCurr.r()][coordCurr.c()-1] == '.' )
        {
            coordQueue.push(Coord(coordCurr.r(), coordCurr.c()-1));
            maze[coordCurr.r()][coordCurr.c()-1] = 'O';
            
        }
        
    }
    return false;
}




int main(int argc, const char * argv[]) {
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X'},
        { 'X','.','.','.','.','.','.','.','.','X'},
        { 'X','X','.','X','.','X','X','X','X','X'},
        { 'X','.','.','X','.','X','.','.','.','X'},
        { 'X','.','.','X','.','.','.','X','.','X'},
        { 'X','X','X','X','.','X','X','X','.','X'},
        { 'X','.','X','.','.','.','.','X','X','X'},
        { 'X','.','.','X','X','.','X','X','.','X'},
        { 'X','.','.','.','X','.','.','.','.','X'},
        { 'X','X','X','X','X','X','X','X','X','X'}
    };
    if (pathExists(maze, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
