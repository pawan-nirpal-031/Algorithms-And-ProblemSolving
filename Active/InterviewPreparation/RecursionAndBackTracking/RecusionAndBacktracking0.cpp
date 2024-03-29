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
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));
#define Print(x) cout<<x
#define Input(x) cin>>x



int MaxInArray(int a[],int i,int n){
  if(i==n-1) return a[i];
  return max(a[i],MaxInArray(a,i+1,n));
}

int MinInArray(int a[],int i,int n){
  if(i==n-1) return a[i];
  return min(a[i],MaxInArray(a,i+1,n));
}

int FirstOccurance(int a[],int x,int i,int n){
  if(i==n-1) return (a[i]==x?i:-1);
  return (a[i]==x?i:FirstOccurance(a,x,i+1,n));
}

int LastOccurance(int a[],int x,int i,int n){
  if(i==n-1){
    return (a[i]==x?i:-1);
  }
  int suffix = LastOccurance(a,x,i+1,n);
  if(suffix>0) return suffix;
  return (a[i]==x?i:-1);
}

void AllIndicesInArray(int a[],int x,vector<int>&ans,int i,int n){
  if(i==n-1){
    if(a[i]==x) ans.push_back(i);
    return;
  }
  if(a[i]==x) ans.push_back(i);
  AllIndicesInArray(a,x,ans,i+1,n);
}

void PrintNameNtimes(int n,string name){
  if(n--){
    cout<<name<<"\n";
    PrintNameNtimes(n,name);
  }
}


void Reverse(int a[],int i,int n){
   if(i<n){
       Reverse(a,i+1,n);
       cout<<a[i]<<' ';
   }
}


void PrintBinary(int n){
  if(n==0) cout<<0;
  if(n>0){
    PrintBinary(n>>1);
    cout<<n%2;
  }
}


bool LinearSearch(int a[],int i,int n,int x){
  if(i<n){
    if(a[i]==x) return 1;
    return LinearSearch(a,i+1,n,x);
  }
  return 0;
}



bool BinarySearch(int a[],int l,int r,int n,int x){
  if(l+1<r){  
    int m = (l+r)/2;
    if(a[m]==x) return 1;
    return (x<a[m]?BinarySearch(a,l,m,n,x):BinarySearch(a,m,r,n,x));
  }else return (a[l]==x or a[r]==x);
}


void PrintToN(int n){
  if(n>0){
    cout<<n<<'\n';
    PrintToN(--n);
  }
}

int sum =0;
void SumOfFirstN(int i,int n){
  if(i>n) return;
  sum+=i;
  SumOfFirstN(i+1,n);
}

int SumOfFirstNFunctional(int n){
  return (n==0?0:n+SumOfFirstNFunctional(n-1));
}



int SumOfFirstN(int n){
  return (n==0?0:n+SumOfFirstN(n-1));
}

ll Factorial(int n){
  return (n==0?1:n*Factorial(n-1));
}

void ReverseF(int a[],int l,int r){
   if(l<r){
       swap(a[l],a[r]);
       ReverseF(a,++l,--r);
   }
}


bool IsPalindrome(string s,int i,int n){
    if(i<(n/2))  return (s[i]==s[n-(i+1)] and IsPalindrome(s,++i,n));
    return 1;
}

ll Fibonacci(int n){
    return ((n==0 or n==1)?n:Fibonacci(n-1)+Fibonacci(n-2));
}


void PrintSubsequences(int a[],int i,int n,vector<int>list){
    if(i>=n){
        for(int x : list) cout<<x<<' ';
        cout<<'\n';
        return;
    }
    list.push_back(a[i]);
    PrintSubsequences(a,i+1,n,list);
    list.pop_back();
    PrintSubsequences(a,i+1,n,list);
}


void SubsequncesWithSumK(int a[],int i,int n,vector<int>list,int k,int curr_sum){
  if(i>=n){
    int s =0;
    for(int x : list) s+=x;
    if(s!=k) return;
    for(int x : list) cout<<x<<' ';
    cout<<'\n';
    return;
  }
  list.push_back(a[i]);
  curr_sum+=a[i];
  SubsequncesWithSumK(a,i+1,n,list,k,curr_sum);
  list.pop_back();
  curr_sum-=a[i];
  SubsequncesWithSumK(a,i+1,n,list,k,curr_sum);
}

bool SubsequncesWithSumKOnlyOne(int a[],int i,int n,int k,int curr_sum){
  if(i>=n) return k==curr_sum;
  return SubsequncesWithSumKOnlyOne(a,i+1,n,k,curr_sum+a[i]) or SubsequncesWithSumKOnlyOne(a,i+1,n,k,curr_sum);
}

int NumberOfSubsequncesWithSumK(int a[],int i,int n,int k,int curr_sum){
  return (i==n?(k==curr_sum):NumberOfSubsequncesWithSumK(a,i+1,n,k,curr_sum+a[i]) + NumberOfSubsequncesWithSumK(a,i+1,n,k,curr_sum));
}


bool Palindrome(string s,int start,int end){
  int l = end-start+1;
  int f = start + (l>>1);
  int temp = start+end;
  for(int i = start;i<f;i++) if(s[i]!=s[temp-i]) return 0;
  return 1;
}

void PalindromePartioning(string s,int start_indx,vector<string>&possible_soln,vector<vector<string>>&res){
  if(start_indx==s.length()){
    res.push_back(possible_soln);
    return;
  }
  for(int i = start_indx;i<s.length();i++){
    if(Palindrome(s,start_indx,i)){
      possible_soln.push_back(s.substr(start_indx,(i-start_indx+1)));
      PalindromePartioning(s,i+1,possible_soln,res);
      possible_soln.pop_back();
    }
  }
}

void KeyPadCombinations(string s,int i,unordered_map<int,string>keypad,string soln){
  if(i==s.length()){
    cout<<endl<<soln<<endl;
    return;
  }
  string key = keypad[s[i]-'0'];
  for(char k : key){
    soln+=k;
    KeyPadCombinations(s,i+1,keypad,soln);
    soln.pop_back();
  }
}

void GetStairPath(vector<int>ways,int stair,vector<vector<int>>&paths,vector<int>&res){
  if(stair==0){
    paths.push_back(res);
    return;
  }
  for(int w : ways){
    if(stair>=w){
      res.push_back(w);
      GetStairPath(ways,stair-w,paths,res);
      res.pop_back();
    }
  }
}



int NumberOfWaysInMaze(int n,int m,int i,int j){
  if(i==n-1 and j==m-1) return 0;
  if(i==n-1) return 1;
  if(j==m-1) return 1;
  if(i>=0 and i<=n-1 and j>=0 and j<=m-1){
    return NumberOfWaysInMaze(n,m,i+1,j) + NumberOfWaysInMaze(n,m,i,j+1);
  }
  return 0;
}


int GetMazePathsWithJumps(int i,int j,int n,int m){
  if(i<0 or j<0 or i>=n or j>=m) return 0;
  if(i==n-1 and j==m-1) return 0;
  if(i==n-1 and (j==m-2 or j==m-3 or j==m-4)) return 1;
  if(j==m-1 and (i==n-2 or i==n-3 or i==n-4)) return 1;
  ll number_of_ways =0;
  for(int x = 1;x<=3;x++) number_of_ways+=GetMazePathsWithJumps(i,j+x,n,m);
  for(int x = 1;x<=3;x++) number_of_ways+=GetMazePathsWithJumps(i+x,j,n,m);
  return number_of_ways;
}

bool IsValid(int i,int j,int n){
    return (i>=0 and i<n and j>=0 and j<n);
}

int nuf =0;
int kinghtmovesx[8] = {-2,-1,1,2,2,1,-1,-2};
int kinghtmovesy[8] = {1, 2, 2,1,-1,-2,-2,-1};
void KnightTour(int i,int j,int n,int count,vector<vector<int>>&grid){
  if(count==n*n){
    grid[i][j] = count;
    for(int p =0;p<n;p++){
      for(int q =0;q<n;q++) cout<<grid[p][q]<<' ';
      cout<<endl;
    }
    grid[i][j] =0;
    cout<<"\n";
    return;
  }
  grid[i][j] = count;
  for(int d =0;d<8;d++){
    int x = i+kinghtmovesx[d];
    int y = j+kinghtmovesy[d];
    if(IsValid(x,y,n) and grid[x][y]==0){
      KnightTour(x,y,n,count+1,grid);
    } 
  }
  grid[i][j] =0;
}

int MaximumScoreOfWordsProblem(vector<string>words,int idx,vector<int>frq,vector<int>score){
  if(idx==words.size()){
    return 0;
  }
  int not_inculded = 0+MaximumScoreOfWordsProblem(words,idx+1,frq,score);
  int word_score =0;
  string word = words[idx];
  bool cancall =1;
  for(int i =0;i<word.length();i++){
    if(frq[word[i]-'a']==0) cancall =0;
    frq[word[i]-'a']--;
    word_score+=score[word[i]-'a'];
  }
  int include_score =0;
  if(cancall) include_score = word_score+MaximumScoreOfWordsProblem(words,idx+1,frq,score);
  for(int i =0;i<word.length();i++) frq[word[i]-'a']+=1;
  return max(not_inculded,include_score);
}



int main(){
  FastIO;
  
  return 0;
} 
