#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,ans=0,cnt=0;
    string s="";
    cin>>n;
    cin>>s;
    string s1 = s+s;
    for(int i=0;i<2*n;i++){
        if(s1[i]=='0'){
            cnt++;
            ans = max(ans,cnt);
        }
        else cnt=0;
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