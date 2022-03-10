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

void GenerateAllSubsets(string s,int i,int n,string temp){
    if(i<n){
        temp+=s[i];
        GenerateAllSubsets(s,i+1,n,temp);
        temp.pop_back();
        GenerateAllSubsets(s,i+1,n,temp);
    }else cout<<temp<<'\n';
}

void PowerSet(string s,int n){
    for(int i =0;i<(1<<n);i++){
        for(int j =0;j<n;j++){
            if((i&(1<<j))) cout<<s[j];
        }
        cout<<'\n';
    }
}

int main(){
  FastIO;
  for(int i =1;i<=3;i++){
      cout<<i*i<<endl;
  }
  return 0;
} 
