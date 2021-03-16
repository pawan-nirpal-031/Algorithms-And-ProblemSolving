#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a) x=0;
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAns(b) cout<<(b?"Yes\n":"No\n"); 

ll Gcd(ll a,ll b){
    return ((a==0)?b:Gcd(b%a,a));
}

ll Lcm(ll a,ll b){
    return (a*b)/Gcd(a,b);
}

void ReplacingElements(){
    int n,d;
    cin>>n>>d;
    vector<int>v(n,0);
    for(int &x : v) cin>>x;
    sort(v.begin(),v.end());
    bool yes =1;
    for(int i = 2;i<n;i++){
        if(v[i]>d and v[0]+v[1]>d){
            BoolAns(0);
            return;
        }
    }
    BoolAns(1);
}

void TwoSeqs(){
    ll n;
    cin>>n;
    ull a[n],b[n];
    for(ull &x : a) cin>>x;
    for(ull &x : b) cin>>x;
    ull dp[n];
    dp[0] = a[0]*b[0];
    ull prefix[n];
    prefix[0] = a[0];
    for(ll i =1;i<n;i++) prefix[i] = max(a[i],prefix[i-1]);
    cout<<dp[0]<<"\n"; 
    for(ll i =1;i<n;i++){
        dp[i] = max(dp[i-1],b[i]*prefix[i]);
        cout<<dp[i]<<"\n";
    }
}

string GetUnit(string s,int l){
    string ans ="";
    for(int i =0;i<l;i++){
        ans+=s;
    }
    return ans;
}



void StringLcm(){
    string s,t;
    cin>>s>>t;
    int ls = s.length();
    int lt = t.length();
    int gcd = Gcd(ls,lt);
    string o1 = GetUnit(s,lt/gcd);
    string o2 = GetUnit(t,ls/gcd);
    if(o1==o2){
        cout<<o1<<"\n";
    }else{
        cout<<"-1"<<endl;
    }
}

int main(){
    FastIO;


    return 0;
}