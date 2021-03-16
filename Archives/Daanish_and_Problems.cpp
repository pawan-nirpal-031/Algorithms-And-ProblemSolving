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


void SolveInstance(){
  vector<ull>a(10,0);
  for(int i =0;i<10;i++) cin>>a[i];
  ull k;
  cin>>k;
  for(int i = 9;i>=0;i--){
      if(a[i]){
        if(k>=a[i]){
          k-=a[i];
          a[i] =0;
        }else{
          break;
        }
      }
  }
  for(int i =9;i>=0;i--){
      if(a[i]){
          cout<<i+1<<'\n';
          return;
      }
  }
}

int main(){
  FastIO;
  int t = 1;
  cin>>t;
  while(t--){
    SolveInstance();
  }
  return 0;
} 