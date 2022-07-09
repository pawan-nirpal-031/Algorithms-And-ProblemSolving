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
  int t;
  cin>>t; 
  while(t--){
    int n,u,d; 
    cin>>n>>u>>d; 
    int h[n]; 
    for(int &x : h) cin>>x; 
    int indx =0; 
    bool taken =0;
    for(int i =0;i<n;i++){
        if(i<n-1){
            if(h[i+1]>h[i]){
                if(abs(h[i+1]-h[i])<=u){
                    continue;
                }else{
                    cout<<i+1<<'\n';
                    break;
                }
            }else if(h[i+1]<h[i]){
                if(abs(h[i+1]-h[i])<=d){
                    continue;
                }else{
                    if(not taken){
                        taken = 1;
                    }else{
                        cout<<i+1<<'\n';
                        break;
                    }
                }
            }
        }else{
            cout<<i+1<<'\n';
            break;
        }
    }
  }
  return 0;
} 
