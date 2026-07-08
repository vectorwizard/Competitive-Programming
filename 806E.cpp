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
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            int x = ch-'0';
            a[i][j] = x;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt_1 = 0;
            if(a[i][j]==1) cnt_1++;
            if(a[j][n-1-i]==1) cnt_1++;
            if(a[n-1-i][n-1-j]==1) cnt_1++;
            if(a[n-1-j][i]==1) cnt_1++;
            ans+=(min(cnt_1,4-cnt_1));
        }
    }
    cout<<ans/4<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
