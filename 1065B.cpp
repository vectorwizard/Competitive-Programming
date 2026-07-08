#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
    }
    for(int i=0;i<n;i++){
        if(i==0 && arr[i]==-1){
            if(arr[n-1]==-1) arr[i] = 0;
            else arr[i] = arr[n-1];
        }
        else if(arr[i]==-1 && i!=n-1) arr[i] = 0;
        else if(i==n-1 && arr[i]==-1) arr[i] = arr[0];
    }
    int sum = abs(arr[n-1] - arr[0]);
    cout<< sum<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}