#include <iostream>
#include <math.h>

using namespace std;

void solve(long long n){
    long long total = (n * n *( n * n - 1))/2;
    long long attacks = 4 * (n - 1) * (n - 2);

    long long ans = total - attacks;
    cout << ans << endl;

}

int main(){
    int n;

    cin>> n;
    for(int i = 1; i <= n; ++i){
       solve(i);
    }

}
