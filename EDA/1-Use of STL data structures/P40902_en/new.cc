#include<iostream>
#include<string>
#include<map>

int main(){
    std::string actor, action;
    int x;
    std::map<std::string, int> casino_situation;
    auto it = casino_situation.begin();
    while(std::cin>>actor>>action){
        if (action=="enters"){
            if (not casino_situation.insert(std::make_pair(actor, 0)).second)
                std::cout<< actor << " is already in the casino" << std::endl;
        }else {
            it = casino_situation.find(actor);
            bool is_here =(it != casino_situation.end());
            if(action=="wins") {
                std::cin>>x;
                if (is_here) it->second+=x;
            }else {
                if (is_here) {
                    std::cout << it->first << " has won " << it->second << std::endl;
                    casino_situation.erase(it);
                }
            }
            if (not is_here) std::cout << actor <<" is not in the casino" << std::endl;
        }
    }
    std::cout << "----------" <<std::endl;
    for (auto &auxiliar : casino_situation)
        std::cout << auxiliar.first << " is winning " << auxiliar.second << std::endl;
}