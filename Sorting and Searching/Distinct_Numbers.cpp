#include <iostream>
#include <map>

using namespace std;


int main(){
   int n, x;
   map<int, int> values;

   cin >> n;
   for(int i = 0; i < n; ++i){
      cin >> x;
      if(values.find(x) == values.end())
         values.insert(pair<int, int> (x, 1));
      else
         values.at(x)++;
   }

   cout << values.size();
}
