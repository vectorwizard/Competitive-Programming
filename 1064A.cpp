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
    char last = s[n-1];
    int cnt = 0;
    for(int i=n-2;i>=0;i--){
        if(s[i]!=last) cnt++;
    }
    cout<<cnt<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
