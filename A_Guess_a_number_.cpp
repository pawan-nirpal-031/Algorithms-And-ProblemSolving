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
  int q;
  cin>>q;
  ll left = -1e9;
  ll right = 1e9;
  while(q--){
    string cmd;
    cin>>cmd;
    ll x;
    cin>>x;
    char res;
    cin>>res;
    if(res=='Y'){
        if(cmd==">=" and left<x){
            left = x;
        }
        if(cmd==">" and left<=x){
            left = x+1;
        }
        if(cmd=="<=" and right>x){
            right = x;
        }
        if(cmd=="<" and right>=x){
            right = x-1;
        }
    }else{
        if(cmd==">=" and right<x){
            right = x-1;
        }
        if(cmd==">" and right<=x){
            right = x;
        }
        if(cmd=="<=" and left>x){
            left = x+1;
        }
        if(cmd=="<" and left<=x){
            left = x;
        }
    }
  }
  if(left>right){
    cout<<"Impossible";
    return 0;
  }
  cout<<(left);
  return 0;
} 