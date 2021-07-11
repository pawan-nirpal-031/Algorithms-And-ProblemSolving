// Problem Link : https://codeforces.com/problemset/problem/1272/C
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

Recently, Norge found a string s=s1s2…sn consisting of n lowercase Latin letters. As an exercise to improve his typing speed, he decided to type all substrings of the string s. Yes, all n(n+1)2 of them!

A substring of s is a non-empty string x=s[a…b]=sasa+1…sb (1≤a≤b≤n). For example, "auto" and "ton" are substrings of "automaton".

Shortly after the start of the exercise, Norge realized that his keyboard was broken, namely, he could use only k Latin letters c1,c2,…,ck out of 26.

After that, Norge became interested in how many substrings of the string s he could still type using his broken keyboard. Help him to find this number.

Input
The first line contains two space-separated integers n and k (1≤n≤2⋅105, 1≤k≤26) — the length of the string s and the number of Latin letters still available on the keyboard.

The second line contains the string s consisting of exactly n lowercase Latin letters.

The third line contains k space-separated distinct lowercase Latin letters c1,c2,…,ck — the letters still available on the keyboard.

Output
Print a single number — the number of substrings of s that can be typed using only available letters c1,c2,…,ck.


*/


/*
Author's solution : 



*/

ll GetLen(int i,ll prev){
    ll len = i-1-prev;
    return ((len*(len+1))>>1);
}

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  vector<bool>can_type(26,0);
  string word;
  cin>>word;
  for(int i =0;i<k;i++){
      char c;
      cin>>c;
      can_type[c-'a'] =1;
  }
  ll ans =0;
  int prev = -1;
  for(int i =0;i<n;i++){
    if(can_type[word[i]-'a']) continue;
    ans+=GetLen(i,prev);
    prev = i;
  }
  ans+=GetLen(n,prev);
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => [1]