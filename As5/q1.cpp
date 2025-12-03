// Q1 

// Develop a menu driven program for the following operations on a Singly Linked List.
// (a) Insertion at the beginning.
// (b) Insertion at the end.
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a
// new Node 35 before/after the Node 30').
// (d) Deletion from the beginning.
// (e) Deletion from the end.
// (f) Deletion of a specific node, say 'Delete Node 60').
// (g) Search for a node and display its position from head.
// (h) Display all the node values. 

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

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node{val, head};
        head = newNode;
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

    void insertInBetween(int val, int refVal, bool before)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot insert.\n";
            return;
        }
        if (before && head->data == refVal)
        {
            insertAtBeginning(val);
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        while (temp != nullptr && temp->data != refVal)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Reference node not found.\n";
            return;
        }
        Node *newNode = new Node{val, nullptr};
        if (before)
        {
            newNode->next = temp;
            if (prev != nullptr)
                prev->next = newNode;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFromBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node from beginning.\n";
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            cout << "Deleted node from end.\n";
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
        cout << "Deleted node from end.\n";
    }

    void deleteNode(int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node with value " << val << ".\n";
            return;
        }
        Node *temp = head;
        Node *prev = nullptr;
        while (temp != nullptr && temp->data != val)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Node with value " << val << " not found.\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Deleted node with value " << val << ".\n";
    }

    void searchNode(int val)
    {
        Node *temp = head;
        int pos = 1;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                cout << "Node with value " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node with value " << val << " not found.\n";
    }

    void displayList()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "List elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
int main()
{
    SinglyLinkedList list;
    int choice, val, refVal;
    bool before;
    do
    {
        cout << "\n--- Singly Linked List Operations ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before/after a node\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete a specific node\n";
        cout << "7. Search a node\n";
        cout << "8. Display list\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter reference node value: ";
            cin >> refVal;
            cout << "Insert before (1) or after (0)? ";
            cin >> before;
            list.insertInBetween(val, refVal, before);
            break;
        case 4:
            list.deleteFromBeginning();
            break;
        case 5:
            list.deleteFromEnd();
            break;
        case 6:
            cout << "Enter node value to delete: ";
            cin >> val;
            list.deleteNode(val);
            break;
        case 7:
            cout << "Enter node value to search: ";
            cin >> val;
            list.searchNode(val);
            break;
        case 8:
            list.displayList();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);
    return 0;
}