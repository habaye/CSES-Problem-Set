#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void solve(string s){
   map<char,int> mp;
   int odd = 0;
   char center;
   vector<char> ans;

   for(char c: s){
      if(!mp[c])
         mp[c] = 1;
      else
         ++mp[c];
   }

   for(auto x: mp){
     if(x.second % 2 != 0){
        ++odd;
        center = x.first;
     }
   }

   if(odd > 1)
      cout << "NO SOLUTION" << endl;
   else{
      for(auto x: mp){
         if(x.first != center){
            int sz = x.second / 2;
            for(int i = 0; i < sz; ++i){
               cout << (x.first);
               ans.push_back(x.first);
            }
         }
      }
      if(odd){
         for(int i = 0; i < mp[center] / 2; ++i){
            cout << center;
            ans.push_back(center);
         }
         cout<<center;
      }

      for(auto x: ans){
         cout << ans.back();
         ans.pop_back();
      }
   }
}

int main(){
   string s;

   cin >> s;
   solve(s);
}
