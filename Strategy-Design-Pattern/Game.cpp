#include <iostream>

// Author - Given Lepita

/*
 * Let's imagine that you are working on a simulation game where players can control different types of characters such as warriors, mages, and archers.
 * Each character has a unique set of abilities and strategies for combat. 
 * The game allows players to switch between characters during gameplay. 
 * To handle the diverse strategies efficiently, you decide to use the Strategy Design Pattern.
 */

class CombatStrategy {
public:
    virtual void performAttack() = 0;
    virtual void performDefense() = 0;
};

class AggressiveStrategy : public CombatStrategy {
public:
    void performAttack() override {
        std::cout << "Performs a powerful attack!" << std::endl;

    }

    void performDefense() override {
        std::cout << "Doesn't focus on defense." << std::endl;

    }
};

class DefensiveStrategy : public CombatStrategy {
public:
    void performAttack() override {
        std::cout << "Focuses on defense and counters attacks." << std::endl;

    }

    void performDefense() override {
        std::cout << "Uses defensive tactics to protect and mitigate dalepita." << std::endl;

    }
};

class Character {
private:
    CombatStrategy* combatStrategy;

public:
    void setCombatStrategy(CombatStrategy* strategy) {
        combatStrategy = strategy;
    }

    void attack() {
        combatStrategy->performAttack();
    }

    void defend() {
        combatStrategy->performDefense();
    }
};

int main() {
    // Create a character
    Character given;

    // Assign an aggressive combat strategy to the given
    given.setCombatStrategy(new AggressiveStrategy());

    // Player controls given
    given.attack();  
    given.defend();  

    // Player switches to a different character
    Character lepita;

    // Assign a defensive combat strategy to the lepita
    lepita.setCombatStrategy(new DefensiveStrategy());

    // Player controls lepita
    lepita.attack();  
    lepita.defend(); 

    return 0;
}
