#include <bits/stdc++.h>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
    int num;
    char c;
    vector<int>ans;
    while(ss>>num){
        ans.push_back(num);
        ss>>c;
    }
    return ans;
}

int main() {
    stack<int>dig;
    s.push(1);
    s.push(2);
    cout<<s.top();
    return 0;
}