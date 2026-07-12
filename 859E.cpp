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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> pref(n+1,0);
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    int low = 1;
    int high = n;
    while(low<high){
        int mid = low+(high-low)/2;
        cout<<'?'<<" "<<mid-low+1<<" ";
        for(int i=low;i<=mid;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        int res;
        cin>>res;
        if(res>(pref[mid]-pref[low-1])){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    cout<<'!'<<" "<<high<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
