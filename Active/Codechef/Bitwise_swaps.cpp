// Problem Link : 
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
#define Status(b) (cout<<(b?"Yes\n":"No\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 



*/


/*
Author's solution : 



*/

class Math{
    public:
    int Floor(int x,int y){
        return floor(x*1.0/y);
    }
    int Ceil(int x,int y){
        return ceil(x*1.0/y);
    }
};


set<ll>masked_components;

void Insert(int x){
  if(masked_components.size()==0){
    masked_components.insert(x);
  }else{
    ll unified_comp_mask =0;
    vector<ll>temp;
    for(ll mask : masked_components){
      if((mask & x)){
        temp.push_back(mask);
      }
    }
    if(temp.size()==0){
      masked_components.insert(x);
    }else{
      unified_comp_mask = x;
      for(ll &mask : temp){
        unified_comp_mask |= mask;
        masked_components.erase(mask);
      }
      masked_components.insert(unified_comp_mask);
    }
  }
}

ll GetComponent(int x){
  for(ll mask : masked_components) if(mask & x) return mask;
  return x;
}

ll SanityCheck(){
  if(masked_components.size()==1) return 0;
  ll mask = LONG_MAX;
  for(ll c : masked_components) mask &=c;
  return mask;
}

bool SameComponent(int x,int y){
  return (GetComponent(x)==GetComponent(y));
}


void solve(){
  int n;
  cin>>n;
  masked_components.clear();
  int a[n],b[n];
  for(int i =0;i<n;i++){
    cin>>a[i];
    b[i] = a[i];
    Insert(a[i]);
  }
  sort(b,b+n);
  bool poss = 1;
  for(int i =0;i<n;i++){
    poss = poss and (SameComponent(a[i],b[i]));
    if(not poss) break;
  }
  Status(poss);
}

void RunTests(){
  int n;
  cin>>n;
  for(int i =0;i<n;i++){
    int x;
    cin>>x;
    Insert(x);
  }
  for(ll msk : masked_components) cout<<msk<<" ";
  int q;
  cin>>q;
  while(q--){
    int x,y;
    cin>>x>>y;
    Status(SameComponent(x,y));
  }
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while (t--){
    solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []