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

    ~Node() {
        // cout << "Node destructor for element " << data << endl;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
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
        if(head != NULL) {
            // cout << "List destructor is called" << endl;
            delete head;
            head = NULL;
        }
    }

    void push_front(int val) {
        // Node *newNode(val);      // This is a static method to allocate the memory which cannot be used outside the push_front function
        Node *newNode = new Node(val);          // We use new as this will give dynamic allocation which can be used outside the push_front function also 

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode -> next = head;
            head = newNode;
        }
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

    void insert(int val, int position) {   // 0-based indexing
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Index out of bound." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if(head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << temp -> data << " is popped out from the list." << endl;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

    void pop_back() {
        if(head == NULL) {
            cout << "The list is already empty." << endl;
            return;
        }
        Node *temp = head;
        while(temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = NULL;
        cout << tail -> data << " is popped out from the list." << endl;
        delete tail;
        tail = temp;
    }

    void printList() {
        Node *temp = head;
        while(temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }

    int searchIter(int ele) {
        int idx = 0;
        Node *temp = head;
        while(temp != NULL) {
            if(temp -> data == ele) {
                return idx;
            } else {
                temp = temp -> next;
                idx++;
            }
        }
        return -1;
    }

    int helper(Node *head, int key) {
        if(head -> data == key) {
            return 0;
        }
        if(head == NULL) {
            return -1;
        }

        int idx = helper(head -> next, key);
        if(idx == -1) return -1;

        return idx + 1;
    }

    int searchRec(int key) {
        helper(head, key);          // head is a private member of list so main cannot access it
    }

    void reverse() {
        Node *prev = NULL;
        Node *curr = head;

        tail = head;
        while(curr != NULL) {
            Node *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main() {
    List ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();
    ll.insert(100, 2);
    ll.printList();
    
    // ll.pop_front();
    // ll.pop_front();
    // ll.pop_back();
    // ll.printList();
    
    int idx = ll.searchIter(3);
    cout << " Element found on index " << idx << endl;
    
    int idx2 = ll.searchRec(3);
    cout << " Element found on index " << idx2 << endl;
    
    ll.reverse();
    ll.printList();
}