#include "Node.hpp"

#include "distance.hpp"

Node::Node() : Node(Coordinates(0,0),Coordinates(0,0)){
}

Node::Node(Coordinates _pos) : 
    pos(_pos), 
    came_from(Coordinates(0,0)), 
    g_cost(0), 
    h_cost(0),
    f_cost(0) 
{
}
Node::Node(Coordinates _pos, Coordinates _came_from) :
    pos(_pos), 
    came_from(_came_from), 
    g_cost(0), 
    h_cost(0),
    f_cost(0) 
{
}
void Node::compute_cost(Node came_from_node, Coordinates final_node_pos){
    g_cost = came_from_node.g_cost + distance(pos, came_from_node.pos); // slower but the best path
    h_cost = distance(pos, final_node_pos);
    f_cost = h_cost + g_cost;
    came_from = came_from_node.pos;

};

float Node::get_node_cost(){
    return f_cost;
}