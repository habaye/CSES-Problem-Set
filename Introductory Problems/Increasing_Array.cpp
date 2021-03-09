#include <iostream>
#include <vector>

using namespace std;

void solve(){
   int n, m, j;
   long long ans;
   vector<long long> arr;

   cin >> n;

   for(int i = 0; i < n; ++i){
      cin >> m;
      arr.push_back(m);
   }

   ans = 0;
   for(int i = 0; i < arr.size() && arr.size() > 1; i = j){
      for(j = i + 1; j < arr.size(); ++j){
          if(arr[i] > arr[j]){
             ans += arr[i] - arr[j];
             arr[j] = arr[i];
             break;
          }
          i = j;
      }
   }
   cout<<ans;
}
int main(){
    solve();
}
