#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


void solve() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> vec(m);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vec[i] = {x,y};
    }
    string s = "";
    for(int i=0;i<n;i++){
        if(i%2==0) s+='0';
        else s+='1';
    }
    cout<<s<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}