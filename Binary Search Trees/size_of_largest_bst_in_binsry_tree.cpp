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

class Info {
public:
    bool isBST;
    int min;
    int max;
    int size;

    Info(bool isBST, int min, int max, int size) {
        this -> isBST = isBST;
        this -> min = min;
        this -> max = max;
        this -> size = size;
    }
};

static int maxSize = 0;

Info *largestBST(Node *root) {
    // if(root == NULL) return NULL;
    // if(root -> left == NULL && root -> right == NULL) {
    //     return new Info(true, root -> data, root -> data, 1);
    // }

    if(root == NULL) {
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    Info *leftInfo = largestBST(root -> left);
    Info *rightInfo = largestBST(root -> right);

    int currMin = min(root -> data, min(leftInfo -> min, rightInfo -> min));
    int currMax = max(root -> data, max(leftInfo -> max, rightInfo -> max));
    int currSize = leftInfo -> size + rightInfo -> size + 1;

    if(leftInfo -> isBST && rightInfo -> isBST 
        && root -> data > leftInfo -> max 
        && root -> data < rightInfo -> min) {
        maxSize = max(maxSize, currSize);
        return new Info(true, currMin, currMax, currSize);
    }
    
    return new Info(false, currMin, currMax, currSize);
}

int main() {
    // vector<int> nums = {5, 1, 3, 4, 2, 7};
    Node *root = new Node(50);
    root -> left = new Node(30);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(20);

    root -> right = new Node(60);
    root -> right -> left = new Node(45);
    root -> right -> right = new Node(70);
    root -> right -> right -> left = new Node(65);
    root -> right -> right -> right = new Node(80);

    largestBST(root);
    cout << "The maximum size of BST in Binary Tree is: " << maxSize << endl;
}