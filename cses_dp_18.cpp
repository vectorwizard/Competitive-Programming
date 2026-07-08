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
    vector<int> ans;
    ans.push_back(a[0]); 
    for(int i=1;i<n;i++){
        if(a[i]>ans.back()) ans.push_back(a[i]);
        else{
            int ind = lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
            ans[ind] = a[i];
        }
    }
    cout<<ans.size()<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
