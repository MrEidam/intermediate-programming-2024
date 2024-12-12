#include <iostream>
#include <vector>

void print(std::vector<int> vec){
    std::cout << "{ ";
    if(vec.size()){
        for(int i = 0; i < vec.size()-1; i++){
            std::cout << vec.at(i) << ", ";
        }
        std::cout << vec.at(vec.size()-1);
    }
    std::cout << " }";
}

void print(std::vector<std::vector<int>> vec){
    std::cout << "{ " << std::endl;
    for(int i = 0; i < vec.size(); i++){
        std::cout << "  ";
        print(vec.at(i));
        std::cout << "," << std::endl;
    }
    std::cout << "}" << std::endl;
}

int sum(std::vector<int> data){
    int num = 0;
    for(int a : data){
        num += a;
    }
    return num;
}

std::vector<int> sum(std::vector<std::vector<int>> vec){
    std::vector<int> out;
    for(std::vector<int> i : vec){
        out.push_back(sum(i));
    }
    return out;
    // {{0, 1}, {2}, {}} -> {1, 2, 0}
}

int product(std::vector<int> data){
    int out = 1;
    if(data.size()){
        for(int i : data){
            out *= i;
        }
    }
    return out;
}

std::vector<int> product(std::vector<std::vector<int>> vec){
    std::vector<int> out;
    for(int i = 0; i < vec.size(); i++){
        out.push_back(product(vec.at(i)));
    }
    return out;
    // {{0, 1}, {2}, {}} -> {0, 2, 1}
}

std::vector<int> concat(std::vector<std::vector<int>> vec){
    std::vector<int> out;
    for(std::vector<int> i : vec){
        for(int j : i){
            out.push_back(j);
        }
    }
    return out;
    // {{0, 1}, {2}, {}} -> {0, 1, 2}
}

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> vec){
    std::vector<std::vector<int>> out;
    out.resize(vec.size());
    for(int i = 0; i < vec.size(); i++){
        for(std::vector<int> j : vec){
            out.at(i).push_back(j.at(i));
        }
    }
    return out;
    // {
    //   {0, 1, 2},
    //   {3, 4, 5},
    //   {6, 7, 8},
    // } -> {
    //   {0, 3, 6},
    //   {1, 4, 7},
    //   {2, 5, 8},
    // }
}

std::vector<std::vector<int>> cartesian_product(std::vector<int> a, std::vector<int> b){
    std::vector<std::vector<int>> out;

    for(int i : a){
        for(int j : b){
            std::vector<int> nums;
            nums.push_back(i);
            nums.push_back(j);
            out.push_back(nums);
        }
    }

    return out;
    // {0, 1} {2, 4} -> {{0, 2}, {0, 4}, {1, 2}, {1, 4}}
    // a1,b1 a1,b2 a2,b1 a2,b2
    // {0, 1} {} -> {} 
}

int main(){
    std::vector<std::vector<int>> a {{0, 1}, {1, 5, 4}, {2}};
    std::vector<int> b {0, 5, 4, 0};
    std::vector<int> bb {1, 2, 3};
    std::vector<int> c {};
    std::vector<std::vector<int>> d {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

    //? std::vector<int> b = a[0];
    //? int c = b[1];
    //? int c = a[0][1];

    std::cout << "Vector A = ";
    print(a);
    std::cout << std::endl;
    std::cout << "Vector B = ";
    print(b);
    std::cout << std::endl << std::endl;

    std::cout << "Sum A = ";
    print(sum(a));
    std::cout << std::endl << std::endl;

    std::cout << "Product A = ";
    print(product(a));
    std::cout << std::endl << std::endl;

    std::cout << "Concat A = ";
    print(concat(a));
    std::cout << std::endl << std::endl;

    std::cout << "Transpose D = ";
    print(transpose(d));
    std::cout << std::endl;

    std::cout << "Cartesian Product B + BB = ";
    print(cartesian_product(b,bb));
    std::cout << std::endl;
}