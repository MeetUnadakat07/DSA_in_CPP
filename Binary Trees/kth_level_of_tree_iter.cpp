#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;

Node *createTree(vector<int> &preorder) {
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node *currNode = new Node(preorder[idx]);
    currNode -> left = createTree(preorder);        // left subtree
    currNode -> right = createTree(preorder);       // right subtree

    return currNode;
}

void printKthLevel(Node *root, int k) {
    if(root == NULL) return;

    int count = 1;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();

        if(curr == NULL) {
            count++;
            if(q.empty()) break;
            q.push(NULL);
        } else {
            if(count == k) {
                cout << curr -> data << " ";
            }
            if(curr -> left) {
                q.push(curr -> left);
            } 
            if(curr -> right) {
                q.push(curr -> right);
            }
        }
    }
    cout << endl;
}

int main() {
    // vector<int> nodes = {1, 2, -1, 4, -1, 5, -1, 6, -1, -1, 3, -1, -1};
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);
    printKthLevel(root, 3);
}