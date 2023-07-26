#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node() {}; // Default constructor
    Node(int data) { // Constructor with data
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void InsertionAtHead(Node* &head, int data, Node* &tail) {
    // If the linked list is empty, create a new node and make it both head and tail.
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        // If the linked list is not empty, create a new node and insert it at the head.
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void print(Node* &head) {
    // Function to print the elements of the linked list starting from the head.
    if(head==NULL){
        cout<<"The Linked List Is Empty "<<endl;
        return;
    }
    Node* temp = head;
    
    while (temp != NULL) {
        cout << temp->data << " " << endl;
        temp = temp->next;
    }
}

void InsertionAtTail(Node* &head, int data, Node* &tail) {
    // If the linked list is empty, create a new node and make it both head and tail.
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        // If the linked list is not empty, create a new node and insert it at the tail.
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int Length(Node* &head) {
    // Function to calculate the length of the linked list.
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void InsertionAtPosition(Node* &head, int data, int position, Node* &tail) {
    // If the linked list is empty, create a new node and make it both head and tail.
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If the position is 1, insert the new node at the head.
    if (position == 1) {
        InsertionAtHead(head, data, tail);
        return;
    }

    // Get the length of the linked list.
    int len = Length(head);
    
    // If the position is greater than or equal to the length, insert the new node at the tail.
    if (position >= len) {
        InsertionAtTail(head, data, tail);
        return;
    }

    // Insert the new node at the specified position in the linked list.
    Node* left = head;
    int i = 1;
    while (i != position - 1) {
        left = left->next;
        i++;
    }
    Node* Right = left->next;
    Node* newNode = new Node(data);
    newNode->next = Right;
    Right->prev = newNode;
    left->next = newNode;
    newNode->prev = left;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int value;

    // Main menu loop
    do {
        cout << "       Main Menu     " << endl;
        cout << "Display a Linked Press 1" << endl;
        cout << "Insertion At Head of a Linked List Press 2" << endl;
        cout << "Insertion At Tail of a Linked List Press 3" << endl;
        cout << "Insertion At Position of a Linked List Press 4" << endl;
   
        cin >> value;

        // Check for valid input
        if (value < 0 || value > 5) {
            cout << "Enter a correct value" << endl;
            continue; // Restart the loop to get a valid input
        }

        int data;
        int position;
        switch (value) {
            case 1:
                // Display the linked list elements
                print(head);
                break;
            case 2:
                // Insertion at the head of the linked list
                cout << "Enter The value for Insertion: ";
                cin >> data;
                InsertionAtHead(head, data, tail);
                break;
            case 3:
                // Insertion at the tail of the linked list
                cout << "Enter The value for Insertion: ";
                cin >> data;
                InsertionAtTail(head, data, tail);
                break;
            case 4:
                // Insertion at a specified position in the linked list
                cout << "Enter The value for Insertion: ";
                cin >> data;
                cout << "Enter The position where you want to Insert this value: ";
                cin >> position;
                InsertionAtPosition(head, data, position, tail);
                break;
        }

        cout << "Press 0 to exit or 5 for the main menu: ";
        cin >> value;

    } while (value != 0);

    return 0;
}
