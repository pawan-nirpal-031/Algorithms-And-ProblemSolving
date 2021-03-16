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
// start  = 1 -> running , 0 -> not running

void Solve(){
    int n;
    cin>>n;
    bool start =0;
    bool errors = 0;
    for(int i =0;i<n;i++){
        string cmd;
        cin>>cmd;
        if(cmd=="start" or cmd =="restart") start= 1;
        else (start?start=0:errors=1);
    }
    cout<<(errors?"404\n":"200\n");
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--)
    Solve();
  return 0;
} 