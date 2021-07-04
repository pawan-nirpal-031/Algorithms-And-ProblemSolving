// Problem Link : https://codeforces.com/contest/1006/problem/B
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

Polycarp is practicing his problem solving skill. He has a list of n problems with difficulties a1,a2,…,an, respectively. His plan is to practice for exactly k days. Each day he has to solve at least one problem from his list. Polycarp solves the problems in the order they are given in his list, he cannot skip any problem from his list. He has to solve all n problems in exactly k days.

Thus, each day Polycarp solves a contiguous sequence of (consecutive) problems from the start of the list. He can't skip problems or solve them multiple times. As a result, in k days he will solve all the n problems.

The profit of the j-th day of Polycarp's practice is the maximum among all the difficulties of problems Polycarp solves during the j-th day (i.e. if he solves problems with indices from l to r during a day, then the profit of the day is maxl≤i≤rai). The total profit of his practice is the sum of the profits over all k days of his practice.

You want to help Polycarp to get the maximum possible total profit over all valid ways to solve problems. Your task is to distribute all n problems between k days satisfying the conditions above in such a way, that the total profit is maximum.

For example, if n=8,k=3 and a=[5,4,2,6,5,1,9,2], one of the possible distributions with maximum total profit is: [5,4,2],[6,5],[1,9,2]. Here the total profit equals 5+6+9=20.


*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  int cost = 0;
  vector<pair<int,int>>seq(n+1,{0,0});// (number,index)
  for(int i = 1;i<=n;i++){
    int x;
    cin>>x;
    seq[i].first = x;
    seq[i].second = i;
  }
  sort(seq.begin(),seq.end());
  vector<int>indx;
  for(int i = n;i>=1;i--){
    if(k==0) break;
    if(seq[i].first==0) continue;
    cost+=seq[i].first;
    indx.push_back(seq[i].second);
    k-=1;
  }
  cout<<cost<<'\n';
  sort(indx.begin(),indx.end());
  vector<int>sqs(indx.size(),0);
  for(int i = 0;i<indx.size();i++){
    if(i==0) sqs[i] = indx[i];
    else{
      sqs[i] = indx[i] - indx[i-1];
    }
  }
  sqs[indx.size()-1]+=(n-indx[indx.size()-1]);
  for(int x : sqs) cout<<x<<' ';
  return 0;

} 
// If Solved Mark (0/1) here => [1]