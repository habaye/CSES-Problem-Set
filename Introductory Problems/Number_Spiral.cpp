#include <iostream>

using namespace std;

void solve(long long r, long long c){
    long long ri, ci;

    if(r == 1 && c == 1){
     cout<< 1 <<endl;
    }
    else if(r % 2 == 0 && r >= c){
       ri = r * r;
       cout<< (ri - (c-1)) <<endl;
    }
    else if(c % 2 != 0 && c >= r){
        ci = c * c;
        cout<< (ci - (r-1)) <<endl;
    }
    else if(r % 2 != 0 && r > c){
        ri = (r-1) * (r-1) + 1;
        cout<< ri + (c - 1) <<endl;
    }
    else if(c % 2 == 0 && c > r){
        ci = (c-1) * (c-1) + 1;
        cout<< ci + (r - 1) <<endl;
    }

}

int main(){
    int t;
    long long x, y;

    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> x >> y;
        solve(x, y);
    }
}
