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
    if(s[0]==s[n-1]){
        cout<<s<<endl;
    }
    else{
        s[0] = s[n-1];
        cout<<s<<endl;
    }
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
