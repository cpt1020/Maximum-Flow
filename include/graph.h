#ifndef GRAPH_H
#define GRAPH_H
#include "VertexPtr.h"
#include "Vertex.h"

bool vertex_exists(VertexPtr* head, int num);
VertexPtr* add_vertex(VertexPtr* head, int num);
void add_edge(VertexPtr* head, int start_node, int end_node, int capacity);
VertexPtr* creat_graph(VertexPtr* head, int &total_node_num, int &start_node, int &end_node, int &capacity);

#endif