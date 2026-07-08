#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> temp;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            mpp[i%k]++;
        }
    }
    for(auto it:mpp){
        if(it.second%2!=0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
