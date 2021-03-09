#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> &apts, vector<int> &request, int k){
   int ans = 0;

   sort(apts.begin(), apts.end(), greater<int>());
   sort(request.begin(), request.end());

   for(int i = 0; i < request.size(); ++i){
      for(int j = apts.size() - 1; j >=0 ; --j){
         if(apts[j] >= (request[i] - k) && apts[j] <= (request[i] + k)){
            ++ans;
            apts.pop_back();
            break;
         }
         if(apts[j] > (request[i] - k))
            break;
         apts.pop_back();
      }
   }

   cout << ans;
}

int main(){
   int n, m, k, x;
   vector<int> apts;
   vector<int> request;


   cin >> n >> m >> k;

   for(int i = 0; i < n; ++i){
      cin >> x;
      request.push_back(x);
   }
   for(int i = 0; i < m; ++i){
      cin >> x;
      apts.push_back(x);
   }
   solve(apts, request, k);
}
