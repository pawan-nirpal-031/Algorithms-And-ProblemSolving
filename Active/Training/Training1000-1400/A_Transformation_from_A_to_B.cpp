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
 

bool isposs(int curr,int b){
  if(curr>b) return 0;
  if(curr==b) return 1;
  bool t1 = isposs(curr*2,b);
  bool t2 = isposs(curr*10+1,b);
  return t1 or t2;
}



int main(){
  FastIO;
  int a,b; 
  cin>>a>>b; 
  cout<<isposs(1,b);
  return 0;
} 
// If Solved Mark (0/1) here => []