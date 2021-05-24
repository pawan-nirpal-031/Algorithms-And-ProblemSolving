// Problem Link : https://codeforces.com/contest/977/problem/D
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

Polycarp likes to play with numbers. He takes some integer number x, writes it down on the board, and then performs with it n−1 operations of the two kinds:

divide the number x by 3 (x must be divisible by 3);
multiply the number x by 2.
After each operation, Polycarp writes down the result on the board and replaces x by the result. So there will be n numbers on the board after all.

You are given a sequence of length n — the numbers that Polycarp wrote down. This sequence is given in arbitrary order, i.e. the order of the sequence can mismatch the order of the numbers written on the board.

Your problem is to rearrange (reorder) elements of this sequence in such a way that it can match possible Polycarp's game in the order of the numbers written on the board. I.e. each next number will be exactly two times of the previous number or exactly one third of previous number.

It is guaranteed that the answer exists.

Input
The first line of the input contatins an integer number n (2≤n≤100) — the number of the elements in the sequence. The second line of the input contains n integer numbers a1,a2,…,an (1≤ai≤3⋅1018) — rearranged (reordered) sequence that Polycarp can wrote down on the board.

Output

*/

int GetNofThrees(ull e){
    int c =0;
    while(e%3==0){
        e/=3;
        c+=1;
    }
    return c;
}




int main(){
  FastIO;
  int n;
  cin>>n;
  map<int,set<ull>>data;
  for(int i =0;i<n;i++){
      ull x;
      cin>>x;
      ll c = GetNofThrees(x);
      data[c].insert(x);
  }
  for(auto rit = data.rbegin();rit!=data.rend();rit++) for(ull x :  rit->second) cout<<x<<' ';
  return 0;
} 
// If Solved Mark (0/1) here => [1]