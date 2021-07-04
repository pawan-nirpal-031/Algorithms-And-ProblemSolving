// Problem Link : https://codeforces.com/contest/1213/problem/A
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

You are given n chips on a number line. The i-th chip is placed at the integer coordinate xi. Some chips can have equal coordinates.

You can perform each of the two following types of moves any (possibly, zero) number of times on any chip:

Move the chip i by 2 to the left or 2 to the right for free (i.e. replace the current coordinate xi with xi−2 or with xi+2);
move the chip i by 1 to the left or 1 to the right and pay one coin for this move (i.e. replace the current coordinate xi with xi−1 or with xi+1).
Note that it's allowed to move chips to any integer coordinate, including negative and zero.

Your task is to find the minimum total number of coins required to move all n chips to the same coordinate (i.e. all xi should be equal after some sequence of moves).

Input
The first line of the input contains one integer n (1≤n≤100) — the number of chips.

The second line of the input contains n integers x1,x2,…,xn (1≤xi≤109), where xi is the coordinate of the i-th chip.

Output
Print one integer — the minimum total number of coins required to move all n chips to the same coordinate.


*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  
  return 0;
} 
// If Solved Mark (0/1) here => []