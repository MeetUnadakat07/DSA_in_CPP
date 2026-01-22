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
    Node *tail;

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
            head = tail = newNode;
            return;
        }

        tail -> next = newNode;
        tail = newNode;
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

void removeCycle(Node *head) {
    bool isCycle = false;
    Node *fast = head;
    Node *slow = head;

    // Cycle detection 
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast == slow) {
            isCycle = true;
            break;
        }
    }

    // If we did not find a cycle 
    if(!isCycle) {
        cout << "Cycle doesn't exist.\n";
        return;
    }

    slow = head;
    // Special case -> If the tail of the list is connected to the head (complete cycle)
    if(slow == fast) {
        while(fast -> next != slow) {
            fast = fast -> next;
        }
        fast -> next = NULL;
        cout << "The cycle has been removed." << endl;
    } else {                        // If any other type of cycle is present
        Node *prev = fast;
        while(slow != fast) {
            slow = slow -> next;
            prev = fast;
            fast = fast -> next;
        }
        prev -> next = NULL;
        cout << "Cycle has been removed." << endl;
    }
}

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.tail -> next = ll.head -> next;
    removeCycle(ll.head);
    printList(ll.head);
}