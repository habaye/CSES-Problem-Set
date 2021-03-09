#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> &coins){
   long long total = 0, ans = 1;

   vector<vector<int>> dp;

   sort(coins.begin(), coins.end());

   for(auto x: coins){
      if(x <= ans)
         ans += x;
      else{
         cout << ans << endl;
         return;
      }
   }
   cout << ans << endl;
}


int main(){
   int n, x;
   vector<int> coins;

   cin >> n;
   do{
      cin >> x;
      coins.push_back(x);
   }while(--n);

   solve(coins);
}
