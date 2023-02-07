#include "Edmonds_Karp.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool from_source_to_sink(VertexPtr* augmenting_path [], int sink){
    bool has_source {false};
    bool has_sink {false};

    for (int i {0}; i < sink; i++){
        
        if (augmenting_path[i] != nullptr){
            
            if (augmenting_path[i]->get_vertex_num() == 0){
                has_source = true;
            }
            if (augmenting_path[i]->get_vertex_num() == sink-1){
                has_sink = true;
            }
        }
    }

    if (has_sink == 1 && has_source == 1){
        return true;
    }
    else{
        return false;
    }
}

void find_residual(VertexPtr* head, VertexPtr* ver, BFSQueue* queue){    
    VertexPtr* ptr {head};
    while (ptr != nullptr){
        if (ptr->get_connected_node() != nullptr){
            Vertex* node_ptr = ptr->get_connected_node();
            while (node_ptr != nullptr){
                if ((node_ptr->get_node_value() == ver->get_vertex_num()) && (node_ptr->get_flow() > 0)){
                    
                    if (ptr->get_color() == 'w'){
                        ptr->set_color('g');
                        ptr->set_distance(node_ptr->get_flow());
                        ptr->set_predecessor(ver);
                        ptr->set_is_residual(true);
                        queue->Enqueue(ptr);
                    }
                    
                    break;
                }
                node_ptr = node_ptr->get_next();
            }
        }
        ptr = ptr->get_next_vertex();
    }
}

void show_augmenting_path(VertexPtr* augmenting_path []){
    int index {0};
    cout << "\nAugmenting path: ";
    while (augmenting_path[index] != nullptr){
        cout << augmenting_path[index]->get_vertex_num() << " ";
        index++;
    }
    cout << endl;
}

void show_augmenting_path_capacity(VertexPtr* augmenting_path_capacity []){
    int index {0};
    cout << "Capacity of augmenting path: ";
    while (augmenting_path_capacity[index] != 0){
        cout << augmenting_path_capacity[index] << " ";
        index++;
    }
    cout << endl;
}

void BFS(VertexPtr* residual, VertexPtr* augmenting_path [], int augmenting_path_capacity [], int sink){
    VertexPtr* ptr {residual};
    
    //記得每次呼叫BFS都要清空augPath array
    for (int i {0}; i < 101; i++){
        augmenting_path[i] = nullptr;
    }
    
    //記得每次呼叫BFS都要清空augPathCapacity array
    for (int i {0}; i < 101; i++){
        augmenting_path_capacity[i] = 0;
    }

    // 將source以外的點做初始化
    while (ptr != nullptr){
        if (ptr->get_vertex_num() != 0){
            ptr->set_color('w');
            ptr->set_distance(INT_MAX);
            ptr->set_predecessor(nullptr);
            ptr->set_is_residual(false);
        }
        ptr = ptr->get_next_vertex();
    }
    
    // 將source初始化
    VertexPtr* source {residual};
    while (source->get_vertex_num() != 0){
        if (source->get_vertex_num() == 0){
            break;
        }
        source = source->get_next_vertex();
    }
    source->set_color('g');
    source->set_distance(0);
    source->set_predecessor(nullptr);
    source->set_is_residual(false);
    
    BFSQueue* queue = new BFSQueue();
    queue->Enqueue(source);
    
    while (queue->queue_is_empty() != true){
        VertexPtr* vertex_ptr = queue->Dequeue();
        
        if (vertex_ptr == nullptr || vertex_ptr->get_vertex_num() == sink-1){
            break;
        }
        
        if (vertex_ptr->get_connected_node() != nullptr){
            // 先把verPtr連出去的點先拜訪
            Vertex* node_ptr = vertex_ptr->get_connected_node();
            while (node_ptr != nullptr){
                // 若這個點的capacity == flow，就代表已經沒有capacity了
                if (node_ptr->get_capacity() == node_ptr->get_flow()){
                    node_ptr = node_ptr->get_next();
                    continue;
                }
                
                ptr = residual;
                while (ptr != nullptr){
                    if (ptr->get_vertex_num() == node_ptr->get_node_value()){
                        break;
                    }
                    ptr = ptr->get_next_vertex();
                }
                
                if (ptr->get_color() == 'w'){
                    ptr->set_color('g');
                    ptr->set_distance(node_ptr->get_capacity() - node_ptr->get_flow());
                    ptr->set_predecessor(vertex_ptr);
                    queue->Enqueue(ptr);
                }
                
                node_ptr = node_ptr->get_next();
            }
            
            // 再檢查有連到verPtr的vertex，檢查flow是否>0，若>0就代表有residual可以走
            // 若有走這條的話，flow要減掉才行
            find_residual(residual, vertex_ptr, queue);
        }
        vertex_ptr->set_color('b');
    }
    
    // 先找到sink
    ptr = residual;
    while (ptr != nullptr){
        if (ptr->get_vertex_num() == sink-1){
            break;
        }
        ptr = ptr->get_next_vertex();
    }
    
    VertexPtr* temp_augmenting_path [101] = {nullptr};
    int temp_augmenting_path_capacity [101] = {0};
    
    int augmenting_path_index {0};
    while (ptr != nullptr){
        temp_augmenting_path[augmenting_path_index] = ptr;
        if (augmenting_path_index != 0){
            temp_augmenting_path_capacity[augmenting_path_index-1] = ptr->get_distance();
        }
        augmenting_path_index++;
        ptr = ptr->get_predecessor();
    }
    
    for (int i {augmenting_path_index-1}; i >= 0; i--){
        augmenting_path[(augmenting_path_index-1)-(i)] = temp_augmenting_path[i];
        if ((augmenting_path_index-1)-(i)-1 >= 0){
            augmenting_path_capacity[(augmenting_path_index-1)-(i)-1] = temp_augmenting_path[i]->get_distance();
        }
    }
    // 顯示這輪找到的augmenting path & capacity
//    show_augmenting_path(augmenting_path);
//    show_augmenting_path_capacity(augmenting_path_capacity);
}

VertexPtr* create_residual(VertexPtr* head, int num){
    VertexPtr* residual = nullptr;
    residual = add_vertex(residual, num);
    while (head != nullptr){
        if (head->get_connected_node() != nullptr){
            Vertex* node_ptr = head->get_connected_node();
            while(node_ptr != nullptr){
                add_edge(residual, head->get_vertex_num(), node_ptr->get_node_value(), node_ptr->get_capacity());
                node_ptr = node_ptr->get_next();
            }
        }
        head = head->get_next_vertex();
    }
    return residual;
}

void initialize_flow_to_zero(VertexPtr* head){
    VertexPtr* ptr {head};
    while (ptr != nullptr){
        if (ptr->get_connected_node() != nullptr){
            Vertex* node_ptr = ptr->get_connected_node();
            while (node_ptr != nullptr){
                node_ptr->set_flow(0);
                node_ptr = node_ptr->get_next();
            }
        }
        ptr = ptr->get_next_vertex();
    }
}

void find_edge_and_update_capacity_flow(VertexPtr* residual, int flow, int start_node, int end_node){
    VertexPtr* ptr {residual};
    while (ptr != nullptr){
        if ((ptr->get_vertex_num() == start_node) && (ptr->get_connected_node() != nullptr)){
            Vertex* node_ptr = ptr->get_connected_node();
            while (node_ptr != nullptr){
                if (node_ptr->get_node_value() == end_node){
//                    node_ptr->capacity = node_ptr->capacity - flow;
                    node_ptr->set_flow(node_ptr->get_flow() + flow);
                    break;
                }
                node_ptr = node_ptr->get_next();
            }
            break;
        }
        ptr = ptr->get_next_vertex();
    }
}

void update_residaul_flow(VertexPtr* residual, int start_node, int end_node, int flow){
    VertexPtr* ptr {residual};
    while (ptr != nullptr){
        if (ptr->get_vertex_num() == end_node){
            break;
        }
        ptr = ptr->get_next_vertex();
    }
    
    Vertex* node_ptr = ptr->get_connected_node();
    while (node_ptr != nullptr){
        if (node_ptr->get_node_value() == start_node){
            break;
        }
        node_ptr = node_ptr->get_next();
    }
    
    node_ptr->set_flow(node_ptr->get_flow() - flow);
}

void update_residual(VertexPtr* residual, int flow, VertexPtr* augmenting_path [], int sink){
    for (int i {0}; i < sink-1; i++){
        if (augmenting_path[i] != nullptr && augmenting_path[i+1] != nullptr){
            
            if (augmenting_path[i+1]->get_is_residual() == true){
                update_residaul_flow(residual, augmenting_path[i]->get_vertex_num(), augmenting_path[i+1]->get_vertex_num(), flow);
            }
            else{
                find_edge_and_update_capacity_flow(residual, flow, augmenting_path[i]->get_vertex_num(), augmenting_path[i+1]->get_vertex_num());
            }
        }
        else{
            return;
        }
    }
}

void show_max_flow(VertexPtr* residual){
    int flow {0};
    Vertex* node_ptr {residual->get_connected_node()};
    while (node_ptr != nullptr){
        flow += node_ptr->get_flow();
        node_ptr = node_ptr->get_next();
    }
    cout << "Maximum Flow: " << flow << endl;
}

void show_edge_capacity_and_flow(VertexPtr* head, VertexPtr* residual){
    VertexPtr* ptr {head};
    VertexPtr* residual_ptr {residual};
    
    cout << left << setw(8) << "Edge" << left << setw(6) << "Flow" << setw(8) << "Capacity" << endl;

    while (ptr != nullptr){
        if (ptr->get_connected_node() != nullptr){
            Vertex* node_ptr {ptr->get_connected_node()};
            Vertex* residual_node_ptr {residual_ptr->get_connected_node()};
            while (node_ptr != nullptr){
                
                while (residual_node_ptr->get_node_value() != node_ptr->get_node_value()){
                    residual_node_ptr = residual_node_ptr->get_next();
                }
                
                string edge {"<" + to_string(ptr->get_vertex_num()) + "," + to_string(node_ptr->get_node_value()) + ">"};
                cout << left << setw(8) << edge << left << setw(6) << residual_node_ptr->get_flow() << left << setw(8) << node_ptr->get_capacity() << endl;
                
                node_ptr = node_ptr->get_next();
            }
        }
        ptr = ptr->get_next_vertex();
        residual_ptr = residual_ptr->get_next_vertex();
    }
}

int find_min_flow_of_augmenting_path(int augmenting_path_capacity []){
    int flow {augmenting_path_capacity[0]};
    int index {0};
    while (augmenting_path_capacity[index] != 0){
        if (augmenting_path_capacity[index] < flow){
            flow = augmenting_path_capacity[index];
        }
        index++;
    }
    
    return flow;
}

void Edmonds_Karp(VertexPtr* head, int sink){
    
    VertexPtr* residual = create_residual(head, sink);
    
    VertexPtr* augmenting_path [101] = {nullptr};
    int augmenting_path_capacity [101] = {0};
    
    BFS(residual, augmenting_path, augmenting_path_capacity, sink);
    
    while(from_source_to_sink(augmenting_path, sink) == true){
        int flow = find_min_flow_of_augmenting_path(augmenting_path_capacity);
        
        // update residual network
        update_residual(residual, flow, augmenting_path, sink);
        
        BFS(residual, augmenting_path, augmenting_path_capacity, sink);
    }
    
    // output result
    show_edge_capacity_and_flow(head, residual);
    show_max_flow(residual);    
}