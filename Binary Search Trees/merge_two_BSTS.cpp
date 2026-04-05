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

void getInorder(Node *root, vector<int> &inSeq) {
    if(root == NULL) return;

    getInorder(root -> left, inSeq);
    inSeq.push_back(root -> data);
    getInorder(root -> right, inSeq);
}

Node *mergeBSTs(Node *root1, Node *root2) {
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i = 0, j = 0;
    while(i < nodes1.size() && j < nodes2.size()) {
        if(nodes1[i] < nodes2[j]) {
            merged.push_back(nodes1[i++]);
        } else {
            merged.push_back(nodes2[j++]);
        }
    }
    while(i < nodes1.size()) {
        merged.push_back(nodes1[i++]);
    }
    while(j < nodes2.size()) {
        merged.push_back(nodes2[j++]);
    }

    return buildBSTFromSorted(merged, 0, merged.size() - 1);
}

int main() {
    Node *root1 = new Node(2);
    root1 -> left = new Node(1);
    root1 -> right = new Node(4);
    
    Node *root2 = new Node(9);
    root2 -> left = new Node(3);
    root2 -> right = new Node(12);

    Node *root = mergeBSTs(root1, root2);
    preorder(root);
    cout << endl;
}