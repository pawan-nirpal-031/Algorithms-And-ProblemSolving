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


void twoten(){
    ll x;
    cin>>x;
    if(x%5!=0){
        cout<<"-1\n";
    }else{
        if(x%2==0){
            cout<<"0\n";
        }else{
            cout<<"1\n";
        }
    }
}

void rectangle(){
    vector<int>v(4,0);
    for(int &x : v){
        cin>>x;
    }
    sort(v.begin(),v.end());
    if(v[0]==v[1] and v[2]==v[3]){
        BoolAnsCall(1);
    }else{
        BoolAnsCall(0);
    }
}

void MaximumRemaining(){
    ll n;
    cin>>n;
    vector<ll>a(n,0);
    for(ll &x : a){
        cin>>x;
    }
    sort(a.begin(),a.end());
    if(a[0]==a[n-1]){
        cout<<0;
    }else{
        ll secondmax = a[n-1];
        for(int i = n-1;i>=0;i--){
            if(a[i]!=secondmax){
                secondmax = a[i];
                break;
            }
        }
        cout<<secondmax;
    }

}


void PLUSMULTIPLY(){ // https://www.codechef.com/problems/PLMU
/*
Chef has a sequence A1,A2,…,AN. 
He needs to find the number of pairs (i,j) (1≤i<j≤N) such that Ai+Aj=Ai⋅Aj.

Ai = Aj/(Aj-1) solve this get 1/Ai+1/Aj = 1 ie hyperbola there exits only 2 solutions eiter 0 or 2 
so ans = pairs(0) + pairs(2) and pairs(i) = i*(i-1)/2 

*/
    int n;
    cin>>n;
    ll two =0;
    ll zero =0;
    while(n--){
        ll x;
        cin>>x;
        if(x==2){
            two++;
        }
        if(x==0){
            zero++;
        }
    }
    cout<<(((two*(two-1))>>1)+((zero*(zero-1))>>1))<<'\n';
}

void TwoSum(){
    ll n,k;
    cin>>n>>k;
    unordered_multimap<ll,ll>table;
    for(int i =0;i<n;i++){
        ll x;
        cin>>x;
        table.insert({x,i}); 
    }
    for(auto p : table){
        auto ptr = table.find(k-p.first);
        if(ptr!=table.end() and ptr->second!=p.second){
            BoolAnsCall(1);
            return;
        }
    }
    BoolAnsCall(0);
    return;
}

void NofCoins(){
    int coins[6] = {100,50,10,5,2,1};
    ll n;
    cin>>n;
    ll cnt =0;
    for(int i=0;i<6;i++){
        while(n-coins[i]>=0){
            cnt++;
            n-=coins[i];
        }
    }
    cout<<cnt<<endl;
}

int main(){
    FastIO;
    int t;
    cin>>t;
    while(t--){
       NofCoins();
    }
    
    return 0;
}



// g++ CodeChefPracticeFile.cpp