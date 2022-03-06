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


int main(){
  FastIO;
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int &x : a) cin>>x;
  int l =0,r =0;
  queue<int>list;
  vector<int>ans;
  while(r<n-k+1 and l<=r){
      if(r<k){
          if(a[r]<0) list.push(a[r]);
          r++;
      }else{
          if(list.size()) ans.push_back(list.front());
          if(list.size() and list.front()==a[l]) list.pop();
          if(a[r+1]<0) list.push(a[r+1]);
          l+=1;
          r+=1; 
      }
  }
  if(r!=n-k+1) ans.push_back((list.size()?list.front():0));
  for(int x : ans) cout<<x<<' ';
  return 0;
} 
