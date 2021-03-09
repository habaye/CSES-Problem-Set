#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<pair<int, int>> &arr, int target){
   int sz = arr.size();
   int l = 0, r = sz - 1, sum = 0;

   sort(arr.begin(), arr.end());

   while(l < sz && r < sz && l < r){
      sum = arr[l].first + arr[r].first;
      if(sum == target){
         cout << arr[l].second << " " << arr[r].second << endl;
         return;
      }
      if(sum < target){
         ++l;
      }
      else{
         --r;
      }
   }
   cout << "IMPOSSIBLE" << endl;

}


int main(){
   int n, x, t;
   vector<pair<int, int>> arr;

   cin >> n >> t;
   for(int i = 0; i < n; ++i){
      cin >> x;
      arr.push_back(pair<int, int>(x, i + 1));
   }

   solve(arr, t);
}
