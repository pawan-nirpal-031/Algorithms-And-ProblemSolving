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

You are a coach of a group consisting of n students. The i-th student has programming skill ai. All students have distinct programming skills. You want to divide them into teams in such a way that:

No two students i and j such that |ai−aj|=1 belong to the same team (i.e. skills of each pair of students in the same team have the difference strictly greater than 1);
the number of teams is the minimum possible.
You have to answer q independent queries.

Input
The first line of the input contains one integer q (1≤q≤100) — the number of queries. Then q queries follow.

The first line of the query contains one integer n (1≤n≤100) — the number of students in the query. The second line of the query contains n integers a1,a2,…,an (1≤ai≤100, all ai are distinct), where ai is the programming skill of the i-th student.

Output
For each query, print the answer on it — the minimum number of teams you can form if no two students i and j such that |ai−aj|=1 may belong to the same team (i.e. skills of each pair of students in the same team has the difference strictly greater than 1)

*/


/*
Author's solution : 



*/


void solve(){
    int n;
    cin>>n;
    vector<bool>cache(101,0);
    int t =0;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        cache[x]=1;
    }
    for(int i =2;i<=100;i++) if(cache[i] and cache[i-1]) t = 1;
    cout<<t+1<<'\n';
}

int main(){
  FastIO;
  int q;
  cin>>q;
  while(q--){
      solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]