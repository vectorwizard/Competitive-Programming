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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> sorted = a;
    sort(sorted.begin(),sorted.end());
    if(sorted==a){
        cout<<-1<<endl;
        return;
    }
    int mini = sorted[0];
    int maxi = sorted[n-1];
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]!=sorted[i]){
            ans = min(ans,max(maxi-a[i],a[i]-mini));
        }
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