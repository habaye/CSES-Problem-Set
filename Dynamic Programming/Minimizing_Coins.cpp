#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void solve(vector<int> coins, int sum){
   vector<long long> dp (sum+1, INT_MAX);
   dp[0] = 0;

   for(int i = 1; i <= sum; ++i){
      for(int j = 0; j < coins.size(); ++j){
         if(i - coins[j] >= 0){
            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
         }
      }
   }

   if(dp[sum] != INT_MAX)
      cout << dp[sum] << endl;
   else
      cout << -1 << endl;
}

int main(){
   int n, x, c;
   vector<int> coins;

   cin >> n >> x;

   do{
      cin >> c;
      coins.push_back(c);
   }while(--n);
   solve(coins, x);
}
