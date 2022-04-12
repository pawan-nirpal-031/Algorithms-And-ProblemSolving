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



string GetBinString(ll s){
    stack<int>process;
    while(s){
        process.push(s%2);
        s/=2;
    }
    string ans;
    while(not process.empty()){
        ans+=(process.top()?'1':'0');
        process.pop();
    }
    return ans;
}


ull Decode(string s){
    ull ans = 0;
    int n = s.length();
    for(int i = n-1;i>=0;i--){
        if(s[i]=='0') continue;
        int pos = n-1-i;
        ans+=(unsigned long long)(1<<pos);
    }
    return ans;
}


int main(){
  FastIO;
  ull n,s;
  cin>>n>>s;
  ull curr = s;
  string cache = GetBinString(s);
  string moves;
  cin>>moves;
  for(char c : moves){
      if(c=='U') cache.pop_back();
      else if(c=='L') cache.push_back('0');
      else cache.push_back('1');
  }
  ull ans = Decode(cache);
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => []