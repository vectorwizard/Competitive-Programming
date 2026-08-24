#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    int i = 0;
    vector<int> ans;
    while(i<n-2){
        if((i+4)<n){
            string temp = s.substr(i,5);
            if(temp=="twone"){
                ans.push_back(i+2);
                i+=5;
                continue;
            }
        }
        string temp = s.substr(i,3);
        if(temp == "two" || temp=="one"){
            ans.push_back(i+1);
            i+=3;
            continue;
        }
        i++;
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it+1<<" ";
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
