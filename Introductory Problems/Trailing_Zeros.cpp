#include <iostream>

using namespace std;

void solve(){
    int ans, n;
    ans = 0;

    cin >> n;
    while(n >= 5){
       n /= 5;
       ans += n;
    }
    cout << ans;

}

int main(){

    solve();
}
