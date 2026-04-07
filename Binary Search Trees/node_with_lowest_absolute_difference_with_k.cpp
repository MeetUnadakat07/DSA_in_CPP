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

void helper(Node *root, int k, int &minDiff, int &minDiffKey) {
    if(root == NULL) return;

    if(root -> data == k) {
        minDiffKey = root -> data;
        minDiff = 0;
        return;
    }

    if(minDiff > abs(root -> data - k)) {
        minDiff = abs(root -> data - k);
        minDiffKey = root -> data;
    }

    if(k < root -> data) {
        helper(root -> left, k, minDiff, minDiffKey);
    } else {
        helper(root -> right, k, minDiff, minDiffKey);
    }
}

int minAbsDiff(Node *root, int k) {
    int minDiff = INT_MAX;
    int minDiffKey = root -> data;
    helper(root, k, minDiff, minDiffKey);
    return minDiffKey;
}

int main() {
    // vector<int> nums = {5, 1, 3, 4, 2, 7};
    vector<int> nums = {8, 5, 11, 3, 6, 20};
    Node *root = buildBST(nums);
    inorder(root);
    cout << endl;
    cout << "The node with minimum absolute difference is " << minAbsDiff(root, 5) << endl;
}