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

 
struct Interval{
    ll s, e;
};
 
bool mycomp(Interval a, Interval b){
    return a.s < b.s; 
}
 
void mergeIntervals(Interval arr[], int n,ll f,ll k){
    sort(arr, arr+n, mycomp);
    int index = 0; 
    for (int i=1; i<n; i++){
        if (arr[index].e >=  arr[i].s){
            arr[index].e = max(arr[index].e, arr[i].e);
            arr[index].s = min(arr[index].s, arr[i].s);
        }
        else {
            index++;
            arr[index] = arr[i];
        }   
    }
    ll ans = 0;
    for (int i = 0; i <= index; i++){
        if(i==0) ans+=arr[i].s - 0;
        else ans+=arr[i].s-arr[i-1].e;
    }
    if(f>arr[index].e) ans+=(f-arr[index].e);
    Status(ans>=k);
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll k,f;
        cin>>n>>k>>f;
        Interval arr[n];
        for(int i =0;i<n;i++){
            ll sx,ex;
            cin>>sx>>ex;
            arr[i].s = sx;
            arr[i].e = ex;
        }
        mergeIntervals(arr,n,f,k);

    }
    return 0;
}