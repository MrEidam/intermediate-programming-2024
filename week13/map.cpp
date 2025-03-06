#include <cassert>
#include <iostream>
#include <string>
#include <set>
#include <map>

bool isSubSet(std::set<std::string> required, std::set<std::string> known){
    for(std::string ing : known){
        if(!required.contains(ing)){
            return false;
        }
    }
    return true;
}


bool canMake(std::string goal, std::set<std::string> start, std::map<std::set<std::string>, std::string> recipes){
    if(start.contains(goal)) return true;

    bool made = true;
    while(made){
        made = false;
        for(auto[recipe, result] : recipes){
            if(start.contains(result)) continue;
            
            if(isSubSet(start, recipe)){
                start.insert(result);
                made = true;
                continue;
            }
        }
        if(start.contains(goal)) return true;
    }
    return false;
}


// goal co chceme 
// start - co máme u sebe
// recepies - co jsou všechno za recepty

/*/
*
* { "A", "B" }
*       1. { "A", "B" } -> "C"
*       2. { "C", "B" } -> "D"
*
/*/

void run_tests(){
    {
        std::set<std::string> start = {"water", "salt", "sugar"};
        std::map<std::set<std::string>, std::string> recipes;
        assert(canMake("water", start, recipes) == true);  
        assert(canMake("salt", start, recipes) == true);  
        assert(canMake("sugar", start, recipes) == true);  
    }
    {
        std::set<std::string> start = {"water", "salt"};
        std::map<std::set<std::string>, std::string> recipes;
        recipes[{ "salt", "water" }] = "saltwater";
        assert(canMake("saltwater", start, recipes) == true);
        assert(canMake("sugar", start, recipes) == false);
    }
    {
        std::set<std::string> start = {"water", "salt", "air"};
        std::map<std::set<std::string>, std::string> recipes;
        recipes[{ "water", "salt" }] = "brine";
        recipes[{ "brine", "air" }] = "saltedAir";
        assert(canMake("saltedAir", start, recipes) == true);
        assert(canMake("fire", start, recipes) == false);
    }
    {
        std::set<std::string> start = {"a", "b", "c", "d"};
        std::map<std::set<std::string>, std::string> recipes;
        recipes[{ "a", "b", "c" }] = "x";
        recipes[{ "x", "d" }] = "y";
        assert(canMake("y", start, recipes) == true);
    }
    {
        std::set<std::string> start = {"flour", "water", "yeast"};
        std::map<std::set<std::string>, std::string> recipes;
        recipes[{ "flour", "water" }] = "dough";
        recipes[{ "dough", "yeast" }] = "bread";
        recipes[{ "bread", "dough" }] = "superBread";
        assert(canMake("bread", start, recipes) == true);
    }
    {
        std::set<std::string> start = {"iron", "carbon"};
        std::map<std::set<std::string>, std::string> recipes;
        recipes[{ "iron", "carbon" }] = "steel";
        assert(canMake("diamond", start, recipes) == false);
    }

    {
        std::set<std::string> start = {"hydrogen", "oxygen"};
        std::map<std::set<std::string>, std::string> recipes;

        // Recipe with 0 ingredients (produces a constant)
        recipes[{ }] = "pureWater";  // No ingredients, pure water is just made
        // Recipe with 1 ingredient
        recipes[{ "hydrogen" }] = "hydrogenGas";
        recipes[{ "oxygen" }] = "oxygenGas";
        // Recipe with 2 ingredients
        recipes[{ "hydrogen", "oxygen" }] = "water";

        // Test if the pureWater can be made directly with no ingredients
        assert(canMake("pureWater", start, recipes) == true);
        // Test if hydrogenGas can be made from hydrogen
        assert(canMake("hydrogenGas", start, recipes) == true);
        // Test if oxygenGas can be made from oxygen
        assert(canMake("oxygenGas", start, recipes) == true);
        // Test if water can be made from hydrogen and oxygen
        assert(canMake("water", start, recipes) == true);

        // Test if an impossible goal that requires a recipe we don't have is handled
        assert(canMake("carbonDioxide", start, recipes) == false);
    }
    {
        std::set<std::string> start = {"hydrogen", "oxygen", "carbon", "nitrogen"};
        std::map<std::set<std::string>, std::string> recipes;

        recipes[{ "hydrogen", "oxygen" }] = "water";
        recipes[{ "carbon", "oxygen" }] = "carbonDioxide";
        recipes[{ "water", "carbonDioxide" }] = "carbonicAcid";
        recipes[{ "carbonicAcid", "oxygen" }] = "carbonicAcidGas";
        recipes[{ "carbonicAcid", "nitrogen" }] = "ammoniumCarbonate";
        recipes[{ "ammoniumCarbonate", "water" }] = "ammoniumHydroxide";

        assert(canMake("ammoniumHydroxide", start, recipes) == true);
        assert(canMake("carbonicAcidGas", start, recipes) == true);
        assert(canMake("sulfuricAcid", start, recipes) == false);
    }

    // Complex test with multiple intermediate steps to produce a final compound
    {
        std::set<std::string> start = {"water", "sodium", "chlorine", "ammonia"};
        std::map<std::set<std::string>, std::string> recipes;

        recipes[{ "water", "sodium" }] = "sodiumHydroxide";
        recipes[{ "sodiumHydroxide", "chlorine" }] = "sodiumChloride";
        recipes[{ "sodiumChloride", "ammonia" }] = "ammoniumChloride";
        recipes[{ "ammoniumChloride", "water" }] = "ammoniumHydroxide";

        assert(canMake("ammoniumHydroxide", start, recipes) == true);
        assert(canMake("sodiumChloride", start, recipes) == true);
        assert(canMake("chlorine", start, recipes) == true);
        assert(canMake("water", start, recipes) == true);
    }

    // Test with a very long sequence of steps (complex chain reaction)
    {
        std::set<std::string> start = {"hydrogen", "oxygen"};
        std::map<std::set<std::string>, std::string> recipes;

        recipes[{ "hydrogen", "oxygen" }] = "water";
        recipes[{ "water", "hydrogen" }] = "hydrogenPeroxide";
        recipes[{ "hydrogenPeroxide", "oxygen" }] = "oxygenGas";
        recipes[{ "oxygen", "water" }] = "ozone";
        recipes[{ "ozone", "hydrogenPeroxide" }] = "oxygenatedWater";

        assert(canMake("oxygenatedWater", start, recipes) == true);
        assert(canMake("oxygenGas", start, recipes) == true);
        assert(canMake("ozone", start, recipes) == true);
        assert(canMake("hydrogenPeroxide", start, recipes) == true);
        assert(canMake("water", start, recipes) == true);
        assert(canMake("carbonDioxide", start, recipes) == false);
    }

    // Test with more than two ingredients in a recipe and multipath recipe
    {
        std::set<std::string> start = {"hydrogen", "oxygen", "carbon", "nitrogen"};
        std::map<std::set<std::string>, std::string> recipes;

        recipes[{ "hydrogen", "oxygen", "carbon" }] = "carbonHydride";
        recipes[{ "carbon", "hydrogen", "nitrogen" }] = "hydrogenNitride";
        recipes[{ "carbonHydride", "oxygen" }] = "carbonDioxide";
        recipes[{ "hydrogenNitride", "oxygen" }] = "nitrousOxide";

        assert(canMake("carbonDioxide", start, recipes) == true);
        assert(canMake("nitrousOxide", start, recipes) == true);
        assert(canMake("carbonHydride", start, recipes) == true);
        assert(canMake("carbon", start, recipes) == true);  // Cannot directly make carbon
    }
    std::cout << "All tests passed!\n";
}

int main(){/*
    std::string need = "C";
    std::set<std::string> inv = {"A", "B", "D"};

    std::set<std::string> ONE = {"a", "b", "c"};
    std::set<std::string> TWO = {"a", "c", "d"};
    std::set<std::string> COST = {"a", "b"};

    if(isSubSet(ONE, COST)) std::cout << "One is" << std::endl;
    else std::cout << "One isn't" << std::endl;

    if(isSubSet(TWO, COST)) std::cout << "Two is" << std::endl;
    else std::cout << "Two isn't" << std::endl;
*/
    run_tests();
}