// Problem Link : https://codeforces.com/contest/1003/problem/B
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

You are given three integers a, b and x. Your task is to construct a binary string s of length n=a+b such that there are exactly a zeroes, exactly b ones and exactly x indices i (where 1≤i<n) such that si≠si+1. It is guaranteed that the answer always exists.

For example, for the string "01010" there are four indices i such that 1≤i<n and si≠si+1 (i=1,2,3,4). For the string "111001" there are two such indices i (i=3,5).

Recall that binary string is a non-empty sequence of characters where each character is either 0 or 1.


This problem has several general cases:

x is even and a>b, then the answer is 01 repeated x2 times, then b−x2 ones and a−x2 zeroes;
x is even and a≤b, then the answer is 10 repeated x2 times, then a−x2 zeroes and b−x2 ones;
x is odd and a>b, then the answer is 01 repeated ⌊x2⌋ times, then a−⌊x2⌋ zeroes and b−⌊x2⌋ ones;
x is odd and a≤b, then the answer is 10 repeated ⌊x2⌋ times, then b−⌊x2⌋ ones and a−⌊x2⌋ zeroes.
I am sure that there are other more beautiful solution, but for me the easiest way to solve this problem is to extract general cases and handle it.

*/

int main(){
  FastIO;
  int z,o,x;
  cin>>z>>o>>x;
  int n = o+z;
  bool c = (o>z?1:0);
  for(int i = 1;i<=n;i++){
    if(i<=x){
      cout<<c;
      if(c==0 and z>0) z-=1;
      if(c==1 and o>0) o-=1;
      c^=1;
    }else{
      if(o>0){
        cout<<1;
        o-=1;
      }else if(z>0){
        cout<<0;
        z-=1;
      }
    }
  }
  return 0;
} 
// If Solved Mark (0/1) here => []
