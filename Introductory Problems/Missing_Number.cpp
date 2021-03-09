#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve(){
    int n, m;
    cin>>n;
    vector<int> arr;

    for (int i = 0; i < n-1; ++i){
        cin>> m;
        arr.push_back(m);
    }

    sort(arr.begin(), arr.begin() + n - 1);

    for(int i = 0; i < n - 1; ++i){
        if(i == 0){
           if(arr[i] != 1)
              cout<<(arr[i] - 1);
           else if(arr[n-2] != n)
              cout<<n;
        }
        else if(i < n-2 && arr[i+1] - arr[i] != 1)
            cout<< (arr[i+1] - 1);
    }
}


int main(){
    solve();
}
