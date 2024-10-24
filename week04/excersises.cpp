#include <cassert>
#include <iostream>

// Napište funckci, která vrátí součin dvou čísel
int multiply(int a, int b){
    return a*b;
}

// Napište funkci, která rozhodne jestli číslo je sudé
bool is_even(int x){
    return !(x%2);
}

// Vypište věechny čísla od start do stop (včetně)
void print_numbers(int start, int stop) {
    for(int i = start; i<=stop; i++){
        std::cout << i << std::endl;
    }
}

// Naimplementujte funkci která pořítá faktoriál
// Faktoriál čísla x je definovaný jako součin všech kladných čísel <= x
int factorial(int x){
    int num = 1;
    for(int i = 1; i<=x; i++){
        num *= i;
    }
    return num;
}

// Funkce vypíše count hvězdiček
void print_stars(unsigned int count){
    for(int i = 0; i<count; i++){
        std::cout << "⬜";
    }
    std::cout << std::endl;
}

// Funkce vypíše obdélníček z hvězdiček
void print_rectangle(unsigned int sirka, unsigned int vyska){
    for(int i = 0; i < vyska; i++){
        print_stars(sirka);
    }
    std::cout << std::endl;
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
// *
// **
// ***
// ****
void print_pyramid_l(unsigned int height){
    for(int i = 1; i<=height; i++){
        print_stars(i);
    }
    std::cout << std::endl;
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
//    *
//   **
//  ***
// ****
void print_pyramid_r(unsigned int height){
    for(int i = 1; i<=height; i++){
        for(int j = 1; j<=height-i;j++){
            std::cout << "  ";
        }
        print_stars(i);
    }
    std::cout << std::endl;
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
//    *
//   ***
//  *****
// *******
void print_pyramid(unsigned int height){
    for(int i = 1; i<=height; i++){
        for(int j = 1; j<=height-i;j++){
            std::cout << "  ";
        }
        print_stars(i+i-1);
    }
    std::cout << std::endl;
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
// *******
//  *****
//   ***
//    *
void print_pyramid_inverse(unsigned int height){
    for(int i = 1; i<=height; i++){
        for(int j = 0; j<i-1;j++){
            std::cout << "  ";
        }
        int size = height-i;
        for(int j = 0; j<=size+size; j++){
            std::cout << "⬜";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "5 * 2:" << multiply(5, 2) << std::endl;
    std::cout << "Číslo 5 je sudé?:" << is_even(5) << std::endl;
    print_numbers(-5, 2);
    std::cout << "Faktoriál 5:" << factorial(5) << std::endl;
    print_stars(5);
    print_rectangle( 10, 20);
    print_pyramid_l(5);
    print_pyramid_r(5);
    print_pyramid(5);
    print_pyramid_inverse(5);
}
