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

void printInRange(Node *root, int st, int end) {
    if(root == NULL) return;

    if(st <= root -> data && root -> data <= end) {
        printInRange(root -> left, st, end);
        cout << root -> data << " ";
        printInRange(root -> right, st, end);
    } else if(root -> data < st) {
        printInRange(root -> right, st, end);
    } else {
        printInRange(root -> left, st, end);
    }
}

int main() {
    // vector<int> nums = {5, 1, 3, 4, 2, 7};
    vector<int> nums = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBST(nums);

    printInRange(root, 5, 12);
    cout << endl;
}