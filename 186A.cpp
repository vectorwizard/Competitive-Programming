#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    set<string> st;
    for(int i=0;i<n-3;i++){
        string temp = s.substr(i,4);
        st.insert(temp);
    }
    if(st.count("2026")||!st.count("2025")) cout<<0<<endl;
    else cout<<1<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
