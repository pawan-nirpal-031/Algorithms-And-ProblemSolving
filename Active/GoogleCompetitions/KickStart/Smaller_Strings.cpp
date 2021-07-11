// Problem Link : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ebe5e
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

You are given an integer K and a string S of length N, consisting of lowercase letters from the first K letters of the English alphabet. Find the number of palindrome strings of length N which are lexicographically smaller than S and consist of lowercase letters from the first K letters of the English alphabet.

A string composed of ordered letters a1,a2,…,an is lexicographically smaller than another string of the same length b1,b2,…,bn if ai<bi, where i is the first index where characters differ in the two strings. For example, the following strings are arranged in lexicographically increasing order: aaa, aab, aba, cab.

A palindrome is a string that is the same written forwards and backwards. For example, anna, racecar, aaa and x are all palindromes, while ab, frog and yoyo are not.

As the number of such strings can be very large, print the answer modulo 109+7.

Input
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case consists of two lines. The first line contains two integers N and K. The second line contains a string S of length N, consisting of lowercase letters.

*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []