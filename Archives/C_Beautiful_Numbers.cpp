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
#define Print(x) cout<<x
#define Input(x) cin>>x


int a,b,n;

bool ExcellentNum(ll num){
    int sum_of_digs = 0;
    int digs[2] = {a,b};
    while(num>0){
        int d = num%10;
        if(d==digs[0] or d==digs[1]){
            sum_of_digs+=d;
        }else{
            return 0;
        }
        num/=10;
    }
    while(sum_of_digs>0){
        int d = sum_of_digs%10;
        if(digs[0]==d or digs[1]==d){
            sum_of_digs/=10;
        }else{
            return 0;
        }
    }
    return 1;
}

// ll cache[100005];

// ll CountOfBeauNums(int pos,ll sum_so_far){
//     if(pos==n){
//         bool rs =  ExcellentNum(sum_so_far);
//         if(rs){
//             cout<<sum_so_far<<'\n';
//             return 1;
//         }
//         return 0;
//     }
//     ll place_a = CountOfBeauNums(pos+1,sum_so_far+a);
//     ll place_b = CountOfBeauNums(pos+1,sum_so_far+b);
//     return place_a+place_b;
// }

// int main(){
//   FastIO;
//   cin>>a>>b>>n;
//    Print(CountOfBeauNums(0,0));
   
//   return 0;
// } 