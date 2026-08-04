#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    if(n<2*m){
        cout<<"NO"<<endl;
        return;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> start;
    vector<int> end;
    for(int i=0;i<m;i++){
        start.push_back(a[i]);
        end.push_back(a[n-1-i]);
    }
    reverse(end.begin(),end.end());
    for(int i=0;i<m;i++){
        if(b[i]>=start[i] && b[i]<=end[i]) continue;
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
