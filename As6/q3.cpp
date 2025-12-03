// Q3

#include<iostream>
using namespace std;

class DNode{
    public:
        int data;
        DNode*prev;
        DNode*next;
        DNode(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }
};

void count(DNode*&head){
    if(head==NULL){
        cout<<"list is empty";
    }
    
    DNode*temp=head;
    int count=1;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    cout<<"Size of Doubly LL is: "<<count;
}

class CNode{
    public:
        int data;
        CNode*prev;
        CNode*next;
        CNode(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }
};

void count(CNode*&head){
    if(head==NULL){
        cout<<"list is empty";
    }
    
    CNode*temp=head;
    int count=1;
    do{
        temp=temp->next;
        count++;
    }
    while(temp!=head);
    cout<<"Size of Circular LL is: "<<count;
}