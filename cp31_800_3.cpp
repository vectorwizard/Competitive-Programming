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
    int cnt = 0;
    int totalcnt = 0;
    int maxi = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='.') {
            cnt++;
            totalcnt++;
        }
        else cnt = 0;
        maxi = max(cnt,maxi);
    }
    if(maxi>2) cout<<2<<endl;
    else cout<<totalcnt<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
