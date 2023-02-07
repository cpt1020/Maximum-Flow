#include "BFS_queue.h"

// constructor
BFSQueue::BFSQueue(){
    rear = 0;
    front = 0;
};

// get function
int BFSQueue::get_rear() const{
    return rear;
}
int BFSQueue::get_front() const{
    return front;
}

// set function
void BFSQueue::set_rear(int rear_val){
    rear = rear_val;
}
void BFSQueue::set_front(int front_val){
    front = front_val;
}


bool BFSQueue::queue_is_empty(){
    if (front == rear){
        return true;
    }
    else{
        return false;
    }
}

void BFSQueue::Enqueue(VertexPtr* vertex){
    if (rear != 100){
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

VertexPtr* BFSQueue::Dequeue(){
    if (this->queue_is_empty() == true){
        // if queue is empty, return nullptr
        return nullptr;
    }
    else{
        front = front + 1;
        VertexPtr* vertex {queue[front]};
        return vertex;
    }
}