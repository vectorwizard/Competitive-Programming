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
    vector<int> a(n);
    int t01 = 1e9;
    int t10 = 1e9;
    int t11 = 1e9;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        string s;
        cin>>s;
        if(s=="00") continue;
        else if(s=="01") t01 = min(t01,m);
        else if(s=="10") t10 = min(t10,m);
        else t11 = min(t11,m);
    }
    int ans = t11;
    ans = min(ans,(t01+t10));
    if(ans==1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
