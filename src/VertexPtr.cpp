#include "VertexPtr.h"

// constructor
VertexPtr::VertexPtr(){
    next_vertex = nullptr;
    connected_node = nullptr;
    predecessor = nullptr;
    is_residual = false;
}

// get function
int VertexPtr::get_vertex_num(){
    return vertex_num;
};
VertexPtr* VertexPtr::get_next_vertex(){
    return next_vertex;
};
Vertex* VertexPtr::get_connected_node(){
    return connected_node;
};
VertexPtr* VertexPtr::get_predecessor(){
    return predecessor;
};
char VertexPtr::get_color(){
    return color;
};
int VertexPtr::get_discovery_time(){
    return discovery_time;
};
int VertexPtr::get_finishing_time(){
    return finishing_time;
};
int VertexPtr::get_distance(){
    return distance;
};
bool VertexPtr::get_is_residual(){
    return is_residual;
};

// set_function
void VertexPtr::set_vertex_num(int vertex_num_val){
    vertex_num = vertex_num_val;
};
void VertexPtr::set_next_vertex(VertexPtr* new_vertex){
    next_vertex = new_vertex;
};
void VertexPtr::set_connected_node(Vertex* new_node){
    connected_node = new_node;
};
void VertexPtr::set_predecessor(VertexPtr* new_predecessor){
    predecessor = new_predecessor;
};
void VertexPtr::set_color(char color_val){
    color = color_val;
};
void VertexPtr::set_discovery_time(int discovery_time_val){
    discovery_time = discovery_time_val;
};
void VertexPtr::set_finishing_time(int finishing_time_val){
    finishing_time = finishing_time_val;
};
void VertexPtr::set_distance(int distance_val){
    distance = distance_val;
};
void VertexPtr::set_is_residual(bool is_residual_val){
    is_residual = is_residual_val;
};