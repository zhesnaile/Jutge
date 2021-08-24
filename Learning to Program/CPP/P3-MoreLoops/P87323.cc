#include<iostream>
using namespace std;
 
int main(){
    int r, c, ctrl=0, num1=0, num2=1;
    cin>>r>>c;
    for(int rr=1;rr<=r;++rr){
        num1=ctrl;
        for(int cc=1;cc<=c;++cc){
            if(rr==cc)cout<<"0";
            else if(cc<rr){
                cout<<num1;
                --num1;
                if(num1==-1)num1=9;
            }else{
                cout<<num2;
                ++num2;
                if(num2==10)num2=0;
            }
        }
        cout<<endl;
        num2=1;
        ++ctrl;
        if(ctrl==10)ctrl=0;
    }
}