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
    char ch = 'R';
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]!=ch){
            ans++;
            if(s[i]=='R') ch = 'B';
            else ch = 'R';
        }
        else if(s[i]=='R'){
            ch = 'B';
        }
        else ch = 'R';
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}