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

void preorder(Node *root) {
    if(root == NULL) return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node *root) {
    if(root == NULL) return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void postorder(Node *root) {
    if(root == NULL) return;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

void levelOrderTraversal(Node *root) {
    if(root == NULL) return;
    
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();

        if(curr == NULL) {
            cout << endl;
            if(q.empty()) {
                break;
            }
            q.push(NULL);
        } else {
            cout << curr -> data << " ";
            if(curr -> left != NULL) {
                q.push(curr -> left);
            }
            if(curr -> right != NULL) {
                q.push(curr -> right);
            }
        }
    }
    cout << endl;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);
    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);
}