// Problem Link : https://codeforces.com/problemset/problem/1499/B
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

You are given a string s, consisting only of characters '0' or '1'. Let |s| be the length of s.

You are asked to choose some integer k (k>0) and find a sequence a of length k such that:

1≤a1<a2<⋯<ak≤|s|;
ai−1+1<ai for all i from 2 to k.
The characters at positions a1,a2,…,ak are removed, the remaining characters are concatenated without changing the order. So, in other words, the positions in the sequence a should not be adjacent.

Let the resulting string be s′. s′ is called sorted if for all i from 2 to |s′| s′i−1≤s′i.

Does there exist such a sequence a that the resulting string s′ is sorted?

*/

void Solve(){
    string s;
    cin>>s;
    int n = s.length();
    vector<int>prefix(n,0),suffix(n,0);
    bool yes =1;
    for(int i = 1;i<n;i++) if(s[i]-'0' and s[i-1]-'0') yes = 0;
    for(int i = n-2;i>=0;i--) if(s[i]=='0' and s[i+1]=='0') yes = 0;
    Status(yes);
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      Solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => [0]