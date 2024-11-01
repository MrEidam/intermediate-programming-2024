#include <iostream>
#include <cassert>

// TODO: Doplňte potřebné hlavičky

void squarePrint(int num){
    for(int i = 0; i < num; i++){
        std::cout << "⬜";
    }
}

void spacePrint(int num){
    for(int i = 0; i < num; i++){
        std::cout << "  ";
    }
}

// Vypište obdélník o zadaných parametrech
// Vraťte 0 pokud vše v pořádku, -1 pokud nastala chyba
int hollow_rect(int x, int y, int thickness){
    if(thickness*2 > x || thickness >= x || thickness*2 > y)
        return -1;

    for(int i = 0; i < thickness; i++){
        squarePrint(x);
        std::cout << std::endl;
    }
    for(int i = 0; i < y-2*thickness; i++){
        squarePrint(thickness);
        spacePrint(x-thickness*2);
        squarePrint(thickness);
        std::cout << std::endl;
    }
    for(int i = 0; i < thickness; i++){
        squarePrint(x);
        std::cout << std::endl;
    }
    return 0;
}

// Vraťte a na n
int power(int a, int n){
    int aOut = 1;
    for(int i = 0; i < n; i++){
        aOut *= a;
    }
    return aOut;
}

int powerFancy(int a, int n){
    if(n == 0) return 1;
    else if(n%2){
        return a * powerFancy(a*a, (n-1)/2);
    }else{
        return powerFancy(a*a, n/2);
    }
}
/*
    In: an integer x; an integer n
    Out: xn

    exp_by_squaring(x, n)
    if n < 0 then
        return exp_by_squaring(1 / x, -n);
    else if n = 0 then 
        return 1;
    else if n is even then 
      return exp_by_squaring(x * x, n / 2);
    else if n is odd then 
      return x * exp_by_squaring(x * x, (n - 1) / 2);
    end function 
*/
// Vraťte idx-té fibonacciho číslo
int fibonacci(int idx){
    int a = 0;
    int b = 1;
    for(int i = 0; i < idx; i++){
        int tmp = a+b;
        a = b;
        b = tmp;
    }
    return b;
}

int main(){
    hollow_rect(8, 10, 2);
    std::cout << std::endl;
    std::cout << "5^4 " << power(5, 4) << std::endl;
    std::cout << "Fibonacci 10: " << fibonacci(10) << std::endl;
    std::cout << "2^5 " << powerFancy(2, 5) << std::endl;
}
