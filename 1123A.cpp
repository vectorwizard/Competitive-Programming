#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    char ch;
    cin>>n>>ch;
    string s;
    cin>>s;
    int ans = 0;
    int l = 0;
    int r = n-1;
    while(l<r){
        if(s[l]!=s[r]){
            int tot = 0;
            if(s[l]==ch) tot++;
            if(s[r]==ch) tot++;
            ans+=(2-tot);
        }
        l++;
        r--;
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
