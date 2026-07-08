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
    vector<int> sorted(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sorted[i]=a[i];
    }
    sort(sorted.begin(),sorted.end());
    if(sorted==a){
        cout<<n<<endl;
        return;
    }
    cout<<1<<endl;
}

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
