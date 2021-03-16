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
#define GoogleOutput(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define BoolAnsCall(b) (cout<<(b?"Yes\n":"No\n"));

ll Gcd(ll a,ll b){
    return ((a==0)?b:Gcd(b%a,a));
}

ll Lcm(ll a,ll b){
    return (a*b)/Gcd(a,b);
}


void Slots(){
    string s;
    cin>>s;
    cout<<((s[0]==s[1]) and (s[0]==s[2])?"Won":"Lost");
}

void Alcholoic(){
    int n;
    ll x;
    cin>>n>>x;
    vector<pair<int,int>>v(n,{0,0});
    for(int i =0;i<n;i++) cin>>v[i].first>>v[i].second;
    int acc = 0;
    x*=100;
    for(int i =0;i<n;i++){
        acc+=(v[i].first*v[i].second);
        if(acc>x){
            cout<<i+1;
            return;
        }
    }
    cout<<-1;
    return;
}

void  MandarinOrange(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++) cin>>a[i];
    int ans = 0;
    for(int left =0;left<n;left++){
        int x = a[left];
        for(int right = left;right<n;right++){
            x = min(x,a[right]);
            ans = max(ans,x*(right-left+1));
        }
    }
    cout<<ans;
}


int main(){
  FastIO;
  
  return 0;
} 
