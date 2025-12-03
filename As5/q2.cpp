// Q2

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
    void insertAtEnd(int value)
    {
        Node *newNode = new Node{value, nullptr};

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
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

    int deleteAllOccurrences(int key)
    {
        int count = 0;
        while (head != nullptr && head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        Node *current = head;
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->data == key)
            {
                Node *temp = current;
                prev->next = current->next;
                current = current->next;
                delete temp;
                count++;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        return count;
    }
};

int main()
{
    SinglyLinkedList list;
    int values[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
    {
        list.insertAtEnd(values[i]);
    }
    cout << "Original Linked List: ";
    list.display();
    int key = 1;
    int count = list.deleteAllOccurrences(key);
    cout << "Count of " << key << ": " << count << endl;
    cout << "Updated Linked List: ";
    list.display();
    return 0;
}