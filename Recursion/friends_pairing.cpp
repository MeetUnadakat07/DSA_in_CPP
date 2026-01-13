#include<iostream>
using namespace std;

int friendsPairing(int n) {
    if(n == 1 || n == 2) {
        return n;
    }

    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main() {
    int n;
    cout << "How many friends are there in the party: ";
    cin >> n;
    int ans = friendsPairing(n);
    cout << "The number of ways to pair is: " << ans << endl;
}