// Problem Link : https://codeforces.com/contest/999/problem/E
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

There are n cities and m roads in Berland. Each road connects a pair of cities. The roads in Berland are one-way.

What is the minimum number of new roads that need to be built to make all the cities reachable from the capital?

New roads will also be one-way.

Input
The first line of input consists of three integers n, m and s (1≤n≤5000,0≤m≤5000,1≤s≤n) — the number of cities, the number of roads and the index of the capital. Cities are indexed from 1 to n.

The following m lines contain roads: road i is given as a pair of cities ui, vi (1≤ui,vi≤n, ui≠vi). For each pair of cities (u,v), there can be at most one road from u to v. Roads in opposite directions between a pair of cities are allowed (i.e. from u to v and from v to u).

Output
Print one integer — the minimum number of extra roads needed to make all the cities reachable from city s. If all the cities are already reachable from s, print 0.

*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []