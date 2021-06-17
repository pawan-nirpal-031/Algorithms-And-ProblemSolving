// Problem Link : https://codeforces.com/contest/1538/problem/B
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

Polycarp has n friends, the i-th of his friends has ai candies. Polycarp's friends do not like when they have different numbers of candies. In other words they want all ai to be the same. To solve this, Polycarp performs the following set of actions exactly once:

Polycarp chooses k (0≤k≤n) arbitrary friends (let's say he chooses friends with indices i1,i2,…,ik);
Polycarp distributes their ai1+ai2+…+aik candies among all n friends. During distribution for each of ai1+ai2+…+aik candies he chooses new owner. That can be any of n friends. Note, that any candy can be given to the person, who has owned that candy before the distribution process.
Note that the number k is not fixed in advance and can be arbitrary. Your task is to find the minimum value of k.

For example, if n=4 and a=[4,5,2,5], then Polycarp could make the following distribution of the candies:

Polycarp chooses k=2 friends with indices i=[2,4] and distributes a2+a4=10 candies to make a=[4,4,4,4] (two candies go to person 3).
Note that in this example Polycarp cannot choose k=1 friend so that he can redistribute candies so that in the end all ai are equal.

For the data n and a, determine the minimum value k. With this value k, Polycarp should be able to select k friends and redistribute their candies so that everyone will end up with the same number of candies.

*/

void Solve(){
    int n;
    cin>>n;
    int a[n];
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n!=0){
        cout<<-1<<'\n';
        return;
    }
    int x = sum/n;
    int count =0;
    for(int i =0;i<n;i++) if(a[i]>x) count+=1;
    cout<<count<<'\n'; 
}

int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--) Solve();
  return 0;
} 
// If Solved Mark (0/1) here => []