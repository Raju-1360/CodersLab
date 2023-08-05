#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(){}
    Node(int data){
        this->data=data;
       this-> next=NULL;
    }
};

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;

    }
}
Node* reverse(Node* &prev ,Node* & curr){

  
    while(curr!=NULL){
          Node* temp=curr->next;
          curr->next=prev;
          prev=curr;
          curr=temp;

    }return prev;
   





}


Node* Middle( Node* &head,Node* &mid){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

       
    }
     mid=slow;
        return mid;


}
bool palindrome(Node* &head){
    if(head==NULL){
        cout<<"The Linked list is empty"<<endl;
        return false;

    }
    Node* mid=NULL;
    Middle(head, mid); 
    
    Node*prev=NULL;
    Node* curr=mid->next;
    Node* reverse_head=reverse(prev,curr);
    mid->next=reverse_head;

    print(head);
    Node* temp=head;
    Node* temp2=reverse_head;
    while(temp2!=NULL){
        if(temp->data!=temp2->data){
            return false;
        }else{
            temp=temp->next;
            temp2=temp2->next;
        }
    }
    return true;



}
int main(){

    Node* head=new Node(10);
    Node* first= new Node(20);
    Node* second= new Node(30);
    Node* third=new Node(30);
    Node* fourth=new Node(20);
    Node* fifth= new Node(10);
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    

    
   bool ans= palindrome(head);

   ans==1?cout<<"Linked list is a Palindrome": cout<<"Given linked list is not a palindrome";



}