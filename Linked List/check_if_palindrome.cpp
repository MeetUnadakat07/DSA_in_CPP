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
    Node *head;

public:
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

    void printList() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node *reverseCopy() {
        Node *curr = head;
        Node *newHead = NULL;

        while(curr != NULL) {
            Node *newNode = new Node(curr -> data);
            newNode -> next = newHead;
            newHead = newNode;
            curr = curr -> next;
        }

        return newHead;
    }

    bool checkPalindrome(Node *head2) {
        Node *temp = head;
        while(temp != NULL && head2 != NULL) {
            if(temp -> data != head2 -> data) {
                return false;
            }
            temp = temp -> next;
            head2 = head2 -> next;
        }
        return true;
    }
};

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(1);
    ll.printList();
    Node *head2 = ll.reverseCopy();
    if(ll.checkPalindrome(head2)) {
        cout << "The list is palindrome." << endl;
    } else {
        cout << "The list is not palindrome" << endl;
    }
}