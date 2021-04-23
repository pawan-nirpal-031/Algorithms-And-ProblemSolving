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
PolandBall is a young, clever Ball. He is interested in prime numbers. He has stated a following hypothesis: "There exists such a positive integer n that for each positive integer m number n·m + 1 is a prime number".

Unfortunately, PolandBall is not experienced yet and doesn't know that his hypothesis is incorrect. Could you prove it wrong? Write a program that finds a counterexample for any n.

Input
The only number in the input is n (1 ≤ n ≤ 1000) — number from the PolandBall's hypothesis.

Output
Output such m that n·m + 1 is not a prime number. Your answer will be considered correct if you output any suitable m such that 1 ≤ m ≤ 103. It is guaranteed the the answer exists.


There are many ways to solve the problem. There can't be many primes in a row, so we can just bruteforce until we find a composite number. Note that it is not neccesarily true for huge numbers. More general, there is a prime arithmetic progression of length k for any k, but there is no infinitely-long sequence!

Another way to solve the problem is noticing that n·(n - 2) + 1 = (n - 1)·(n - 1), so we can just output n - 2. However, we can't do that when n ≤ 2. This is a special case.

*/

int main(){
  FastIO;
  int max_n = 1000006;
  vector<bool>Prime(1000006,1);
  Prime[0] = Prime[1] =0;
  for(int i = 2;i*i<=max_n;i++) if(Prime[i]) for(int j = i*i;j<=max_n;j+=i) Prime[j] =0;
  int n;
  cin>>n;
  for(int i=1;i<=1000;i++) if(not Prime[n*i+1]){
      cout<<i<<'\n';
      return 0;
  }
  return 0;
} 
// If Solved Mark (0/1) here => []