#include<iostream>
#include<stack>
using namespace std;

string decodeString(string str) {
    stack<string> s;
    stack<int> nums;
    string curr = "";
    int num = 0;
    for(char ch : str) {
        if(isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } else if(ch == '[') {
            nums.push(num);
            s.push(curr);
            num = 0;
            curr = "";
        } else if(ch == ']') {
            int k = nums.top();
            nums.pop();

            string prev = s.top();
            s.pop();

            string temp = "";
            while(k--) {
                temp += curr;
            }
            curr = prev + temp;
        } else {
            curr += ch;
        }
    }
    return curr;
}

int main() {
    string str = "3[a]2[bc]";
    // string str = "2[abc]3[cd]ef";
    // string str = "2[a3[c2[x]]y]";
    string decodedString = decodeString(str);
    cout << "The decoded string is: " << decodedString << endl;
}