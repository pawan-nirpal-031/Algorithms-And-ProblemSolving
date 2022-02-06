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

int TeleSche(vector<vector<int>>&requests,vector<vector<int>>&memo,int curr,int nxt){
  if(curr==0) return memo[curr][nxt] = requests[curr][2];
  if(memo[curr][nxt]>-1) return memo[curr][nxt];
  if(requests[nxt][0]>=requests[curr][1])
   return memo[curr][nxt] =  max(requests[curr][2]+TeleSche(requests,memo,curr-1,curr),TeleSche(requests,memo,curr-1,nxt));
  return memo[curr][nxt] = TeleSche(requests,memo,curr-1,nxt);
}



int main(){
  FastIO;
  int n;
  cin>>n;
  vector<vector<int>>requests(n+1,vector<int>(3,0));
  vector<vector<int>>memo(n+1,vector<int>(2,-1));
  for(int i=0;i<n;i++) cin>>requests[i][0]>>requests[i][1]>>requests[i][2];
  requests[n][0] = requests[n][1] = INT_MAX;
  requests[n][2] =0;
  cout<<TeleSche(requests,memo,n-1,n);
  return 0;
} 
