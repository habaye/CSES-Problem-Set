#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

const int N = 7;
int ANS = 0;

bool valid(int i, int j, bool (&visited)[N][N]){
   if(i >= 0 && i < N && j >= 0 && j < N && !visited[i][j])
      return true;
   else
      return false;
}


void solve(char (&s)[48], int i, int j, int p, bool (&visited)[N][N]){

   if(visited[i][j] == 1)
      return;
   if(i == N - 1 && j == 0){
      if(p == 48)
         ++ANS;
      return;
   }

   visited[i][j] = true;

   if((s[p] == 'D' || s[p] == '?') && i < N - 1 && !visited[i + 1][j]){
      if(!(!valid(i + 2, j, visited) && (valid(i + 1, j + 1, visited) && valid(i + 1, j - 1, visited))))
         solve(s, i + 1, j, p + 1, visited);
   }
   if((s[p] == 'U' || s[p] == '?') && i > 0 && !visited[i - 1][j]){
      if(!(!valid(i - 2, j, visited) && (valid(i - 1, j + 1, visited) && valid(i - 1, j - 1, visited))))
         solve(s, i - 1, j, p + 1, visited);
   }
   if((s[p] == 'L' || s[p] == '?') && j > 0 && !visited[i][j - 1]){
      if(!(!valid(i, j - 2, visited) && (valid(i + 1, j - 1, visited) && valid(i - 1, j - 1, visited))))
         solve(s, i, j - 1, p + 1, visited);
   }
   if((s[p] == 'R' || s[p] == '?') && j < N - 1 && !visited[i][j + 1]){
      if(!(!valid(i, j + 2, visited) && (valid(i + 1, j + 1, visited) && valid(i - 1, j + 1, visited))))
         solve(s, i, j + 1, p + 1, visited);
   }

   visited[i][j] = false;
   return;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   char s[48];
   bool visited[N][N] = {false};
   string x;
   int i = 0, j = 0, p = 0;

   cin >> x;
   for(int i = 0; i < 48; ++i){
      s[i] = x[i];
   }
   solve(s, i, j, p, visited);
   cout << ANS;

}
