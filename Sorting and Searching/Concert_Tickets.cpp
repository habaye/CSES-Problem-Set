#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void solve(){

   int n, m, x;
   multiset<int> prices;

   cin >> n >> m;
   for(int i = 0; i < n; ++i){
      cin >> x;
      prices.insert(x);
   }

   for(int i = 0; i < m; ++i){
      cin >> x;
      auto iter = prices.upper_bound(x);
      if(iter == prices.begin())
         cout << -1 << endl;
      else{
         --iter;
         cout << (*iter) << endl;
         prices.erase(iter);
      }
   }

}

int main(){
   solve();
}
