#include <iostream>
#include <vector>

void print(std::vector<int> data){
    if(data.size() == 0){
        std::cout << "[]";
        return;
    }

    std::cout << "[ ";
    for(std::size_t i = 0; i < data.size() - 1; i++){
        std::cout << data[i] << ", ";
    }

    std::cout << data.back() << " ]";
}

int sum(std::vector<int> data){
    int num = 0;
    for(int a : data){
        num += a;
    }
    return num;
}

float average(std::vector<int> data){
    return (sum(data)+.0)/data.size();
}

float median(std::vector<int> data){  // seznam lichy veznem prostřední | seznam sudý vezmem prostřední 2 a průměr
    if(data.size()%2){
        return data.at(data.size()/2);
    }else{
        return average({(data.at(data.size()/2-1)), (data.at(data.size()/2))});
    }
}

std::vector<int> range(int start, int end){
    std::vector<int> out;
    if(start < end){
        for(int i = start; i<end;i++){
            out.push_back(i);
        }
    }else{
        for(int i = start; i>end;i--){
            out.push_back(i);
        }
    }
    return out;
}

std::vector<int> runningSum(std::vector<int> data){
    std::vector<int> out;
    int num = 0;
    for(int i = 0; i < data.size(); i++){
        out.push_back(num+data.at(i));
        num = data.at(i);
    }
    return out;
}

std::vector<int> rotateRight(std::vector<int> data, int count){
    std::vector<int> out;
    for(int i = 0; i < (data.size());i++){
        int j = i + count;
        if(j >= data.size()){
            out.push_back(data.at(j%data.size()));
        }else{
            out.push_back(data.at(j));
        }
    }
    return out;
}

int main(){
    std::vector<int> vec1 = { 1, 9, 4, 8, 4, 0, 9, 2, 3, 5, 6 };
    std::vector<int> asc1 = { 0, 2, 4, 7, 8 };
    std::vector<int> asc2 = { 1, 3, 5, 6, 7, 9 };

    std::cout << "sum(vec1): " << sum(vec1) << std::endl;
    std::cout << "average(vec1): " << average(vec1) << std::endl;
    std::cout << "median(asc1): " << median(asc1) << std::endl;

    std::cout << "range(5, 10): ";
    print(range(5, 10));
    std::cout << std::endl;

    std::cout << "range(11, 4): ";
    print(range(11, 4));
    std::cout << std::endl;

    std::cout << "runningSum(vec1): ";
    print(runningSum(vec1));
    std::cout << std::endl;

    std::cout << "rotateRight(asc1): ";
    print(rotateRight(asc1, 2));
    std::cout << std::endl;
}
