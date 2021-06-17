// Problem Link : https://codeforces.com/contest/1536/problem/A
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

Omkar has received a message from Anton saying "Your story for problem A is confusing. Just make a formal statement." Because of this, Omkar gives you an array a=[a1,a2,…,an] of n distinct integers. An array b=[b1,b2,…,bk] is called nice if for any two distinct elements bi,bj of b, |bi−bj| appears in b at least once. In addition, all elements in b must be distinct. Can you add several (maybe, 0) integers to a to create a nice array b of size at most 300? If a is already nice, you don't have to add any elements.

For example, array [3,6,9] is nice, as |6−3|=|9−6|=3, which appears in the array, and |9−3|=6, which appears in the array, while array [4,2,0,6,9] is not nice, as |9−4|=5 is not present in the array.

For integers x and y, |x−y|=x−y if x>y and |x−y|=y−x otherwise.

*/


void Solve(){
  
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => []