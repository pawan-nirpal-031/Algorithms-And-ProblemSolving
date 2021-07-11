// Problem Link : https://codeforces.com/contest/1272/problem/A
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

Three friends are going to meet each other. Initially, the first friend stays at the position x=a, the second friend stays at the position x=b and the third friend stays at the position x=c on the coordinate axis Ox.

In one minute each friend independently from other friends can change the position x by 1 to the left or by 1 to the right (i.e. set x:=x−1 or x:=x+1) or even don't change it.

Let's introduce the total pairwise distance — the sum of distances between each pair of friends. Let a′, b′ and c′ be the final positions of the first, the second and the third friend, correspondingly. Then the total pairwise distance is |a′−b′|+|a′−c′|+|b′−c′|, where |x| is the absolute value of x.

Friends are interested in the minimum total pairwise distance they can reach if they will move optimally. Each friend will move no more than once. So, more formally, they want to know the minimum total pairwise distance they can reach after one minute.

You have to answer q independent test cases.

Input
The first line of the input contains one integer q (1≤q≤1000) — the number of test cases.

The next q lines describe test cases. The i-th test case is given as three integers a,b and c (1≤a,b,c≤109) — initial positions of the first, second and third friend correspondingly. The positions of friends can be equal.

Output
For each test case print the answer on it — the minimum total pairwise distance (the minimum sum of distances between each pair of friends) if friends change their positions optimally. Each friend will move no more than once. So, more formally, you have to find the minimum total pairwise distance they can reach after one minute.

*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  int q;
  cin>>q;
  while(q--){
     ll ans = Infinity;
      ll a,b,c;
      cin>>a>>b>>c;
      for(int i = -1;i<=1;i++){
          for(int j = -1;j<=1;j++){
              for(int k = -1;k<=1;k++){
                  ll a1 = a+i;
                  ll b1 = b+j;
                  ll c1 = c+k;
                  ans = min(ans,abs(a1-b1)+abs(a1-c1)+abs(b1-c1));
              }
          }
      }
      cout<<ans<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]