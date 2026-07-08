#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> ans(3,0);
    bool fl = true;
    vector<int> sorted = a;
    sort(sorted.begin(),sorted.end());
    for(int i=1;i<n;i++){
        if((sorted[i]-sorted[i-1])!=1){
            fl = false;
            break;
        }
    }
    if(fl==true){
        ans[0] = a[0];
        ans[1] = a[1];
        ans[2] = a[2];
        for(int i=0;i<k;i++){
            cout<<ans[i%3]<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=1;i<n;i++){
            if((a[i]>a[i-1]) && ((a[i]-a[i-1])!=1)){
                ans[0] = a[i]-1;
                break;
            }
            else if((a[i]<a[i-1]) && ((a[i-1]-a[i])!=1)){
                ans[0] = a[i-1]+1;
                break;
            }
        }
        ans[2] = a[n-1];
        if(n!=ans[2] && n!=ans[0]) ans[1] = n;
        else if(n-1!=ans[2] && n-1!=ans[0]) ans[1] = n-1;
        else if(n-2!=ans[2] && n-2!=ans[0]) ans[1] = n-2;
        for(int i=0;i<k;i++){
            cout<<ans[i%3]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
