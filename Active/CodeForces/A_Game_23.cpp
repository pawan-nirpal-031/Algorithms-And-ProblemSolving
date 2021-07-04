// Problem Link : https://codeforces.com/contest/1141/problem/A
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

Polycarp plays "Game 23". Initially he has a number n and his goal is to transform it to m. In one move, he can multiply n by 2 or multiply n by 3. He can perform any number of moves.

Print the number of moves needed to transform n to m. Print -1 if it is impossible to do so.

It is easy to prove that any way to transform n to m contains the same number of moves (i.e. number of moves doesn't depend on the way of transformation).

Input
The only line of the input contains two integers n and m (1≤n≤m≤5⋅108).

Output
Print the number of moves to transform n to m, or -1 if there is no solution.


*/


/*
Author's solution : 



*/

map<int,int> PrimeFactorization(ll n){
    map<int,int> prime_factors;
    for(int i = 2;i*i<=n;i++){
    if(n%i==0){
        int frequency =0;
        while(n%i==0){
        n/=i;
        frequency+=1;
        }
        prime_factors.insert(Pair(i,frequency));
    }
    }
    if(n>1){
    prime_factors.insert(Pair(n,1));
    }
    return prime_factors;
}

void show(map<int,int>s){
    for(auto p : s) cout<<p.first<<' '<<p.second<<'\n';
    cout<<'\n';
}

int main(){
  FastIO;
  ll n,m;
  cin>>n>>m;
  if(n==m){
      cout<<0;
      return 0;
  }
  map<int,int>pfn = PrimeFactorization(n);
  map<int,int> pfm = PrimeFactorization(m);
  bool y = 1;
  int ans =0;
  if(pfn[2]==0) pfn[2] = 0;
  if(pfm[3]==0) pfm[3] = 0;
  for(auto pm : pfm){
    auto pn = pfn.find(pm.first);
    if(pn==pfn.end() or ((pn->first==2 or pn->first==3 ) and pn->second>pm.second) or (pn->first>3 and pn!=pfn.end() and pn->second!=pm.second)){
        cout<<-1;
        return 0;
    }
    if(pm.first==2 or pm.first==3){
        ans+=pm.second-pn->second;
    }
  }
  cout<<ans;
  return 0;
} 
// If Solved Mark (0/1) here => []