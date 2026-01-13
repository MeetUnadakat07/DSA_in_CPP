#include<iostream>
using namespace std;

void removeDuplicates(string str, string ans, int i, int map[]) {
    if(i == str.size()) {
        cout << ans << endl;
        return;
    }
    int mapIdx = (int) (str[i] - 'a');

    if(map[mapIdx]) {
        removeDuplicates(str, ans, i + 1, map);
    } else {
        map[mapIdx] = true;
        ans += str[i];
        removeDuplicates(str, ans, i + 1, map);
    }
}

int main() {
    string str = "appnnacollege";
    string ans = "";
    int map[26] = {false};

    removeDuplicates(str, ans, 0, map);
}