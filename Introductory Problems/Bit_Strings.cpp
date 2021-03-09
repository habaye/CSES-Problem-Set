#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;
long long M = 1e9 + 7;

void solve(){
   long long ans = 1;
   long long x = 2;
   long long n;

   cin >> n;

   while(n > 0){
      if(n % 2 != 0)
         ans = (ans * x) % M;
      x = (x * x) % M;
      n /= 2;
   }
   cout<< ans;
}

int main(){
   solve();
}
