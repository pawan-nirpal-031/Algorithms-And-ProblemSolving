#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)

ll a[100005];
ll getLastIndx(ll i, ll m){
    for(;i<=m;i++){
        if(a[i]>0){
            return i;
        }
    }
    return i;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll>res(n+1,-1);
        ll prft=0;
        for(ll i =1;i<=m;i++){
            cin>>a[i];
        }
        for(ll i=1;i<=n;i++){
            ll d,f,o;
            cin>>d>>f>>o;
            if(a[d]>0){
                prft+=f;
                res[i] = d;
                a[d]--;
            }else{
                prft+=o;
            }
        }
        cout<<prft<<'\n';
        ll lastIndx =1;
        for(ll i =1;i<=n;i++){
            if(res[i]!=-1){
                cout<<res[i]<<' ';
            }else{
                lastIndx = getLastIndx(lastIndx,m);
                cout<<lastIndx<<' ';
                a[lastIndx]--;
            }
        }
        cout<<'\n';
    }
    
    return 0;
}

