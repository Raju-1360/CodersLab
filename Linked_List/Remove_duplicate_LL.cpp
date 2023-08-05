#include<iostream>

using namespace std;
#include<bits/stdc++.h>
class Node{

    public:
    int data;
    Node* next;
    Node(){}
    Node(int data){
        this->data=data;
        this->next=nullptr;

    }
};

void Remove_duplicate(Node* & head){

//Finding the occurences of element of each
    unordered_map<int,int>mp;
    Node* temp=head;
    while(temp!=nullptr){
        mp[temp->data]++;
        temp=temp->next;

    }
//Removing the duplicate
       Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        if (mp[curr->data] > 1) {
            mp[curr->data]--;
            Node* temp = curr;
            curr = curr->next;
            if (prev != nullptr) {
                prev->next = curr;
            } else {
                head = curr;
            }
            temp->next = nullptr;
            delete temp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

   // Printng The element after Removing

    Node* temp2=head;
    while(temp2!=nullptr){
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
    

}
int main(){

  Node* head=new Node(10);
  Node* first=new Node(20);
  Node* second= new Node(60);
  Node* third= new Node(20);
  Node* fourth= new Node(10);
  head->next=first;
  first->next=second;
  second->next=third;
  third->next=fourth;
  Remove_duplicate(head);

}