#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} 
#define NofSetBits(x) __builtin_popcount(x);
#define InpGrph(g,e) while(e--){ll x;ll y;cin>>x>>y ;g[x].pub(y);g[y].pub(x);}
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       ll n,m;
       cin>>n>>m;
       ll hw,vw,s;
       cin>>hw>>vw>>s;
       ll prv =0;
       ll a1 =0,a2=0;
       for(ll i =0;i<hw;i++){
           ll x;
           cin>>x;
           a1+=floor((ll)((x-prv-1)/s));
           prv = x;
       }
       if(prv!=n){
           a1+=floor((ll)((n-prv)/s));
       }
       prv =0;
       for(ll i =0;i<vw;i++){
           ll x;
           cin>>x;
           a2+=floor((ll)((x-prv-1)/s));
           prv = x;
       }
       if(prv!=m){
          a2+=floor((ll)((m-prv)/s));
       }
       cout<<a1*a2<<'\n';
    }
    return 0;
}

