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
  int n;
  cin>>n;
  int a[n];
  int sum =0;
  for(int &x : a){
      cin>>x;
      sum+=x;
  }
  int s1,s2;
  cin>>s1>>s2;
  if(s1>s2) swap(s1,s2);
  int its = s2-s1;
  int p = s1-1;
  int one =0;
  for(int i =0;i<its;i++){
       one+=a[p];
       p = (p+1)%n;
  }
  cout<<min(one,sum-one);
  return 0;
} 
// If Solved Mark (0/1) here => []