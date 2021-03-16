#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll  Que1(){
  string s;
  cin>>s;
  ll  kick =0;
  ll ans =0;
  ll l = s.length();
  for(int i=0;i<l;i++){
    if(i+3<l){
      if(s[i]=='K'&&s[i+1]=='I'&&s[i+2]=='C'&&s[i+3]=='K'){
        kick+=1;
      }
    }
    if(i+4<l){
      if(s[i]=='S'&&s[i+1]=='T'&&s[i+2]=='A'&&s[i+3]=='R'&&s[i+4]=='T'){
        ans+=kick;
      }
    }
  }
  return ans;
}


ll Que2(){
  ll n;
  cin>>n;
  ll g[n][n];
  for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){
      cin>>g[i][j];
    }
  } 
  ll ans =0;
  int daig =0;
  for(int col = 0;col<n;col++) {
    int row = col;
    for(int d = daig;d<n;d++){
      if((row==n-1 || d ==n-1)&&(row<n&&d<n)){
        
      }
    } 
  }
  return 0;
}




int main(){
  FastIO;
  int t;
  cin>>t;
  // for(int i=1;i<=t;i++ ){
  //    GoogleOutput(i,Que1());
  // }
  return 0;
} 
