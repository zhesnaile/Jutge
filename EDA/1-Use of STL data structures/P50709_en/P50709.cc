#include <iostream>
#include <queue>
using namespace std;

int main()
{
    char oper;
    int help;
    priority_queue<int> coll;
    while (cin>>oper)
    {
        if (oper=='S')
        {
            cin>>help;
            coll.push(help);
        }
        else if (not coll.empty())
        {
            if (oper=='A')
            {
                cout << coll.top() << endl;
            }
            else if (oper=='R')
            {
                coll.pop();
            }
            else if (oper=='I' or oper=='D')
            {
                cin>>help;
                if (oper=='I')
                    help += coll.top();
                else help = coll.top() - help;
                coll.pop();
                coll.push(help);
            }
        }
        else 
        {
            cout << "error!" << endl;
            if (oper== 'I' or oper == 'D') cin>>help;
        }
    }
}
