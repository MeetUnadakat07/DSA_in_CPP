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

    void push_back(int data) {
        Node *newNode = new Node(data);

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

// Node* mergeKSortedLists(vector<Node *> &lists) {
//     vector<int> nums;

//     // 1. Collect all dataues
//     for (int i = 0; i < lists.size(); i++) {
//         Node *temp = lists[i];
//         while (temp != NULL) {
//             nums.push_back(temp->data);
//             temp = temp->next;
//         }
//     }

//     // 2. Sort
//     sort(nums.begin(), nums.end());

//     // 3. Convert vector -> linked list
//     Node *head = NULL;
//     Node *tail = NULL;

//     for (int i = 0; i < nums.size(); i++) {
//         Node *newNode = new Node(nums[i]);

//         if (head == NULL) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     return head;
// }

Node* mergeTwoLists(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) return head1 == NULL ? head2 : head1;

    if(head1 -> data <= head2 -> data) {
        head1 -> next = mergeTwoLists(head1 -> next, head2);
        return head1;
    } else {
        head2 -> next = mergeTwoLists(head1, head2 -> next);
        return head2;
    }
}

// Node* mergeKSortedLists(vector<Node *> &lists) {
//     if (lists.size() == 0) return NULL;
//     Node *head = lists[0];

//     for(int i = 1; i < lists.size(); i++) {
//         head = mergeTwoLists(head, lists[i]);
//     }
//     return head;
// }

Node* mergeKListsHelper(vector<Node*>& lists, int left, int right) {
    if (left > right) return NULL;
    if (left == right) return lists[left];

    int mid = left + (right - left) / 2;

    Node* l1 = mergeKListsHelper(lists, left, mid);
    Node* l2 = mergeKListsHelper(lists, mid + 1, right);

    return mergeTwoLists(l1, l2);
}

Node* mergeKSortedLists(vector<Node*>& lists) {
    if (lists.size() == 0) return NULL;
    return mergeKListsHelper(lists, 0, lists.size() - 1);
}

int main() {
    List ll1;
    ll1.push_back(2);
    ll1.push_back(4);
    ll1.push_back(6);

    List ll2;
    ll2.push_back(1);
    ll2.push_back(5);

    List ll3;
    ll3.push_back(1);
    ll3.push_back(1);
    ll3.push_back(3);
    ll3.push_back(7);
    
    List ll4;
    ll4.push_back(8);
    
    vector<Node *> lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);
    lists.push_back(ll4.head);
    
    for (int i = 0; i < lists.size(); i++) {
        cout << "List " << i + 1 << ": ";
        printList(lists[i]);
    }
    cout << endl;

    Node *mergedHead = mergeKSortedLists(lists);
    cout << "The merged list is: ";
    printList(mergedHead);
}