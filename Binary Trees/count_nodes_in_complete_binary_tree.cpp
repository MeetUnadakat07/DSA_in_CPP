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

int countLeftNodes(Node *root) {
    int h = 0;
    while(root != NULL) {
        h++;
        root = root -> left;
    }
    return h;
}

int countRightNodes(Node *root) {
    int h = 0;
    while(root != NULL) {
        h++;
        root = root -> right;
    }
    return h;
}

int countNodes(Node *root) {
    if(root == NULL) return 0;

    int leftHeight = countLeftNodes(root);
    int rightHeight = countRightNodes(root);
    if(leftHeight == rightHeight) {
        return (1 << leftHeight) - 1;
    }
    return 1 + countNodes(root -> left) + countNodes(root -> right);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, -1};
    Node *root = createTree(nodes);
    int count = countNodes(root);
    cout << "The number of nodes in the tree is: " << count << endl;
}