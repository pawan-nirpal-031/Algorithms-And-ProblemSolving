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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


int main(){
  FastIO;
  int n,m,q;
  cin>>n>>m>>q;
  string s,t;
  cin>>s>>t;
  vector<int>prefix(n+1,0);
  for(int i =1;i<=n-m+1;i++){
    if(s[i-1]==t[0]){
       int yes = 1;
       for(int j = 0;j<m;j++){
            if(s[i-1+j]!=t[j]){
                yes =0;
                break;
            }
        }
        prefix[i] = yes + prefix[i-1];
    }
  }
  for(int i =1;i<=n;i++) prefix[i]+=prefix[i-1]; 
 // for(int i =0;i<=n;i++) cout<<i<<" "<<prefix[i]<<'\n';
  while(q--){
      int l,r;
      cin>>l>>r;
      cout<<prefix[r]-prefix[l-1]<<"\n";
  }
  return 0;
} 




















/*


vector<int>prefix(n,0);
  prefix[0] = 1;
  for(int i =0;i<m;i++){
      if(s[i]!=t[i]){
          prefix[0] =0;
          break; 
      }
  }
  for(int i =0;i<n-m+1;i++){
    if(s[i]==t[0]){
        int yes = 1;
        for(int j = i;j<i+m;j++){
            if(s[j]!=t[j-i]) yes = 0;
        }
        prefix[i] = yes;
    }
  }
  for(int i =1;i<n;i++) prefix[i]+=prefix[i-1];
 // for(int i =0;i<n;i++) cout<<i<<" "<<prefix[i]<<'\n';
  while(q--){
      int l,r;
      cin>>l>>r;
      l-=1;
      r-=1;
      if(l==0){
          cout<<prefix[r]<<'\n';
      }else{
          cout<<prefix[r]-prefix[l-1]<<'\n';
      }
  }


*/