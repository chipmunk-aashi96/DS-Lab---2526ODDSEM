// Q3 

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
        cout << endl;
    }

    int findMiddle()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return -1;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

int main()
{
    SinglyLinkedList list;
    int values[] = {1, 2, 3, 4, 5};
    for (int val : values)
    {
        list.insertAtEnd(val);
    }
    cout << "Linked List: ";
    list.display();
    int middleValue = list.findMiddle();
    if (middleValue != -1)
    {
        cout << "Middle of the Linked List: " << middleValue << endl;
    }
    return 0;
}