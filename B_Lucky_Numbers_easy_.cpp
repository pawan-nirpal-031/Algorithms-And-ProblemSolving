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

class MathModule{
  public:
    ull Gcd(ull a,ull b){
        return (a%b==0?b:Gcd(b,a%b));
    }

    ll Lcm(ll a,ll b){
        return (a*b)/Gcd(a,b);
    }

    ll Pow(ll a,ll n){
      if(n==1) return a;
      ll half = Pow(a,n>>1);
      return (n&1?half*half*a:half*half);
    }
    ll ModuloExpo(ll a,ll n,ll m){
      if(n==1) return a%m;
      ll half = ModuloExpo(a,n>>1,m)%m;
      if(n&1){
        return (((half*half)%m)*(a%m))%m;
      }else{
        return (half*half)%m;
      }
    }
};


bool IsSuperLucky(ll x){
    int fourc =0;
    int sevc =0;
    while(x>0){
        int d = x%10;
        if(d==4) fourc+=1;
        if(d==7) sevc+=1;
        x/=10;
    }
    return (fourc==sevc and fourc>0);
}

ll n;
vector<ll>luckyNums;
void GenrateAllPossibleSuperLucky(ll curr_val,int no_sevens,int no_fours){
    if(curr_val>10000000000LL){
        return;
    }
    if(no_fours==no_sevens){
        luckyNums.emplace_back(curr_val);
    }
    GenrateAllPossibleSuperLucky(curr_val*10+4,no_sevens,no_fours+1);
    GenrateAllPossibleSuperLucky(curr_val*10+7,no_sevens+1,no_fours);
    return;
}

ll BinarySearch(vector<ll>&s,ll k,ll left,ll right){
  ll mid = (left+right)>>1;
  if(s[mid]>=k and s[mid-1]<k){
      return mid;
  }else if(s[mid]>k and s[mid-1]==k){
      return mid-1;
  }else if(s[mid]>k and s[mid-1]>k){
      return BinarySearch(s,k,left,mid);
  }
  return BinarySearch(s,k,mid,right);
}

int main(){
  FastIO;
  cin>>n;
  GenrateAllPossibleSuperLucky(0,0,0);
  sort(luckyNums.begin(),luckyNums.end());
  ll left = 0;
  ll right = luckyNums.size();
  cout<<luckyNums[BinarySearch(luckyNums,n,left,right)];
  return 0;
} 