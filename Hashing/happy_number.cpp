#include<bits/stdc++.h>
using namespace std;

// unordered_set<int> s;
// bool isHappy(int n) {
//     if(n == 1) return true;

//     int num = 0;
//     while(n > 0) {
//         int rem = n % 10;
//         n /= 10;
//         num += (rem * rem);
//     }
//     if(s.find(num) != s.end()) {
//         return false;
//     } else {
//         s.insert(num);
//         return isHappy(num);
//     }
// }

int nextNumber(int num) {
    int sum = 0;
    while(num > 0) {
        int rem = num % 10;
        num /= 10;
        sum += (rem * rem);
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;

    do {
        slow = nextNumber(slow);
        fast = nextNumber(nextNumber(fast));
    } while(slow != fast);

    return slow == 1;
}

int main() {
    int n = 7;
    if(isHappy(n)) {
        cout << n << " is a happy number." << endl;
    } else {
        cout << n << " is not a happy number." << endl;
    }
}