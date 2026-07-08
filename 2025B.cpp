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
    int n=s.size();
    s = 'u'+s+'u';
    int ans =0;
    for(int i=1;i<n+2;i++){
        if(s[i]=='u'&& s[i-1]=='u'){
            s[i] = 's';
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
