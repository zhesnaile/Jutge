#include<iostream>
#include<set>

//sequence_max = 10^8
//

int main(){
    int x, y, n;
    while (std::cin>>x>>y>>n){
        std::set<int> collatz_sequence;
        std::pair<std::set<int>::iterator ,bool> arbitro;
        arbitro.second=false;
        while (n <= 100000000 and arbitro.second){
            arbitro=collatz_sequence.insert(n); 
            if (n%2==0) n=n/2+x;
            else n=3*n+y;
        }
        if (not arbitro.second) n = (collatz_sequence.size() - arbitro.first);
        std::cout << n << std::endl;
    }
}