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
#define BoolAns(b) cout<<(b?"Yes\n":"No\n"); 
#define ConsoleLog(a) for(auto x : a) cout<<x<<" ";


ll SumofDigitsCubed(ll n){
    ll ans =0;
    while(n>0){
        ans+=(n%10);
        n/=10;
    }
    return (ans*ans*ans);
}

int n;
vector<vector<ll>>dp(5005,vector<ll>(5005,-1));

ll TrainingUtil(vector<ll>&exp,vector<ll>&trainings,int curr_city,int training_no){
    if(curr_city==exp.size()) return 0;
    if(dp[curr_city][training_no]!=-1) return dp[curr_city][training_no];

    ll train_now = TrainingUtil(exp,trainings,curr_city+1,training_no+1);
    ll fight_now = exp[curr_city]*trainings[training_no] + TrainingUtil(exp,trainings,curr_city+1,training_no);
    return dp[curr_city][training_no] = max(train_now,fight_now);
}

void Training(){
    cin>>n;
    vector<ll>trainings(n,0);
    cin>>trainings[0];
    vector<ll>exp(n,0);
    for(int i =0;i<n;i++){
        cin>>exp[i];
        if(i>0) trainings[i] = trainings[i-1]+SumofDigitsCubed(trainings[i-1]);
    }

    cout<<TrainingUtil(exp,trainings,0,0);

}    


int main(){
    FastIO;
    
    return 0;
}