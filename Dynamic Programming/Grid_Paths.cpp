#include <iostream>
#include <vector>
#define M (int)(1e9 + 7)
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>

using namespace std;

int solve(vvc& grid){
   int n = grid.size();
   vvi dp(n, vector<int>(n, 0));

   if(grid[0][0] == '*')
      return 0;
   else
      dp[0][0] = 1;

   for(int r = 1; r < n; ++r){
      dp[r][0] = grid[r][0] == '.' ? dp[r - 1][0] : 0;
   }

   for(int c = 1; c < n; ++c){
      dp[0][c] = grid[0][c] == '.' ? dp[0][c - 1] : 0;
   }

   for(int r = 1; r < n; ++r){
      for(int c = 1; c < n; ++c){
         if(grid[r][c] == '.'){
            dp[r][c] = dp[r-1][c] + dp[r][c-1];
            dp[r][c] %= M;
         }
      }
   }

   return dp[n-1][n-1];
}

int main(){
   int n;
   char x;
   cin >> n;

   vvc grid(n);

   for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
         cin >> x;
         grid[i].push_back(x);
      }
   }

   cout << solve(grid);
}
