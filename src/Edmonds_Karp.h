#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H
#include "VertexPtr.h"
#include "Vertex.h"
#include "BFS_queue.h"
#include "graph.h"

bool from_source_to_sink(VertexPtr* augmenting_path [], int sink);
void find_residual(VertexPtr* head, VertexPtr* ver, BFSQueue* queue);
void show_augmenting_path(VertexPtr* augmenting_path []);
void show_augmenting_path_capacity(VertexPtr* augmenting_path_capacity []);
void BFS(VertexPtr* residual, VertexPtr* augmenting_path [], int augmenting_path_capacity [], int sink);
VertexPtr* create_residual(VertexPtr* head, int num);
void initialize_flow_to_zero(VertexPtr* head);
void find_edge_and_update_capacity_flow(VertexPtr* residual, int flow, int start_node, int end_node);
void update_residaul_flow(VertexPtr* residual, int start_node, int end_node, int flow);
void update_residual(VertexPtr* residual, int flow, VertexPtr* augmenting_path [], int sink);
void show_max_flow(VertexPtr* residual);
void show_edge_capacity_and_flow(VertexPtr* head, VertexPtr* residual);
int find_min_flow_of_augmenting_path(int augmenting_path_capacity []);
void Edmonds_Karp(VertexPtr* head, int sink);

#endif