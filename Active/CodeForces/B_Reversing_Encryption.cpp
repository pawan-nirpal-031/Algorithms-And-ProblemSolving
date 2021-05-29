// Problem Link : https://codeforces.com/contest/999/problem/B
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

A string s of length n can be encrypted by the following algorithm:

iterate over all divisors of n in decreasing order (i.e. from n to 1),
for each divisor d, reverse the substring s[1…d] (i.e. the substring which starts at position 1 and ends at position d).
For example, the above algorithm applied to the string s="codeforces" leads to the following changes: "codeforces" → "secrofedoc" → "orcesfedoc" → "rocesfedoc" → "rocesfedoc" (obviously, the last reverse operation doesn't change the string because d=1).

You are given the encrypted string t. Your task is to decrypt this string, i.e., to find a string s such that the above algorithm results in string t. It can be proven that this string s always exists and is unique.

*/

int main(){
  FastIO;
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<int>divs;
  for(int i =1;i<=n;i++) if(n%i==0) divs.push_back(i);
  for(int d : divs){
    reverse(s.begin(),s.begin()+d);
  }
  cout<<s<<endl;
  return 0;
} 
// If Solved Mark (0/1) here => [1]