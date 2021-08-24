#include<iostream>
#include<set>
using namespace std;

struct player{
	string pname;
	int elo;
	bool online;
	inline bool operator<(const player& p1) const {
		if (elo != p1.elo) return elo < p1.elo;
		else return pname < p1.pname;	
	}
};

int main(){
	string inst;
	set<player> log;
	set<player>::iterator it;
	player dummy;
	while (cin >> inst) {
		cin>>dummy.pname;
		it = log.find(dummy);
		if (inst == "LOGIN") {
			dummy.online = 1;
			if (it!=log.end() && not (*it).online){
				dummy.elo = (*it).elo;
				log.erase(it);
			}
			else dummy.elo = 1200;
			log.insert(dummy);
		}
		else if (inst == "LOGOUT"){	
			dummy.online = 0;
			if (it!=log.end() && (*it).online){
				dummy.elo = (*it).elo;
				log.erase(it);
			}
			else dummy.elo = 1200;
			log.insert(dummy);
		}
		else if (inst == "PLAY" ) {
			cin >> dummy.pname;
			auto it2 = log.find(dummy);
			bool b = (it == log.end() or it2 == log.end()) or ((*it).online == false or (*it2).online == false);
			if (not b){
				dummy = *it;
				dummy.elo += 10;
				log.erase(it);
				log.insert(dummy);
				dummy = *it2;
				if (dummy.elo > 1200) dummy.elo -= 10;
				log.erase(it2);
				log.insert(dummy);
			}
			else cout << "player(s) not connected" << endl;
		}
		else cout << (*it).pname << ' ' << (*it).elo << endl;
	}
	cout << "RANKING" << endl;
	for (player x : log) cout << x.pname << ' ' << x.elo << endl;
}
