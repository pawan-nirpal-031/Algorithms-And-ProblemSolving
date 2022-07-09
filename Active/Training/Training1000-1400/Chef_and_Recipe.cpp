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

void solve(){
    int n;
    cin>>n;
    int unique =0;
    int prev = -1; 
    vector<int>frequency(1005,0);
    bool yes =1;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        if(i==0){
            frequency[x]+=1; 
            cout<<x<<" : "<<frequency[x]<<'\n';
            unique+=1;
            prev = x;
            continue;
        }
        if(frequency[x]>0 and x!=prev){ 
            yes =0;
            break;
        }
        frequency[x]+=1;  
        cout<<x<<" : "<<frequency[x]<<'\n';
        if(frequency[x]==1) unique+=1;
        prev = x;
    } 
    // cout<<"--\n"; 
    // for(int i =0;i<4;i++){
    //     cout<<i<<" : "<<frequency[i]<<'\n';
    // }
    // cout<<"--\n";
    if(yes==0){
        Status(0);
    }else{ 
        set<int>cache; 
        for(int i =0;i<1005;i++){
            if(frequency[i]==0) continue;
            cache.insert(frequency[i]);
        }   
        // for(int i = 0;i<3;i++){
        //     cout<<i<<" : "<<frequency[i]<<'\n';
        // } 
        Status(cache.size()==unique);  
    }
}
// https://www.codechef.com/submit/CHEFRECP

int main(){
  FastIO;
  int t;
  cin>>t;
  for(int c =1;c<=t;c++){
    solve();
  }
  return 0;
} 
