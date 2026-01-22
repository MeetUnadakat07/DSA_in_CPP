#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }

    ~Node() = default;
};

class List {
public:
    
    Node *head;
    List() {
        head = NULL;
    }

    ~List() {
        Node *curr = head;
        while (curr != NULL) {
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = NULL;
    }

    void push_back(int val) {
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool isCycle(Node *head) {
    Node *fast = head;
    Node *slow = head;

    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast == slow) {
            return true;
        }
    }
    return false;
}

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(1);
    printList(ll.head);
    if(isCycle(ll.head)) {
        cout << "The linked list is cyclic." << endl;
    } else {
        cout << "The linked list is not cyclic." << endl;
    }
}