#ifndef BFS_QUEUE_H
#define BFS_QUEUE_H
#include "VertexPtr.h"

class BFSQueue{

private:
    VertexPtr* queue [101] = {nullptr};
    int rear;
    int front;

public:

    // Constructor
    BFSQueue();

    // get function
    int get_rear() const;
    int get_front() const;

    // set function
    void set_rear(int rear_val);
    void set_front(int front_val);

    bool queue_is_empty();
    void Enqueue(VertexPtr* vertex);
    VertexPtr* Dequeue();
};

#endif