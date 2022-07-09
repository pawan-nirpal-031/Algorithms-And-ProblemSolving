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
    ll count = 2*n;
    ll a[count]; 
    int odd =0; 
    vector<ll>evens;
    for(int i =0;i<count;i++){
        cin>>a[i];
        odd+=(a[i]&1);
        if(a[i]%2==0) evens.push_back(a[i]);  
    }
    int even = count - odd; 
    if(even==odd) cout<<0; 
    else if(odd>even){
        cout<<odd-n;
    }else{
        int k = even-n;  
        vector<int>bag;
        for(int i=0;i<evens.size();i++){
            ll x = evens[i]; 
            int twocount =0; 
            while(x%2==0){
                twocount++; 
                x>>=1;
            } 
            bag.push_back(twocount);
        } 
        int ans =0;
        sort(bag.begin(),bag.end()); 
        for(int i=0;i<k;i++) ans+=bag[i];
        cout<<ans;
    }
    cout<<'\n';
  }
  return 0;
} 
