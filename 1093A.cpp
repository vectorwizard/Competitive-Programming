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
    unordered_set<int> st;
    for(int i=0;i<n;i++) st.insert(a[i]);
    if(st.size()!=n){
        cout<<-1<<endl;
        return;
    }
    sort(a.rbegin(),a.rend());
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
