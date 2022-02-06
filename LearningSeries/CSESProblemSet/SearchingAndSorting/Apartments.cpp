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

There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input

The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.

The next line contains $n$ integers a_1, a_2, ... a_n: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x-k and x+k.

The last line contains $m$ integers b_1, b_2, ...b_m: the size of each apartment.

Output

Print one integer: the number of applicants who will get an apartment.

Constraints
1 \le n, m \le 2 \cdot 10^5
0 \le k \le 10^9

1 \le a_i, b_i \le 10^9


*/


/*
Author's solution : 



*/

int main(){
  FastIO;
  ll n,m,k;
  cin>>n>>m>>k;
  ll a[n];
  ll b[m];
  for(ll &x : a) cin>>x;
  for(ll &x : b) cin>>x;
  sort(a,a+n);
  sort(b,b+m);
  int cnt =0;
  for(int i =0,j =0;i<n and j<m;){
      if(abs(a[i]-b[j])<=k){
          cnt+=1;
          i+=1;
          j+=1;
          continue;
      }
      if(a[i]-b[j]>k){
          j+=1;
      }else{
          i+=1;
      }
  }
  cout<<cnt;
  return 0;
} 
// If Solved Mark (0/1) here => [1]