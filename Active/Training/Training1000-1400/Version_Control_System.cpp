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



int main(){
  FastIO;
  int t;
  cin>>t; 
  while(t--){
    int n,m,k; 
    cin>>n>>m>>k; 
    int count[n+1] = {0}; 
    for(int i =0;i<m;i++){
        int x; 
        cin>>x; 
        count[x]+=1;
    }
    for(int i = 0;i<k;i++){
        int x; 
        cin>>x; 
        count[x]+=2;
    }
    int ans1 =0,ans2 =0; 
    for(int i =1;i<=n;i++){
        if(count[i]==0) ans2+=1;
        else if(count[i]==3) ans1+=1;
    }
    cout<<ans1<<' '<<ans2<<'\n';
  }
  return 0;
} 
