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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x



bool cases =0;

void SolveCase(){
    string alp;
    cin>>alp;
    vector<bool>read(26,0);
    for(char c : alp) read[c-'a']=1;
    int x;
    cin>>x;
    for(int i =0;i<x;i++){
        string w;
        cin>>w;
        bool y =1;
        for(char c : w){
            if(not read[c-'a']) {
                y =0;
                break;
            }
        }
        Status(y);
    }
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
