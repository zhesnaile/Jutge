#include<iostream>
#include<set>
#include<sstream>
#include<queue>
using namespace std;

int main(){
	string l;
	while (getline(cin, l)){
		set<int> s;
		priority_queue<int> p;
		istringstream iss(l);
		int x;
		while (iss >> x) s.insert(x);
		auto it = s.begin();
		while(it != s.end()){
			if (it == s.begin()) p.push (*it);
			else {
				x = *it;
				int y = p.top();
				x -= y;
				if (x%2!=0) p.push(*it);
			}	
			++it;
		}
		cout << p.size() << endl;
	}
}
