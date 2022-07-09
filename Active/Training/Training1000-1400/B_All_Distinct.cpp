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



*/


/*
Author's solution : 



*/





int main(){
  FastIO;
  int t; 
  cin>>t;
  while(t--){
      int n;
      cin>>n; 
      vector<int>fr(10005,0); 
      int mx = 0;
      for(int i =0;i<n;i++){
          int x;
          cin>>x; 
          fr[x]+=1;
          mx = max(x,mx);
      }
      vector<int>nums;
      for(int i=1;i<=mx;i++){
          if(fr[i]&1) nums.push_back(i);
          else{
              nums.push_back(i); 
              nums.push_back(i); 
          }
      }
      int rm =0; 
      for(int i =0;i<nums.size();i++){
          if(i%3==0){
              if(nums[i]==nums[i-1] or nums[i-2]==nums[i-1]) rm+=2;
          }
      }
      cout<<nums.size()-rm<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []