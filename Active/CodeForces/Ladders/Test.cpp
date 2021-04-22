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


void UnitTests(){
    
}


bool cases =1;

void RandomGenrator(){

}

void SolveCase(){
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int i =0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  vector<int>prefix(n,0),suffix(n,0);
  suffix[n-1] = prefix[0] = 1;
  for(int i =1;i<n;i++) prefix[i] = (a[i-1]!=a[i]?1 + prefix[i-1]:prefix[i-1]);
  for(int i = n-2;i>=0;i--) suffix[i] = (a[i+1]!=a[i]?1 + suffix[i+1]:suffix[i+1]);
  int ans = 0;
  for(int i = 0;i<=n-x;i++){
    if(i==0){
      ans = max(ans,(x<n?suffix[x]:0));
    }else if(i==n-x){
      ans = max(ans, (n-x-1>=0?prefix[n-x-1]:0));
    }else{
      ans = max(ans,((i-1>=0)?prefix[i-1]:0)+((i+x<n)?suffix[i+x]:0));
    }
  }
  //for(int i =0;i<n;i++) cout<<prefix[i]<<' ';
  cout<<'\n'<<min(ans,prefix[n-1])<<'\n';
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
