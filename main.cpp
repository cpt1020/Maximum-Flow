#include <iostream>
#include "src/Vertex.h"
#include "src/VertexPtr.h"
#include "src/BFS_queue.h"
#include "src/graph.h"
#include "src/Edmonds_Karp.h"
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