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
    int alice,bob;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            bob = i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            alice = i;
            break;
        }
    }
    string ans = "";
    for(int i=0;i<n;i++){
        if(i==alice || i==bob) continue;
        ans+=s[i];
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
