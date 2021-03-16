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

string s;
string t;
int a[200005];
int n,k;

bool Issubsequence(int mid){
    string tmp = s;
    for(int i =1;i<mid;i++) tmp[a[i]-1]='.';
    int j =0;
  //  cout<<mid<<' '<<tmp<<'\n';
    for(int i =0;i<tmp.size();i++){
        if(tmp[i]==t[j]) j+=1;
        if(j==t.size()) return 1;
    }
    return 0;
}


/*

ababcba
abb
5 3 4 1 7 6 2
3 ab.b.ba
5 .b...ba
4 ab...ba
5 .b...ba
3

*/

int main(){
  FastIO;
  cin>>s>>t;
  for(int i =1;i<=s.size();i++) cin>>a[i];
  int low = 0;
  int high = s.size();
  while(high-low>1){
      int mid = (low+high)/2;
      ((Issubsequence(mid)?low=mid:high=mid));
  }
  if(Issubsequence(high))cout<<high-1;
  else cout<<low-1;
  return 0;
} 
