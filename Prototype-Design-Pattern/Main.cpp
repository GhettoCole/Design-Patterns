#include <iostream>
#include <unordered_map>
#include <string>

// Prototype interface for magical spells
class SpellPrototype {
public:
    virtual SpellPrototype* clone() = 0;
    virtual void cast() = 0;
    virtual ~SpellPrototype() {}
};

// Concrete prototype for a Fireball spell
class FireballSpell : public SpellPrototype {
private:
    int damage;
    int range;
    int castingTime;
    int manaCost;

public:
    FireballSpell(int damage, int range, int castingTime, int manaCost) : 
        damage(damage), range(range), castingTime(castingTime), manaCost(manaCost) {}

    // Implement the clone method to create a copy of the Fireball spell
    SpellPrototype* clone() override {
        return new FireballSpell(damage, range, castingTime, manaCost);
    }

    // Implement the cast method to display spell information
    void cast() override {
        std::cout << "Casting Fireball Spell:" << std::endl;
        std::cout << "Damage: " << damage << std::endl;
        std::cout << "Range: " << range << std::endl;
        std::cout << "Casting Time: " << castingTime << std::endl;
        std::cout << "Mana Cost: " << manaCost << std::endl;
    }
};

int main() {
    // Create a map to store spell prototypes
    std::unordered_map<std::string, SpellPrototype*> spellPrototypes;

    // Create a Fireball prototype and add it to the map
    FireballSpell* fireballPrototype = new FireballSpell(50, 30, 3, 20);
    spellPrototypes["Fireball"] = fireballPrototype;

    // Clone and cast a Fireball spell from the prototype
    SpellPrototype* fireballSpell = spellPrototypes["Fireball"]->clone();
    fireballSpell->cast();

    // Clean up allocated memory
    delete fireballSpell;
    delete fireballPrototype;

    return 0;
}
