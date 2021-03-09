#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> &weights, int mxW){

   int i = 0, ans = 0;
   int j = weights.size() - 1;

   sort(weights.begin(), weights.end());

   while(i < j){
      if(weights[i] + weights[j] <= mxW){
         ++ans;
         weights[i] = -1;
         weights[j] = -1;
         ++i;
         --j;
      }
      else
         --j;
   }

   for(int k = 0; k < weights.size(); ++k){
      if(weights[k] > 0 && weights[k] <= mxW)
         ++ans;
   }

   cout << ans;
}


int main(){
   int n, x, mxW;
   vector<int> weights;

   cin >> n >> mxW;

   for(int i = 0; i < n; ++i){
      cin >> x;
      weights.push_back(x);
   }

   solve(weights, mxW);
}
