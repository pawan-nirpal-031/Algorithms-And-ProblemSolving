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


// int Moves(int n,int steps_so_far,int m){
//   if(steps_so_far==n){

//   }
//   int one = Moves(n,steps_so_far+1,m);
//   int two = Moves(n,steps_so_far+2,m);

// }

int main(){
  FastIO;
  int n;
  cin>>n;
  int c = n;
  int rev = 0;
  while(c>0){
    rev = 10*rev + c%10;
    c/=10;
  }
  if(n<0){
    cout<<-rev;
  }else{
    cout<<rev;
  }

  return 0;
} 