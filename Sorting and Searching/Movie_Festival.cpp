#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool col_sort(const vector<int> a, const vector<int> b){
   return a[1] < b[1];
}

void solve(vector<vector<int>> &times){
   int ending, next, ans = 1;

   sort(times.begin(), times.end(), col_sort);
   ending = times[0][1];

   for(int i = 1; i < times.size(); ++i){
      next = times[i][0];
      if(next >= ending){
         ++ans;
         ending = times[i][1];
      }
   }

   cout << ans << endl;
}

int main(){
   int n, s, e;
   vector<vector<int>> times;

   cin >> n;
   for(int i = 0; i < n; ++i){
      cin >> s >> e;
      times.push_back({s, e});
   }

   solve(times);
}
