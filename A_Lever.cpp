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
  string s;
  cin>>s;
  ll left_w =0;
  ll right_w = 0;
  ll pivot = -1;
  ll n = s.length();
  for(ll i =0;i<n;i++){
      if(s[i]=='^'){
          pivot = i;
          break;
      }
  }
  for(ll i =0;i<n;i++){
    if(i<pivot and s[i]!='='){
        left_w+=((abs(pivot-i)*(s[i]-'0')));
    }
    if(i>pivot and s[i]!='='){
        right_w+=((abs(pivot-i)*(s[i]-'0')));
    }
  }
  if(left_w==right_w){
      cout<<"balance";
  }else if(right_w>left_w){
      Print("right");
  }else{
      Print("left");
  }
  return 0;
} 