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

vector<ll>spaces;

int main(){
  FastIO;
  for(int i = 1;i<=9;i++) for(ll j = i;j<=(1e9);j=10*j+i) spaces.push_back(j);
  sort(spaces.begin(),spaces.end());
  int t;
  cin>>t;
  while(t--){
      ll x;
      cin>>x;
      int low = 0;
      int high = spaces.size();
      while(low+1<high){
          int m = (low+high)/2;
          if(spaces[m]<=x) low  = m;
          else high = m;
      }
      cout<<(x<=spaces[high]?high:low+1)<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []