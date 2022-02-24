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


int GetIndx(int a[],int n,int x){
    int l = 0;
    int h = n-1;
    while(l+1<h){
        int m = (l+h)/2;
        if(a[m]==x) return m;
        else if(x<a[m]){
            h = m;
        }else l = m;
    }
    if(a[l]==x) return l;
    else if(a[h]==x) return h;
    else return -1;
}

int main(){
  FastIO;
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int &v : a) cin>>v;
  cout<<GetIndx(a,n,x);
  return 0;
} 
