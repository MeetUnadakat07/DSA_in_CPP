#include<iostream>
#include<vector>
#include<queue>
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

static int idx = -1;

Node *createTree(vector<int> &preorder) {
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node *currNode = new Node(preorder[idx]);
    currNode -> left = createTree(preorder);        // left subtree
    currNode -> right = createTree(preorder);       // right subtree

    return currNode;
}

bool rootToNodePath(Node *root, int n, vector<int> &path) {
    if(root == NULL) {
        return false;
    }

    path.push_back(root -> data);
    if(root -> data == n) {
        return true;
    }

    int isLeft = rootToNodePath(root -> left, n, path);
    int isRight = rootToNodePath(root -> right, n, path);

    if(isLeft || isRight) {
        return true;
    }
    path.pop_back();
    return false;
}

int lowestCommonAncestor(Node *root, int n1, int n2) {
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for(int i = 0, j = 0; i < path1.size(), j < path2.size(); i++, j++) {
        if(path1[i] != path2[j]) {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

Node *lowestCommonAncestor2(Node *root, int n1, int n2) {
    if(root == NULL) {
        return NULL;
    }

    if(root -> data == n1 || root -> data == n2) {
        return root;
    }

    Node *leftLCA = lowestCommonAncestor2(root -> left, n1, n2);
    Node *rightLCA = lowestCommonAncestor2(root -> right, n1, n2);

    if(leftLCA && rightLCA) {
        return root;
    }
    
    return leftLCA ? leftLCA : rightLCA;
}

int main() {
    // vector<int> nodes = {1, 2, -1, 4, -1, 5, -1, 6, -1, -1, 3, -1, -1};
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);
    // int ans = lowestCommonAncestor(root, 4, 6);
    // cout << "The lowest common ancestor is: " << ans << endl;

    Node *res = lowestCommonAncestor2(root, 4, 6);
    cout << "The lowest common ancestor is: " << res -> data << endl;
}