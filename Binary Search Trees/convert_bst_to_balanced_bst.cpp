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

void getInorder(Node *root, vector<int> &inSeq) {
    if(root == NULL) return;

    getInorder(root -> left, inSeq);
    inSeq.push_back(root -> data);
    getInorder(root -> right, inSeq);
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

Node *balanceBST(Node *root) {
    vector<int> nodes;
    getInorder(root, nodes);
    return buildBSTFromSorted(nodes, 0, nodes.size() - 1);
}

int main() {
    vector<int> nums = {6, 5, 4, 3, 7, 8, 9};
    Node *root = buildBST(nums);

    cout << "Initial tree preorder: ";
    preorder(root);
    cout << endl;
    
    root = balanceBST(root);
    cout << "Final preorder of tree: ";
    preorder(root);
    cout << endl;
}