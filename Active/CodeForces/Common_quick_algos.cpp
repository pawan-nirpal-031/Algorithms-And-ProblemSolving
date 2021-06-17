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



int LowerIndx(ll a[],ll e,ll n){
    if(a[n-1]<e) return -1;
    if(a[0]>=e) return 0;
    int low = 0;
    int high = n-1;
    while(high-low>1){
        ll mid = ((low+high)>>1);
        if(a[mid]>=e) high = mid;
        else low = mid;
    }
    return (a[high]>=e?high:-1);
}

int HigherIndx(ll a[],ll e,ll n){
    if(a[0]>e) return -1;
    if(a[n-1]<=e) return n-1;
    int low = 0;
    int high = n-1;
    while(high-low>1){
        ll mid = ((low+high)>>1);
        if(a[mid]<=e) low = mid;
        else high = mid;
    }
    return (a[low]<=e?low:-1);
}

int main(){
  FastIO;
  
  return 0;
} 
