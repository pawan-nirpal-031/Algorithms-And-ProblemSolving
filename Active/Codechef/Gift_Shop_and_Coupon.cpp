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
     int n,k;
     cin>>n>>k;
     vector<int>a(n,0);
     for(int &x : a) cin>>x;
     sort(a.begin(),a.end());
     ll total_cost = k;
     int count =0;
     for(int i =0;i<n;i++){
         if(total_cost>=a[i]){
             count+=1;
             total_cost-=a[i];
         }else{
             if(total_cost-ceil((a[i]*1.0)/2)>=0) count++;
             break;
         }
     }
     cout<<count<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []