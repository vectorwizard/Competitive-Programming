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
    vector<int> ans;
    int l = 1;
    int r = 3*n;
    for(int i=0;i<n;i++){
        ans.push_back(l);
        l++;
        ans.push_back(r);
        r--;
        ans.push_back(r);
        r--;
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}