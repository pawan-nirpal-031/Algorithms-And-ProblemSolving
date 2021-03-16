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
#define BoolAnsCall(b) (cout<<(b?"YES\n":"NO\n"));

class MathModule{
  public:
    ull Gcd(ull a,ull b){
        return (a%b==0?b:Gcd(b,a%b));
    }

    ll Lcm(ll a,ll b){
        return (a*b)/Gcd(a,b);
    }

    ll Pow(ll a,ll n){
      if(n==1) return a;
      ll half = Pow(a,n>>1);
      return (n&1?half*half*a:half*half);
    }
    ll ModuloExpo(ll a,ll n,ll m){
      if(n==1) return a%m;
      ll half = ModuloExpo(a,n>>1,m)%m;
      if(n&1){
        return (((half*half)%m)*(a%m))%m;
      }else{
        return (half*half)%m;
      }
    }
};





int main(){
  FastIO;
  string s;
  cin>>s;
  vector<int>zero(s.length(),0),ones(s.length(),0);
  if(s[0]=='0'){
      zero[0] = 1;
  }else{
      ones[0] = 1;
  }
  int ans =0;
  for(int i = 1;i<s.length();i++){
    if(s[i]-'0'){
        ones[i] = 1;
        if(s[i-1]-'0'){
            ones[i] +=ones[i-1];
        }
    }else{
        zero[i] = 1;
        if(s[i-1]=='0'){
            zero[i]+=zero[i-1];
        }
    }
    ans = max(ans,max(zero[i],ones[i]));
  }
  BoolAnsCall(ans>=7);
  return 0;
} 