#include<iostream>
#include<vector>
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

Node *insert(Node *root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root -> data) {
        root -> left = insert(root -> left, val);
    } else {
        root -> right = insert(root -> right, val);
    }

    return root;
}

Node *buildBST(vector<int> nums) {
    int n = nums.size();
    Node *root = NULL;

    for(int i = 0; i < n; i++) {
        root = insert(root, nums[i]);
    }

    return root;
}

void inorder(Node *root) {
    if(root == NULL) return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

Node *getInorderSuccessor(Node *root) {
    while(root -> left != NULL) {
        root = root -> left;
    }
    return root;
}

Node *deleteNode(Node *root, int target) {
    if(root == NULL) return NULL;

    // To reach at the node to be deleted 
    if(target < root -> data) {
        root -> left = deleteNode(root -> left, target);
    } else if(target > root -> data) {
        root -> right = deleteNode(root -> right, target);
    } else {
        // If the node is a leaf node 
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        // If the node has only one child 
        if(root -> left == NULL) {
            delete root;
            return root -> right;
        } else if(root -> right == NULL) {
            delete root;
            return root -> left;
        }

        // The node has 2 children 
        Node *inorderSuccessor = getInorderSuccessor(root -> right);
        root -> data = inorderSuccessor -> data;
        root -> right = deleteNode(root -> right, inorderSuccessor -> data);
        return root;
    }
    return root;
}

int main() {
    // vector<int> nums = {5, 1, 3, 4, 2, 7};
    vector<int> nums = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBST(nums);
    inorder(root);
    cout << endl;

    deleteNode(root, 8);
    inorder(root);
    cout << endl;
}