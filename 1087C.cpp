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
    cout<<"?"<<" "<<1<<" "<<2<<"\n";
    cout.flush();
    int x;
    cin>>x;
    if(x==1){
        cout<<"!"<<" "<<1<<"\n";
        cout.flush();
        return;
    }
    else if(x==-1){
        exit(0);
        cout.flush();
    }
    cout<<"?"<<" "<<2<<" "<<3<<"\n";
    cout.flush();
    cin>>x;
    if(x==1){
        cout<<"!"<<" "<<2<<"\n";
        cout.flush();
        return;
    }
    else if(x==-1){
        exit(0);
        cout.flush();
    }
    cout<<"?"<<" "<<3<<" "<<1<<"\n";
    cout.flush();
    cin>>x;
    if(x==1){
        cout<<"!"<<" "<<1<<"\n";
        cout.flush();
        return;
    }
    else if(x==-1){
        exit(0);
        cout.flush();
    }
    for(int i=4;i<=(2*n-1);i+=2){
        cout<<"?"<<" "<<i<<" "<<i+1<<"\n";
        cout.flush();
        cin>>x;
        if(x==1){
            cout<<"!"<<" "<<i<<"\n";
            cout.flush();
            return;
        }
        else if(x==-1){
            exit(0);
        }
    }
    cout<<"!"<<" "<<2*n<<"\n";
    cout.flush();
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}