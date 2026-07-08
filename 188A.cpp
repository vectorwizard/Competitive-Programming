#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<int> vis(n,0);
    vis[0] = 1;
    int ball = 0;
    for(int i=0;i<n;i++){
        if(s[ball]=='R') ball++;
        else ball--;
        vis[ball] = 1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(vis[i]==1) ans++;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}