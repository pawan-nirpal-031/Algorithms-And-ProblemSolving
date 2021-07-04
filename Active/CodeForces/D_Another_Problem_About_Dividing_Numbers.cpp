// Problem Link : https://codeforces.com/contest/1538/problem/D
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
#define Gcd(a,b) __gcd(a,b)
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 

You are given two integers a and b. In one turn, you can do one of the following operations:

Take an integer c (c>1 and a should be divisible by c) and replace a with 
a
c
 
;
Take an integer c (c>1 and b should be divisible by c) and replace b with 
b
c
 
.
Your goal is to make a equal to b using exactly k turns.

For example, the numbers a=36 and b=48 can be made equal in 4 moves:

c=6, divide b by c ⇒ a=36, b=8;
c=2, divide a by c ⇒ a=18, b=8;
c=9, divide a by c ⇒ a=2, b=8;
c=4, divide b by c ⇒ a=2, b=2.
For the given numbers a and b, determine whether it is possible to make them equal using exactly k turns.

Input
The first line contains one integer t (1≤t≤104). Then t test cases follow.

Each test case is contains three integers a, b and k (1≤a,b,k≤109).

*/

ll GetPrimePowsum(ll x){
  ll cnt =0;
  for(ll i=2;i<=sqrt(x);i++){
    ll f =0;
    while(x%i==0){
      x/=i;
      f+=1;
    }
    cnt+=f;
  }
  cnt+=(x>1);
  return cnt;
}

void solve(){
  ll a,b,k;
  cin>>a>>b>>k;
  ll m = 2;
  ll g = Gcd(a,b);
  if(a==b) m = 0;
  else if(g==a or g==b) m = 1;
  ll n = GetPrimePowsum(a) + GetPrimePowsum(b);
  Status((k==1 and m==1 and (m<=k and k<=n)) or (k!=1 and m<=k and k<=n));
}

/*

Author's solution : 

Let's denote for n the maximum number of moves for which the numbers a and b can be made equal. It is easy to understand that the number of moves is maximum when a=b=1 and each time we divided a or b by a prime number. That is, n= sum of exponents of prime divisors of a+ sum of exponents of prime divisors of b.

Let's denote by m the minimum number of moves for which the numbers a and b can be made equal. Consider a few cases:

If a=b, then m=0;
If gcd(a,b)=a or gcd(a,b)=b, then m=1;
Otherwise, then m=2.
Then, the answer "Yes" is possible in the following cases:

m≤k≤n and k=1 and m=1,
or, m≤k≤n and k≠1.


*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
} 
// If Solved Mark (0/1) here => []