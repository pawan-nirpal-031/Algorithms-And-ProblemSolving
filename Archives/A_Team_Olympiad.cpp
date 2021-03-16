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
  int q[n];
  int one =0;
  int two =0;
  int three =0;
  for(int &x : q){
    cin>>x;
    if(x==1){
        one+=1;
    }else if(x==2){
        two+=1;
    }else if(x==3){
        three+=1;
    }
  } 
  if(one>0 and two>0 and three>0){
    int w = min(one,min(two,three));
    cout<<w<<'\n';
    vector<int>One,Two,Three;
    for(int i =0;i<n;i++){
        if(q[i]==1){
            One.emplace_back(i+1);
        }else if(q[i]==2){
            Two.emplace_back(i+1);
        }else if(q[i]==3){
            Three.emplace_back(i+1);
        }
    }
    for(int i =0;i<w;i++){
        cout<<One[i]<<' '<<Two[i]<<' '<<Three[i]<<'\n';
    }
  }else{
    cout<<0<<'\n';
  }
  
  return 0;
} 