#include <iostream>
#include <vector>
#define M 1e9 + 7

using namespace std;

void solve(int sum){
   vector<long long> dp (sum + 1, 0);

   dp[0] = 1;

   for(int i = 1; i <= sum; ++i){
      for(int j = 1; j <= 6; ++j){
         if(i - j >= 0){
            dp[i] += dp[i-j];
            dp[i] %= int(M);
         }
         else
            break;
      }
   }
   cout << dp[sum] << endl;
}

int main(){
   int n;

   cin >> n;
   solve(n);
}
