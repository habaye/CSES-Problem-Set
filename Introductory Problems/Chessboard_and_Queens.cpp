#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
const int N = 8;

void solve(char board[N][N]){

   int offset = N - 1;
   int ans = 0;
   vector<int> diag1(N + offset,0);
   vector<int> diag2(N + offset,0);
   vector<int> placement;
   bool  flag = true;

   for(int i = 0; i < N; ++i)
      placement.push_back(i);

   do{
      for(int i = 0; i < N; ++i){
         if(board[placement[i]][i] == '*'
            || diag1[placement[i]-i+offset] == 1
            || diag2[placement[i]+i] == 1){
             flag = false;
             break;
         }else{
            diag1[placement[i]-i+offset] = 1;
            diag2[placement[i]+i] = 1;
         }
      }
      if(flag)
         ++ans;
      fill(diag1.begin(), diag1.end(), 0);
      fill(diag2.begin(), diag2.end(), 0);
      flag = true;
   }while(next_permutation(placement.begin(), placement.end()));
   cout<<ans<<endl;

}

int main(){

   char board[N][N];

   for(int i = 0; i < 8; ++i)
      for(int j = 0; j < 8; ++j)
         cin >> board[i][j];

   solve(board);
}
