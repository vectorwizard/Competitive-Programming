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
    int x = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') x++;
        else x--;
        if(x<0) cnt++;
    }
    if(x!=0) {
        cout<<"NO"<<endl;
        return;
    }
    else cout<<"YES"<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
