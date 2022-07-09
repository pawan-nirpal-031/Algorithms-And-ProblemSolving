#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


void solve(){
    int n,m; 
    cin>>n>>m;
    vector<int>alice(1000002,0);
    vector<int>berta(1000002,0);
    int amax =0; 
    int bmax =0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x; 
        alice[x]+=1;
        amax = max(amax,x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x; 
        berta[x]+=1;
        bmax = max(bmax,x);
    }
    int ans =0; 
    int up = min(amax,bmax);
    for(int i =1;i<=up;i++){
        if(alice[i]>0 and berta[i]>0){
            ans+=alice[i];
        }
    }
    cout<<ans<<'\n';
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
