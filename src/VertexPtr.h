#ifndef VERTEXPTR_H
#define VERTEXPTR_H
#include "Vertex.h"

class VertexPtr{

private:
    int vertex_num;
    VertexPtr* next_vertex;
    Vertex* connected_node;
    char color;
    VertexPtr* predecessor;
    int discovery_time;
    int finishing_time;
    int distance;
    bool is_residual;

public:

    // constructor
    VertexPtr();

    // get function
    int get_vertex_num();
    VertexPtr* get_next_vertex();
    Vertex* get_connected_node();
    VertexPtr* get_predecessor();
    char get_color();
    int get_discovery_time();
    int get_finishing_time();
    int get_distance();
    bool get_is_residual();
    
    // set_function
    void set_vertex_num(int vertex_num_val);
    void set_next_vertex(VertexPtr* new_vertex);
    void set_connected_node(Vertex* new_node);
    void set_predecessor(VertexPtr* new_predecessor);
    void set_color(char color_val);
    void set_discovery_time(int discovery_time_val);
    void set_finishing_time(int finishing_time_val);
    void set_distance(int distance_val);
    void set_is_residual(bool is_residual_val);
};

#endif