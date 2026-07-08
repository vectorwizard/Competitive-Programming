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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int cnt=INT_MAX,cnt1=INT_MAX,cnt2=INT_MAX;
    if((a[0]+a[n-1])%2==0){
        cout<<0<<endl;
        return;
    }
    int odd=0,even=0,ev=0,od=0;
    if(a[0]%2==0){
        int i=1;
        while(i<n){
            if(a[i]%2==1) {
                odd=i;
                break;
            }
            i++;
        }
        int j=n-2;
        while(j>=0){
            if(a[j]%2==0) {
                even = n-1-j;
                break;
            }
            j--;
        }
        cnt1 = min(odd,even);
    }
    else{
        int i=1;
        while(i<n){
            if(a[i]%2==0) {
                ev = i;
                break;
            }
            i++;
        }
        int j=n-2;
        while(j>=0){
            if(a[j]%2==1) {
                od=n-1-j;
                break;
            }
            j--;
        }
        cnt2 = min(ev,od);
    } 
    cnt = min(cnt1,cnt2);
    cout<<cnt<<endl;
    return;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
