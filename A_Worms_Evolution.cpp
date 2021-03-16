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
  int n;
  cin>>n;
  vector<bool>f(1003,0);
  for(int i =0;i<n;i++){
    int x;
    cin>>x;
    f[x] = 1;
  }  
  for(int i =1;i<=1002;i++){
    for(int j = 1;j<=1002;j++){
        if(i!=j and f[i] and f[j] and f[i+j]){
            cout<<i<<' '<<j<<" "<<i+j;
            return 0;
        }
    }
  }
  cout<<-1;  
  return 0;
} 