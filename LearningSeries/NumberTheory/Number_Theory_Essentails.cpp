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
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x

inline ull Gcd(ull a,ull b) {return (a%b==0?b:Gcd(b,a%b));}

ll Lcm(ll a,ll b){ return (a*b)/Gcd(a,b); }

ll Power(ll a,ll n){
    if(n==1) return a;
    ll half = Power(a,n>>1);
    return (n&1?half*half*a:half*half);
}

ll ModulorExponention(ll a,ll n,ll m){
    if(n==1) return a%m;
    ll half = ModulorExponention(a,n>>1,m)%m;
    return ((n&1)?(((half*half)%m)*(a%m))%m:(half*half)%m);
}

bool PrimalityInRootN(ll n){
    if(n==1) return 0;
    for(int i = 2;i*i<=n;i++) if(n%i==0) return 0;
    return 1; 
}

vector<pair<int,int>> DivisorsInRootN(ll n){
    vector<pair<int,int>>divisors;
    for(int i = 1;i*i<=n;i++){
        if(n%i==0){
            if(i!=(n/i)) divisors.push_back({i,n/i});
            else divisors.push_back({i,i});
        }
    }
    return divisors;
}

vector<bool> PrimalityUsingSeive(ll max_limit){ // O(NLog(LogN))
    max_limit+=5;
    vector<bool>primes(max_limit,1);// i is prime if primes[i]==true
    primes[0] = primes[1] = 0;
    for(int i = 2;i*i<=max_limit;i++){
        if(primes[i]) for(int j = i*i;j<=max_limit;j+=i) primes[j] =0;
    }
    return primes;
}

vector<pair<int,int>> PrimeFactorizationInRootN(ll n){
  vector<pair<int,int>>prime_factors;
  for(int i = 2;i*i<=n;i++){
      if(n%i==0){
          int freq =0;
          while(n%i==0){
              freq+=1;
              n/=i;
          }
          prime_factors.push_back({i,freq});
      }
  }
  if(n!=1) prime_factors.push_back({n,1}); 
  return prime_factors; 
}

vector<vector<ll>> FactorizationOfARangeOfNumbers(ll n){ 
// This could check prime and factors otherwise in O(Nlog(N)) for all numbers betwwen 1 to n
    vector<vector<ll>>Factors(n+1);
    for(int i = 1;i<=n;i++){
        for(int j = i; j<=n;j+=i) Factors[j].emplace_back(i);
    }
    return Factors;
}

int main(){
  FastIO;
  
  return 0;
} 
