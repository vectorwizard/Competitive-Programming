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
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='Y'){
            cnt++;
        }
    }
    if(cnt>1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
