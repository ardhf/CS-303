#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// Creating a node with the data for each node
struct Node {
    int data;
    Node* next;
};

class LinkedList {
   private:
    Node* head = NULL;    // the head node of the list
    Node* tail = NULL;    // the tail node of the list
    size_t numItems = 0;  // number of items in the list

   public:
    /*  Appends a new node to the front of the linked list
        @param data          the data */
    void push_front(int data);

    /*  Appends a new node to the back of the linked list
            @param data          the data */
    void push_back(int data);

    // Removes the item at the front of the linked list
    void pop_front();

    // Removes the item at the back of the linked list
    void pop_back();

    // Returns the item at the front of the linked list
    void front();

    // Returns the item at the back of the linked list
    void back();

    // Checks if the list is empty
    void empty();

    /* Inserts a new node in the linked list
    @param index    index to insert the node into the list
    @param d        data to be added */
    void insert(size_t index, int d);

    /*Removes an item from the list
    @param index    index to remove from the list */
    bool remove(size_t index);

    /* Finds if data is in the list, returns the numItems if not found
    @param d        data to look for in list */
    size_t find(const int d);

    /*  Prints the linked list */
    void printList();

    // Returns the number of items in the list
    int getNumItems() { return numItems; }
};

#endif  // LINKEDLIST_H_