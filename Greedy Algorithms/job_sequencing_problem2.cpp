#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this -> idx = idx;
        this -> deadline = deadline;
        this -> profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs) {
    int n = pairs.size();
    vector<Job> jobs;

    for(int i = 0; i < n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    });
    cout << "Selecting job " << jobs[0].idx << endl;
    int profit = jobs[0].profit;
    int safeDeadline = 2;

    for(int i = 1; i < n; i++) {
        if(jobs[i].deadline > safeDeadline) {
            cout << "Selecting job " << jobs[i].idx << endl;
            safeDeadline++;
            profit += jobs[i].profit;
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