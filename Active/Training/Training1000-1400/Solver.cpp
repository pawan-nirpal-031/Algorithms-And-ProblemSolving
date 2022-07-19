#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Pair(a,b) make_pair(a,b)
#define Point(x) std::fixed<<setprecision(6)<<x
#define SetBits(x) __builtin_popcount(x);
#define Case(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"Yes\n":"No\n"));



void CoronavirusSpread(){
  int n;
  cin>>n; 
  int a[n]; 
  for(int &x : a) cin>>x; 
  int component[13] = {0}; 
  component[a[0]] =1; 
  for(int i =1;i<n;i++){ 
    component[a[i]] = component[a[i-1]] + (a[i]-a[i-1]>2);
  }
  int freq[20] = {0}; 
  int mx = 0; 
  int mn = 100;
  for(int i =0;i<13;i++){ 
    if(component[i]==0) continue;
    freq[component[i]]+=1;
  }
  for(int i =0;i<13;i++){
    if(freq[i]==0) continue;
    mx = max(mx,freq[i]); 
    mn = min(mn,freq[i]);
  }
  cout<<mn<<' '<<mx<<'\n';
}



void SubAnagrams(){ // https://www.codechef.com/submit/SUBANAGR
    int n;
    cin>>n; 
    vector<int>exist(26,0);
    vector<int>count(26,10000);
    for(int i =0;i<n;i++){
        string s;
        cin>>s; 
        vector<int>local_freq_tab(26,0);
        for(char c : s) local_freq_tab[c-'a']+=1;
        for(int i =0;i<26;i++){
            if(local_freq_tab[i]==0) continue;
            exist[i]+=1; 
            count[i] = min(count[i],local_freq_tab[i]);
        }
    }
    string ans; 
    for(int i =0;i<26;i++){
        if(exist[i]==n){
            for(int j =0;j<count[i];j++) ans+=('a'+i);
        }
    }
    if(ans.size()) cout<<ans<<'\n';
    else cout<<"no such string\n";
}



void DailyTrain(){
  int k,n; 
  cin>>k>>n;
  vector<ll>factorial(11,0);
  factorial[0] = factorial[1] = 1; 
  for(int i = 2;i<=10;i++) factorial[i] = i*factorial[i-1]; 
  vector<vector<int>>train(n,vector<int>(54,0)); 
  for(int i =0;i<n;i++){
    string s;
    cin>>s; 
    for(int j =0;j<54;j++) train[i][j] = s[j]-'0';
  }
  ll ways =0; 
  for(int car =0;car<n;car++){
    for(int comp =0;comp<9;comp++){
      int occupied = train[car][4*comp] + train[car][4*comp+1] + train[car][4*comp+2] + train[car][4*comp+3] + (train[car][53-2*comp]+train[car][52-2*comp]); 
      int free = 6 - occupied;   
      if(free>=0 and free>=k){
        ways+=(ll)(factorial[free]/(factorial[k]*factorial[free-k]));
      }
    }
  }
  cout<<ways;
}

void GoodSet(){
  vector<int>good(502,1);
  vector<int>sets;
  good[0] =0;
  sets.push_back(1); 
  sets.push_back(2); 
  for(int i = 3;i<=500;i++){
    for(int j = 1;j<=(i/2);j++){
      int n = j; 
      int m = i-j; 
      if(n==m) continue;
      if(good[n] and good[m]) good[i] =0; 
    } 
    if(good[i]) sets.push_back(i);
  } 
  int t; 
  cin>>t; 
  while(t--){
    int n;
    cin>>n; 
    for(int i =0;i<n;i++){
      cout<<sets[i]<<' ';
    }
    cout<<'\n';
  }
}


void ChefAndSubset(){
  int t; 
  cin>>t; 
  while(t--){
    int a[4]; 
    for(int i =0;i<4;i++) cin>>a[i]; 
    bool yes = 0;
    for(int i =1;i<16;i++){
      int sum =0;
      int x = i; 
      int indx =0;
      while(x){
        if(x&1){
          sum+=a[indx];
        }
        indx+=1; 
        x>>=1;
      }
      if(sum==0) yes = 1;
      if(yes) break; 
    }
    Status(yes);
  }
}


void LittleChefAndSums(){
  int n;
  cin>>n; 
  ll a[n]; 
  ull prefix[n] = {0}; 
  for(int i =0;i<n;i++){
    cin>>a[i]; 
    prefix[i] = a[i]+((i>0)?prefix[i-1]:0);
  }
  ull suffix[n] = {0}; 
  ull min_val = 1000000000000; 
  for(int i = n-1;i>=0;i--){
    suffix[i] = a[i]+(i<n-1?suffix[i+1]:0);
    min_val = min(min_val,prefix[i]+suffix[i]);
  }
  for(int i =0;i<n;i++){
    if(prefix[i]+suffix[i]==min_val){
      cout<<i+1<<'\n'; 
      return;    
    }
  }
}

int main(){
  FastIO;
  int t;
  cin>>t; 
  while(t--) LittleChefAndSums();
  return 0;
} 
