#include<iostream>
#include<string>
using namespace std;

string largestOddNumber(string num) {
    for(int i = num.size() - 1; i >= 0; i--) {
        int n = num[i] - '0';
        if(n % 2) return num;
        num.pop_back();
    }
    return "";
}

int main() {
    // string num = "52";
    string num = "35427";
    string largestOdd = largestOddNumber(num);
    cout << "the maximum odd number that be formed is: " << largestOdd << endl;
}