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

bool Check(ll a,ll b){
  return a*a>=b;
}

int BinarySearch(vector<ll>&s,ll k,ll n){
  ll left = 0;
  ll right = n-1;
  while(right-left>1){
    ll mid = (left + (right-left)>>1);
    if(Check(s[mid],k)){
      right = mid;
    }else{
      left = mid;
    }
  }
  return n-(left +1);
}


int main(){
  FastIO;
  vector<bool>primes(100005,1);
  ll ub = 100005;
  primes[0] = primes[1] =0;
  vector<ll>squares;
  for(ll i =2;i*i<=ub;i++){
    if(primes[i]){
      for(ll j = i*i;j<=ub;j+=i){
        primes[j] =0;
      }
    }
  }
  for(ll i =2;i<=ub;i++){
    if(primes[i]){
      squares.emplace_back(i*i);
    }
  }
  int t;
  cin>>t;
  while(t--){
    ll n,k;
    cin>>n>>k;
    cout<<BinarySearch(squares,k,n)<<"\n";
  }

  
  // working on this spoj probelem

  return 0;
} 