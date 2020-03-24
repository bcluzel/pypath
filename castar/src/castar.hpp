#ifndef H_CASTAR
#define H_CASTAR

#include <sys/types.h>
#include <vector>
#include "field.hpp"
#include "error.hpp"

#define square(_a) ((_a)*(_a))

class Node
{
    public:
        Node(){
            pos = Coordinates(0,0);
            came_from = Coordinates(0,0);
            g_cost = f_cost = h_cost = 0;
        }
        Node(Coordinates _pos){
            pos= _pos;
            came_from = Coordinates(0,0);
            g_cost = f_cost = h_cost = 0;
        }
        Node(Coordinates _pos, Coordinates _came_from){
            pos= _pos;
            came_from = _came_from;
            g_cost = f_cost = h_cost = 0;
        }
        Coordinates pos;
        Coordinates came_from;
        float g_cost;
        float h_cost;
        float f_cost;
};

class Castar
{
private:
    float distance(Coordinates a, Coordinates b);
    void reconstruct_path(std::vector<Node> *valid_paths , std::vector<Coordinates> *real_path, Node end);
public:
    Castar();
    ~Castar();
    int find_path(Coordinates start, Coordinates end, Field field, std::vector<Coordinates> *final_path);
    int simplify_path(std::vector<Coordinates> path, std::vector<Coordinates> *final_path);
    int find_path_simplified(Coordinates start, Coordinates end, Field field, std::vector<Coordinates> *final_path);

};

#endif