#include <iostream>
#include "Character_header/Character.h"

class Hero : public Character {
public:
    Hero(const std::string& name, int health, int attackAmount, int damageAmount)
        : Character(MAINCHAR, name, health, attackAmount, damageAmount) {}

    void attack(Character& enemy) override {
        std::cout << name << " (Hero) attacks " << enemy.getType() << " for " << attackAmount << " damage.\n";
        enemy.receiveDamage(attackAmount);
    }
};

class Goblin : public Character {
public:
    Goblin(const std::string& name, int health, int attackAmount, int damageAmount)
        : Character(GOBLIN, name, health, attackAmount, damageAmount) {}

    void attack(Character& enemy) override {
        std::cout << name << " (Goblin) attacks " << enemy.getType() << " for " << attackAmount << " damage.\n";
        enemy.receiveDamage(attackAmount);
    }
};

int main() {
    // Create Characters
    Hero hero("Theodore", 100, 15, 20);
    Goblin goblin("Sneaky Goblin", 50, 10, 15);

    // Print initial states
    std::cout << "Initial Health:\n";
    std::cout << hero.getType() << " (" << hero.getHealth() << " HP)\n";
    std::cout << goblin.getType() << " (" << goblin.getHealth() << " HP)\n\n";

    // Hero attacks Goblin
    std::cout << "Battle begins!\n";
    hero.attack(goblin);

    // Check Goblin's health
    if (goblin.isalive()) {
        std::cout << goblin.getType() << " is still alive with " << goblin.getHealth() << " HP.\n";
    } else {
        std::cout << goblin.getType() << " has been defeated!\n";
    }

    // Goblin attacks Hero
    if (goblin.isalive()) {
        goblin.attack(hero);
    } else {
        std::cout << goblin.getType() << " cannot attack because it is defeated.\n";
    }

    // Hero heals and attacks again
    std::cout << "\nHero heals by 20 HP.\n";
    hero.setHealth(hero.getHealth() + 20);
    std::cout << "Hero now has " << hero.getHealth() << " HP.\n";

    std::cout << "\nHero attacks Goblin again!\n";
    hero.attack(goblin);

    // Check final health
    std::cout << "\nFinal Health:\n";
    std::cout << "Hero: " << hero.getHealth() << " HP\n";
    std::cout << "Goblin: " << goblin.getHealth() << " HP\n";

    return 0;
}


