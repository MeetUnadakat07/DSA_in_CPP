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

Node* oddEvenLinkedLists(Node* head) {
    if (!head) return head;

    Node *evenHead = NULL, *evenTail = NULL;
    Node *oddHead = NULL, *oddTail = NULL;
    Node *curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {  // even
            if (!evenHead) {
                evenHead = evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {  // odd
            if (!oddHead) {
                oddHead = oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }

    if (evenTail) {
        evenTail->next = oddHead;
    }
    if (oddTail) {
        oddTail->next = NULL;
    }

    if(evenHead != NULL) {
        return evenHead;
    } else {
        return oddHead;
    }
}

int main() {
    List ll;
    ll.push_back(8);
    ll.push_back(12);
    ll.push_back(10);
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(1);
    ll.push_back(6);
    printList(ll.head);
    ll.head = oddEvenLinkedLists(ll.head);
    printList(ll.head);
}