#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(6)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


void solve(){
    int n;
    cin>>n; 
    vector<int>tree(n+1,0); 
    for(int i =0;i<n;i++){
        int x;
        cin>>x; 
        tree[x] = 1; 
    }
    for(int i = 1;i<=n;i++){
        if(tree[i]) continue; 
        cout<<i<<' ';
    }
    cout<<'\n';
}


int main(){
  FastIO;
  int t = 1;
 // cin>>t; 
  while(t--) solve();
  return 0;
} 
