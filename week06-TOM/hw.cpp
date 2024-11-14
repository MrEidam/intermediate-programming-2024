#include <iostream>
#include <cassert>

// TODO: doplťe co potřebujete


// Implementujte funkci ‹power_digit_sum›, která vrátí „speciální“
// ciferný součet čísla ‹number›, který se od běžného ciferného
// součtu liší tím, že každou cifru před přičtením umocníme na číslo
// její pozice. Pozice číslujeme zleva, přičemž první má číslo 1.
// Vstupem funkce ‹power_digit_sum› bude libovolné nezáporné celé
// číslo, na výstupu se očekává celé číslo. Výpočet budeme provádět
// v číselné soustavě se základem 7.
// Příklad: Číslo ⟦1234⟧ zapíšeme v sedmičkové soustavě jako
// ⟦(3412)₇⟧ – skutečně, ⟦3⋅7³ + 4⋅7² + 1⋅7¹ + 2⋅7⁰ = 1029 + 196 + 7
// + 2 = 1234⟧.  Proto ‹power_digit_sum(1234)› získáme jako ⟦3¹ + 4²
// + 1³ + 2⁴ = 36⟧.

int power(int a, int exp){
    int result = 1;
    for(int i = 0; i < exp; i++){
        result *= a;
    }
    return result;
}

int powerDigitSum(int num){
    int digits = 0;
    int _num = num;

    while(_num > 0){
        digits++;
        _num /= 7;
    }

    int res = 0;
    while(digits > 0){
        res += power(num%7, digits);
        digits--;
        num /= 7;
    }

    return res;
}

// Napište funkci, která najde celé číslo ‹x›, které leží mezi
// hodnotami ‹low› a ‹high› (včetně), a pro které vrátí funkce ‹poly›
// maximální hodnotu (tzn. libovolné ⟦x⟧ takové, že pro všechny ⟦x'⟧
// platí ⟦f(x) ≥ f(x')⟧, kde ⟦f⟧ je funkce, kterou počítá podprogram
// ‹poly›).

int poly(int x){
    return 10 + 30 * x - 15 * x * x * x + x * x * x * x * x;
}

int fn_max(int low, int high){
    int max_val = poly(low);
    int max_idx = low;

    for(int i = low+1; i <= high; i++){
        if(poly(i) > max_val){
            max_val = poly(i);
            max_idx = i;
        }
    }
    return max_idx;
}

// Napište funkci, která zjistí, kolik bude pracovních dnů v roce
// ‹year›. Dny v týdnu mají hodnoty 0–6 počínaje pondělím s hodnotou 0.
// Předpokládejte, že ‹year› je větší než 1600.
// České státní svátky jsou:
//
// │  datum │ svátek                                         │
// ├┄┄┄┄┄┄┄▻┼◅┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄│
// │   1.1. │ Den obnovy samostatného českého státu          │
// │      — │ Velký pátek                                    │
// │      — │ Velikonoční pondělí                            │
// │   1.5. │ Svátek práce                                   │
// │   8.5. │ Den vítězství                                  │
// │   5.7. │ Den slovanských věrozvěstů Cyrila a Metoděje   │
// │   6.7. │ Den upálení mistra Jana Husa                   │
// │  28.9. │ Den české státnosti                            │
// │ 28.10. │ Den vzniku samostatného československého státu │
// │ 17.11. │ Den boje za svobodu a demokracii               │
// │ 24.12. │ Štědrý den                                     │
// │ 25.12. │ 1. svátek vánoční                              │
// │ 26.12. │ 2. svátek vánoční                              │
// Přestupné roky: v některých letech se na konec února přidává 29.
// den. Jsou to roky, které jsou dělitelné čtyřmi, s výjimkou těch,
// které jsou zároveň dělitelné 100 a nedělitelné 400.
// Čistou funkci ‹first_day› můžete použít k tomu, abyste zjistili,
// na který den v týdnu padne 1. leden daného roku. Např.
// ‹first_day(2001)› vrátí nulu, protože rok 2001 začínal pondělím.

int index_of_day(int day, int month, int year){
    
}

int first_day(int year) {
    assert(year >= 1601);
    int years = year - 1601;
    int offset = years + years / 4 - years / 100 + years / 400;
    return offset % 7;
}

int main(){
    std::cout << powerDigitSum(1234) << std::endl;
    return 0;
}