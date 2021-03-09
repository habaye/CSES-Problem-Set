#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> &sticks){
   long long ans = 0;
   int median;

   sort(sticks.begin(), sticks.end());
   median = sticks[sticks.size() / 2];

   for(auto x: sticks)
      ans += abs(median - x);

   cout << ans <<endl;
}

int main(){
   int n, x;
   vector<int> sticks;

   cin >> n;

   do{
      cin >> x;
      sticks.push_back(x);
   }while(--n);

   solve(sticks);
}
