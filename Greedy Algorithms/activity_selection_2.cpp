#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;   // sort by end time
}

int maxActivities(vector<pair<int,int>> activities) {
    int count = 1;
    int currEnd = activities[0].second;

    cout << "A0 is selected\n";

    for(int i = 1; i < activities.size(); i++) {
        if(activities[i].first >= currEnd) {
            count++;
            currEnd = activities[i].second;
            cout << "A" << i << " is selected\n";
        }
    }

    return count;
}

int main() {

    vector<pair<int,int>> activities = {
        {0,9},
        {1,2},
        {2,4}
    };

    sort(activities.begin(), activities.end(), compare);

    int max = maxActivities(activities);

    cout << "Maximum activities: " << max << endl;
}
