#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


void solve(){
  int r,g,b,k; 
  cin>>r>>g>>b>>k; 
  int checkpoint1 = min(r,min(g,b));
  if(checkpoint1>=k-1){
    cout<<3*(k-1)+1<<'\n';
  }else{
    int count = 3*checkpoint1; 
    r-=checkpoint1; 
    g-=checkpoint1; 
    b-=checkpoint1;
    k-=checkpoint1;
    if(r==0){
      int checkpoint2 = min(g,b);
      if(checkpoint2>=k-1){
        count+=(2*(k-1)+1);
      }else{
        g-=checkpoint2; 
        b-=checkpoint2; 
        k-=checkpoint2; 
        count+=(2*(checkpoint2)+k);
      }
    }else if(g==0){
      int checkpoint2 = min(r,b);
      if(checkpoint2>=k-1){
        count+=(2*(k-1)+1);
      }else{
        r-=checkpoint2; 
        b-=checkpoint2; 
        k-=checkpoint2; 
        count+=(2*(checkpoint2)+k);
      }
    }else if(b==0){
      int checkpoint2 = min(g,r);
      if(checkpoint2>=k-1){
        count+=(2*(k-1)+1);
      }else{
        g-=checkpoint2; 
        r-=checkpoint2; 
        k-=checkpoint2; 
        count+=(2*(checkpoint2)+k);
      }
    }
    cout<<count<<'\n';
  }
}

int main(){
  FastIO;
  int t; 
  cin>>t; 
  while(t--){
    solve();
  }
  return 0;
} 
