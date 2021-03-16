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
  int n;
  cin>>n;
  int a[n];
  vector<int>pos,neg,zero;
  for(int &x : a){
    cin>>x;
    if(x==0) zero.emplace_back(x);
    else if(x>0) pos.emplace_back(x);
    else neg.emplace_back(x);
  }
  if(neg.size()%2==0) {
    zero.emplace_back(neg.back());
    n = neg.size()-1;
  }else{
    n = neg.size(); 
  }
  if(pos.size()==0){
    pos.emplace_back(neg[n-2]);
    pos.emplace_back(neg[n-3]);
    n-=2;
  }
  cout<<n<<' ';
  for(int i =0;i<n;i++){
    cout<<neg[i]<<" ";
  }
  cout<<'\n'<<pos.size()<<' ';
  for(int i =0;i<pos.size();i++){
      cout<<pos[i]<<' ';
  }
  cout<<'\n'<<zero.size()<<' ';
  for(int x : zero) cout<<x<<' ';
  
  
  return 0;
} 