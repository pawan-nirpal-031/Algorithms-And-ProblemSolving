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
    int n,m; 
    cin>>n>>m; 
    vector<string>a(n,"");
    for(int i =0;i<n;i++){
        cin>>a[i];
    }  
    int count =0;
    for(int i=0;i<n;i++){ 
        for(int j =0;j<m;j++){
            for(int k = 1;k<=min(n,m);k++){
                int x = i+k;
                int y = j+k;
                int cnt = 1; 
                if(y<m and a[i][y]==a[i][j]) cnt+=1; 
                if(x<n and a[i][j]==a[x][j]) cnt+=1; 
                if(x<n and y<m and a[i][j]==a[x][y]) cnt+=1; 
                count+=(cnt==4);
            }
        }
    }
    cout<<count<<'\n';
}


int main(){
  FastIO;
  int t = 1;
  cin>>t; 
  while(t--) solve();
  return 0;
} 
