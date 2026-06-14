#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

vector<int> bottomView(Node *root) {
    vector<int> ans;

    if(root == NULL) return ans;

    map<int, int> m;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while(!q.empty()) {
        auto p = q.front();
        Node *node = p.first;
        int hd = p.second;
        q.pop();

        m[hd] = node -> data;

        if(node -> left) {
            q.push({node -> left, hd - 1});
        }

        if(node -> right) {
            q.push({node -> right, hd + 1});
        }
    }

    for(auto &p : m) {
        ans.push_back(p.second);
    }
    
    return ans;
}

int main() {
    Node *root = new Node(20);
    root -> left = new Node(8);
    root -> right = new Node(22);

    root -> left -> left = new Node(5);
    root -> left -> right = new Node(3);
    root -> right -> right = new Node(25);

    root -> left -> right -> left = new Node(10);
    root -> left -> right -> right = new Node(14);

    vector<int> ans = bottomView(root);
    for(int ele : ans) {
        cout << ele << " ";
    } 
    cout << endl;
}