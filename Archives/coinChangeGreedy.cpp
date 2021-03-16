#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
#define pub(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    ll coins[6] = {100,50,10,5,2,1};
    while(t--){
        ll n;
        cin>>n;
        ll c=0;
        for(int i =0;i<6;i++){
            while(n>=coins[i]){
                c++;
                n-=coins[i];
            }
        }
        cout<<c<<'\n';
    }
    return 0;
}
