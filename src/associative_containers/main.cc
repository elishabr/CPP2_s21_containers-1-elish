#include <iostream>
#include <map>
#include <set>

int main(){
    const std::map<int, char> alfa{{1,'n'},{2,'v'},{3, 'v'}};
    std::map<int, char>::const_iterator it = alfa.end();
    it--;
    for(; it != alfa.begin() ; --it){
        std::cout << (*it).first << std::endl; 
    }
    return 0;
}