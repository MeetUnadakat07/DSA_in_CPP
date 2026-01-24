#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList {
public:
    Node *head;
    Node *tail;

    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node *newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
    
    void pop_front() {
        if(head == NULL) {
            cout << "The list is already empty. Cannot pop." << endl;
            return;
        }
        Node *temp = head -> next;
        cout << "Removing " << head -> data << " from the list." << endl;
        if(temp != NULL) {
            temp -> prev = NULL;
        }
        head -> next = NULL;
        delete head;
        head = temp;
    }

    void push_back(int val) {
        Node *newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        }
        Node *temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
        newNode -> prev = temp;
        tail = newNode;
    }
    
    void pop_back() {
        if(head == NULL) {
            cout << "The list is already empty. Cannot pop." << endl;
        }
        Node *temp = head;
        while(temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        Node *toDel = temp -> next;
        cout << "Removing " << toDel -> data << " from the list." << endl;
        toDel -> prev = NULL;
        temp -> next = NULL;
        delete toDel;
        tail = temp;
    }
    
    void printList() {
        if(head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        Node *temp = head;
        while(temp != NULL) {
            cout << temp -> data << " <=> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList dbl;
    dbl.push_front(4);
    dbl.push_front(3);
    dbl.push_front(2);
    dbl.push_front(1);
    dbl.printList();
    dbl.pop_front();
    dbl.pop_front();
    dbl.printList();
    dbl.push_back(5);
    dbl.push_back(6);
    dbl.printList();
    dbl.pop_back();
    dbl.printList();
}