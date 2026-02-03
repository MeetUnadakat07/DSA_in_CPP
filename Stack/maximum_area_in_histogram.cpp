#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxAreaHistogram(vector<int> &heights) {
    int n = heights.size();
    vector<int> nsl(n);             // to find the next smaller element to the left
    vector<int> nsr(n);             // to find the next smaller element to the right
    stack<int> s;

    // To calculate the next smaller left 
    nsl[0] = -1;
    s.push(0);
    for(int i = 1; i < n; i++) {
        int curr = heights[i];
        while(!s.empty() && heights[s.top()] >= curr) {
            s.pop();
        }
        if(s.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }
        s.push(i);
    }

    // empty the stack so that we can reuse it
    while(!s.empty()) s.pop();

    // To calculate the next smaller right 
    s.push(n - 1);
    nsr[n - 1] = n;
    for(int i = n - 2; i >= 0; i--) {
        int curr = heights[i];
        while(!s.empty() && heights[s.top()] >= curr) {
             s.pop();
        }
        if(s.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }
        s.push(i);
    }

    // To calculate the area 
    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int height = heights[i];
        int width = nsr[i] - nsl[i] - 1;
        int area = height * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = maxAreaHistogram(heights);
    cout << "The maximum area in the histogram can be: " << maxArea << endl;
}