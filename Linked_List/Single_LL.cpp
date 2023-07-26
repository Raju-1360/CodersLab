#include<iostream>
using namespace std;
class Node{

  public:

  int data;
  Node*next;
  Node(){
    this->data=0;
    this->next=NULL;

  }
  Node(int data){

    this->data=data;
    this->next=NULL;
  }



};

void InsertionAtHead(Node* &head, int data, Node* &tail){

  if(head==NULL){

    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
    return;
  }
else{
  Node* newNode=new Node(data);
  newNode->next=head;
  head=newNode;
}

}

void InsertionAtTail(Node* &head,Node* &tail,int data){
  
  if(head==NULL){

    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
    return;
  }
 Node* newNode=new Node(data);
tail->next=newNode;
tail=newNode;
 
}
// void insertAtTail(Node* &head,Node* &tail, int data) {
//         if(head == NULL) {
//                 Node* newNode = new Node(data);
//                 head = newNode;
//                 tail = newNode;
//                 return;
//         }
//         //step1: creatae a node
//         Node* newNode = new Node(data);
//         //step2: connect woth tail ndoe
//         tail->next = newNode;
//         //step3: update tail;
//         tail = newNode;
// }

// void InsertionAtPosition(Node* &head, Node* &tail,int  position,int data){
//  if(head==NULL){

//     Node* newNode=new Node(data);
//     head=newNode;
//     tail=newNode;
//     return;
//   }

// if(position==0){
//   InsertionAtHead(  head, data, tail);
//   return;
// }
// int len=lenght(head);
// if(position>=len){
//   InsertionAtTail(head,tail,data);
//   return;
// }

// Node* prev=head;

// int i=1;
// Node* temp=head;
// while(i>position){
// prev=prev->next;

//   i++;

// }
// Node* curr=prev->next;
// Node* newNode=new Node(data);
// newNode->next=curr;
// prev->next=newNode;



// }



void print(Node* &head){

  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" "<<endl;
    temp=temp->next;
  }
}
int lenght( Node* & head){
   Node* temp=head;
   int len=0;
  while(temp!=NULL){
   
    temp=temp->next;
    len++;
  }
  return len;

}

void InsertionAtPosition(Node* &head, Node* &tail,int  position,int data){
 if(head==NULL){

    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
    return;
  }

if(position==0){
  InsertionAtHead(  head, data, tail);
  return;
}
int len=lenght(head);
if(position>=len){
  InsertionAtTail(head,tail,data);
  return;
}

Node* prev=head;

int i=1;
Node* temp=head;
while(i<position-1){
prev=prev->next;

  i++;

}
Node* curr=prev->next;

Node* newNode=new Node(data);

newNode->next=curr;
prev->next=newNode;




}


int main(){

  cout<<"Hello world its linked list time "<<endl;

Node* head=NULL;
Node* tail=NULL;
InsertionAtHead(head,45,tail);
InsertionAtHead(head,1,tail);
InsertionAtHead(head,63,tail);
InsertionAtHead(head,5,tail);
InsertionAtHead(head,4,tail);

// print(head);
// cout<<head->next->next->data;

InsertionAtTail(head,tail,10);
InsertionAtTail(head,tail,1);
InsertionAtTail(head,tail,1);
InsertionAtTail(head,tail,12);
// insertAtTail(head,tail,41);
// insertAtTail(head,tail,401);
// insertAtTail(head,tail,401);
// insertAtTail(head,tail,408);
print(head);
// cout<<" -->";
// // int len=lenght(head);
// // cout<<len;
// print(head);
// InsertionAtPosition(head,tail,3,400);
// cout<<"Adding at a given position"<<endl;

// print(head);




// print(tail);

cout<<"Hello world its me raju chaudhary "<<endl;
cout<<"learning c++ language "<<endl;


}