// Problem Link : https://codeforces.com/contest/279/problem/B
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

When Valera has got some free time, he goes to the library to read some books. Today he's got t free minutes to read. That's why Valera took n books in the library and for each book he estimated the time he is going to need to read it. Let's number the books by integers from 1 to n. Valera needs ai minutes to read the i-th book.

Valera decided to choose an arbitrary book with number i and read the books one by one, starting from this book. In other words, he will first read book number i, then book number i + 1, then book number i + 2 and so on. He continues the process until he either runs out of the free time or finishes reading the n-th book. Valera reads each book up to the end, that is, he doesn't start reading the book if he doesn't have enough free time to finish reading it.

Print the maximum number of books Valera can read.

*/

/*

When solving this problem, it was easiest to use the method of two pointers: the left pointer means the beginning of the segment, the right one - the end. When moving the left pointer one unit to the right, the right one must be moved until the sum of ai inside the segment is less than or equal to t. So we can find for each left end the most distant right end, and the answer to the problem is the maximum length of these segments 

*/

int main(){
  FastIO;
  ll n,t;
  cin>>n>>t;
  int a[n];
  for(int i =0;i<n;i++) cin>>a[i];
  ll left = 0,right = 0;
  ll sum =0;
  for(int i )
  return 0;
} 
// If Solved Mark (0/1) here => []