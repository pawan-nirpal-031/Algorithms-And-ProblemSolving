
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<ll,ll>a,b;
        ll isValid =0;
        ll mn = 1e9;
        for(ll i =0;i<n;i++){
            ll x;
            cin>>x;
            isValid^=x;
            a[x]++;
            mn = min(mn,x);
        }
        for(ll i =0;i<n;i++){
            ll x;
            cin>>x;
            b[x]++;
            isValid^=x;
            mn = min(mn,x);
        }
        if(isValid){
            cout<<-1<<'\n';
            continue;
        }
        for(auto p : a){
            ll e = p.first;
            if(b.find(e)!=b.end()){
                ll rm = min(a[e],b[e]);
                a[e]-=rm;
                b[e]-=rm;
            }
        }
        for(auto p : b){
            ll e = p.first;
            if(a.find(e)!=a.end()){
                ll rm = min(a[e],b[e]);
                a[e]-=rm;
                b[e]-=rm;
            }
        }
        vector<ll>v1,v2;
        for(auto p : a){
            ll e = p.first;
            ll c = p.second;
            for(ll i =0;i<c/2;i++){
                v1.push_back(e);
            }
        }
        for(auto p : b){
            ll e = p.first;
            ll c = p.second;
            for(ll i =0;i<c/2;i++){
                v2.push_back(e);
            }
        }
        ll ans =0;
        reverse(v2.begin(),v2.end());
        for(ll i=0;i<v1.size();i++){
            ans+=min(2*mn,min(v1[i],v2[i]));
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}

