// Q4 

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node*prev;
        Node*next;
        Node(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }
};

void checkpallin(Node*&head){
    if(head==NULL){
        cout<<"list is empty";
    }
    
    Node*temp1=head;
    Node*temp2=head;
    while(temp2!=NULL){
        temp2=temp2->next;
    }
    while(temp1!=temp2){
        if(temp1->data==temp2->data){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else{
            cout<<"Not Palindrome";
            return;
        }
    }
    cout<<"Palindrome";
}