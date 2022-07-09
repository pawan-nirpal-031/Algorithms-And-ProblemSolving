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
  vector<bool>good(210,1);
  for(int i = 1;i<102;i++){
    for(int j =1;j<102;j++){
        if(i!=j){
            good[i+j] = 0;
        }
    }
  } 
  for(int i =0;i<210;i++) if(good[i]) cout<<i<<' ';
//   int t;
//   cin>>t; 
//   while(t--){
//     int n;
//     cin>>n; 
//     int count =0;
//     for(int i =1;i<102;i++){
//         if(count<n and good[i]){
//              cout<<i<<' ';
//              count+=1;
//         }
//         if(count==n) break;
//     }
//     cout<<'\n';
//   }
  return 0;
} 
