#ifndef H_FIELD
#define H_FIELD

#include <vector>
#include "Coordinates.hpp"

class Size
{
    public:
        Size(){}
        Size(int _width, int _height){
            width=_width;
            height=_height;
        }
    unsigned int width;
    unsigned int height; 
};


class Circle{
    public:
        Circle(){}
        Circle(Coordinates _pos, int _diameter){
            pos = _pos;
            diameter = _diameter;
        }
    Coordinates pos;
    unsigned int diameter;
};

class Rectangle{
    public:
        Rectangle(){}
        Rectangle(Coordinates _pos, Size _dim) {
            pos = _pos;
            dim = _dim;
        }
        Coordinates pos;
        Size dim;
};



class Field
{
private:
    Size size;
    Circle robot;
    std::vector<Rectangle> list_obsctacles; 
    // Need class obstacle qui agit defférement si c'est une node weight ou classique
public:
    Field();
    Field(unsigned int robot_diameter);
    Field(unsigned int width, unsigned int height, unsigned int robot_diameter);
    ~Field();
    Size get_dimensions(void);
    int get_number_of_obstacle(void);
    void add_obsctacle(Rectangle obsctacle);
    bool delete_obstacle(Coordinates obstacle_position);
    bool is_possible(Coordinates robot_pos);
    bool intersect(Circle c, Rectangle r);
    std::vector<Rectangle> get_list_of_obstacle(void);
    // TODO load_chunk();
};



#endif