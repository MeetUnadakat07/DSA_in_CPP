#include<iostream>
using namespace std;

int tilingProblemFor2(int n) {          // 2 * n
    if(n == 0 || n == 1) {
        return 1;
    }

    // Vertical 
    int ans1 = tilingProblemFor2(n - 1);    // 2 * (n - 1)
    
    // Horizontal 
    int ans2 = tilingProblemFor2(n - 2);    // 2 * (n - 2)

    return (ans1 + ans2);
}

int tilingProblemFor3(int n) {          // 3 * n
    if(n == 0 || n == 1 || n == 2) {
        return 1;
    }

    // Vertical 
    int ans1 = tilingProblemFor3(n - 1);    // 3 * (n - 1)
    
    // Horizontal 
    int ans2 = tilingProblemFor3(n - 3);    // 3 * (n - 3)

    return (ans1 + ans2);
}

int main() {
    int n;
    cout << "Enter the height you want: ";
    cin >> n;
    int ans1 = tilingProblemFor2(n);
    cout << "The number of ways in which we can use 2 * 1 tiles to fit 2 * " << n << " area is: " << ans1 << endl;
    int ans2 = tilingProblemFor3(n);
    cout << "The number of ways in which we can use 3 * 1 tiles to fit 3 * " << n << " area is: " << ans2 << endl;
}