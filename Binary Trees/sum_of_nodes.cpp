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

int sumOfNodes(Node *root) {
    if(root == NULL) return 0;

    int leftSum = sumOfNodes(root -> left);
    int rightSum = sumOfNodes(root -> right);
    return leftSum + rightSum + root -> data;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);
    int sum = sumOfNodes(root);
    cout << "The sum of the nodes of the tree is: " << sum << endl;
}