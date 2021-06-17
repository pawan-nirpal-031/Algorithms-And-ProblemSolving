// Problem Link : https://codeforces.com/problemset/problem/1538/C
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
#define Triplet(a,b,c) pair<ll,pair<ll,ll>>
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 

You are given an array a of n integers. Find the number of pairs (i,j) (1≤i<j≤n) where the sum of ai+aj is greater than or equal to l and less than or equal to r (that is, l≤ai+aj≤r).

For example, if n=3, a=[5,1,2], l=4 and r=7, then two pairs are suitable:

i=1 and j=2 (4≤5+1≤7);
i=1 and j=3 (4≤5+2≤7).
Input
The first line contains an integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains three integers n,l,r (1≤n≤2⋅105, 1≤l≤r≤109) — the length of the array and the limits on the sum in the pair.

The second line contains n integers a1,a2,…,an (1≤ai≤109).

It is guaranteed that the sum of n overall test cases does not exceed 2⋅105.

*/



int LowerIndx(ll a[],ll e,ll n){
    int low = -1;
    int high = n;
    while(high-low>1){
        ll mid = ((low+high)>>1);
        if(a[mid]>=e) high = mid;
        else low = mid;
    }
    return low+1;
}

int HigherIndx(ll a[],ll e,ll n){
    int low = -1;
    int high = n;
    while(high-low>1){
        ll mid = ((low+high)>>1);
        if(a[mid]<=e) low = mid;
        else high = mid;
    }
    return high;
}

void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    ll a[n];
    ll ans = 0;
    for(ll &x : a) cin>>x;
    sort(a,a+n);
    for(int i =0;i<n;i++){
      int low = LowerIndx(a,l-a[i],n);
      int up = HigherIndx(a,r-a[i],n);
      if(low>-1 and up>low) ans+=(up-low);
      if(2*a[i]>=l and 2*a[i]<=r) ans-=1;
    }
    cout<<(ans/2)<<'\n';
}



int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []