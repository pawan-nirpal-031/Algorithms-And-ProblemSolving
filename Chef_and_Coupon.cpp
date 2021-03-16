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

bool cases =1;
void SolveCase(){
  int d,c;
  cin>>d>>c;
  int a1,a2,a3,b1,b2,b3;
  cin>>a1>>a2>>a3>>b1>>b2>>b3;
  int day1_cost = a1+a2+a3;
  int day2_cost = b1+b2+b3;
  if(day1_cost>=150 and day2_cost>=150){
    int buy = day1_cost+day2_cost+c;
    int not_buy = day1_cost+day2_cost+2*d;
    Status(buy<not_buy);
  }else if((day1_cost<150 and day2_cost>=150) or (day1_cost>=150 and day2_cost<150)){
    int buy = day1_cost+day2_cost+c+d;
    int not_by = day1_cost+day2_cost+2*d;
    Status(buy<not_by);
  }else{
    int buy = day1_cost+day2_cost+c+2*d;
    int not_buy = day1_cost+day2_cost+2*d;
    Status(buy<not_buy);
  }
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