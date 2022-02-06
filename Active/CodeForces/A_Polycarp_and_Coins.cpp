// Problem Link : 
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


/*
Problem Statement : 

Polycarp must pay exactly n burles at the checkout. He has coins of two nominal values: 1 burle and 2 burles. Polycarp likes both kinds of coins equally. So he doesn't want to pay with more coins of one type than with the other.

Thus, Polycarp wants to minimize the difference between the count of coins of 1 burle and 2 burles being used. Help him by determining two non-negative integer values c1 and c2 which are the number of coins of 1 burle and 2 burles, respectively, so that the total value of that number of coins is exactly n (i. e. c1+2⋅c2=n), and the absolute value of the difference between c1 and c2 is as little as possible (i. e. you must minimize |c1−c2|).

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

Each test case consists of one line. This line contains one integer n (1≤n≤109) — the number of burles to be paid by Polycarp.

Output
For each test case, output a separate line containing two integers c1 and c2 (c1,c2≥0) separated by a space where c1 is the number of coins of 1 burle and c2 is the number of coins of 2 burles. If there are multiple optimal solutions, print any one.

*/


/*
Author's solution : 



*/



int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll c1 = n/3;
    ll c2 = n/3 + (n%3!=0);
    if(c1+2*c2==n) cout<<c1<<' '<<c2<<'\n';
    else cout<<c2<<' '<<c1<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => []