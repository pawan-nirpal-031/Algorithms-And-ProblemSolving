// Problem Link : https://codeforces.com/contest/1203/problem/A
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

There are n students standing in a circle in some order. The index of the i-th student is pi. It is guaranteed that all indices of students are distinct integers from 1 to n (i. e. they form a permutation).

Students want to start a round dance. A clockwise round dance can be started if the student 2 comes right after the student 1 in clockwise order (there are no students between them), the student 3 comes right after the student 2 in clockwise order, and so on, and the student n comes right after the student n−1 in clockwise order. A counterclockwise round dance is almost the same thing — the only difference is that the student i should be right after the student i−1 in counterclockwise order (this condition should be met for every i from 2 to n).

For example, if the indices of students listed in clockwise order are [2,3,4,5,1], then they can start a clockwise round dance. If the students have indices [3,2,1,4] in clockwise order, then they can start a counterclockwise round dance.

Your task is to determine whether it is possible to start a round dance. Note that the students cannot change their positions before starting the dance; they cannot swap or leave the circle, and no other student can enter the circle.

You have to answer q independent queries.

Input
The first line of the input contains one integer q (1≤q≤200) — the number of queries. Then q queries follow.

The first line of the query contains one integer n (1≤n≤200) — the number of students.

The second line of the query contains a permutation of indices p1,p2,…,pn (1≤pi≤n), where pi is the index of the i-th student (in clockwise order). It is guaranteed that all pi are distinct integers from 1 to n (i. e. they form a permutation).


*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []