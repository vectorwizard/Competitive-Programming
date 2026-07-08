#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,c;
    cin>>n>>c;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int cnt = 0;
    bool fl = true;
    int mini = 1e9;
    for(int i=0;i<n;i++){
        if(a[i]>=b[i]){
            cnt+=(a[i]-b[i]);
        }
        else fl = false;
    }
    if(fl) mini = cnt;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cnt = 0;
    fl = true;
    for(int i=0;i<n;i++){
        if(a[i]>=b[i]){
            cnt+=(a[i]-b[i]);
        }
        else fl = false;
    }
    if(fl) mini = min(mini,(cnt+c));
    if(mini==1e9){
        cout<<-1<<endl;
        return;
    }
    cout<<mini<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
