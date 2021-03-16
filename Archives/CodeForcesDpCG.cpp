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
 
/*
    Contest about DP
    https://codeforces.com/gym/302977
*/
 
 
// void Problem1(){
//    int n;
//    cin>>n;
//    ll dp[n+1]; // Dp solution 
//    dp[0]=1;
//    dp[1]=0;
//    for(int i = 2;i<=n;i++){
//        dp[i] = 2*dp[i-2];
//    }
//    cout<<dp[n]<<endl;
//     //cout<<(n&1?0:(1<<(n/2))); // direct solution
// }
 
// void Problem2(){
//     /*
 
//     Recently, Norge found a string s=s1s2…sn consisting of n lowercase Latin letters. As an exercise to improve his 
//     typing speed, he decided to type all substrings of the string s. Yes, all n(n+1)2 of them!
//     A substring of s is a non-empty string x=s[a…b]=sasa+1…sb (1≤a≤b≤n). For example, "auto" and "ton" are substrings of "automaton".
//     Shortly after the start of the exercise, Norge realized that his keyboard was broken, namely, he could use only k Latin letters c1,c2,…,ck out of 26.
//     After that, Norge became interested in how many substrings of the string s he could still type using his broken keyboard. Help him to find this number.
 
//     Input
//     The first line contains two space-separated integers n and k (1≤n≤2⋅105, 1≤k≤26) — the length of the string s and the number of Latin letters still available on the keyboard.
//     The second line contains the string s consisting of exactly n lowercase Latin letters.
//     The third line contains k space-separated distinct lowercase Latin letters c1,c2,…,ck — the letters still available on the keyboard.
//     Output Print a single number — the number of substrings of s that can be typed using only available letters c1,c2,…,ck.
 
//     ex : 
//        s = abacaba, keyboard = ab
//        1110111 <- typeable or not
 
//         dp[i] = length of substring ending at i if i is typeable from the first char typeable in this substring 
//         ex 
//         s =  abacabaaa
//         dp = 123012345
 
//         ans = sum(dp[i])
 
//     */
//     int n,k;
//     cin>>n>>k;
//     string s;
//     cin>>s;
//     vector<bool>can(26,0);
//     for(int i =0;i<k;i++){
//         char c;
//         cin>>c;
//         can[c-'a']=1;
//     }
//     vector<bool>stype(n,0);
//     for(int i=0;i<n;i++){
//         stype[i] = can[s[i]-'a'];
//     }
//     vector<ll>dp(n+1,0);
//     dp[0]=0;
//     ll ans =0;
//     for(int i =1;i<=n;i++){
//         if(stype[i-1]){
//             dp[i] = 1+dp[i-1];
//             ans+=dp[i];
//         }
//     }
//     cout<<ans;
// }
 
// ll dp[1001][8];
// ll n;
 
// ll CalculateMinCost(vector<pair<ll,ll>>&data,ll currjuice,ll currvit){
    
//     if(currvit==7){
//         return 0;
//     }
 
//     if(currjuice==n){
//         return Mod;
//     }
    
//     if(dp[currjuice][currvit]==-1  or currvit==data[currjuice].second ){
//         dp[currjuice][currvit] = CalculateMinCost(data,currjuice+1,currvit);
//     }
//     if(currvit==data[currjuice].second){
//         return dp[currjuice][currvit];
//     }
    
//     ll newvit = currvit|data[currjuice].second;
//     if(dp[currjuice][newvit]==-1 or newvit==data[currjuice].second){
//         dp[currjuice][newvit] = data[currjuice].first+CalculateMinCost(data,currjuice+1,currvit|newvit);
//     }
//     return min(dp[currjuice][currvit],dp[currjuice][newvit]);
// }
 
// void Probelem3(){
//   /*
//     Berland shop sells n kinds of juices. Each juice has its price ci. Each juice includes some set of vitamins in it. 
//     There are three types of vitamins: 
//     vitamin "A", vitamin "B" and vitamin "C". Each juice can contain one, two or all three types of vitamins in it.
//     Petya knows that he needs all three types of vitamins to stay healthy. 
//     What is the minimum total price of juices that Petya has to buy to obtain all three vitamins? 
//     Petya obtains some vitamin if he buys at least one juice containing it and drinks it.
//     InputThe first line contains a single integer n (1≤n≤1000) — the number of juices.
//     Each of the next n lines contains an integer ci (1≤ci≤100000) and a string si — the price of the i-th juice and the vitamins it contains. String si contains from 1 to 3 characters, and the only possible characters are "A", "B" and "C". It is guaranteed that each
//     letter appears no more than once in each string si. The order of letters in strings si is arbitrary.
//     Output
//     Print -1 if there is no way to obtain all three vitamins. Otherwise print the minimum total price of juices that Petya has to buy to obtain all three vitamins.
 
//     example of bitmask dp ( do we have a or not (0/1) do we have b or not(0/1) lly for c)
//     so dp state could be dp[0/1][0/1][0/1] but we could rep it like a mask 011 -> 5 meaning we have b and c but not a 
//     and ofc we need to have n as a state too, so ans = dp(n,111 or 7) minimum cost to have all three vitamins with given n strings (vitamin strings)
 
//     rec 1) f(i,mask) = min(f(i+1,mask), f(i+1, mask | M   ) + cost[i+1] ) // min(do not take this , take it) M is the mask for i+1 th vitamin string
 
//   */
 
 
//     cin>>n;
//     vector<pair<ll,ll>>data(n,{0,0});
//     for(ll i =0;i<n;i++){
//         ll cost;
//         cin>>cost;
//         bitset<3>vits;
//         string vit;
//         cin>>vit;
//         for(char v : vit){
//             if(v=='A'){
//                 vits.set(0);
//             }
//             if(v =='B'){
//                 vits.set(1);
//             }
//             if(v=='C'){
//                 vits.set(2);
//             }
//         }
//         data[i] = {cost,vits.to_ulong()};
//     }
//     memset(dp,-1,sizeof(dp));
//     ll ans = CalculateMinCost(data,0,0);
//     cout<<((ans==Mod)?-1:ans);
// }
 

// void Probelem4(){
//     ll n;
//     cin>>n;
//     ll a[n];
//     for(int i =0;i<n;i++){
//         cin>>a[i];
//     }
//     int l = 0;
//     int r = n-1;
//     if(n&1){
//         while(l!=r){
//             cout<<a[l]<<' '<<a[r]<<' ';
//             l++;
//             r--;
//         }
//         cout<<a[l]<<' ';
//     }else{
//         while(r!=l+1){
//             cout<<a[l]<<' '<<a[r]<<' ';
//             l++;
//             r--;
//         }
//         cout<<a[l]<<' '<<a[r]<<' ';
//     }
//     cout<<"\n";

// }

ll n,k;
vector<bool>stat;
vector<ll>val;
// ll dp[1000LL][2][1000LL];

ll LecSleep(ll curr,int use,ll k){

    /*
Your friend Mishka and you attend a calculus lecture. Lecture lasts n minutes. Lecturer tells ai theorems during the i-th minute.

Mishka is really interested in calculus, though it is so hard to stay awake for all the time of lecture. You are given an array t of Mishka's behavior. If Mishka is asleep during the i-th minute of the lecture then ti will be equal to 0, otherwise it will be equal to 1. When Mishka is awake he writes down all the theorems he is being told — ai during the i-th minute. Otherwise he writes nothing.

You know some secret technique to keep Mishka awake for k minutes straight. However you can use it only once. You can start using it at the beginning of any minute between 1 and n - k + 1. If you use it on some minute i then Mishka will be awake during minutes j such that  and will write down all the theorems lecturer tells.

You task is to calculate the maximum number of theorems Mishka will be able to write down if you use your technique only once to wake him up.

Input
The first line of the input contains two integer numbers n and k (1 ≤ k ≤ n ≤ 105) — the duration of the lecture in minutes and the number of minutes you can keep Mishka awake.

The second line of the input contains n integer numbers a1, a2, ... an (1 ≤ ai ≤ 104) — the number of theorems lecturer tells during the i-th minute.

The third line of the input contains n integer numbers t1, t2, ... tn (0 ≤ ti ≤ 1) — type of Mishka's behavior at the i-th minute of the lecture.
    */
    if(curr==n-1){
        if(k){
            return  val[curr];
        }else{
           return (stat[curr]?val[curr]:0);
        }
    }
    if(k){
        if(use){
            return val[curr]+LecSleep(curr+1,use,k--);
        }else{
            return (stat[curr]?val[curr]:0) + max(LecSleep(curr+1,use,k),LecSleep(curr+1,use^1,k));
        }
    }else{
        return (stat[curr]?val[curr]:0) + LecSleep(curr+1,use,k);
    }
}

void LecsleepDpSoln(){
    ll n,k;
    cin>>n>>k;
    ll val[n];
    int stat[n];
    for(ll &x : val){
        cin>>x;
    }
    for(int &b : stat){
        cin>>b;
    }
    ll p[n];
    ll s[n];
    ll prfx[n];
    p[0] = val[0]*stat[0];
    prfx[0] = val[0];
    s[n-1] = val[n-1]*stat[n-1];
    for(int i=1;i<n;i++){
        p[i] = p[i-1]+val[i]*stat[i];
        prfx[i] = prfx[i-1]+val[i];
    }
    for(ll i = n-2;i>=0;i--){
        s[i] = s[i+1]+val[i]*stat[i];
    }
    ll ans =0;
    for(int i =0;i+k-1<n;i++){
       ll winsum =0;
       ll curr =0;
       if(i>0) curr+=p[i-1];
       if(i+k<n) curr+=s[i+k];
       if(i>0) winsum-=prfx[i-1];
       winsum+=prfx[i+k-1];
       curr+=winsum;
       ans = max(ans,curr);
    }
    cout<<ans;
}

ll dp[103][3];

ll VactionsUtil(vector<int>&stat,int len,int day,int last){
    if(day>=len){
        return 0;
    }
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    if(stat[day]==0){
        dp[day][last] = 1+VactionsUtil(stat,len,day+1,0);
    }else{
        if(stat[day]==1){
            if(stat[day]==last){
                dp[day][last] = 1+VactionsUtil(stat,len,day+1,0);
            }else{
                dp[day][last] = VactionsUtil(stat,len,day+1,1);
            }
        }else if(stat[day]==2){
            if(stat[day]==last){
                dp[day][last] = 1+VactionsUtil(stat,len,day+1,0);
            }else{
                dp[day][last] = VactionsUtil(stat,len,day+1,2);
            }
        }else{
            ll gym = ((last==2)?INT64_MAX:VactionsUtil(stat,len,day+1,last));
            ll contest = ((last==1)?INT64_MAX:VactionsUtil(stat,len,day+1,last));
            dp[day][last] = min(gym,contest);
        }
    }
    return dp[day][last];
}


void Vacations(){
    ll n;
    cin>>n;
    vector<int>stat(n,0);
    for(int i=0;i<n;i++){
        cin>>stat[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<VactionsUtil(stat,n,0,stat[0]);
}


int main(){
  FastIO;
  Vacations();
  return 0;

}
// g++ CodeForcesDpCG.cpp