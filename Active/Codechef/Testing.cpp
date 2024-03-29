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
#define Status(b) (cout<<(b?"POSITIVE\n":"NEGATIVE\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

int GreatestOneSmallerThan(ll a[],int n,ll x){
    if(a[0]>x) return -1;
    if(a[n-1]<=x) return n-1;
    int low = 0;
    int high = n-1;
    while(high>low+1){
        int mid = ((low+high)>>1);
        if(a[mid]<=x) low = mid;
        else high = mid;
    }
    return (a[high]<=x?high:low);
}

void Thewave(){
    int n,q;
    cin>>n>>q;
    ll a[n];
    for(ll &x : a) cin>>x;
    sort(a,a+n);
    while(q--){
        ll x;
        cin>>x;
        int greatest = GreatestOneSmallerThan(a,n,x);
        int plus = greatest+1;
        int minus = n-1-greatest;
        if(greatest>-1 and a[greatest]==x){
            cout<<"O\n";
            continue;
        }
        Status(minus%2==0);
    }
}
 
int main(){
    FastIO;
    Thewave();
    return 0;
}