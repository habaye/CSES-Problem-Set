#include <iostream>
#include <vector>
#include <limits.h>
#include <map>

using namespace std;


void bottom_up(vector<int> w){
   long long target, sum = 0;
   long  long diff = LONG_LONG_MAX;
   int n = w.size();

   for(int x: w)
      sum += x;
   target = sum / 2;

   vector<vector<bool>> dp;//(n,vector<bool>(target+1));

   for(int i = n - 1; i >= 0; --i){
      vector<bool> l;
      l.push_back(true);
      for(int j = 1; j <= target; ++j){
         if(i == 0 && j > 0)
            l.push_back((i == w[0]? true:false));
         else
            l.push_back(false);
      }
      dp.push_back(l);
      l.clear();
   }
   cout<<"out"<< endl;

/*   for(int i = 0; i < n; ++i)
      dp[i][0] = true;

   for(int i = 1; i <= target; ++i)
      dp[0][i] = (i == w[0]? true:false);
*/
   for(int i = 1; i < n; ++i){
      for(int j = 1; j <= target; ++j){
         dp[i][j] = dp[i - 1][j];
         if(w[i] <= j){
            dp[i][j] = dp[i][j] || dp[i-1][j-w[i]]? true:false;
         }
      }
   }

   for(int i = target; i >= 0; --i){
      if(dp[n-1][i]){
         diff = sum - 2 * i;
         break;
      }
   }
   cout << diff << endl;

}

long long solve(vector<int> w, int i, long long sum, long long target){

   if(i == 0)
      return abs((target-sum) - sum);

   // include i
   long long s1 = top_down(w, i-1, sum+w[i-1], target);

   // exclude i
   long long s2 = top_down(w, i-1, sum, target);

   return min(s1, s2);
}
int main(){
   int n, x;
   long long sum = 0;
   vector<int> w;

   cin >> n;

   for(int i = 0; i < n; ++i){
      cin >> x;
      w.push_back(x);
      sum += x;
   }
   if(n == 1)
      cout << w.back() << endl;
   else{
      //recursion, brute force
      cout << solve(w, n, 0, sum) << endl;

      // bottom_up iterative, too slow
      //cout << bottom_up(w) << endl;
   }
}
