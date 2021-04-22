// Problem Link : https://www.codechef.com/COOK128C/problems/CM164364
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
There are n chocolates, and you are given an array of n numbers where the i-th number Ai is the flavour type of the i-th chocolate. Sebrina wants to eat as many different types of chocolates as possible, but she also has to save at least x number of chocolates for her little brother.
Find the maximum possible number of distinct flavour types Sebrina can have.
*/

void SolveCase(){
    int n,x;
    cin>>n>>x;
    map<ll,int>data; // (type,freq);
    multimap<int,ll>rev; // (freq,type);
    for(int i =0;i<n;i++){
        ll t;
        cin>>t;
        auto it = data.find(t);
        if(it==data.end()) data.insert({t,1});
        else it->second+=1;
    }
    for(auto it= data.begin();it!=data.end();it++) rev.insert({it->second,it->first});
    for(auto it= rev.rbegin();it!=rev.rend();it++){
        auto st = data.find(it->second);
        int freq = st->second;
        if((freq)>=x){
            if(freq>x){
                st->second-=x;
                x = 0;
                break;
            }else{
                st->second  = x = 1;
            }
        }else{
            if(freq>0){
                st->second = 1;
                x = x - freq + 1;
            }
        }
    }
    if(x>0){
        for(auto it= data.begin();it!=data.end();it++){
            if(x==0) break;
            if(it->second==1 and x>0){
                it->second =0;
                x-=1;
            }
        }

    }
    int cnt = 0;
    for(auto it= data.begin();it!=data.end();it++){
        if(it->second>0) cnt+=1;
    }
    cout<<cnt<<'\n';
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      SolveCase();
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]