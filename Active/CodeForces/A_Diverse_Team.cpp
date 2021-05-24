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

There are n students in a school class, the rating of the i-th student on Codehorses is ai. You have to form a team consisting of k students (1≤k≤n) such that the ratings of all team members are distinct.

If it is impossible to form a suitable team, print "NO" (without quotes). Otherwise print "YES", and then print k distinct numbers which should be the indices of students in the team you form. If there are multiple answers, print any of them.

*/

int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  vector<int>index(103,0);
  set<int>cache;
  for(int i = 1;i<=n;i++){
      int x;
      cin>>x;
      if(cache.size()<k) cache.insert(x);
      index[x] = i;
  }
  if(cache.size()<k){
      Status(0);
      return 0;
  }
  Status(1);
  int r = 0;
  for(int e : cache){
      cout<<index[e]<<' ';
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]