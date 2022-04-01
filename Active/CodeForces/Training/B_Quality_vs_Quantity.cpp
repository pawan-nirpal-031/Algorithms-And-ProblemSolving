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


int GreatestPrefixSmallerThanSuffix(vector<ll>&prefix,int high,ll suffix){
    if(high<0) return -1;
    int low = 0;
    while(low+1<high){
        int m = (low+high)/2;
        if(prefix[m]<suffix) low = m;
        else high = m;
    }
    if(prefix[high]<suffix) return high;
    if(prefix[low]<suffix) return low;
    return -1;
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      ll a[n];
      vector<ll>prefix(n,0);
      for(int i=0;i<n;i++){
          cin>>a[i];
      }
      sort(a,a+n);
      for(int i =0;i<n;i++) prefix[i]=(i>0?prefix[i-1]:0)+a[i];
      ll suffix_sum =0;
      bool yes = 0;
      for(int i = n-1;i>=0;i--){
          suffix_sum+=a[i];
          int idx = GreatestPrefixSmallerThanSuffix(prefix,i-1,suffix_sum);
          if(idx>-1 and ((n-i)<(idx+1))) yes = 1;
      }
      Status(yes);
  }
  return 0;
} 
// If Solved Mark (0/1) here => []