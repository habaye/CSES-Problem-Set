#include <iostream>
#include <vector>
#define M (int)(1e9 + 7)

using namespace std;

void solve(vector<int> coins, int sum){
   vector<long long> dp(sum + 1, 0);
   dp[0] = 1;

   for(int i = 1; i <= sum; ++i){
      for(int j = 0; j < coins.size(); ++j){
         if(i - coins[j] >= 0){
            dp[i] += dp[i-coins[j]];
            dp[i] %= M;
         }
      }
   }
   cout << dp[sum] << endl;
}

int main(){
   int n, x;
   cin >> n >> x;

   vector<int> coins(n);

   for(int i = 0; i < n; ++i)
      cin >> coins[i];

   solve(coins, x);
}
