#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
   private:
    int* arr;                         // pointer
    int front, rear, capacity, size;  // integers to keep track of front, rear, capacity and size

   public:
    Queue(int capacity) {           // constructor for queue class
        this->capacity = capacity;  // sets capacity to passed value
        arr = new int[capacity];    // sets the array pointer to head of new capacity array
        front = rear = size = 0;    // initalizes front rear and size to 0
    }

    bool is_empty();      // returns if the queue is empty or not
    bool is_full();       // returns if the queue is full or not
    int size_of_queue();  // returns the number of elements in the queue
    bool enqueue(int);    // enqueues an element
    int dequeue();        // dequeues an element and returns it to the user
    int front_element();  // returns the front element
};

#endif