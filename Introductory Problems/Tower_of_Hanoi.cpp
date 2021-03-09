#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int swap_disk(vector<int>& a, vector<int>& b){
   if(a.empty() && b.empty())
      return 0;
   if(!a.empty() && !b.empty()){
      if(a.back() > b.back()){
         a.push_back(b.back());
         b.pop_back();
         return 2;
      }
      else{
         b.push_back(a.back());
         a.pop_back();
         return 1;
      }
   }
   else if(a.empty() && !b.empty()){
         a.push_back(b.back());
         b.pop_back();
         return 2;
   }
   else{
         b.push_back(a.back());
         a.pop_back();
         return 1;
   }
}

void solve(int n){
   vector<int> s1, s2, s3;
   int marker;

   for(int i = n; i > 0; --i)
      s1.push_back(i);

   cout << pow(2, n) - 1 << endl;

   if(n % 2 == 0){
      while(s3.size() != n){
         marker = swap_disk(s1, s2);
         if(marker == 0)
            break;
         else if(marker == 1)
            cout << "1 2" << endl;
         else if(marker == 2)
            cout << "2 1" << endl;

         marker = swap_disk(s1, s3);
         if(marker == 0)
            break;
         else if(marker == 1)
            cout << "1 3" << endl;
         else if(marker == 2)
            cout<< "3 1" << endl;

         marker = swap_disk(s2, s3);
         if(marker == 0)
            break;
         else if(marker == 1)
            cout << "2 3" << endl;
         else if(marker == 2)
            cout<< "3 2" << endl;
      }
   }
   else{
      while(s3.size() != n){
         marker = swap_disk(s1, s3);
         if(marker == 0)
            break;
         else if(marker == 1)
            cout << "1 3" << endl;
         else if(marker == 2)
            cout << "3 1" << endl;

         marker = swap_disk(s1, s2);
         if(marker == 0)
            break;
         else if(marker == 1)
            cout << "1 2" << endl;
         else if(marker == 2)
            cout<< "2 1" << endl;

         marker = swap_disk(s2, s3);
         if(marker == 0)
            break;
         else if(marker == 1)
            cout << "2 3" << endl;
         else if(marker == 2)
            cout<< "3 2" << endl;
      }
   }


}

int main(){
   int n;

   cin >> n;
   solve(n);
}

