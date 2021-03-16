#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iterator>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define MOD 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define forit0(i,n) for(ll i =0;i<n;i++)
#define forit(i,l,r) for(ll i =l;i<=r;i++) // run in inclusive range [l to r]
#define setA0(a) for(ull i =0;i<n;i++){a[i] = 0;}
#define aout(a) for(auto x : a){cout<<x<<' ';} // array output macro 
#define ain(a) for(ull i =0;i<n;i++){cin>>a[i];} //array input macro
#define getl(s) getline(cin,s);
#define nofSetBits(x) __builtin_popcount(x);
#define inGrph(g,e) while(e--){ll x;ll y;cin>>x>>y ;g[x].pub(y);g[y].pub(x);}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll tests; 
   cin>>tests;
   while(tests--){
       ll chfpr,rkpwr;
       cin>>chfpr>>rkpwr;
       ll chfdig =0,rkdig = 0;
       if(chfpr%9==0){
           chfdig = chfpr/9;
       }else{
           chfdig = chfpr/9 +1;
       }
       if(rkpwr%9==0){
           rkdig = rkpwr/9;
       }else{
           rkdig = rkpwr/9+1;
       }
       if(chfdig<rkdig){
           cout<<0<<' '<<chfdig<<'\n';
       }else{
           cout<<1<<' '<<rkdig<<'\n';
       }
   }    
   
    return 0;
}