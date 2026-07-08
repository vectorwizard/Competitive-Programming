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
    if(n==2){
        cout<<max(a[0],a[1])<<" "<<min(a[0],a[1])<<endl;
        return;
    }
    vector<int> sorted = a;
    sort(sorted.rbegin(),sorted.rend());
    int x = sorted[0];
    int y = sorted[1];
    vector<int> temp(n);
    temp[0] = sorted[0];
    temp[1] = sorted[1];
    for(int i=2;i<n;i++){
        if(y==0) break;
        int rem = x%y;
        temp[i] = rem;
        x = y;
        y = rem;
    }
    if(sorted!=temp){
        cout<<-1<<endl;
        return;
    }
    cout<<sorted[0]<<" "<<sorted[1]<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
