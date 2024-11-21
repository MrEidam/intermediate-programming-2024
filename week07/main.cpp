#include <iostream>
#include <vector>

// [ 1, 5, 5, 8]

void vectorPrint(std::vector<int> arr){
    if(!arr.size()){
        std::cout << "[ ]" << std::endl;
        return;
    }
    std::cout << "[ ";
    for(int i = 0; i < arr.size()-1; i++){
        std::cout << arr.at(i) << ", ";
    }
    std::cout << arr.at(arr.size()-1) << " ]" << std::endl;
}

int main(){
    std::vector<int> vectorus = {};
    vectorPrint(vectorus);
    return 0;
}