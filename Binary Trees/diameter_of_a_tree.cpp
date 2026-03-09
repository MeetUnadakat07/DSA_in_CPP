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

int countLeftNodes(Node *root) {
    int h = 0;
    while(root != NULL) {
        h++;
        root = root -> left;
    }
    return h;
}

int countRightNodes(Node *root) {
    int h = 0;
    while(root != NULL) {
        h++;
        root = root -> right;
    }
    return h;
}

int height(Node *root) {
    if(root == NULL) return 0;

    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    return 1 + max(leftHeight, rightHeight);
}

int diameter(Node *root) {
    if(root == NULL) return 0;

    int currDiameter = height(root -> left) + height(root -> right) + 1;
    int leftDiameter = diameter(root -> left);
    int rightDiameter = diameter(root -> right);
    return max(currDiameter, max(leftDiameter, rightDiameter));
}

// Diameter, height
pair<int, int> diameter2(Node *root) {
    if(root == NULL) return make_pair(0, 0);

    pair<int, int> leftInfo = diameter2(root -> left);      // ld, lh
    pair<int, int> rightInfo = diameter2(root -> right);    // rd, rh

    int currDiameter = leftInfo.second + rightInfo.second + 1;
    int finalDiameter = max(currDiameter, max(leftInfo.first, rightInfo.first));
    int finalHeight = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiameter, finalHeight);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);
    int d = diameter2(root).first;
    cout << "The diameter of the tree is: " << d << endl;
}