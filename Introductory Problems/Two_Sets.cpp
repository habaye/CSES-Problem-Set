#include <iostream>
#include <vector>

using namespace std;

void solve(long long n){
    long long sum = n*(n+1)/2;
    long long target;
    vector<int> s1, s2;


    if(sum % 2 != 0)
       cout << "NO" << endl;
    else{
       cout << "YES" << endl;
       target = sum / 2;
       while(n){
          if(target - n >= 0){
             target -= n;
             s1.push_back(n);
             --n;
          }else{
             s2.push_back(n);
             --n;
          }
       }
       cout << s1.size() << endl;
       for(auto x: s1)
          cout << x << " ";

       cout <<"\n"<< s2.size() << endl;
       for(auto x: s2)
          cout << x << " ";
    }


}


int main(){
    long long n;

    cin >> n;
    solve(n);

}
