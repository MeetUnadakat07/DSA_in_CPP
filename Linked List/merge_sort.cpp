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

Node *splitAtMid(Node *head) {
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while(fast != NULL && fast -> next != NULL) {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if(prev != NULL) {
        prev -> next = NULL;
    }
    return slow;
}

Node *merge(Node *left, Node *right) {
    // Allocate on heap so destructor does NOT run when function exits
    List* ans = new List();

    while(left != NULL && right != NULL) {
        if(left->data <= right->data) {
            ans->push_back(left->data);
            left = left->next;
        } else {
            ans->push_back(right->data);
            right = right->next;
        }
    }

    while(left != NULL) {
        ans->push_back(left->data);
        left = left->next;
    }

    while(right != NULL) {
        ans->push_back(right->data);
        right = right->next;
    }
    // Return head of new list; don't delete ans!
    return ans->head;
}

Node *mergeSort(Node *head) {
    if(head == NULL || head -> next == NULL) return head;
    Node *rightHead = splitAtMid(head);

    Node *left = mergeSort(head);        // left half
    Node *right = mergeSort(rightHead);   // right half

    return merge(left, right);
}

int main() {
    List ll;
    ll.push_back(3);
    ll.push_back(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(2);
    printList(ll.head);
    ll.head = mergeSort(ll.head);
    printList(ll.head);
}