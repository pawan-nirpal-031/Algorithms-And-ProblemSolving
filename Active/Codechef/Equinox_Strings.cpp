// Problem Link : 
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

Sarthak and Anuradha are very good friends and are eager to participate in an event called Equinox. It is a game of words. In this game, N strings S1,…,SN are given. For each string Si, if it starts with one of the letters of the word “EQUINOX”, Sarthak gets A points and if not, Anuradha gets B points. The one who has more points at the end of the game wins. If they both the same number of points, the game is a draw..

Print the winner of the game, if any, otherwise print “DRAW”.

*/

bool CharExists(char c){
    string eqi = "EQUINOX";
    for(char x : eqi) if(c==x) return 1;
    return 0;
}

void Solvecase(){
    int n;
    ll a,b;
    cin>>n>>a>>b;
    ll sarthk =0;
    ll anur = 0;
    while(n--){
        string s;
        cin>>s;
        if(CharExists(s[0])) sarthk+=a;
        else anur+=b;
    }
    if(sarthk>anur) cout<<"SARTHAK\n";
    else if(sarthk<anur)cout<<"ANURADHA\n";
    else cout<<"DRAW\n";
}


int main(){
  FastIO;
  int t;
  cin>>t;
  while(t--){
      Solvecase();
  }
  return 0;
} 
// If Solved Mark (0/1) here => []