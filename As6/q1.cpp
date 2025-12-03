// Question 1

#include <iostream>
using namespace std;

class DNode{
public:
    int data;
    DNode *prev;
    DNode *next;

    DNode(int val){
        data = val;
        prev = next = nullptr;
    }
};

class DoublyLinkedList{
    DNode *head;
public:
    DoublyLinkedList(){
        head = nullptr;
}

void insertB(int val){ // insertion at beginning  --1
    DNode *newNode = new DNode(val);
    if(!head){ // if empty list
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev=newNode;
    head = newNode;
}

void insertE(int val){ // insertion at end  -- 2
    DNode *newNode = new DNode(val);
    if(!head){ // if empty list
        head = newNode;
    }
    else{
        DNode *temp= head;
        while(temp->next){
            temp = temp->next;
        }
    temp->next = newNode;
    newNode->prev = temp;
    }
}

void insertAfterP(int P,int val){ // insert after given Node -- 3
    DNode *temp = head;
    while(temp && temp->data != P ){
        temp = temp->next;
    }
    if(!temp){
        cout<<"Node not found";
    }
    else{
        DNode *newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next){
            temp->next->prev=newNode;
        }
        temp->next = newNode;
    }
}

void deletion(int key){ // delete entered Node -- 4
    if(!head)return;
    DNode *temp = head;
    if (head->data == key){
        head = head->next;
        if(head) head->prev = nullptr;
        delete temp;
        return;
    }
    while(temp && temp->data != key){
        if(!temp){
            cout << "Node not found  \n";
            return;
        }
        if(temp->next){
            temp->next->prev = temp->prev;
        }
        if(temp->prev){
            temp->prev->next = temp->next;
        }

        delete temp;
    }
}
void search(int key){ // search given Node -- 5
    DNode *temp = head;
    int pos = 1;
    while(temp){
        if(temp->data == key){
            cout << "Node found -- " << key << "found at position : "<< pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node not found \n";
}

void display(){ // display -- 6
    DNode *temp = head;
    cout << "List : ";
    while (temp){
        cout << temp->data << "  " ;
        temp = temp->next;
    }
    cout << endl;
    }
};

class CNode {
public:
    int data;
    CNode* next;

    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    CNode* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (!head) { // no node
            head = newNode;
            newNode->next = head;  
            return;
        }
        // To insert at beginning
        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;  
            return;
        }
        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // Insert after node with value P
    void insertAfter(int P, int val) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        do{
            if (temp->data == P) {
                CNode* newNode = new CNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << val << " after " << P << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node with value " << P << " not found.\n";
    }

    // Delete node with value key
    void deletion(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        CNode* curr = head;
        CNode* prev = nullptr;

        // if head is to be deleted
        if (head->data == key) {
            // If only one node present
            if (head->next == head) {
                delete head;
                head = nullptr;
                cout << "Node " << key << " deleted.\n";
                return;
            }
            // Find last node to update its next pointer
            CNode* last = head;
            while (last->next != head) {
                last = last->next;
            }
            CNode* toDelete = head;
            last->next = head->next;
            head = head->next;
            delete toDelete;
            cout << "Node " << key << " deleted.\n";
            return;
        }

        // For other nodes
        prev = head;
        curr = head->next;
        while (curr != head) {
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                cout << "Node " << key << " deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Node " << key << " not found.\n";
    }

    // Search for node with value key
    void search(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node " << key << " not found.\n";
    }

    // Display list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        cout << "Circular List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};



int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choiceL, opt;
    bool running = true;

    cout << "Menu driven program\n";

    while (running) {
        cout << "  Select List Type:\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circularly Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choiceL;

        if (choiceL == 3) {
            running = false;
            cout << "Exiting program.\n";
            break;
        }

        cout << "  Operations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert after given node\n";
        cout << "4. Delete node\n";
        cout << "5. Search node\n";
        cout << "6. Display list\n";
        cout << "7. Back to List Type Selection\n";

        cout << "Enter your operation choice: ";
        cin >> opt;

        int val, posVal;

        switch (choiceL) {
            case 1: // Doubly Linked List
                switch (opt) {
                    case 1:
                        cout << "Enter value to insert at beginning: ";
                        cin >> val;
                        dll.insertB(val);
                        break;
                    case 2:
                        cout << "Enter value to insert at end: ";
                        cin >> val;
                        dll.insertE(val);
                        break;
                    case 3:
                        cout << "Enter the node value after which to insert: ";
                        cin >> posVal;
                        cout << "Enter value to insert: ";
                        cin >> val;
                        dll.insertAfterP(posVal, val);
                        break;
                    case 4:
                        cout << "Enter value of node to delete: ";
                        cin >> val;
                        dll.deletion(val);
                        break;
                    case 5:
                        cout << "Enter value to search: ";
                        cin >> val;
                        dll.search(val);
                        break;
                    case 6:
                        dll.display();
                        break;
                    case 7:
                        // Go back to list selection
                        break;
                    default:
                        cout << "Invalid.\n";
                }
                break;

            case 2: // Circularly Linked List
                switch (opt) {
                    case 1:
                        cout << "Enter value to insert at beginning: ";
                        cin >> val;
                        cll.insertBeginning(val);
                        break;
                    case 2:
                        cout << "Enter value to insert at end: ";
                        cin >> val;
                        cll.insertEnd(val);
                        break;
                    case 3:
                        cout << "Enter the node value after which to insert: ";
                        cin >> posVal;
                        cout << "Enter value to insert: ";
                        cin >> val;
                        cll.insertAfter(posVal, val);
                        break;
                    case 4:
                        cout << "Enter value of node to delete: ";
                        cin >> val;
                        cll.deletion(val);
                        break;
                    case 5:
                        cout << "Enter value to search: ";
                        cin >> val;
                        cll.search(val);
                        break;
                    case 6:
                        cll.display();
                        break;
                    case 7:
                        // Go back to list selection
                        break;
                    default:
                        cout << "Invalid.\n";
                }
                break;

            default:
                cout << "Invalid.\n";
        }
    }
    return 0;
}
