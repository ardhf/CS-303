#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

void LinkedList::push_front(int data) {
    Node* new_node = new Node();  // creates a new node
    numItems++;                   // increment the number of items in the list

    new_node->data = data;  // sets the data

    // if its the first item in the list, set the tail also to the same item
    if (numItems == 1) {
        tail = new_node;
    } else {
        new_node->next = head;  // link the new first node to the head of the list (now the second node)
    }

    head = new_node;  // update the head of the list to the new first node

    printList();
}

void LinkedList::push_back(int data) {
    Node* new_node = new Node();  // Create a new node
    numItems++;                   // increment the number of items in the list

    new_node->data = data;  // Sets the data

    new_node->next = NULL;  // Sets the value of the next item to NULL since the new link is at the end of the list

    // If its the first item in the list, set the head also to the same link as the tail
    if (numItems == 1) {
        head = new_node;
    } else {
        tail->next = new_node;  // Links the last item of the list to the new last item of the list
    }

    tail = new_node;  // Updates the reference to the tail of the list
    printList();
}

void LinkedList::pop_front() {
    if (numItems == 1) {  // If there is only one item in the list, set head and tail to NULL and set numItems to 0
        head = NULL;
        tail = NULL;
        numItems--;
        return;
    }

    if (head != NULL) {
        Node* temp = head;  // Makes a new node that points to the head
        head = head->next;  // Sets head to the second item in the list
        numItems--;         // decrements numItems
        delete temp;        // Deletes the old head
    } else {
        cout << "Cannot pop front from empty list" << endl;
    }
    printList();
}

void LinkedList::pop_back() {
    // Tests if the list is empty
    if (!numItems) {
        cout << "Cannot pop back from empty list" << endl;
    }

    // If there is only one item in the list, set head and tail to NULL and set numItems to 0
    if (numItems == 1) {
        head = NULL;
        tail = NULL;
        numItems--;
        return;
    }

    Node* temp = head;  // Makes a new node that points to the head

    // Traverses the list and goes to the second to last item
    for (size_t i = 0; i < numItems - 2; i++) {
        temp = temp->next;
    }

    /*
        In a list of 3 items, the loop above will set temp to the 2nd node
        Then set the 2nd node->next to NULL
        Then set temp to the last item and then delete it
    */

    tail = temp;        // The tail node is now the second to last node
    temp = temp->next;  // temp is now the last node
    delete temp;        // The last node is deleted

    tail->next = NULL;  // The next of the new tail is set to NULL

    numItems--;  // numItems is decremented

    printList();  // Updated list is shown to the user
}

void LinkedList::front() {
    // Checks to see if there is a head node in the list
    if (head == NULL) {
        cout << "No items in list" << endl;
    } else {
        cout << head->data << " is at the front of the list" << endl;  // Returns the data of the head node
    }
}

void LinkedList::back() {
    // Checks if there is a tail node
    if (tail == NULL) {
        cout << "No items in list" << endl;
    } else {
        // Returns the data of the tail node
        cout << tail->data << " is at the back of the list" << endl;
    }
}

void LinkedList::empty() {
    // Checks if the list is empty
    if (!numItems) {
        cout << "List is empty" << endl;
    } else {
        cout << "List is not empty" << endl;
    }
}

void LinkedList::insert(size_t index, int d) {
    /*
        If the index is 4, the loop will return the third element of the list
    */

    // Will use the push_front function if possible
    if (index == 1 || numItems == 0) {
        push_front(d);
        return;
    }

    Node* temp = head;            // New node that points to the head;
    Node* new_node = new Node();  // New node

    new_node->data = d;  // Sets the data of the new node

    // Catches the index if it exceedes the amount of items in the list
    if (index > numItems) {
        index = numItems + 1;
        tail = new_node;
    }

    // Traverses the list to the second to last item
    for (size_t i = 2; i < index; i++) {
        temp = temp->next;
    }

    // temp is the element behind the index thats wanted to insert at (if index is 4, temp is the 3rd element)

    new_node->next = temp->next;  // Makes the new_node next to the temp next

    temp->next = new_node;  // Makes the temp next to the new node

    numItems++;  // increments the numItems

    printList();  // Prints the updated list to the user
}

bool LinkedList::remove(size_t index) {
    /*
        To remove a node from a linked list, first you need to make a new node
        Then traverse the list until you get to the node behind the one you want to delete
        Then link the node before the node to be deleted with the one in front of the same node
        Then delete the node
    */

    // If index is invalid, let the user know
    if ((index < 1) || (index > numItems)) {
        cout << "Invalid index" << endl;
        return false;
    }

    // Will use pop_front or pop_back if possible
    if (index == 1) {
        pop_front();
        return true;
    } else if (index == numItems) {
        pop_back();
        return true;
    }

    Node* new_node = head;  // Makes a new node that points to the head

    // sets new_node to the node before the node to be deleted
    for (size_t i = 0; i < index - 2; i++) {
        new_node = new_node->next;
    }

    new_node->next = new_node->next->next;  // Sets the new_node next to the next of the new_node next (cuts out the middle node)

    numItems--;  // decrements the number of items

    printList();  // Returns the updated list to the user

    return true;  // Returns true because it was successful
}

size_t LinkedList::find(const int d) {
    Node* temp = head;  // Creates a new node that points to the head of the list
    int index = 1;      // start the list index at 1
    // traverses the list and looks at each data value for the data to find
    for (int i = 0; i < numItems; i++) {
        if (temp->data == d) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    // If the data is found, return the index where it is first found
    return numItems;
}

// Prints the list
void LinkedList::printList() {
    Node* head_ref = head;  // Makes a new node starting at the head to print out all of the values
    while (head_ref != NULL) {
        cout << head_ref->data << "--->";
        head_ref = head_ref->next;
    }
    cout << endl;
}

int main() {
    int s;       // stores the user selection
    int p1, p2;  // temps to store parameter

    LinkedList l;  // Makes a linkedList object l

    while (s != 0) {  // Will prompt the user as long as the input is not 0
        cout << "Enter an option\n1) Push front\n2) Push back\n3) Print list\n4) Pop front\n5) Pop back\n6) Front\n7) Back\n8) "
                "Empty\n9) Insert\n10) Remove\n11) Find\n0) Exit\n\n";
        cin >> s;

        // swtich case for all of the different functions and prompts for the user
        switch (s) {
            case 1:
                cout << "Enter integer data: ";
                cin >> p1;
                l.push_front(p1);
                break;

            case 2:
                cout << "Enter integer data: ";
                cin >> p1;
                l.push_back(p1);
                cout << l.getNumItems() << " items in the list\n" << endl;
                break;

            case 3:
                // print the linked list data
                l.printList();
                cout << l.getNumItems() << " items in the list\n" << endl;
                break;

            case 4:
                // Pops the first node out of the list
                l.pop_front();
                cout << l.getNumItems() << " items in the list\n" << endl;
                break;

            case 5:
                // Pops the last node out of the list
                l.pop_back();
                cout << l.getNumItems() << " items in the list\n" << endl;
                break;

            case 6:
                // Returns the item at the front of the list
                l.front();
                break;

            case 7:
                // Returns the item at the end of the list
                l.back();
                break;

            case 8:
                // Checks if the list is empty
                l.empty();
                break;

            case 9:
                cout << "Enter an index to insert at" << endl;
                cin >> p1;
                cout << "Enter the integer you would like to insert" << endl;
                cin >> p2;
                l.insert(p1, p2);
                break;

            case 10:
                cout << "Enter an index to remove" << endl;
                cin >> p1;
                if (l.remove(p1))
                    cout << "Item at index " << p1 << " was removed successfully" << endl;
                break;
            case 11:
                cout << "Enter an integer to find" << endl;
                cin >> p1;
                cout << "Item found at index " << l.find(p1) << endl;
                break;
            default:
                cout << "Enter a valid integer" << endl;
        }
    }

    return 0;
}