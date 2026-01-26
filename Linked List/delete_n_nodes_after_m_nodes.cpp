#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
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

    ~List() = default;

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

Node* linkdelete(Node* head, int m, int n) {
    // code here
    if(head == NULL) return head;
    if(m == 0) return NULL;
    
    Node *curr = head;
    while(curr != NULL) {
        for(int i = 1; i < m && curr != NULL; i++) {
            curr = curr -> next;
        }
        if(curr == NULL) break;
        
        Node *temp = curr -> next;
        for(int i = 0; i < n && temp != NULL; i++) {
            Node *del = temp;
            temp = temp -> next;
            delete del;
        }
        curr -> next = temp;
        curr = temp;
    }
    return head;
}

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.push_back(10);
    printList(ll.head);
    linkdelete(ll.head, 3, 2);
    printList(ll.head);
}