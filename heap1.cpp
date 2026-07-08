#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
    vector<int> a;
    int size=0;
    heap(){
        a.resize(100);
        a[0] = -1;
        size=0;
    }
    void insert(int val){
        size++;
        int ind = size;
        a[ind] = val;
        while(ind>1){
            int parent = ind/2;
            if(a[parent]<a[ind]){
                swap(a[parent],a[ind]);
                ind = parent;
            }
            else break;
        }
    }
    void deleteheap(){
        a[1] = a[size];
        size--;
        int i = 1;
        while(i<size){
            int largest = i;
            int leftind = 2*i;
            int rightind = 2*i+1;
            if(leftind<=size && a[leftind]>a[largest]){
                largest = leftind;
            }
            if(rightind<=size && a[rightind]>a[largest]){
                largest = rightind;
            }
            if(largest!=i){
                swap(a[largest],a[i]);
                i = largest;
            }
            else return;
        }
    }

    void printheap(){
        for(int i=1;i<=size;i++){
            cout<<a[i]<<endl;
        }
    }
};

int main() {
    heap hp;
    int n;
    for(int i=0;i<5;i++){
        cin>>n;
        hp.insert(n);
    }
    hp.deleteheap();
    hp.printheap();
    return 0;
}
