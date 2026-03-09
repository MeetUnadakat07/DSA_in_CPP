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

bool isIdentical(Node *root1, Node *root2) {
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;

    if(root1 -> data != root2 -> data) return false;

    return isIdentical(root1 -> left, root2 -> left) && isIdentical(root1 -> right, root2 -> right);
}

bool isSubtree(Node *root, Node *subroot) {
    if(root == NULL) return false;
    if(subroot == NULL) return true;

    if(root->data == subroot->data) {
        if(isIdentical(root, subroot)) {
            return true;
        }
    }

    return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);
    Node *subroot = new Node(2);
    subroot -> left = new Node(4);
    subroot -> right = new Node(5);

    if(isSubtree(root, subroot)) {
        cout << "The given subroot forms a valid subtree." << endl;
    } else {
        cout << "The given subroot does not form a valid subtree." << endl;
    }
}