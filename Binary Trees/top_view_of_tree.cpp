#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topView(Node *root) {
    queue<pair<Node*, int>> Q;      // Node, horizontal dist
    map<int, int> m;                // Horizontal dist, Node -> data

    Q.push(make_pair(root, 0));
    while(!Q.empty()) {
        pair<Node *, int> curr = Q.front();
        Q.pop();

        Node *currNode = curr.first;
        int currHoriDist = curr.second;

        if(m.count(currHoriDist) == 0) {    // is not covered
            m[currHoriDist] = currNode -> data;
        }

        if(currNode -> left != NULL) {
            pair<Node *, int> left = make_pair(currNode -> left, currHoriDist - 1);
            Q.push(left);
        }

        if(currNode -> right != NULL) {
            pair<Node *, int> right = make_pair(currNode -> right, currHoriDist + 1);
            Q.push(right);
        }
    }

    for(auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    // vector<int> nodes = {1, 2, -1, 4, -1, 5, -1, 6, -1, -1, 3, -1, -1};
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = createTree(nodes);
    topView(root);
}