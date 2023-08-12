#include<iostream>
using namespace std;

class Node{

public:
int data;
Node* next=nullptr;
Node(){}
Node(int data){
    this->data=data;
    this->next=nullptr;
}


};

void print(Node* &head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr= curr->next;

    }

}
void insertAtone( Node* &head, Node* &tail, Node* &element){

    if(head==nullptr){
       head=element;
       tail=element;
        return;

    }
    else{
    tail->next=element;
    tail=element;
    }



}
void insertAtTwo( Node* &head, Node* &tail, Node* &element){

    if(head==nullptr){
        head=element;
        tail=element;
        return;

    }
   else{ tail->next=element;
    tail=element;
   }



}
void insertAtZero( Node* &head, Node* &tail, Node* &element){

    if(head==nullptr){
        head=element;
        tail=element;
        return;

    }
    else{
    tail->next=element;
    tail=element;
    }



}

void Sort( Node* &head, Node* &one, Node* &oneTail, Node* &two, Node* twoTail, Node* &zero ,Node* &zeroTail){
    Node* curr=head;

    
Node* temp=curr->next;

    while(curr!=nullptr){
         temp = curr->next;
        if(curr->data==1){
            insertAtone(one, oneTail, curr);
        }
        else if(curr->data==2){
            insertAtTwo(two, twoTail, curr);
        }
        else if  (curr->data==0){
            insertAtZero(zero, zeroTail, curr);
        }
       
        curr->next=nullptr;
        
        


        


        curr=temp;
        
        
    }
 
    Node* sort=nullptr;

    if(zeroTail!=nullptr){
        if(oneTail!=nullptr){
        zeroTail->next=one;

        sort=zero;}
        else {
            zeroTail->next=two;
            sort =zero;
        }
    }
  else if (oneTail!=nullptr){
       oneTail->next=two;
        sort=one;
    }
   else  if (twoTail!=nullptr) {
        sort=two;
    }if(oneTail!=nullptr){
        oneTail->next=two;
    }
   
 
 


}


int main(){



    cout<<"Hello world its me raju chadhary"<<endl;
    cout<<"Sorting 0s ,1s,2s"<<endl;


    Node* head=new Node(0);
    Node*first=new Node(0);
    Node* second = new Node(1);
    Node* third = new Node(1);
    Node* fourth= new Node(0);
    Node* fifth= new Node(2);
    Node* sixth= new Node(2);
    head->next= first; first->next=second; second->next=third; third->next=fourth; fourth->next=fifth; fifth->next =sixth;
cout<<"The Before Sorting "<<endl;
    Node* curr=head;
    Node* one=nullptr;
Node* oneTail=nullptr;
Node* two=nullptr;
Node* twoTail=nullptr;
Node* zero=nullptr;
Node* zeroTail=nullptr;
Node* temp=curr->next;
print(head);



Sort(head, one ,oneTail, two,twoTail, zero, zeroTail);
cout<<endl<<" After Sorting "<<endl;
print(head);



}