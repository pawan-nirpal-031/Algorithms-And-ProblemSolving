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
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x


/*
Problem Statement : 



*/


/*
Author's solution : 



*/





int main(){
  FastIO;
  int n;
  cin>>n;
  int a[n],b[n];
  unordered_map<int,int>data;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i =0;i<n;i++){
      cin>>b[i];
      data[b[i]]++;
  }
  int same_pos =0;
  int diff_pos = 0;
  for(int i =0;i<n;i++){
    auto it = data.find(a[i]);
    if(a[i]==b[i]){
        same_pos++;
        diff_pos+=(it->second-1);
    }else if(it!=data.end()) diff_pos+=(it->second);
  }
  cout<<same_pos<<'\n'<<diff_pos<<endl;
  return 0;
} 
// If Solved Mark (0/1) here => []