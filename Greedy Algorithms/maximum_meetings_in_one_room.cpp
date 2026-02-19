#include<iostream>
#include<vector>
#include<algorithm>
#include <tuple>
using namespace std;

vector<int> maxMeetings(vector<int> start, vector<int> end) {
    int n = start.size();

    vector<tuple<int, int, int>> meetings;

    for(int i = 0; i < n; i++) {
        meetings.push_back(make_tuple(end[i], start[i], i + 1));
    }

    sort(meetings.begin(), meetings.end());

    vector<int> ans;
    int currEnd = -1;

    for(int i = 0; i < n; i++) {
        int e = get<0>(meetings[i]);
        int st = get<1>(meetings[i]);
        int idx = get<2>(meetings[i]);

        if(st > currEnd) {
            ans.push_back(idx);
            currEnd = e;
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> start = {0, 1, 2};
    vector<int> end = {9, 2, 4};

    cout << "The meetings will be scheduled in the order: " << endl;
    vector<int> ans = maxMeetings(start, end);
    for(int ele : ans) {
        cout << "Meeting " << ele << endl;
    }
}