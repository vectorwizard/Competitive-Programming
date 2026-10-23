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
    string t = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    int j = 0;
    while(i<n){
        if(s[i]<=t[j]){
            s[i] = t[j];
            i++;j++;
        }
        else i++;
    }
    if(j!=26) cout<<-1<<endl;
    else cout<<s<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
