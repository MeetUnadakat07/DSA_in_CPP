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

bool search(Node *root, int target) {
    if(root == NULL) return false;

    if(root -> data == target) return true;

    if(target < root -> data) {
        return search(root -> left, target);
    } else {
        return search(root -> right, target);
    }
}

int main() {
    // vector<int> nums = {5, 1, 3, 4, 2, 7};
    vector<int> nums = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBST(nums);
    inorder(root);
    cout << endl;

    int target = 4;
    if(search(root, target)) {
        cout << "The node " << target << " is found in the bst";
    } else {
        cout << "The node " << target << " is not found in the bst";
    }
}