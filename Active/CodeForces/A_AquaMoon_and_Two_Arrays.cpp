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

void call(int c,int i,int j){
    while(c>0){
        cout<<i+1<<" "<<j+1<<'\n';
        c-=1;
    }
}

void solve(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int &x : a) cin>>x;
    for(int &x : b) cin>>x;
    vector<int>diff(n,0);
    int s=0;
    int plus_cnt=0;
    for(int i=0;i<n;i++){
        diff[i] = b[i]-a[i];
        s+=diff[i];
        if(diff[i]>0) plus_cnt+=diff[i];
    }
    if(s!=0){
        cout<<-1<<'\n';
        return;
    }
    cout<<plus_cnt<<'\n';
    for(int i = 0;i<n;i++){
        if(diff[i]==0) continue;
        if(diff[i]<0){
            for(int j =0;j<n;j++){
                if(diff[j]>0){
                    if(diff[j]<abs(diff[i])){
                        call(diff[j],i,j);
                        diff[i]+=diff[j];
                        diff[j] =0;
                    }else{
                        call(abs(diff[i]),i,j);
                        diff[j]+=diff[i];
                        diff[i] = 0;
                    }
                }
            }
        }else{
            for(int j =0;j<n;j++){
                if(diff[j]<0){
                    if(abs(diff[j])<diff[i]){
                        call(abs(diff[j]),i,j);
                        diff[i]+=diff[j];
                        diff[j] = 0;
                    }else{
                        call(diff[i],i,j);
                        diff[j]+=diff[i];
                        diff[i] =0;
                    }
                }
            }
        }
    }
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      solve();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []