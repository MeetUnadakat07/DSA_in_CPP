#include<iostream>
using namespace std;

void binaryString(int n, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    if(ans[ans.size() - 1] != '1') {
        binaryString(n - 1, ans + '0');
        binaryString(n - 1, ans + '1');
    } else {
        binaryString(n - 1, ans + '0');
    }
}

int main() {
    string ans = "";
    binaryString(3, ans);
}