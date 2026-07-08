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
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>y[i];
    vector<int> diff(n,0);
    for(int i=0;i<n;i++){
        diff[i] = y[i] - x[i];
    }
    vector<int> pos;
    vector<int> neg;
    vector<int> zeros;
    for(int i=0;i<n;i++){
        if(diff[i]>0) pos.push_back(diff[i]);
        else if(diff[i]<0) neg.push_back(abs(diff[i]));
        else zeros.push_back(diff[i]);
    }
    sort(pos.rbegin(),pos.rend());
    sort(neg.rbegin(),neg.rend());
    int l = 0;
    int r = 0;
    int ans = 0;
    while(l<pos.size() && r<neg.size()){
        if(pos[l]>=neg[r]){
            ans++;
            l++;
            r++;
        }
        else if(pos[l]<neg[r]){
            r++;
        }
    }
    int rem = (pos.size()-l+zeros.size());
    cout<<ans+(rem/2)<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
