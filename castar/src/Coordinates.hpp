#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
    public:
        Coordinates(){}
        Coordinates(int _x, int _y): x(_x), y(_y){
        }
        int x;
        int y; 
};

#endif