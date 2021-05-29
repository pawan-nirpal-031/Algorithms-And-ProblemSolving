// Problem Link : https://codeforces.com/contest/999/problem/D
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

You are given an array consisting of n integers a1,a2,…,an, and a positive integer m. It is guaranteed that m is a divisor of n.

In a single move, you can choose any position i between 1 and n and increase ai by 1.

Let's calculate cr (0≤r≤m−1) — the number of elements having remainder r when divided by m. In other words, for each remainder, let's find the number of corresponding elements in a with that remainder.

Your task is to change the array in such a way that c0=c1=⋯=cm−1=nm.

Find the minimum number of moves to satisfy the above requirement.

*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []