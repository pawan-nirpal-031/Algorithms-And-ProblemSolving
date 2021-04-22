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
#define Status(b) (cout<<(b?"YES ":"NO "));
#define Print(x) cout<<x
#define Input(x) cin>>x



bool cases =1;

void SolveCase(){
  int n,k;
  cin>>n>>k;
  vector<pair<string,bool>>forgot(n,{"",0});
  for(int i=0;i<n;i++){
      string wrd;
      cin>>wrd;
      forgot[i].first = wrd;
  }
  for(int i =0;i<k;i++){
      int x;
      cin>>x;
      for(int j =0;j<x;j++){
          string w;
          cin>>w;
          for(int k =0;k<n;k++){
              if(forgot[k].first==w) {
                  forgot[k].second= 1;
                  break;
              }
          }
      }
  }
  for(int i =0;i<n;i++) Status(forgot[i].second);
  cout<<'\n';

}

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
     SolveCase();
  }
  return 0;
} 
