#include<iostream>
#include<vector>
#include <climits>
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

bool helper(Node *root, int min, int max) {
    if(root == NULL) return true;

    if(min > root -> data || max < root -> data) {
        return false;
    }

    return  helper(root -> left, min, root -> data) &&
            helper(root -> right, root -> data, max);
}

bool isValid(Node *root) {
    return helper(root, INT_MIN, INT_MAX);
}

int main() {
    // vector<int> nums = {5, 1, 3, 4, 2, 7};
    vector<int> nums = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBST(nums);

    Node *root2 = new Node(3);
    root2 -> left = new Node(2);
    root2 -> right = new Node(5);
    root2 -> left -> left = new Node(1);
    root2 -> left -> right = new Node(4);
    if(isValid(root2)) {
        cout << "The tree is a valid BST" << endl;
    } else {
        cout << "The tree is not a valid BST" << endl;
    }
}