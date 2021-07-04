// Problem Link : https://codeforces.com/contest/1006/problem/D
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

You are given two strings a and b consisting of lowercase English letters, both of length n. The characters of both strings have indices from 1 to n, inclusive.

You are allowed to do the following changes:

Choose any index i (1≤i≤n) and swap characters ai and bi;
Choose any index i (1≤i≤n) and swap characters ai and an−i+1;
Choose any index i (1≤i≤n) and swap characters bi and bn−i+1.
Note that if n is odd, you are formally allowed to swap a⌈n2⌉ with a⌈n2⌉ (and the same with the string b) but this move is useless. Also you can swap two equal characters but this operation is useless as well.

You have to make these strings equal by applying any number of changes described above, in any order. But it is obvious that it may be impossible to make two strings equal by these swaps.

In one preprocess move you can replace a character in a with another character. In other words, in a single preprocess move you can choose any index i (1≤i≤n), any character c and set ai:=c.

Your task is to find the minimum number of preprocess moves to apply in such a way that after them you can make strings a and b equal by applying some number of changes described in the list above.

Note that the number of changes you make after the preprocess moves does not matter. Also note that you cannot apply preprocess moves to the string b or make any preprocess moves after the first change is made.

Input
The first line of the input contains one integer n (1≤n≤105) — the length of strings a and b.

The second line contains the string a consisting of exactly n lowercase English letters.

The third line contains the string b consisting of exactly n lowercase English letters.

Output
Print a single integer — the minimum number of preprocess moves to apply before changes, so that it is possible to make the string a equal to string b with a sequence of changes from the list above.


*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []