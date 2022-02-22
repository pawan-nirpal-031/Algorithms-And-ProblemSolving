#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;



string decryptPassword(string s) {
    stack<char>digits;
    int n = s.length();
    string ans = "";
    for(int i=0;i<n;i++){
        if(s[i]>='1' and s[i]<='9'){
            digits.push(s[i]);
            s[i] = '#';
        }else if(s[i]=='0' and(not digits.empty())){
            char c = digits.top();
            s[i] = c;
            digits.pop();
        }else if(s[i]>='A' and s[i]<='Z'){
            if(i+1<n){
                if(s[i+1]>='a' and s[i+1]<='z' and i+2<n and s[i+2]=='*') swap(s[i],s[i+1]);
                i+=1;
            }
        }
    }
    for(char c : s) if(c!='#' and c!='*' and c!='0') ans+=c;
    if(!digits.empty()){
        while (!digits.empty()){
            ans+=digits.top();
            digits.pop();
        }
    }
    return ans; 
}

int main() {
    
    return 0;
}
