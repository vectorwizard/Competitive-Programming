#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,q;
    cin>>n>>q;
    string s,t;
    cin>>s>>t;
    int c00 = 0;
    int c11 = 0;
    int c01 = 0;
    int c10 = 0;
    map<int,vector<int>> pref;
    pref[-1] = {0,0,0,0};
    for(int i=0;i<n;i++){
        if(s[i]==t[i] && s[i]=='0') c00++;
        else if(s[i]==t[i] && s[i]=='1') c11++;
        else if(s[i]!=t[i] && s[i]=='0') c10++;
        else c01++;
        pref[i] = {c00,c11,c01,c10};
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        int c00n = pref[r][0] - pref[l-1][0];
        int c11n = pref[r][1] - pref[l-1][1];
        int c01n = pref[r][2] - pref[l-1][2];
        int c10n = pref[r][3] - pref[l-1][3];
        int diff = abs(c01n-c10n);
        if(diff<=(c00n+c11n)){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
