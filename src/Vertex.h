#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
private:
// public:
    int node_value;
    int capacity;
    int flow;
    Vertex* next;

public:

    // constructor
    Vertex();

    // get function
    int get_node_value();
    int get_capacity();
    int get_flow();
    Vertex* get_next();

    // set function
    void set_node_value(int node_val);
    void set_capacity(int capacity_val);
    void set_flow(int flow_val);
    void set_next(Vertex* next_node);
};

#endif