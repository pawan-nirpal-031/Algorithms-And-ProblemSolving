// Problem Link : https://codeforces.com/contest/978/problem/C
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

There are n dormitories in Berland State University, they are numbered with integers from 1 to n. Each dormitory consists of rooms, there are ai rooms in i-th dormitory. The rooms in i-th dormitory are numbered from 1 to ai.

A postman delivers letters. Sometimes there is no specific dormitory and room number in it on an envelope. Instead of it only a room number among all rooms of all n dormitories is written on an envelope. In this case, assume that all the rooms are numbered from 1 to a1+a2+⋯+an and the rooms of the first dormitory go first, the rooms of the second dormitory go after them and so on.

For example, in case n=2, a1=3 and a2=5 an envelope can have any integer from 1 to 8 written on it. If the number 7 is written on an envelope, it means that the letter should be delivered to the room number 4 of the second dormitory.

For each of m letters by the room number among all n dormitories, determine the particular dormitory and the room number in a dormitory where this letter should be delivered.v

*/
int GetIndx(ull prefix[],ull e,int n){
    ll left = 0;
    ll right = n-1;
    int ans = n-1;
    while(left<=right){
        ll mid = ((right+left)>>1);
        if(prefix[mid]<e){
            left = mid+1;
        }else{
            ans = mid;
            right = mid-1;
        }
    }
    return ans;
}

int main(){
  FastIO;
  int n,q;
  cin>>n>>q;
  ull a[n];
  ull prefix[n];
  for(int i =0;i<n;i++){
      cin>>a[i];
      prefix[i] = ((i>0)?prefix[i-1]+a[i]:a[0]);
  }
  while(q--){
      ull x;
      cin>>x;
      ull dorm = GetIndx(prefix,x,n);
      ull room = x - (dorm>0?prefix[dorm-1]:0);
      cout<<dorm+1<<" "<<room<<'\n';
  }
  return 0;
} 
// If Solved Mark (0/1) here => [1]