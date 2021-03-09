#include <iostream>
#include <vector>

using namespace std;

void solve(){
    string n;
    vector<char> dna;

    cin >> n;
    for(char c: n)
        dna.push_back(c);

    int ans = 1;
    int mx = 1;
    int j;

    for(int i = 0; i < dna.size() && dna.size() > 1; i=j){
        for(j = i + 1; j < dna.size(); ++j){
            if(dna[i] == dna[j]){
                ++mx;
                ans = (mx>ans)? mx:ans;
            }else
                break;
        }
        mx = 1;
    }
    cout<<ans;
}

int main(){
    solve();
}
