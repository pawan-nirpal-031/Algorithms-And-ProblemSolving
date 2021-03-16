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
#define Status(b) (cout<<(b?"First\n":"Second\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


void Release(){
  int n;
  cin>>n;
  vector<int>f(n+1,0);
  for(int i =1;i<=n;i++){   
   int x;
   cin>>x;
   f[x]+=1;
  }
  int curr = 1;
  if((f[1]<1 or (n==1)) or (n>=2 and f[2]==0 and f[1]==1)){
    Status(0);
    return;
  }
  for(int i = 2;i<=n;i++){
    if(f[i-1]==1){
      if(f[i]==1) continue;
      if(f[i]==0) {
        Status(curr^1);
        return;
      }
    }
    if(f[i-1]>1){
      int diff = f[i-1]-1;
      f[i]+=diff;
      f[i-1]=1;
      curr = (curr+diff)%2;
    }
  }
  Status(curr^1);
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      Release();
  }
  return 0;
} 

/*

6
1 1 3 5 6 6

6
1 1 5 6 6 6

5
1 1 2 5 5 



*/
