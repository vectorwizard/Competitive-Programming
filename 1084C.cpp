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
    stack<char> st;
    for(int i=0;i<n;i++){
        if(st.empty()) st.push(s[i]);
        else if(s[i]==st.top()) st.pop();
        else st.push(s[i]);
    }
    if(st.empty()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
