#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<pair<int, int>> jobs) {
    sort(jobs.begin(), jobs.end(), [] (pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    });
    int profit = jobs[0].second;
    int safeDeadline = 2;

    for(int i = 1; i < jobs.size(); i++) {
        if(jobs[i].first >= safeDeadline) {
            profit += jobs[i].second;
            safeDeadline++;
        }
    }
    return profit;
}

int main() {
    vector<pair<int, int>> jobs;
    jobs.push_back({4, 20});
    jobs.push_back({1, 10});
    jobs.push_back({1, 40});
    jobs.push_back({1, 30});

    int profit = maxProfit(jobs);
    cout << "The maximum profit that can be earned from the jobs sequencing is: " << profit << endl;
}