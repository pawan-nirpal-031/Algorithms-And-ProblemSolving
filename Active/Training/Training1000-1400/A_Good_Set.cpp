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



int main(){
  FastIO;
  vector<int>good(502,1);
  vector<int>sets;
  good[0] =0;
  sets.push_back(1); 
  sets.push_back(2); 
  for(int i = 3;i<=500;i++){
    for(int j = 1;j<=(i/2);j++){
      int n = j; 
      int m = i-j; 
      if(n==m) continue;
      if(good[n] and good[m]) good[i] =0; 
    } 
    if(good[i]) sets.push_back(i);
  } 
  int t; 
  cin>>t; 
  while(t--){
    int n;
    cin>>n; 
    for(int i =0;i<n;i++){
      cout<<sets[i]<<' ';
    }
    cout<<'\n';
  }
  return 0;
} 
