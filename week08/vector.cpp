#include <iostream>
#include <vector>

void print(std::vector<int> data) {
    if (data.size() == 0) {
        std::cout << "[]";
        return;
    }

    std::cout << "[ ";
    for (std::size_t i = 0; i < data.size() - 1; i++) {
        std::cout << data[i] << ", ";
    }

    std::cout << data.back() << " ]";
}

std::vector<int> filter_larger(const std::vector<int>& original, int value){
    std::vector<int> out;

    for(int i : original){
        if(i>value){
            out.push_back(i);
        }
    }

    return out;
}

std::vector<int> sort(std::vector<int>& vec){
    std::vector<int> out;
    int n = vec.size();
    bool swapped;

    for(int i = 0; i < n-1;i++){
        swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(vec.at(j) > vec.at(j+1)){
                std::swap(vec.at(j), vec.at(j+1));
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    out = vec;
    return out;
}

std::vector<int> shuffle(std::vector<int> vec, int value){
    size_t tempOut = 0;
    size_t tempTemp = 0;

    for(int i : vec){
        if(i < value){
            tempOut++;
        }else if(i > value){
            tempTemp++;
        }else if(i == value){
            continue;
        }
    }

    std::vector<int> out(tempOut);
    std::vector<int> temp(tempTemp);

    tempOut = 0;
    tempTemp = 0;


    for(int i : vec){
        if(i < value){
            out.at(tempOut) = i;
            tempOut++;
        }else if(i > value){
            temp.at(tempTemp) = i;
            tempTemp++;
        }else if(i == value){
            continue;
        }
    }

    out = sort(out);
    temp = sort(temp);

    out.push_back(value);

    for(int i : temp){
        out.push_back(i);
    }

    return out;
}

bool palendrum(std::vector<int> vec){
    std::vector<int> temp;
    for(int i = vec.size()-1; i>=0; i--){
        temp.push_back(vec.at(i));
    }
    if(vec == temp){
        return true;
    }else{
        return false;
    }
}

int main(){
    std::vector<int> vec1 = { 1, 9, 4, 8, 4, 0, 9, 2, 3, 5, 6 };
    std::vector<int> vec2 = { 1, 0, 2, 0, 2, 0, 1 };
    std::cout << "filter_larger(vec1, 5): ";
    print(filter_larger(vec1, 5));
    std::cout << std::endl;
    std::cout << "shuffle(vec1, 5): ";
    print(shuffle(vec1, 5));
    std::cout << std::endl;
    std::cout << "palendrum(vec1): " << palendrum(vec1) << std::endl;
    std::cout << "palendrum(vec2): " << palendrum(vec2) << std::endl;
}