#include "Vertex.h"

// constructor
Vertex::Vertex(){
    flow = 0;
    next = nullptr;
}

// get function
int Vertex::get_node_value(){
    return node_value;
};
int Vertex::get_capacity(){
    return capacity;
};
int Vertex::get_flow(){
    return flow;
};
Vertex* Vertex::get_next(){
    return next;
};

// set function
void Vertex::set_node_value(int node_val){
    node_value = node_val;
};
void Vertex::set_capacity(int capacity_val){
    capacity = capacity_val;
};
void Vertex::set_flow(int flow_val){
    flow = flow_val;
};
void Vertex::set_next(Vertex* next_node){
    next = next_node;
};