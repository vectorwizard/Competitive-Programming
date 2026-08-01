#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> mpp;
    mpp['T']++;
    mpp['i']++;
    mpp['m']++;
    mpp['u']++;
    mpp['r']++;
    for(int i=0;i<n;i++){
        mpp[s[i]]--;
    }
    for(auto it:mpp){
        if(it.second!=0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
