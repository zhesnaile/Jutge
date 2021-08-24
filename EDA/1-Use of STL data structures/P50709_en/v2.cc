#include <iostream>
#include <queue>
using namespace std;

int main()
{
    char inst;
    int help;
    priority_queue<int> coll;
    while (cin>>inst)
    {
        if (inst=='S' or inst=='I' or inst=='D') cin>>help;
        if (inst=='S') coll.push(help);
        else if (coll.empty()!=1)
        {
            if (inst=='A') cout << coll.top() << endl;
            else if (inst=='R') coll.pop();
            else {
                if (inst=='D') help*=-1;
                help+=coll.top();
                coll.pop();
                coll.push(help);
            }
        }
        else cout << "error!" << endl;
    }
}
