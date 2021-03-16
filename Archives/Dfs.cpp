#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)

void dfs(vector<ll>g[],ll i,vector<bool>&vis){
    if(!vis[i]){
        vis[i]=1;
        cout<<i<<' ';
        for(ll ch : g[i]){
            if(!vis[ch]){
                dfs(g,ch,vis);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<ll>g[n+1];
    vector<bool>vis(n+1,0);
    while(m--){
        ll s,d;
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    dfs(g,1,vis);

    return 0;
}
