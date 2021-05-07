// Problem Link : https://codeforces.com/contest/1520/problem/B
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

Let's call a positive integer n ordinary if in the decimal notation all its digits are the same. For example, 1, 2 and 99 are ordinary numbers, but 719 and 2021 are not ordinary numbers.

For a given number n, find the number of ordinary numbers among the numbers from 1 to n.

Input
The first line contains one integer t (1≤t≤104). Then t test cases follow.

Each test case is characterized by one integer n (1≤n≤109).

Output
For each test case output the number of ordinary numbers among numbers from 1 to n.


*/

vector<ll>nums;
ll max_l = 10000000000;

ll Next(ll lt){
    int nd = 0;
    while(lt>0){
        nd+=1;
        lt/=10;
    }
    ll res = 1;
    for(int i =1;i<=(nd);i++) res = res*10 + 1;
    return res;
}

void Genrate(ll curr,ll add){
    if(curr>max_l) return;
    nums.push_back(curr);
    if(curr%10==9){
      ll gt = Next(curr);
      curr = gt;
      add = gt;
      nums.push_back(curr);
    }
    Genrate(curr+add,add);
}

void Solve(){// Runs in 46ms , 16000 kb memory 
    ll n;
    cin>>n;
    Genrate(1,1);
    int ans =0;
    for(ll x : nums){
      if(x<=n) ans+=1;
      else break;
    }
    cout<<ans<<'\n';
}

void MoreElegentSoln(){ // Runs in 15ms , 3600 kb memory 
  ll n;
  cin>>n;
  ll res =0;
  for(ll p = 1;p<=n;p=p*10+1) for(int d = 1;d<=9;d++) if(p*d<=n) res+=1;
  cout<<res<<'\n';
}

/*

Note that every ordinary number can be represented as d⋅(100+101+…+10k). Therefore, to count all ordinary numbers among the numbers from 1 to n, it is enough to count the number of (d,k) pairs such that d⋅(100+101+…+10k)≤n. In the given constraints, it is enough to iterate over d from 1 to 9 and k from 0 to 8.


*/

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) MoreElegentSoln();

  return 0;
} 
// If Solved Mark (0/1) here => [1]