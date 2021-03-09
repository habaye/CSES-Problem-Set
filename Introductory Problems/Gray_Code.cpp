#include <iostream>
#include <vector>


using namespace std;

void solve(vector<string> pre, int cnt){
    vector<string> suf;

    if(cnt<=1){
        for(int i = 0; i < pre.size(); ++i)
            cout << pre[i] << endl;
            return;
    }else{
       for(int j = pre.size() - 1; j >= 0; --j){
          suf.push_back(pre[j]);
          pre[j] = "0" + pre[j];
       }
       for(int j = 0; j < suf.size(); ++j){
          suf[j] = "1" + suf[j];
          pre.push_back(suf[j]);
       }
    }

    cnt--;
    solve(pre,cnt);
}

int main(){
   int n;
   vector<string> pre;

   pre.push_back("0");
   pre.push_back("1");

   cin >> n;

   solve(pre, n);
}
