#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool col_sort(const vector<int> a, const vector<int> b){
   return a[0] < b[0];
}

void solve(vector<vector<int>> &times){
   long long ans = 1, sum = 1;

   sort(times.begin(), times.end(), col_sort);

   for(int i = 1; i < times.size(); ++i){
      if(times[i][1] > 0)
         ++sum;
      else
         --sum;
      ans = ans > sum ? ans : sum;
   }

   cout << ans << endl;
}

int main(){
   int n, a, b;
   vector<vector<int>> times;

   cin >> n;
   for(int i = 0; i < n; ++i){
      cin >> a >> b;
      times.push_back({a, 1});
      times.push_back({b, -1});
   }
   solve(times);
}
