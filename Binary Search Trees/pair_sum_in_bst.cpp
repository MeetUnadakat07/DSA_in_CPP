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

void inorder(Node *root, vector<int> &a) {
    if(root == NULL) return;

    inorder(root -> left, a);
    a.push_back(root -> data);
    inorder(root -> right, a);
}

void helper(Node *root1, Node *root2, int target, vector<pair<int, int>> &ans) {
    vector<int> a, b;
    inorder(root1, a);
    inorder(root2, b);

    int i = 0, j = b.size() - 1;

    while(i < a.size() && j >= 0) {
        int sum = a[i] + b[j];
        
        if(sum == target) {
            ans.push_back({a[i],b[j]});
            i++;
            j--;
        } else if(sum < target) {
            i++;
        } else {
            j--;
        }
    }
    return;
}

vector<pair<int, int>> findPairs(Node *root1, Node *root2, int target) {
    vector<pair<int, int>> ans;
    helper(root1, root2, target, ans);
    return ans;
}

int main() {
    vector<int> nums1 = {5, 3, 2, 4, 7, 6, 8};
    Node *root1 = buildBST(nums1);
    vector<int> nums2 = {10, 6, 15, 3, 8, 11, 18};
    Node *root2 = buildBST(nums2);
    int target = 16;
    vector<pair<int, int>> ans = findPairs(root1, root2, target);
    for (auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}