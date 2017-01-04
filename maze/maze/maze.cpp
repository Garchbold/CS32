//
//  main.cpp
//  maze
//
//  Created by George Archbold on 5/4/15.
//  Copyright (c) 2015 George Archbold. All rights reserved.
//

#include <iostream>

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


bool pathExists(char maze[][10], int sr, int sc, int er, int ec){
    
    Coord coordCurr(sr, sc);
    Coord coordEnd(er, ec);
    
    if (coordCurr.r() == coordEnd.r() && coordCurr.c() == coordEnd.c()) {
        return true;
    }
    maze[sr][sc] = 'O';
    
    //North
    if( maze[coordCurr.r()-1][coordCurr.c()] == '.' )
    {
        if( pathExists(maze, coordCurr.r()-1, coordCurr.c(), coordEnd.r(), coordEnd.c()) ){
            return true;
        }
        maze[coordCurr.r()-1][coordCurr.c()] = 'O';
    }
    
    //East
    if( maze[coordCurr.r()][coordCurr.c()+1] == '.' )
    {
        if( pathExists(maze, coordCurr.r(), coordCurr.c()+1, coordEnd.r(), coordEnd.c())){
            return true;
        }

        maze[coordCurr.r()][coordCurr.c()+1] = 'O';
    }
    
    //South
    if( maze[coordCurr.r()+1][coordCurr.c()] == '.' )
    {
        if ( pathExists(maze, coordCurr.r()+1, coordCurr.c(), coordEnd.r(), coordEnd.c())){
            return true;
        }

        maze[coordCurr.r()+1][coordCurr.c()] = 'O';
    }
    
    //West
    if( maze[coordCurr.r()][coordCurr.c()-1] == '.' )
    {
        if( pathExists(maze, coordCurr.r(), coordCurr.c()-1, coordEnd.r(), coordEnd.c()) ){
            return true;
        }

        maze[coordCurr.r()][coordCurr.c()-1] = 'O';
    }

    
    return false;
}
