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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x



int main(){
  FastIO;
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  if(x1==x2 or y1==y2){
    if(x1==x2){
      int side = abs(y1-y2);
      int xn =0;
      if(x1+side<=1000){
        xn = x1+side;
      }else{
        xn = x1-side;
      }
      cout<<xn<<' '<<y1<<" "<<xn<<' '<<y2;
    }else{
      int side = abs(x1-x2);
      int yn = 0;
      if(y1+side<=1000){
        yn = y1+side;
      }else{
        yn = y1-side;
      }
      cout<<x1<<' '<<yn<<" "<<x2<<' '<<yn;
    }
  }else{
    if(abs(x1-x2)==abs(y1-y2)){
      int side = abs(x1-x2);
      cout<<x1<<' '<<y2<<' '<<x2<<' '<<y1;
    }else{
      cout<<-1;
    }
  }
  return 0;
} 

// WA on 100 -100 -100 -100