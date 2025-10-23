#include<iostream>
using namespace std;
int main(){
    int a[] = {1,4,2,53};
    int l=a[0];
    int s=a[0];
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        if(a[i]>l){
            s=l;
            l=a[i];
        }else if(a[i]<l && a[i]>s){
            s=a[i];
        }
    }
    cout<<l<<" "<<s;
}
