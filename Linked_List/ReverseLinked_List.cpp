
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {}; // Default constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head) {
    // Function to print the linked list starting from the head node
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

Node* Reverse_Linked_List(Node* &prev, Node* &curr) {
    // Recursive function to reverse a linked list using a helper function
    if (curr == NULL) {
        return prev;
    }
    Node* forward = curr->next;
    curr->next = prev;
    Reverse_Linked_List(curr, forward);
}

void ReverseLinkedList(Node* &prev, Node* &curr) {
    // Iterative function to reverse a linked list
    while (curr != NULL) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
}

int main() {
    Node* head = new Node(45);
    Node* first = new Node(46);
    Node* second = new Node(47);
    Node* third = new Node(48);
    Node* fourth = new Node(49);
    Node* fifth = new Node(50);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* prev = NULL;
    Node* curr = head;

    int value;
    Node* ans = NULL;

    do {
        cout << "Main Menu " << endl;
        cout << "Reversing a Linked List " << endl;
        cout << "There are 2 Approaches " << endl;
        cout << "Press 1 to Reverse a Linked List By Recursion " << endl;
        cout << "Press 2 to Reverse a Linked List By Loop " << endl;
        cout << "Note: You can Reverse Linked List only once. To reverse again, run the program again. " << endl;
        cin >> value;

        if (value < 1 || value > 2) {
            continue; // Handling invalid inputs, re-displaying the menu.
        }

        switch (value) {
        case 1:
            cout << "The Linked List Before Reversing: " << endl;
            print(head);
            cout << endl << "The Linked List After Reversing: " << endl;
            ans = Reverse_Linked_List(prev, curr);
            print(ans);
            break;
        case 2:
            cout << "The Linked List Before Reversing: " << endl;
            print(head);
            cout << endl << "The Linked List After Reversing: " << endl;
            ReverseLinkedList(prev, curr);
            print(prev);
            break;
        }

        cout << "Enter 0 to exit" << endl << "Press 5 to go back to the main menu" << endl;
        cin >> value;
    } while (value != 0);


    return 0;
}
