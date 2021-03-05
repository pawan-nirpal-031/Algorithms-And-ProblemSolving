#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} 
#define NofSetBits(x) __builtin_popcount(x);
#define InpGrph(g,e) while(e--){ll x;ll y;cin>>x>>y ;g[x].pub(y);g[y].pub(x);}
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
    string nav;
    cin>>nav;
    ll xs,ys;
    cin>>xs>>ys;
    ll cntR =0,cntL =0,cntU =0,cntD =0;
    for(char c : nav){
      if(c=='R'){
        cntR++;
      }else if(c=='L'){
        cntL++;
      }else if(c=='U'){
        cntU++;
      }else{
        cntD++;
      }
    }
    ll q;
    cin>>q;
    while(q--){
      ll x,y;
      cin>>x>>y;
      ll dx = x-xs;
      ll dy = y-ys;
      if((dx>=0 && (cntR>=dx))||(dx<0 && (cntL>=abs(dx)))){
         if((dy>=0 && (cntU>=dy)) || ((dy<0)&&(cntD>=abs(dy)))){
           cout<<"YES"<<' '<<abs(dx)+abs(dy)<<'\n';
         }else{
           cout<<"NO"<<"\n";
         }
      }else{
        cout<<"NO"<<"\n";
      }
    }
  }
  return 0;
}