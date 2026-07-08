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
    int x = (n*(n-1))/2;
    vector<int> b(x+1);
    for(int i=1;i<=x;i++) cin>>b[i];
    sort(b.begin()+1,b.end());
    vector<int> a;
    int ind = 1;
    int cnt = 1;
    while(ind<=x){
        a.push_back(b[ind]);
        ind+=n-cnt;
        cnt++;
    }
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<1000000000;
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
