#ifndef NODE_H
#define NODE_H

#include "Coordinates.hpp"

class Node
{
    public:
        Node();
        Node(Coordinates _pos);
        Node(Coordinates _pos, Coordinates _came_from);
        void compute_cost(Node came_from_node, Coordinates final_node_pos);
        float get_node_cost();
        Coordinates pos;
        Coordinates came_from;
    private:
        float g_cost;
        float h_cost;
        float f_cost;
};



#endif