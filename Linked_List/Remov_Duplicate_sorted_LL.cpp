#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next=NULL;
    Node(){}
    Node(int data){
        this->data=data;
        this->next=NULL;

    }


};
void print(Node* & head){

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
void Remove_duplicate(Node* &head){
    Node* curr= head;
    while(curr!=NULL){

        if((curr->next!=NULL)&&(curr->data==curr->next->data)){
            Node* temp=curr->next;
            curr->next=curr->next->next;
            temp->next=NULL;
            delete temp;

        }
        else {
            curr=curr->next;
        }
    }


 


    }


int main(){
    Node* head=new Node(10);
    Node* second=new Node(10);
    Node* third= new Node(20);
    Node* fourth=new Node(20);
    Node* fifth=new Node(30);
    Node* sixth= new Node(30);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    print(head);
  
Remove_duplicate(head);
cout<<"After Removing Duplicate"<<endl;
print(head);


}


