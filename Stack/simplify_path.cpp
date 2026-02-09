#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    vector<string> stack;
    string token;
    int n = path.size();

    for (int i = 0; i <= n; i++) {
        if (i == n || path[i] == '/') {
            if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (!token.empty() && token != ".") {
                stack.push_back(token);
            }
            token.clear();
        } else {
            token += path[i];
        }
    }

    string result = "/";
    for (int i = 0; i < stack.size(); i++) {
        result += stack[i];
        if (i + 1 < stack.size()) {
            result += "/";
        }
    }

    return result;
}

int main() {
    string path = "/home/user/Documents/../Pictures/";
    cout << "The simplified path is: " << simplifyPath(path) << endl;
}