#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void greedy_solve(int n){
   vector<int> num;
   int x = n, digit, cs = -1, ans = 0;

   do{
      do{
         digit = x % 10;
         x /= 10;
         cs = cs > digit? cs : digit;
      }while(x > 0 && digit != 9);
      n -= cs;
      x = n;
      cs = -1;
      ++ans;
   }while(x > 0);
   cout << ans << endl;

}

void dp_solve(int n){
   vector<long long> dp (n + 1, INT_MAX);
   int digit, c;

   dp[0] = 0;
   for(int i = 1; i <= n; ++i){
      c = i;
      while(c > 0){
         digit = c % 10;
         dp[i] = min(dp[i], dp[i-digit] + 1);
         c /= 10;
      }
   }
   cout << dp[n] << endl;
}

int main(){
   int n;

   cin >> n;
   dp_solve(n);
}
