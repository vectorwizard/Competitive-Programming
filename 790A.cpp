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
    int total = 0,first = 0;
    for(int i=0;i<6;i++){
        total+=(s[i]-'0');
        if(i<3){
            first+=(s[i]-'0');
        }
    }
    int last = total - first;
    if(last==first) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
