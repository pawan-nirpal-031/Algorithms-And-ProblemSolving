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


ull CountPairs (ll arr[], int n){
    ll cnttwo = 0, more = 0;
    for (int i = 0; i<n; i++){
        if (arr[i] == 2) cnttwo++;
        else if (arr[i] > 2) more++;
    }
    ull ans = cnttwo*more +  (more*(more-1))/2;
    return ans;
}


ll solveopt(ll a[],int n){
    ull comp = CountPairs(a,n);
    ll v = ((n*(n-1))>>1);
    ull ans =  (v-comp);
    return ans;
}

ll solvebf(ll a[],int n){
  ll cnt =0;
  for(int i =0;i<n;i++){
    for(int j = i+1;j<n;j++){
      if(a[i]+a[j]>=a[i]*a[j]) cnt+=1;
    }
  }
  return cnt;
}
   

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll a[n];
    for(ll &x : a) cin>>x; 
    ll ans = solveopt(a,n);
    cout<<ans<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []