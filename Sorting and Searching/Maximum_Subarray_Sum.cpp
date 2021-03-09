#include <iostream>
#include <vector>
#include <limits>

#define MIN -1e18

using namespace std;

void solve(vector<int> &arr){
   long long sum = arr[0], ans = arr[0];

   for(int i = 1; i < arr.size(); ++i){
      sum = max(sum + arr[i], (long long)arr[i]);

      ans = max(sum, ans);
   }

   cout << ans << endl;

}

int main(){
   int n, x;
   vector<int> arr;

   cin >> n;
   for(int i = 0; i < n; ++i){
      cin >> x;
      arr.push_back(x);
   }
   solve(arr);
}
