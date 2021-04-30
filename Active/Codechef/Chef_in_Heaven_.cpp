// Problem Link : https://www.codechef.com/LTIME95C/problems/CCHEAVEN
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

When Chef was born, his parents took him to the famous monk Doctor Strange to know whether he will land himself in heaven after his life or not. According to Strange, Chef will live for L years in total. If he wants to go to heaven, he must spend at least 50% of his life years doing good deeds. He also shows them his future using a string S of length L where Si=0 means the i-th year will be counted as bad as per the rule books of heaven and Si=1 means the i-th year will be counted as good.

Also, Strange can use his special powers to make Chef end his life earlier than that planned by god, i.e, he can choose some L′ (1≤L′≤L) and make him live for only L′ years. Strange wants Chef to succeed, so if there is any choice of L′ that allows Chef to go to heaven, he will do so.

Tell whether Chef can go to heaven.

*/

void SolveCase(){
    int total;
    cin>>total;
    int good =0;
    bool flag =0;
    for(int life =1;life<=total;life++){
        char c;
        cin>>c;
        if(c-'0') good+=1;
        if(good>=(life-good)) flag=1;
    }
    Status(flag);
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
// If Solved Mark (0/1) here => []