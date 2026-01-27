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

Node *swapNodes(Node *head, int ele1, int ele2) {
    if(head == NULL || ele1 == ele2) return head;

    Node *prev1 = NULL;
    Node *curr1 = head;
    while(curr1 != NULL && curr1 -> data != ele1) {
        prev1 = curr1;
        curr1 = curr1 -> next;
    }
    Node *prev2 = NULL;
    Node *curr2 = head;
    while(curr2 != NULL && curr2 -> data != ele2) {
        prev2 = curr2;
        curr2 = curr2 -> next;
    }
    if(curr1 == NULL || curr2 == NULL) return head;
    
    if(prev1 != NULL) {
        prev1 -> next = curr2;
    } else {
        head = curr2;
    }
    if(prev2 != NULL) {
        prev2 -> next = curr1;
    } else {
        head = curr1;
    }

    Node *temp = curr1 -> next;
    curr1 -> next = curr2 -> next;
    curr2 -> next = temp;

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
    printList(ll.head);
    ll.head = swapNodes(ll.head, 4, 2);
    printList(ll.head);
}