#include <iostream>
#include <string>
#include <ctime>

class Monster {
protected:
    std::string name;
    int healthPoints;
    int attackPoints;

public:
    Monster(const std::string& _name, int _healthPoints, int _attackPoints)
        : name(_name), healthPoints(_healthPoints), attackPoints(_attackPoints) {}

    void attack(Monster& opponent) {
        std::cout << name << " attacks " << opponent.getName() << "!" << std::endl;
        opponent.takeDamage(attackPoints);
    }

    void takeDamage(int damage) {
        healthPoints -= damage;
        std::cout << name << " takes " << damage << " damage." << std::endl;
        if (healthPoints <= 0) {
            std::cout << name << " has been defeated!" << std::endl;
        }
    }

    bool isAlive() const {
        return healthPoints > 0;
    }

    const std::string& getName() const {
        return name;
    }
};

class FireMonster : public Monster {
public:
    FireMonster(const std::string& _name)
        : Monster(_name, 100, 20) {} 
};

class WaterMonster : public Monster {
public:
    WaterMonster(const std::string& _name)
        : Monster(_name, 120, 15) {} 
};

class ElectricMonster : public Monster {
public:
    ElectricMonster(const std::string& _name)
        : Monster(_name, 80, 25) {} 
};

int main() {
    srand(time(0));

    FireMonster fireMonster("Blaze");
    WaterMonster waterMonster("Aqua");
    ElectricMonster electricMonster("Spark");

    while (fireMonster.isAlive() && waterMonster.isAlive()) {
        if (rand() % 2 == 0) {
            fireMonster.attack(waterMonster);
        } else {
            waterMonster.attack(fireMonster);
        }
    }

    if (fireMonster.isAlive()) {
        std::cout << fireMonster.getName() << " wins!" << std::endl;
    } else {
        std::cout << waterMonster.getName() << " wins!" << std::endl;
    }

    return 0;
}
