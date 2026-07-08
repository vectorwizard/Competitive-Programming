#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,h,l;
    cin>>n>>h>>l;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int maxi = max(h,l);
    int mini = min(h,l);
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(a[i]<=mini) x++;
        else if(a[i]<=maxi) y++;
    }
    cout<<(x+min(x,y))/2<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}