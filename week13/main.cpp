#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <set>

void showcase_tuple() {
    std::tuple<int, int> point_a = {3, 2};

    {
        int x = std::get<0>(point_a);
        int y = std::get<1>(point_a);

        std::cout << x << ", " << y << std::endl;
    }

    {
        auto [x, y] = point_a;
        std::cout << x << ", " << y << std::endl;
    }

    std::tuple<int, float, std::string> grade_now = {2, 0.5, "physics"}; 

    {
        auto [value, weight, subject] = grade_now;
        std::cout << value << ", " << weight << ", " << subject << std::endl;
    }

    std::vector<std::tuple<int, int>> pairs = {{0, 1}, {2, 3}, {4, 5}};

    for(auto[x, y] : pairs) {
        std::cout << "{" << x << ", " << y << "}, ";
    }

    std::cout << std::endl;
}

void showcase_set() {
    std::set<int> a = {0, 1, 2, 2};

    a.size();

    a.insert(0);

    a.contains(6);

    std::set<std::string> b = { "Jana", "Petr", "Marek" };

    for (std::string name: b) {
        std::cout << name << std::endl;
    }
}

void showcase_map() {
    std::map<int, int> map;
    map[0] = 5;
    map[0] = 12;
    map[2] = 11;

    std::cout << map[0] << std::endl;

    if (map.contains(2)) {
        std::cout << "has" << std::endl;
    } else {
        std::cout << "doesn't have" << std::endl;
    }

    std::cout << "Mapa má " << map.size() << " prvků" << std::endl;

    for(auto[x, y] : map) {
        std::cout << "{" << x << ", " << y << "}, ";
    }

    std::cout << std::endl;

    std::map<std::string, int> phone_numbers = {
        {"Pepa", 456},
        {"Adam", 123}};
    std::cout << phone_numbers["Adam"] << std::endl;

    if (phone_numbers.contains("Petr")){
        std::cout << "has" << std::endl;
    } else {
        std::cout << "doesn't have" << std::endl;
    }

    std::cout << "Mapa má " << phone_numbers.size() << " prvků" << std::endl;

    for(auto[name, number] : phone_numbers) {
        std::cout << "{" << name << ", " << number << "}, ";
    }

    std::cout << std::endl;
}

int main() {
    showcase_map();
    //showcase_map();
}

