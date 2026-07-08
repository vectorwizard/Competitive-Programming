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
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int x = a[i];
        int mini = 0;
        int maxi = 0;
        for(int j=i+1;j<n;j++){
            if(a[j]>x) maxi++;
            else if(a[j]<x) mini++;
        }
        ans[i] = max(mini,maxi);
    }
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}