#include "Queue.h"
#include <iostream>

using namespace std;

bool Queue::enqueue(int value) {  // adds an element to the queue and returns true if successful
    if (is_full()) {              // returns false if the queue is full
        return false;
    }
    arr[rear] = value;             // sets the user value to the element in the array with the index of rear
    rear = (rear + 1) % capacity;  // updates the circular arrays rear
    size++;                        // updates the size
    return true;
}

int Queue::dequeue() {  // removes an element from the queue and returns the value if successful
    if (is_empty()) {   // checks if queue is empty
        cout << "Error: Queue is empty." << endl;
        return -1;
    }
    int value = arr[front];          // sets value to the front of the circular array
    front = (front + 1) % capacity;  // updates the front
    size--;                          // updates the size
    return value;                    // returns the value
}

int Queue::front_element() {  // returns the element at the front of the queue
    if (is_empty()) {         // checks if queue is empty
        cout << "Error: Queue is empty." << endl;
        return -1;
    }
    return arr[front];  // returns the front of the queue
}

bool Queue::is_full() {  // returns true if the queue is full
    return size == capacity;
}

bool Queue::is_empty() {  // returns true if the queue is empty
    return size == 0;
}

int Queue::size_of_queue() {  // returns the number of elements in the queue
    return size;
}

int main() {
    int p1, s;  // int for the size of the queue and the current selection

    cout << "What should be the max number of elements allowed in the queue? (enter an integer): ";  // prompts the user and takes the input
                                                                                                     // and initializes the queue
    cin >> p1;
    cout << endl;

    Queue q(p1);  // makes a new Queue object with the size the user gave it

    while (s != 0) {  // while the user doesn't want to stop the program, do what the user selected
        cout << "\nWhat would you like to do? \n";
        cout << "0) Stop the program. \n";
        cout << "1) Insert an integer in the rear of the queue. \n";
        cout << "2) Remove and return the integer in the front. \n";
        cout << "3) Return the first element without removing it. \n";
        cout << "4) Check if the queue is empty. \n";
        cout << "5) Return the number of elements in the queue" << endl;

        cin >> s;  // stores the users selection

        switch (s) {  // switch case for what the user selected
            case 1:   // prompts the user for an integer to enqueue
                cout << "Enter an integer to enqueue to the rear: ";
                cin >> p1;

                if (q.enqueue(p1))  // tells the user if the enqueue was a success
                    cout << "\nThe enqueue was a success" << endl;
                else
                    cout << "\nThe enqueue was not a success, the queue is full" << endl;

                break;
            case 2:  // dequeues and returns if success or not
                if (q.dequeue() != -1)
                    cout << "\nThe dequeue was a success and returns: " << q.dequeue() << endl;
                else
                    cout << "\nThe dequeue was not a success, queue is empty" << endl;

                break;
            case 3:  // returns the front element
                cout << "\nThe front element is: " << q.front_element() << endl;

                break;
            case 4:  // returns if the queue is empty or not
                if (q.is_empty())
                    cout << "\nThe queue is empty" << endl;
                else
                    cout << "\nThe queue is not empty" << endl;

                break;
            case 5:  // returns the size of the queue
                cout << "\nThe queue has " << q.size_of_queue() << " elements" << endl;

                break;
        }
    }
    return 0;
}
