// Problem Link : https://codeforces.com/problemset/problem/115/A
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
A company has n employees numbered from 1 to n. Each employee either has no immediate manager or exactly one immediate manager, who is another employee with a different number. An employee A is said to be the superior of another employee B if at least one of the following is true:

Employee A is the immediate manager of employee B
Employee B has an immediate manager employee C such that employee A is the superior of employee C.
The company will not have a managerial cycle. That is, there will not exist an employee who is the superior of his/her own immediate manager.

Today the company is going to arrange a party. This involves dividing all n employees into several groups: every employee must belong to exactly one group. Furthermore, within any single group, there must not be two employees A and B such that A is the superior of B.

What is the minimum number of groups that must be formed?

*/

int GetMaxLvlUtil(int par[],vector<int>&max_lvl,int u){
    return (par[u]==-1?1:max_lvl[u] = 1 + GetMaxLvlUtil(par,max_lvl,par[u]));
}



int main(){
  FastIO;
  int n;
  cin>>n;
  int par[n]; // par[i] : immediadte  sup of i 
  for(int i =0;i<n;i++){
      cin>>par[i];
      if(par[i]!=-1) par[i]-=1;
  }
  vector<int>max_lvl(n,1);
  int ans =1;
  for(int i=0;i<max_lvl.size();i++){
        if(par[i]!=-1 and max_lvl[i]==1) max_lvl[i] = max(max_lvl[i],GetMaxLvlUtil(par,max_lvl,i));
        ans = max(ans,max_lvl[i]);
  }
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => [1]