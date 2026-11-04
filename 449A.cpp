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
    string s;
    cin>>s;
    while(m--){
        int l,r;
        char c1,c2;
        cin>>l>>r>>c1>>c2;
        l--;
        r--;
        for(int i=l;i<=r;i++){
            if(s[i]==c1) s[i] = c2;
        }
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