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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    vector<int> sum(n);
    sum[0] = a[0];
    for(int i=1;i<n;i++){
        sum[i] = sum[i-1] + a[i];
    }
    while(q--){
        int x;
        cin>>x;
        int ind = lower_bound(sum.begin(),sum.end(),x)-sum.begin();
        if(ind==n) cout<<-1<<endl;
        else cout<<ind+1<<endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
