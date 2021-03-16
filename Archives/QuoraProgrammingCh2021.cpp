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


int Follows_Or_Created(vector<ll>Follows_Story[],vector<ll>Created[],ll user, ll story_no){
  for(auto st : Created[user]){
    if(st==story_no) return 2;
  }
  for(auto flows : Follows_Story[user]){
    if(flows==story_no) return 1;
  }
  return 0;
}



bool User1_follows_User2(vector<ll>Follows_User[],ll user1,ll user2){
  for(auto u : Follows_User[user1]){
    if(u==user2) return 1;
  }
  return 0;
}

bool User1_follows_User2Stories(vector<ll>Follows_Story[],vector<ll>Created[],ll user1,ll user2){
  unordered_multiset<ll>created;
  for(auto &x : Created[user2]){
    created.insert(x);
  }
  for(auto st : Follows_Story[user1]){
    auto it = created.find(st);
    if(it!=created.end()){
      return 1;
    }
  }
  return 0;
}

bool User1_follows_User2_FolloewdStories(vector<ll>Follows_Story[],ll user1,ll user2){
  unordered_multiset<ll>followed;
  for(auto st : Follows_Story[user2]){
    followed.insert(st);
  }
  for(auto st : Follows_Story[user1]){
    auto it = followed.find(st);
    if(it!=followed.end()){
      return 1;
    }
  }
  return 0;
}


void Dijest(){
    ll stories,users;
    cin>>stories>>users;
    vector<ll>Created[users+1];
    vector<ll>Follows_Story[users+1];
    vector<ll>Follows_User[users+1];
    for(int st = 1;st<=stories;st++){
      int user;
      cin>>user;
      Created[user].emplace_back(st);
    }
    ll user_follows, stroies_follows;
    cin>>user_follows>>stroies_follows;
    for(int u = 1;u<=user_follows;u++){
      ll user1,user2;
      cin>>user1>>user2;
      Follows_User[user1].emplace_back(user2);
    }
    for(int u = 1;u<=stroies_follows;u++){
      ll user,story;
      cin>>user>>story;
      Follows_Story[user].emplace_back(story);
    }

    // genrate all stories recc scores for one user 
    vector<pair<int,int>>Story_Score(stories+1,{0,0});
    ll user = 1;
    for(int kst = 1;kst<=stories;kst++){
      if(Follows_Or_Created(Follows_Story,Created,user,kst)>0){
        Story_Score[kst].first = -1;
        Story_Score[kst].second = kst;
      }else{
        ll curr_story_score = 0;
        for(int u = 1;u<=users;u++){
          if(user!=u){
            int b = Follows_Or_Created(Follows_Story,Created,u,kst);
            if(b==0){
              continue;
            }
            if(User1_follows_User2(Follows_User,user,u)){// a = 3
              Story_Score[kst].first+=(3*b);
            }else if(User1_follows_User2Stories(Follows_Story,Created,user,u)){// a = 2
              Story_Score[kst].first+=(2*b);
            }else if(User1_follows_User2_FolloewdStories(Follows_Story,user,u)){//a =  1
              Story_Score[kst].first+=(b);
            }
            Story_Score[kst].second = kst;
          }
        }
      }
    }
    sort(Story_Score.begin(),Story_Score.end());
    // if((Story_Score[0].first==Story_Score[1].first) and (Story_Score[2].first==Story_Score[1].first)){
    //   cout<<1<<' '<<2<<' '<<3<<'\n';
    // }else
    {
      cout<<Story_Score[0].second<<' '<<Story_Score[1].second<<' '<<Story_Score[2].second<<'\n';
    }

}


// void bfs(vector<vector<int>>&spread,vector<vector<int>>&gaurd){
//   int dx[4] = {0,1,0,-1};
//   int dy[4] = {1,0,-1,0};
//   for(int g = 0;g<gaurd.size();g++){
//     queue<pair<int,int>>que;
//     que.push(Pair(gaurd[g][0],gaurd[g][1]));
//     spread[gaurd[g][0]][gaurd[g][1]] = 0;
//     while(not que.empty()){
//       for(int d =0;d<4;d++){

//       }
//     }
    
//   }

// }

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void Fill(vector<vector<int>>&spread,int n,int m,int x,int y,int step,int d){
  if(x>=0 and x<n and y>=0 and y<m ){
    if(step>d) return;
    if(spread[x][y]>0) return;
    spread[x][y] = step;
    for(int i = 0;i<4;i++){
      if(spread[x+dx[i]][y+dy[i]]==0){
        Fill(spread,n,m,x+dx[i],y+dy[i],step+1,d);
      }
    }
  }
}

void Escape(){
  int n,m,k;
  cin>>n>>m>>k;
  string g[n];
  for(int row=0;row<n;row++){      
    cin>>g[row];
  }
  vector<vector<int>>gaurd(k,vector<int>(3,0));
  for(int i = 0;i<k;i++){
    cin>>gaurd[i][0]>>gaurd[i][1]>>gaurd[i][2];
  }
  vector<vector<int>>spread(n,vector<int>(m,0));
  for(int i =0;i<k;i++){
    Fill(spread,n,m,gaurd[i][0],gaurd[i][1],0,gaurd[i][2]);
  }
  for(int row=0;row<n;row++){      
    for(int col=0;col<m;col++){       
        cout<<spread[row][col]<<" ";
    }
    cout<<'\n';
  }

}


ll TreasureUtil(vector<vector<int>>&grid,int n,vector<vector<ll>>&dp,int i,int j){
  if(i>=0 and i<n and j>=0 and j<n){
    if(i==n-1 and j==n-1){
       return dp[i][j] = grid[i][j];
    }
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] =  grid[i][j] + max(TreasureUtil(grid,n,dp,i,j+1),TreasureUtil(grid,n,dp,i+1,j));
  }
  return 0;
}


// ll TreasureUtil2(vector<vector<int>>&grid,int n,vector<vector<ll>>&paths,int i,int j,int max_t){
//   if(i>=0 and i<n and j>=0 and j<n){
//     if(i==n-1 and j==n-1){
//        return paths[i][j] = grid[i][j];
//     }
//     if(paths[i][j]!=-1){
//       if(paths[i][j]==max_t) cnt+=1;
//       return paths[i][j];
//     }
//     paths[i][j] =  grid[i][j] + max(TreasureUtil2(grid,n,paths,i,j+1,max_t),TreasureUtil2(grid,n,paths,i+1,j,max_t));
//     if(paths[i][j]==max_t) cnt+=1;
//     return paths[i][j];
//   }

//   return 0;
// } 

void Treasure(){
  int n;
  cin>>n;
  ll cnt = 0;
  vector<vector<int>>grid(n,vector<int>(n,0));
  string g[n];
  for(int i =0;i<n;i++){
    cin>>g[i];
  }
  for(int row=0;row<n;row++){      
    for(int col=0;col<n;col++){       
      grid[row][col] = g[row][col]-'0';
    }
  }
  vector<vector<ll>>dp(n,vector<ll>(n,-1)),paths(n,vector<ll>(n,-1));
   ll max_t = TreasureUtil(grid,n,dp,0,0);
  // for(int row=0;row<n;row++){      
  //   for(int col=0;col<n;col++){       
  //       if(row!=0 and col!=0){
  //         if(dp[row][col]==max_t) cnt++;
  //       }
  //   }
  // }
  cout<<max_t<<" "<<max_t-1;
}



void DataCentre(){
  int n;
  cin>>n;
  bool yes =1;
  int d[n][2];
  for(int i=0;i<n;i++){
    cin>>d[i][0]>>d[i][1];
    if(d[i][0]!=d[i][1]) yes =0;
  }
  if(not yes){
    ll max_dist = 0;
    ll city = 0;
    for(int i = 1;i<n;i++){
      max_dist += max(abs(d[0][0]-d[i][0]),abs(d[0][1]-d[i][1]));
    }
    cout<<max_dist<<'\n';
    for(int i = 1;i<n;i++){
      ll curr_dist = 0;
      for(int j = 0;j<n;j++){
         curr_dist +=max(abs(d[i][0]-d[j][0]),abs(d[i][1]-d[j][1]));
      }
      cout<<curr_dist<<'\n';
      if(curr_dist<max_dist){
        max_dist = curr_dist;
        city = i;
      }
    }
    cout<<city+1;
  }else{
    if(n&1){
      cout<<(n>>1 + 1);
    }else{
      cout<<(n>>1);
    }
  }

}

int main(){
  FastIO;
  Escape();
  return 0;
} 

/*

7 5
1
1
2
3 
4
5
5
2 4
1 2
4 5
1 7
5 2
3 3
4 1

*/