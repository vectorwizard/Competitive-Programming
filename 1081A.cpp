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
    s = s+s;
    int l = 0;
    int ans = 0;
    while(l<n){
        int block = 1;
        for(int i = l+1;i<l+n;i++){
            if(s[i]!=s[i-1]) block++;
        }
        ans = max(ans,block);
        l++;
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