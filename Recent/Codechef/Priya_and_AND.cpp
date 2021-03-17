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

Priya loves bitwise AND, but she hates programming. Help her solve this problem.
Given an array A of size N, let Bij denote the bitwise AND of A[i] and A[j]. You have to 
find the number of pairs (i,j), such that i<j and Bij=A[i].
1≤T≤100 
1≤N≤100
1≤A[i]≤100

*/


bool cases =1;

void SolveCase(){
   int n;
   cin>>n;
   int a[n];
   for(int i =0;i<n;i++){
      cin>>a[i];
   }
   ll ans =0;
   for(int i = n-2;i>=0;i--){
      for(int j = i+1;j<n;j++){
         if((a[i]&a[j])==a[i]) ans+=1;
      }
   }
   cout<<ans<<'\n';
}

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
     SolveCase();
  }
  return 0;
} 
