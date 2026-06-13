#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> gropuAnagrams(vector<string> strs) {
    map<string, vector<string>> m;

    for(auto str : strs) {
        string s = str;
        sort(str.begin(), str.end());
        m[str].push_back(s);
    }

    vector<vector<string>> ans;
    for(pair<string, vector<string>> p : m) {
        ans.push_back(p.second);
    }
    return ans;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = gropuAnagrams(strs);
    cout << "The grouped anagrams are: " << endl;
    for(int i = 0; i < ans.size(); i++) {
        for(string s : ans[i]) {
            cout << s << " ";
        }
        cout << endl;
    }
}