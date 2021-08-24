#include<iostream>
#include<string>
#include<set>

//median = (n+1)/2 lower bound
int main(){
    std::set<std::string> sequence;
    std::string input;
    std::cin>>input;
    if (input != "END"){
        auto mid =sequence.insert(input).first;
        std::cout << *mid << std::endl;
     
        bool parity = 0;
        while (std::cin>>input && input!="END"){
            sequence.insert(input);
            parity = !parity;
            if (input < *mid && parity) --mid;
            else if (input > *mid && !parity) ++mid;
            std::cout << *mid << std::endl;
        }
    }
}