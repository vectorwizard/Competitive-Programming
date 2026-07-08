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
    sort(a.begin(),a.end());
    int prev = a[0];
    int maxi = 1;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(a[i]==prev) continue;
        else if(a[i]-prev==1){
            prev = a[i];
            cnt++;
            maxi = max(maxi,cnt);
        }
        else{
            cnt = 1;
            prev = a[i];
        }
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}