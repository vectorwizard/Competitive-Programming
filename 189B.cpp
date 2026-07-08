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
    int ans = 0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]) ans++;
    }
    if(ans<=2){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
