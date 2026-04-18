#include<iostream>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
using namespace std;

int main() {
    // unordered_map<string, int> m;
    map<string, int> m;
    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;

    // cout << m["India"] << endl;
    for(pair<string, int> country: m) {
        cout << country.first << ": " << country.second << endl;
    }

    m.erase("Nepal");

    if(m.count("Nepal")) {
        cout << "Nepal exists in the map." << endl;
    } else {
        cout << "Nepal does not exist in the map." << endl;
    }

    // unordered_set<int> s;
    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);
    cout << s.size() << endl;

    s.erase(3);
    if(s.find(3) != s.end()) {
        cout << "3 exists in the set." << endl;
    } else {
        cout << "3 does not exist in the set." << endl;
    }

    for(auto el : s) {
        cout << el << ", ";
    }
    cout << endl;
}