#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> stockSpan(vector<int> &stock, int n) {
    stack<int> s;
    vector<int> span(n, 0);
    s.push(0);
    span[0] = 1;

    for(int i = 1; i < stock.size(); i++) {
        int currPrice = stock[i];
        while(!s.empty() && stock[s.top()] <= currPrice) {
            s.pop();
        }
        if(s.empty()) {
            span[i] = i + 1;
        } else {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
        s.push(i);
    }
    return span;
}

int main() {
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    // vector<int> stock = {100, 70, 60, 50};
    vector<int> span = stockSpan(stock, stock.size());
    cout << "The span for the stock is: ";
    for(int ele : span) {
        cout << ele << " ";
    }
    cout << endl;
}