#include <iostream>
#include <map>

using namespace std;

void solve(map<int, int> &mp){
   int ans = 1;

   for(int i = 1; i < mp.size(); ++i){
      if(mp.at(i) > mp.at(i + 1))
         ++ans;
   }
   cout << ans <<endl;
}

int main(){
   int n, x;
   map<int, int> mp;

   cin >> n;
   for(int i = 1; i <= n; ++i){
      cin >> x;
      mp.insert(pair<int, int>(x, i));
   }
   solve(mp);
}
