// Problem Link : 
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 



*/


/*
Author's solution : 



*/

string ans = "0";

bool Palindrome(string s,int start,int end){
  int l = end-start+1;
  int f = start + (l>>1);
  int temp = start+end;
  for(int i = start;i<f;i++) if(s[i]!=s[temp-i]) return 0;
  return 1;
}

set<string>test;
void MaxPalindrome(string s,int indx,vector<string>&vs){
    if(indx==s.length()){
        for(string x : vs) test.insert(x);
        return;
    }
    for(int i = indx;i<s.length();i++){
        if(Palindrome(s,indx,i)){
            vs.push_back(s.substr(indx,i-indx+1));
            MaxPalindrome(s,i+1,vs);
            vs.pop_back();
        }
    }
}

int main(){
  FastIO;
  string s;
  cin>>s;
  string soln;
  vector<string>pq;
  MaxPalindrome(s,0,pq);
  
  return 0;
} 
// If Solved Mark (0/1) here => []