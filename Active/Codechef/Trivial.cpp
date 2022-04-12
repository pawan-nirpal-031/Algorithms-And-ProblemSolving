// Problem Link : https://www.codechef.com/COOK130B/problems/WAV2
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
#define Status(b) (cout<<(b?"POSITIVE\n":"NEGATIVE\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 

Chef is stuck in the wavey world of polynomials. You are given all N roots of a polynomial P(x)=∏Ni=1(x−ai). The roots are pairwise distinct integers, but they are not given in any particular order.

To help Chef escape, you should answer Q queries (numbered 1 through Q). For each valid i, in the i-th query, you are given an integer xi and you have to determine whether P(xi) is positive, negative or 0.

Input
The first line of the input contains two space-separated integers N and Q.
The second line contains N space-separated integers a1,a2,…,aN.
Q lines follow. For each valid i, the i-th of these lines contains a single integer xi describing the i-th query.
Output
For each query, print a single line containing the string "POSITIVE", "NEGATIVE" or "0" (without quotes) describing the value of the polynomial for the i-th query.

Constraints
1≤N,Q≤2⋅105
|ai|≤109 for each valid i
a1,a2,…,aN are pairwise distinct
|xi|≤109 for each valid i

*/


/*
Author's solution : 



*/


int main(){
  FastIO;
  char str1[20] = "Hello";
  char str2[20] = "World";
  cout<<strcpy(str2,strcat(str1,str2));
  return 0;
} 
// If Solved Mark (0/1) here => [1]