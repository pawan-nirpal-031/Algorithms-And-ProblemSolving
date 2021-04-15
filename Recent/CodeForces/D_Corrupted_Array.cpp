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
You are given a number n and an array b1,b2,…,bn+2, obtained according to the following algorithm:

some array a1,a2,…,an was guessed;
array a was written to array b, i.e. bi=ai (1≤i≤n);
The (n+1)-th element of the array b is the sum of the numbers in the array a, i.e. bn+1=a1+a2+…+an;
The (n+2)-th element of the array b was written some number x (1≤x≤109), i.e. bn+2=x; The
array b was shuffled.
For example, the array b=[2,3,7,12,2] it could be obtained in the following ways:

a=[2,2,3] and x=12;
a=[3,2,7] and x=2.
For the given array b, find any array a that could have been guessed initially.

Input
The first line contains a single integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains a single integer n (1≤n≤2⋅105).

The second row of each test case contains n+2 integers b1,b2,…,bn+2 (1≤bi≤109).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output:

"-1", if the array b could not be obtained from any array a;
n integers a1,a2,…,an, otherwise.
If there are several arrays of a, you can output any

*/

bool cases =1;

void SolveCase(){
    ll n;
    cin>>n;
    ll b[n+2];
    ll sum_b =0;
    unordered_multiset<ll>cache;
    for(int i =0;i<n+2;i++){
        cin>>b[i];
        cache.insert(b[i]);
        sum_b+=b[i];
    }
    ll orig_x = -1;
    ll sum_a = -1;
    for(int i =0;i<n+2;i++){
        ll x = sum_b - 2*b[i];
        if(cache.find(x)!=cache.end()){
            orig_x = x;
            sum_a = b[i];
            b[i] = -1;
            break;
        } 
    }
    if(orig_x==-1 or sum_a==-1){
        cout<<"-1\n";
        return;
    }
    for(int i=0;i<n+2;i++){
        if(b[i]==orig_x){
            b[i] = -1;
            break;
        }
    }
    int cnt = 0;
    for(int i =0;i<n+2;i++) if(b[i]==-1) cnt+=1;
    if(cnt<2) {
        cout<<"-1\n";
        return;
    }
     for(int i =0;i<n+2;i++){
        if(b[i]!=-1) cout<<b[i]<<' ';
     }
    //cout<<orig_x<<" "<<sum_a;
    cout<<'\n';
}

int main(){
  FastIO;
  int t = 1;
  if(cases) cin>>t;
  while(t--){
     SolveCase();
  }
  return 0;
} 
/*

3
1 1 1 1 2

*/