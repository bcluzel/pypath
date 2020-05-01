#include "field.hpp"
#include "math.h"

#define square(_a) ((_a)*(_a))

Field::Field()
{
    size.height = 200;
    size.width = 300;
    robot.pos.x = robot.pos.y = 0;
    robot.diameter = 20;
}

Field::Field(unsigned int robot_diameter)
{
    size.height = 200;
    size.width = 300;
    robot.pos.x = robot.pos.y = 0;
    robot.diameter = robot_diameter;

}

Field::Field(unsigned int width, unsigned int height, unsigned int robot_diameter){
    size.height = height;
    size.width = width;
    robot.pos.x = robot.pos.y = 0;
    robot.diameter = robot_diameter;
}


Field::~Field()
{
}

Size Field::get_dimensions(void){
    return size;
}

bool Field::is_possible(Coordinates robot_pos){
    robot.pos = robot_pos;

    for (const Rectangle & obstacle : list_obsctacles)
    {
        if(intersect(robot, obstacle)){
            return false;
        }
    }
    
    return true;
}

bool Field::intersect(Circle circle, Rectangle rect){

    unsigned int circle_distance_x = abs((int)circle.pos.x - (int)rect.pos.x);
    unsigned int circle_distance_y = abs((int)circle.pos.y - (int)rect.pos.y);

    if (circle_distance_x > ((rect.dim.width + circle.diameter)/2)) { return false; }
    if (circle_distance_y > ((rect.dim.height + circle.diameter)/2)) { return false; }

    if (circle_distance_x <= (rect.dim.width/2)) { return true; } 
    if (circle_distance_y <= (rect.dim.height/2)) { return true; }

    unsigned int corner_distance_sq = square(circle_distance_x - rect.dim.width/2) +
                         square(circle_distance_y - rect.dim.height/2);

    return (corner_distance_sq <= square(circle.diameter/2));
}


void Field::add_obsctacle(Rectangle obsctacle){
    list_obsctacles.push_back(obsctacle);
}

bool Field::delete_obstacle(Coordinates obstacle_position){
    for( std::vector<Rectangle>::iterator iter = list_obsctacles.begin(); iter != list_obsctacles.end(); ++iter )
    {
        if( iter->pos.x == obstacle_position.x and iter->pos.y == obstacle_position.y)
        {
            list_obsctacles.erase( iter );
            return true;
        }
    }
    return false;
}

int Field::get_number_of_obstacle(void){
    return (int)list_obsctacles.size();
}

std::vector<Rectangle> Field::get_list_of_obstacle(void){
    return list_obsctacles;
}