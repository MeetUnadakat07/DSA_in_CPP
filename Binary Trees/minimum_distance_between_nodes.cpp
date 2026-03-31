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

Node *LCA(Node *root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }

    if(root -> data == n1 || root -> data == n2) {
        return root;
    }

    Node *leftLCA = LCA(root -> left, n1, n2);
    Node *rightLCA = LCA(root -> right, n1, n2);

    if(leftLCA && rightLCA) {
        return root;
    }
    
    return leftLCA ? leftLCA : rightLCA;
}

int dist(Node *root, int n) {
    if(root == NULL) return -1;

    if(root -> data == n) return 0;

    int leftDist = dist(root -> left, n);
    if(leftDist != -1) return leftDist + 1;

    int rightDist = dist(root -> right, n);
    if(rightDist != -1) return rightDist + 1;

    return -1;
}

int minDist(Node *root, int n1, int n2) {
    Node *lca = LCA(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}

int main() {
    // vector<int> nodes = {1, 2, -1, 4, -1, 5, -1, 6, -1, -1, 3, -1, -1};
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    int ans = minDist(root, 4, 6);
    cout << "The minimum distance is: " << ans << endl;
}