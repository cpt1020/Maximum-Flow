#include <iostream>
#include "graph.h"
using namespace std;

bool vertex_exists(VertexPtr* head, int num){
    while (head != nullptr){
        if (head->get_vertex_num() == num){
            return true;
        }
        else{
            head = head->get_next_vertex();
        }
    }
    return false;
}

VertexPtr* add_vertex(VertexPtr* head, int num){
    
    for (int i {0}; i < num; i++){
        VertexPtr* new_vertex = new VertexPtr();
        new_vertex->set_vertex_num(i);
        
        if (head == nullptr){
            head = new_vertex;
        }
        else if (head->get_next_vertex() == nullptr){
            head->set_next_vertex(new_vertex);
        }
        else{
            VertexPtr* ptr {head};
            while (ptr->get_next_vertex() != nullptr){
                ptr = ptr->get_next_vertex();
            }
            ptr->set_next_vertex(new_vertex);
        }
    }
    return head;
}

void add_edge(VertexPtr* head, int start_node, int end_node, int capacity){
    if (vertex_exists(head, start_node) == false || vertex_exists(head, end_node) == false){
        cout << "add an invalid edge" << endl;
        return;
    }
    
    VertexPtr* ptr = head;
    while (ptr != nullptr){
        if (ptr->get_vertex_num() == start_node){
            break;
        }
        ptr = ptr->get_next_vertex();
    }
    
    // 先找start_node是否已指向end_node
    Vertex* node_ptr = ptr->get_connected_node();
    while (node_ptr != nullptr){
        // 若start_node已指向end_node，就assign新的capacity
        if (node_ptr->get_node_value() == end_node){
            node_ptr->set_capacity(capacity);
            return;
        }
        node_ptr = node_ptr->get_next();
    }
    
    // 最後處理start_node沒有指向end_node的狀況
    Vertex* new_node = new Vertex();
    new_node->set_node_value(end_node);
    new_node->set_capacity(capacity);
    
    node_ptr = ptr->get_connected_node();
    if (node_ptr == nullptr){
        ptr->set_connected_node(new_node);
    }
    else if (node_ptr->get_next() == nullptr && new_node->get_node_value() < node_ptr->get_node_value()){
        ptr->set_connected_node(new_node);
        new_node->set_next(node_ptr);
    }
    else if (node_ptr->get_next() == nullptr){
        node_ptr->set_next(new_node);
    }
    else{
        while (new_node->get_node_value() > node_ptr->get_node_value()){
            if (node_ptr->get_next() != nullptr){
                if (new_node->get_node_value() < node_ptr->get_next()->get_node_value()){
                    new_node->set_next(node_ptr->get_next());
                    node_ptr->set_next(new_node);
                    return;
                }
            }
            else{
                node_ptr->set_next(new_node);
                return;
            }
            node_ptr = node_ptr->get_next();
        }
        
        ptr->set_connected_node(new_node);
        new_node->set_next(node_ptr);
    }
    return;
}

VertexPtr* creat_graph(VertexPtr* head, int &total_node_num, int &start_node, int &end_node, int &capacity){
    cin >> total_node_num;
    head = add_vertex(head, total_node_num);
    
    while (cin >> start_node){
        cin >> end_node;
        cin >> capacity;
        add_edge(head, start_node, end_node, capacity);
    }
    return head;
};