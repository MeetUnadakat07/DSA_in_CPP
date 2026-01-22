#include<iostream>
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
    Node *head;
    Node *tail;
    
public: 
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        Node *curr = head;
        while (curr != NULL) {
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = tail = NULL;
    }

    void push_back(int val) {
        Node *newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node *temp = head;
        while(temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }

    void removeNth(int n) {
        Node *fast = head;

        // First reach till the nth position from the start 
        for(int i = 0; i < n; i++) {
            fast = fast -> next;
        }

        // If we are trying to remove the element with n == size (head) 
        if(fast == NULL) {
            Node *temp = head -> next;
            delete head;
            head = temp;
            return;
        }

        // Then the slow pointer wll start to move and move until the fast one will reach the end and hence there are n elements between both
        Node *slow = head;
        while(fast -> next != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }

        // The slow pointer has reached at n - 1 position from the end so remove the nth element 
        Node *temp = slow -> next;
        slow -> next = temp -> next;
        delete temp;
    }
};

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();
    ll.removeNth(2);
    ll.printList();
}