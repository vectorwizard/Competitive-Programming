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
    int last = 0;
    int cnt = 0;
    int l = 0;
    int r = n-1;
    string ans = "";
    bool leftposs = true;
    bool rightposs = true;
    while(l<=r){
        if(a[l]<last){
            leftposs= false;
        }
        if(a[r]<last){
            rightposs = false;
        }
        if(leftposs && rightposs){
            if(a[l]<a[r]){
                last = a[l];
                l++;
                cnt++;
                ans+='L';
            }
            else{
                last = a[r];
                r--;
                cnt++;
                ans+='R';
            }
        }
        else if(leftposs){
            last = a[l];
            l++;
            cnt++;
            ans+='L';
        }
        else if(rightposs){
            last = a[r];
            r--;
            cnt++;
            ans+='R';
        }
        else break;
    }
    cout<<cnt<<endl;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}