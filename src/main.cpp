#include <iostream>
#include "Vertex.h"
#include "VertexPtr.h"
#include "BFS_queue.h"
#include "graph.h"
#include "Edmonds_Karp.h"
using namespace std;

int main(){
    
    VertexPtr* head {nullptr};
    int total_node_num {0};
    int start_node {0};
    int end_node {0};
    int capacity {0};
    
    head = creat_graph(head, total_node_num, start_node, end_node, capacity);
    
    Edmonds_Karp(head, total_node_num);
    
    return 0;
} 