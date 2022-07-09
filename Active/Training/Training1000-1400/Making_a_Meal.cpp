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
    int n; 
    cin>>n;
    int count[6] = {0,0,0,0,0,0};// c o d e h f 
    for(int i =0;i<n;i++){
        string s; 
        cin>>s; 
        for(char c : s){
            if(c=='c') count[0]+=1; 
            else if(c=='o') count[1]+=1; 
            else if(c=='d') count[2]+=1; 
            else if(c=='e') count[3]+=1; 
            else if(c=='h') count[4]+=1; 
            else if(c=='f') count[5]+=1; 
        }
    }
    count[0]/=2;
    count[3]/=2; 
    int times =INT_MAX; 
    for(int i=0;i<6;i++) times = min(times,count[i]); 
    cout<<times<<'\n'; 
  }
  return 0;
} 
