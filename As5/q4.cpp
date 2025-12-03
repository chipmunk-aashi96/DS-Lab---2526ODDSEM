// Q4

#include <iostream>
using namespace std;
class SinglyLinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node{val, nullptr};
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << "->";
            temp = temp->next;
        }
        cout << "->NULL\n";
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main()
{
    SinglyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    cout << "Original Linked List: ";
    list.display();
    list.reverse();
    cout << "Reversed Linked List: ";
    list.display();
    return 0;
}