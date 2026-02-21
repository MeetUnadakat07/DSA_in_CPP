#include<iostream>
#include<string>
using namespace std;

string getSmallestString(int n, int k) {
    string ans(n, 'a');
    k -= n;

     int i = n - 1;
     while(k > 0) {
        int add = min(k, 25);
        ans[i] += add;
        k -= add;
        i--;
     }
     return ans;
}

int main() {
    int n = 3;
    int k = 27;
    string ans = getSmallestString(n, k);
    cout << "The smallest string of " << n << " size and having sum " << k << " is " << ans << endl;
}