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

// Node *findIntersection(Node *head1, Node *head2) {
//     vector<Node*> intersection;
//     Node *temp = head1;
//     while(temp != NULL) {
//         intersection.push_back(temp);
//         temp = temp -> next;
//     }
//     temp = head2;
//     while(temp != NULL) {
//         if(find(intersection.begin(), intersection.end(), temp) != intersection.end()) {
//             return temp;
//         }
//         temp = temp -> next;
//     }
//     return NULL;
// }

// Node *findIntersection(Node *head1, Node *head2) {
//     int size1 = 0;
//     int size2 = 0;
//     Node *temp1 = head1;
//     Node *temp2 = head2;
//     while(temp1 != NULL) {
//         size1++;
//         temp1 = temp1->next;
//     }
//     while(temp2 != NULL) {
//         size2++;
//         temp2 = temp2->next;
//     }
//     temp1 = head1;
//     temp2 = head2;
//     if(size1 > size2) {
//         for(int i = 0; i < (size1 - size2); i++) {
//             temp1 = temp1->next;
//         }
//     } else {
//         for(int i = 0; i < (size2 - size1); i++) {
//             temp2 = temp2 -> next;
//         }
//     }
//     while(temp1 != NULL && temp2 != NULL) {
//         if(temp1 == temp2) {
//             return temp1;
//         }
//         temp1 = temp1 -> next;
//         temp2 = temp2 -> next;
//     }
//     return NULL;
// }

Node *findIntersection(Node *head1, Node *head2) {
    Node *temp1 = head1;
    Node *temp2 = head2;

    while(temp1 != temp2) {
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;

        if(temp1 == temp2) return temp1;

        if(temp1 == NULL) temp1 = head2;
        if(temp2 == NULL) temp2 = head1;
    }
    return temp1;
}

int main() {
    List ll1;
    ll1.push_back(1);
    ll1.push_back(2);
    ll1.push_back(3);
    ll1.push_back(6);
    Node *connNode = ll1.tail;
    ll1.push_back(7);

    List ll2;
    ll2.push_back(4);
    ll2.push_back(5);
    ll2.tail -> next = connNode;

    printList(ll1.head);
    printList(ll2.head);

    Node *ans = findIntersection(ll1.head, ll2.head);
    if(ans) {
        cout << "The intersection of two lists is at " << ans->data << endl;
    } else {
        cout << "The lists are not connected." << endl;
    }
}