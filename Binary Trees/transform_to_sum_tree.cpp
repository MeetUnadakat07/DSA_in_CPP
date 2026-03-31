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
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;

Node* createTree(vector<int> &preorder) {
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = createTree(preorder);
    root->right = createTree(preorder);

    return root;
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

int transform(Node *root) {
    if(root == NULL) return 0;

    int leftOld = transform(root -> left);
    int rightOld = transform(root -> right);

    int currOld = root -> data;

    root -> data = leftOld + rightOld;

    if(root -> left) {
        root -> data += root -> left -> data;
    }
    if(root -> right) {
        root -> data += root -> right -> data;
    }

    return currOld;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);

    transform(root);
    levelOrderTraversal(root);

    return 0;
}