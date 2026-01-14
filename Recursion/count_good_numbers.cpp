#include<iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long a, long long b) {
    if(b == 0) return 1;
    long long half = power(a, b / 2);
    long long result = (half * half) % MOD;
    if(b & 1) {
        result = (result * a) % MOD;
    }
    return result;
}

int countGoodNumbers(long long n) {
    long long oddPos = n / 2;
    long long evenPos = (n + 1) / 2;
    return (power(5, evenPos) * power(4, oddPos)) % MOD;
}

int main() {
    int n;
    cout << "How many digit numbers you want to search for: ";
    cin >> n;
    long long ans = countGoodNumbers(n);
    cout << "We will have " << ans << " good numbers of " << n << " digits." << endl;
}