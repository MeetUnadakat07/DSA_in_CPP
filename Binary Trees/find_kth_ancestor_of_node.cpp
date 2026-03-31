#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;

Node* createTree(vector<int> &preorder) {
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = createTree(preorder);
    root->right = createTree(preorder);

    return root;
}

// Helper function
int solve(Node* root, int k, int node, int &ans) {
    if(root == NULL) return -1;

    if(root->data == node) return 0;

    int left = solve(root->left, k, node, ans);
    int right = solve(root->right, k, node, ans);

    if(left == -1 && right == -1) return -1;

    int dist = (left != -1) ? left : right;

    // When we reach kth ancestor
    if(dist + 1 == k) {
        ans = root->data;
    }

    return dist + 1;
}

int kthAncestor(Node *root, int k, int node) {
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    int result = kthAncestor(root, 1, 5);
    cout << "The kth ancestor is: " << result << endl;

    return 0;
}