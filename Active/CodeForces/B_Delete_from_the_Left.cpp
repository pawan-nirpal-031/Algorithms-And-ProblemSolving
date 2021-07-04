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

You are given two strings s and t. In a single move, you can choose any of two strings and delete the first (that is, the leftmost) character. After a move, the length of the string decreases by 1. You can't choose a string if it is empty.

For example:

by applying a move to the string "where", the result is the string "here",
by applying a move to the string "a", the result is an empty string "".
You are required to make two given strings equal using the fewest number of moves. It is possible that, in the end, both strings will be equal to the empty string, and so, are equal to each other. In this case, the answer is obviously the sum of the lengths of the initial strings.

Write a program that finds the minimum number of moves to make two given strings s and t equal.




*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  string s1,s2;
  cin>>s1>>s2;
  int suffix_len =0;
  int s1_p = s1.length()-1;
  int s2_p = s2.length()-1;
  for(;s1_p>=0 and s2_p>=0;){
    if(s1[s1_p]!=s2[s2_p]) break;
    s1_p--;
    s2_p--;
    suffix_len+=1;
  }
  cout<<s1.length()+s2.length()-2*(suffix_len);
  return 0;
} 
// If Solved Mark (0/1) here => [1]