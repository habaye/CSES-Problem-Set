#include <iostream>


using namespace std;

void solve(long long a, long long b){
    bool flag = false;

    if(a == 0 && b == 0)
       flag = true;
    else if(a+b == max(a,b))
       flag = false;
    else if((max(a, b) > 2 * min(a, b)))
       flag = false;
    else{
       if((2*b-a) % 3 == 0 || (2*a-b) %3 == 0)
          flag = true;
    }
    if(flag)
        cout << "YES" << endl;
    else cout<< "NO" <<endl;


}

int main(){
    int t;
    long long a, b;

    cin >> t;
    for(int i = 0; i < t; ++i){
       cin >> a >> b;
       solve(a, b);
    }
}
