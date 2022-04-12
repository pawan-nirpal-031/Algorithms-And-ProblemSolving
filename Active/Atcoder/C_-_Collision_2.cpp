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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 



*/


/*
Author's solution : 



*/





int main(){
  FastIO;
  int n;
  cin>>n;
  vector<pair<int,int>>data(n,{0,0});
  for(int i =0;i<n;i++) cin>>data[i].first>>data[i].second;
  string moves;
  cin>>moves;
  unordered_map<int,int>right_movers,left_movers;
  for(int i =0;i<n;i++){
      if(moves[i]=='L'){
          auto it = left_movers.find(data[i].second);
          if(it==left_movers.end()) left_movers[data[i].second] = data[i].first;
          else left_movers[data[i].second] = max(left_movers[data[i].second],data[i].first);
      }
      else{
          auto it = right_movers.find(data[i].second);
          if(it==right_movers.end()) right_movers[data[i].second] = data[i].first;
          else right_movers[data[i].second] = min(right_movers[data[i].second],data[i].first);
      }
  }
  bool yes =0;
  for(int i=0;i<n;i++){
      auto left = left_movers.find(data[i].second);
      auto right = right_movers.find(data[i].second);
      if(left!=left_movers.end() and right!=right_movers.end() and (left->second>=right->second)){
          yes =1;
          break;
      }
  }
  Status(yes);
  return 0;
} 
// If Solved Mark (0/1) here => []