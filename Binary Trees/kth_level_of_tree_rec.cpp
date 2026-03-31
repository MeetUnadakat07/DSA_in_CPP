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

void kthHelper(Node *root, int k, int currLevel) {
    if(root == NULL) return;

    if(currLevel == k) {
        cout << root -> data << " ";
        return;
    }
    
    kthHelper(root -> left, k, currLevel + 1);
    kthHelper(root -> right, k, currLevel + 1);
}

void printKthLevel(Node *root, int k) {
    kthHelper(root, k, 1);
    cout << endl;
}

int main() {
    // vector<int> nodes = {1, 2, -1, 4, -1, 5, -1, 6, -1, -1, 3, -1, -1};
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);
    printKthLevel(root, 3);
}