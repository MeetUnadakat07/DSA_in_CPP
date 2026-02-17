#include<bits/stdc++.h>
using namespace std;

// int timeRequiredToBuy(vector<int> &tickets, int k) {
//     queue<pair<int, int>> q;
//     int n = tickets.size();

//     for(int i = 0; i < n; i++) {
//         q.push(make_pair(tickets[i], i));
//     }

//     int time = 0;
//     while(!q.empty()) {
//         pair<int,int> front = q.front();
//         q.pop();

//         int num_tickets = front.first;
//         int og_i = front.second;

//         time++;
//         num_tickets--;

//         if(og_i == k && num_tickets == 0)
//             return time;

//         if(num_tickets > 0)
//             q.push(make_pair(num_tickets, og_i));
//     }

//     return time;
// }

int timeRequiredToBuy(vector<int> tickets, int k) {
    int count = 0;
    int i = 0;

    while(tickets[k] != 0) {
        if(tickets[i] != 0) {
            tickets[i]--;
            count++;
        }
        i++;

        if(i == tickets.size()) i = 0;
    }
    return count;
}

int main() {
    vector<int> tickets = {2,3,2};
    int k = 2;
    int ans = timeRequiredToBuy(tickets, k);
    cout << "The time required to buy the ticket is: " << ans << endl;
}