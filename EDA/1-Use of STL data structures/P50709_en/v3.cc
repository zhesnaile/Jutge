#include<iostream>
#include<queue>
using namespace std;

int main(){
    char oper_type;
    int x;
    priority_queue<int> muh_stack;
    while (cin >> oper_type){
        if (oper_type == 'S'){
            cin>>x;
            muh_stack.push(x);
        } else{
            if (oper_type=='I' or oper_type=='D') {
                cin >> x;
                if (oper_type=='D'){
                    x *= -1;
                }
            }
            if (not muh_stack.empty()) {
                switch (oper_type){
                    case 'R':
                        muh_stack.pop();
                        break;
                    case 'A':
                        cout << muh_stack.top() << endl;
                        break;
                    default:
                        x = muh_stack.top() + x ;
                        muh_stack.pop();
                        muh_stack.push(x);
                }
            } else cout << "error!" << endl;
        }
    }
}