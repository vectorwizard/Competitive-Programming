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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> safest(n+1,0);
    vector<int> temp;
    for(int i=1;i<=n;i++){
        if(a[i]<=i) safest[i] = safest[i-1]+1;
        else {
            safest[i] = safest[i-1];
            temp.push_back(a[i]);
        }
    }
    sort(temp.begin(),temp.end());
    int ans = safest[n];
    int m = temp.size();
    for(int i=0;i<m;i++){
        ans = max(ans,temp[i]-i-1);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}