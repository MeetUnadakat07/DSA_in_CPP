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

void preorder(Node *root) {
    if(root == NULL) return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

Node *buildBSTFromSorted(vector<int> &nums, int st, int end) {
    if(st > end) return NULL;

    int mid = st + (end - st) / 2;
    Node *curr = new Node(nums[mid]);

    curr -> left = buildBSTFromSorted(nums, st, mid - 1);
    curr -> right = buildBSTFromSorted(nums, mid + 1, end);

    return curr;
}

int main() {
    // vector<int> nums = {5, 1, 3, 4, 2, 7};
    vector<int> nums = {3, 4, 5, 6, 7, 8, 9};
    Node *root = buildBSTFromSorted(nums, 0, nums.size() - 1);
    preorder(root);
}