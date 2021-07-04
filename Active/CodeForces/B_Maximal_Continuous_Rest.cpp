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

Each day in Berland consists of n hours. Polycarp likes time management. That's why he has a fixed schedule for each day — it is a sequence a1,a2,…,an (each ai is either 0 or 1), where ai=0 if Polycarp works during the i-th hour of the day and ai=1 if Polycarp rests during the i-th hour of the day.

Days go one after another endlessly and Polycarp uses the same schedule for each day.

What is the maximal number of continuous hours during which Polycarp rests? It is guaranteed that there is at least one working hour in a day.


*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int n;
  cin>>n;
  vector<int>day(n,0);
  for(int i =0;i<n;i++) cin>>day[i];
  for(int i =1;i<n;i++) if(day[i-1] and day[i]) day[i]+=day[i-1];
  int ans = day[n-1];
  if(ans>0){
      for(int i =0;i<n;i++){
        if(day[i]==0) break;
        ans+=1;
      }
  }
  for(int i =0;i<n;i++) ans = max(ans,day[i]);
  cout<<'\n'<<min(n,ans);
  return 0;
} 
// If Solved Mark (0/1) here => [1]