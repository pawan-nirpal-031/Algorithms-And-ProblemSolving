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
#define BoolAns(b) cout<<(b?"YES\n":"NO\n"); 
#define Print(x) cout<<x
#define Input(x) cin>>x
#define ConsoleLog(a) for(auto x : a) cout<<x<<" ";


void KingEscape(){
  int n;
  cin>>n;
  int qx,qy;
  cin>>qx>>qy;
  int kx,ky;
  cin>>kx>>ky;
  int dx,dy;
  cin>>dx>>dy;
  if( (( (qy-dy)<0 and (qy-ky<0)) and (qx-dx<0 and qx-kx<0) ) or (( (qy-dy)<0 and (qy-ky<0)) and (qx-dx>0 and qx-kx>0) ) or (( (qy-dy)>0 and (qy-ky>0)) and (qx-dx<0 and qx-kx<0) ) or (( (qy-dy)>0 and (qy-ky>0)) and (qx-dx>0 and qx-kx>0) )  ){
      BoolAns(1);
  }else{
      BoolAns(0);
  }
}


void BmailCompNet(){
  int n;
  cin>>n;
  vector<int>par(n+1,0);
  for(int i = 2;i<=n;i++){
    cin>>par[i];
  }
  par[1] = 1;
  vector<int>path;
  path.emplace_back(n);
  
  while(par[n]!=n){
    n = par[n];
    path.emplace_back(n);
  }
  for(auto it = path.rbegin();it<path.rend();it++){
    cout<<*it<<' ';
  }
}



void IncreasingSubarrayLen(){
  ll n;
  cin>>n;
  vector<ll>v(n,0);
  for(ll &x : v) cin>>x;
  vector<ll>dp(n,1);
  for(int i =1;i<n;i++){
    if(v[i]>v[i-1]){
      dp[i] = 1+dp[i-1];
    }
  }
  ll ans = dp[0];
  for(int i =0;i<n;i++){
    ans = max(ans,dp[i]);
  }
  cout<<ans;
}

void Tiles(){
  int n;
  cin>>n;
  cout<<(2*(2*(n-1)*n -((n-1)*(n+1)))) + 2*n-1<<endl;
}

set<int> ExtractDigits(ll n){
  set<int>s;
  while(n>0){
    s.insert(n%10);
    n/=10;
  }
  return s;
}

void GreatJulyaCalendarC1(){ 
  // https://codeforces.com/problemset/problem/331/C1

  // C2 and c3 are pending for this probelem
  ull n;
  cin>>n;
  vector<ull>dp(n+1,Mod);
  dp[0] =0;
  for(ll i = 1;i<=n;i++){
    set<int>digits = ExtractDigits(i);
    for(int dig : digits){
      if(dig>0){
        dp[i] = min(dp[i],dp[i-dig]);
      } 
    }
    dp[i]++;
  }
 
  cout<<dp[n];


}

void HittheLotteryGreedy(){
  ll n;
  cin>>n;
  int ans =0;
  int coins[5] = {100,20,10,5,1};
  for(int c : coins){
    while(n-c>=0){
      n-=c;
      ans++;
    }
  }
  cout<<ans;
}

void HonestCoach(){
  int n;
  cin>>n;
  int s[n];
  for(int &x : s) cin>>x;
  sort(s,s+n);
  int ans = abs(s[n-2]-s[n-1]);
  for(int i = n-2;i>=0;i--){
    ans = min(ans,abs(s[i]-s[i+1]));
  }
  cout<<ans<<'\n';
}

int Badgeutil(vector<int>&direct,vector<bool>&vis,int a){
  if(vis[a]) return a;
  return vis[a] = 1, Badgeutil(direct,vis,direct[a]);
} 


void Badge(){
  int n;
  cin>>n;
  vector<int>direct(n+1,0);
  for(int i =1;i<=n;i++) cin>>direct[i];
  for(int a=1;a<=n;a++){
    vector<bool>vis(n+1,0);
    cout<<Badgeutil(direct,vis,a)<<" ";
  }
}

void ProtectSheep(){
  int r,c;
  cin>>r>>c;
  char g[r][c];
  vector<pair<int,int>>sheep_pos;
  for(int i =0;i<r;i++){
    for(int j =0 ;j<c;j++){
      cin>>g[i][j];
      if(g[i][j]=='S'){
        sheep_pos.emplace_back(Pair(i,j));
      }
    }
  }
  
  for(auto sh : sheep_pos){
    int x = sh.first;
    int y = sh.second;
    pair<int,int> d[4] = {{0,1},{1,0},{0,-1},{-1,0}};
    for(int i =0;i<4;i++){
      int x_ = x+d[i].first;
      int y_ = y+d[i].second;
      if(x_>=0 and x_<r and y_>=0 and y_<c){
        if(g[x_][y_]=='W'){
          BoolAns(0);
          return;
        }if(g[x_][y_]!='S'){
          g[x_][y_] = 'D';
        }
      }
    }
  }
  BoolAns(1);
  for(int i =0;i<r;i++){
    for(int j =0;j<c;j++){
      cout<<g[i][j];
    }
    cout<<'\n';
  }

}

void TheWayToHome(){ // https://codeforces.com/problemset/problem/910/A
  int n,d;
  cin>>n>>d;
  string p;
  cin>>p;
  vector<bool>lily(p.length(),0);
  for(int i =1;i<=p.length();i++) lily[i] = p[i-1]-'0';
  vector<int>dp(n+1,INT_MAX);
  dp[n] = 0;
  for(int i = n-1;i>=0;i--){
    for(int j = 1;j<=d;j++){
      if(i+j<=n and lily[i]){
        if(lily[i+j]){
          dp[i] = min(dp[i],dp[i+j]);
        }
      }
    }
    if(dp[i]!=INT_MAX) dp[i]++;
  }
  cout<<(dp[1]!=INT_MAX?dp[1]:-1)<<'\n';
}

void EvenArray(){
  int n;
  cin>>n;
  int a[n];
  int even =0;
  int odd =0;
  for(int i =0;i<n;i++){
    cin>>a[i];
    if(i&1 and a[i]%2==0){
      even++;
    }
    
    if(i%2==0 and a[i]&1){
      odd++;
    }
  }
  cout<<((odd!=even)?-1:even)<<'\n';
}


void Party(){
  int n;
  cin>>n;
  int par[n+1];
  for(int i =1;i<=n;i++){
    cin>>par[i];
    if(par[i]==-1) par[i] = i;
  }
  vector<int>heights(n+1,1);
  int ans =0;
  for(int i = n;i>=1;i--){
    int x = i;
    while(par[x]!=x){
      heights[par[x]] = max(heights[par[x]],1+heights[x]);
      x = par[x];
    }
    ans = max(ans,heights[x]);
  }
  cout<<ans;
}




void LoveTriangle(){
  int n;
  cin>>n;
  int edge[n+1];
  for(int i =1;i<=n;i++) cin>>edge[i];
  for(int i =1;i<=n;i++){
    if(edge[edge[edge[i]]]==i){
      cout<<"YES";
      return;
    }
  }
  cout<<"NO";
}


void HamsterFarm(){
  ll n,k;
  cin>>n>>k;
  vector<ll>hams(k+1,0);
  ll min_mod = 0;
  int type = 1;
  ll nums = 0;
  for(int i =1;i<=k;i++){
    cin>>hams[i];
    min_mod = n%hams[i];
    type = i;
    nums = n/hams[i];
  }
  for(int i =1;i<=k;i++){
    if(n%hams[i]<min_mod){
      min_mod = n%hams[i];
      type = i;
      nums = n/hams[i];
    }
  }
  cout<<type<<' '<<nums;
}

void  Transformation(){ // https://codeforces.com/problemset/problem/727/A
  ll a,b;
  cin>>a>>b;
 
}


vector<vector<int>>VacDp(100,vector<int>(3,-1));
int VacationUtil(int a[],int n,int i,int prev){
  if(i==n){
    return 0;
  }
  if(VacDp[i][prev]!=-1){
    return VacDp[i][prev];
  }
  int zero = 1+VacationUtil(a,n,i+1,0);
  if(a[i]==0){
    return VacDp[i][prev] =  zero;
  }else if(a[i]==1 or a[i]==2){
    return VacDp[i][prev]  = (prev==a[i]?zero:min(VacationUtil(a,n,i+1,a[i]),zero));
  }
  if(prev==0){
    return VacDp[i][prev]  = min(zero,min(VacationUtil(a,n,i+1,1),VacationUtil(a,n,i+1,2)));
  }
  return VacDp[i][prev] = min(zero,VacationUtil(a,n,i+1,prev^3));
}


void Vacation(){/* Frist Dp probelem CF 1400 */
  int n;
  cin>>n;
  int a[n];
  for(int &x : a) cin>>x;
  VacationUtil(a,n,0,0);
  cout<<VacDp[0][0];
}

void OddDivisor(){
  ull n;
  cin>>n;
  if(n%2==0 and (n&(n-1))==0){
    BoolAns(0);
  }else{
    BoolAns(1);
  }
}


void NewYearsNumber(){
  int t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    ll q = n/2020;
    int r = n%2020;
    if(q>=r and (q*2020 + r == n)){
      BoolAns(1);
    }else{
      BoolAns(0);
    }
  }
}

int Solve(int a[],int n,int x){
  int l = 0;
  int r = n-1;
  int mid;
  while(r>l+1){
    mid = (l + (r-l)/2);
    if(a[mid]<x){ 
      l = mid;
    }
    else if(a[mid]>=x) {
      r = mid;
    }
  }
 return (r+1);
}

void RepublicSubarray(){
  int n;
  cin>>n;
  int a[n];
  vector<int>dp(n,0);
  int ans = 0;
  for(int  i =0;i<n;i++){
    cin>>a[i];
    if(a[i]==1){
      dp[i] = 1;
    }
    if(i>0 and dp[i-1]>0 and (a[i] == 1+a[i-1])){
      dp[i] = 1+dp[i-1];
    }
    ans = max(dp[i],ans);
  }
  cout<<ans<<'\n';
}

void VideoGames(){
  ll inital_price,i,terminating_price,pocket_money;
  cin>>inital_price>>i>>terminating_price>>pocket_money;
  ll count = 0;
  ll current_price = inital_price;
  while(pocket_money>0){
    pocket_money-=current_price;
    if(pocket_money<0) break;
    count+=1;
    current_price = max(current_price-i,terminating_price);
  }
  cout<<count;
}

void StupidPattern(){
  int startno;
  int height;
  cin>>startno>>height;
  int curr = 1;

  for(int h = 1;h<=height;h++){
    int rowstart = startno;
    for(int c = 1;c<=curr;c++){
      cout<<rowstart<<' ';
      rowstart-=1;
    }
    cout<<'\n';
    curr+=1;
    startno+=(curr);
  }
}

ll SumOfDigitsCube(int n){
  ll ans =0;
  while(n>0){
    ans+=(n%10);
    n/=10;
  }
  return (ans*ans*ans);
}



/*

----------------------------------------------
Number theory

*/

// bool TwoDistinctPrimeDivisors(int n,vector<bool>&primes){
//   int divcount = 0;
//   for(int d =2;d<=sqrt(n);d++){
//     if(n%d==0 and primes[d]) divcount++;
//   }
//   if(divcount==2) return 1;
//   return 0;
// }

// void AlmostPrime(){
//   int n;
//   cin>>n;
//   int count = 0;
//   int lim = 3005;
//   vector<bool>primes(3005,1);
//   primes[0] = primes[1] = 0;
//   for(int i =2;i*i<=lim;i++){
//     if(primes[i]){
//       for(int j = i*i;j<=lim;j+=i){
//         primes[j] = 0;
//       }
//     }
//   }
//   for(int num = 2;num<=n;num++){
//     if(TwoDistinctPrimeDivisors(num,primes)) count++;
//   }
//   cout<<count;
// }

void DirectionalMove(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int curr_dir = 0;
  for(int i =0;i<n;i++){
    bool x = s[i]-'0';
    if(x==0){
      curr_dir = (curr_dir+1)%4;
    }else{
      curr_dir = (4+curr_dir-1)%4;
    }
  }
  char dir[4] = {'E','S','W','N'};
  cout<<dir[curr_dir]<<'\n';
}

void MakeAllOdd(){
  int n;
  cin>>n;
  int evenc = 0, oddc = 0;
  while(n--){
    ll x;
    cin>>x;
    if(x&1){
      oddc+=1;
    }else{
      evenc+=1;
    }
  }
  cout<<(oddc>0?evenc:-1)<<'\n';
}

void Team(){
  int n,k;
  cin>>n>>k;
  int s[n];
  for(int i =0;i<n;i++) cin>>s[i];
  int teams = 0;
  sort(s,s+n);
  for(int l =0, r = n-1;l<=r;){
    if(s[r]>=k){
      teams+=1;
      r-=1;
    }else if(s[r]+s[l]>=k and r!=l){
      teams+=1;
      l+=1;
      r-=1;
    }else{
      l+=1;
    }
  }
  cout<<teams<<'\n';
}

void XORGame(){
  ll a,b;
  cin>>a>>b;
  if((a^b)==(a+b)){
    BoolAns(0);
  }else{
    BoolAns(1);
  }
}

void Lecture(){
  int n,m;
  cin>>n>>m;
  unordered_map<string,string>h;
  while(m--){
    string a,b;
    cin>>a>>b;
    h.insert(Pair(a,b));
  }
  while(n--){
    string word;
    cin>>word;
    auto it = h.find(word);
    string w1= it->first;
    string w2 = it->second;
    if(w1.size()==w2.size()){
      cout<<w1<<' ';
    }else if(w1.size()>w2.size()){
      cout<<w2<<' ';
    }else{
      cout<<w1<<" ";
    }
  }
}

void BearAndRaspberry(){
  int n,c;
  cin>>n>>c;
  int a[n];
  int profit = -1000;
  for(int i =0;i<n;i++){
    cin>>a[i];
  }
  if(n==0){
    cout<<n;
    return;
  }
  for(int i =0;i<n-1;i++){
    profit = max(profit,a[i]-(a[i+1]+c));
    if(profit<0) profit = 0;
  }
  cout<<profit;
}

void valeraX(){
  int n;
  cin>>n;
  char cd;
  char x;
  string g[n];
  for(int row=0;row<n;row++){         
        cin>>g[row];
        if(row==0){
          cd = g[row][0];
        }
        if(row==0){
          x = g[row][1];
        }
    }
    if(x==cd){
      cout<<"NO";
      return;
    }
    for(int row=0;row<n;row++){      
      for(int col=0;col<n;col++){       
          if((((row==col) or (row+col==n-1)) and cd!=g[row][col]) or ((row!=col and row+col!=n-1) and x!=g[row][col])){
            cout<<"NO";
            return;
          }
      }
    }
    cout<<"YES";
}

void ValeraAndAntiqueItems(){
  int n,v;
  cin>>n>>v;
  vector<int>sellers;
  for(int i =1;i<=n;i++){
    int k;
    cin>>k;
    bool deal =0;
    while(k--){
      int p;
      cin>>p;
      if(v>p){
        deal = 1;
      }
    }
    if(deal) sellers.emplace_back(i);
  }
  cout<<sellers.size()<<'\n';
  for(int s : sellers) cout<<s<<' ';
}

void DZYLovesStrings(){
  string s;
  cin>>s;
  int k;
  cin>>k;
  int v[26];
  ll savl =0;
  int max_v = 0;
  for(int i=0;i<26;i++){
    cin>>v[i];
    max_v = max(max_v,v[i]);
  }
  for(int i =0;i<s.length();i++){
    savl+=((i+1)*(v[s[i]-'a']));
  }
  ll ul = s.length()+k;
  ll cl = s.length();
   cout<<savl+ max_v*((((ul*(ul+1)))>>1) - (((cl*(cl+1)))>>1));
  
}

void RoundHouse(){
  int n,a,b;
  cin>>n>>a>>b;
  int x = (n+a+b)%n;
  if(x==0) cout<<x+n;
  else cout<<x;
}

void KefaandFirstSteps(){
  int n;
  cin>>n;
  ll a[n];
  for(ll &x : a) cin>>x;
  vector<ll>dp(n,1);
  ll ans = 1;
  for(int i = 1;i<n;i++){
    if(a[i]>=a[i-1]){
      dp[i] = 1+dp[i-1];
    }
    ans = max(ans,dp[i]);
  }
  cout<<ans;
}

void MaximumSubarray(){
  int n;
  cin>>n;
  vector<ll>a(n,0);
  vector<ll>dp(n,0);
  for(int i =0;i<n;i++){
    cin>>a[i];
    dp[i] = a[i];
  }
  
  for(int i =0;i<n;i++){
    if(i>0) dp[i] = max(dp[i],max(a[i]+dp[i-1],dp[i-1]));
  }
  for(int i =0;i<n;i++){
    cout<<i<<' '<<dp[i]<<endl;
  }
}

void  HittheLottery(){
  ll n;
  cin>>n;
  int coins[5] = {100,20,10,5,1};
  int count = 0;
  for(int i =0;i<5;i++){
    while(n>=coins[i]){
      n-=coins[i];
      count+=1;
    }
  }
  cout<<count;
}

bool CheckKthBit(ll a,ll k){
   return (a&(1LL<<(k-1)));
}

ll const HelpBob_N = 1000005;
ll Help_bob_array[HelpBob_N];

void HelpBob(){
  int n,k;
  cin>>n>>k;  
  for(int i =0;i<n;i++){
    cin>>Help_bob_array[i];
  }
  ll ans = CheckKthBit(Help_bob_array[0],k);
  for(int i=1;i<n;i++){
    if(CheckKthBit((Help_bob_array[i]^Help_bob_array[i-1]),k)) ans+=1;
  }
  cout<<ans;
}

void MetrologyStation(){
  ll ans =0;
  ll a[7];
  for(int i =0;i<7;i++){
    cin>>a[i];
  }
  for(int i =0;i<7;i++){
    ll x;
    cin>>x;
    ans +=(abs(a[i]-x));
  }
  cout<<ans;
}

void Twins(){
  int n;
  cin>>n;
  int a[n];
  int sum =0;
  for(int &x : a){
    cin>>x;
    sum+=x;
  }
  sort(a,a+n);
  int ms =0;
  int c =0;
  for(int i = n-1;i>=0;i--){
    if(ms<=sum){
      c+=1;
      ms+=a[i];
      sum-=a[i];
    }else{
      break;
    }
  }
  cout<<c;

}

bool IsSubsequnece(string s,string t){
  int p1,p2;
  for(p2 =0,p1=0;p2<t.length() and p1<s.length();){
    if(t[p2]==s[p1]){
      p2+=1;
      p1+=1;
    }else{
      p1+=1;
    }
  }
  return (p2==t.length());
}

vector<int>LuckyNums;

void GenrateLuckyNums(int curr_no){
  if(curr_no>1000){
    return;
  }
  if(curr_no>0){
    LuckyNums.emplace_back(curr_no);
  }
  GenrateLuckyNums(10*curr_no+4);
  GenrateLuckyNums(10*curr_no+7);
}

void LuckySubstring(){
  string s;
  Input(s);
  int c4 =0;
  int c7 =0;
  for(char c : s){
    if(c-'0'==4) c4++;
    if(c-'0'==7) c7++;
  }
  if(c4==0 and c7==0){
    Print(-1);
    return;
  }else if((c4==c7 and c4>0) or (c4>c7)){
    Print(4);
  }else{
    Print(7);
  }
}

int main(){
  FastIO;
  
  return 0;
  
} 



/* 

  g++ CodeForcesPracticeSession500-1000.cpp
  ./a.exe


*/