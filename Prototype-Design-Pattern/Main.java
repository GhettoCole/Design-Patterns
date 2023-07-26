import java.util.HashMap;
import java.util.Map;

// Author - Given Lepita

/*
 * Imagine you are developing a game that involves creating different types of magical spells.
 * Each spell can have unique properties, such as damage amount, range, casting time, and mana cost.
 * However, you don't want to create a new class for each spell type since it would lead to a large number of classes and duplication of code.
 * Instead, you decide to use the Prototype design pattern to create spells based on existing prototypes.
 * Prototype Design Pattern Explanation -> he Prototype design pattern is used to create new objects by copying an existing object, called the prototype,
 * rather than creating new instances from scratch. This pattern is beneficial when the cost of creating a new object is expensive or when there are multiple variations of the same object with slight differences.
*/

// Prototype interface for magical spells
interface SpellPrototype {
    SpellPrototype clone();
    void cast();
}

// Concrete prototype for a Fireball spell
class FireballSpell implements SpellPrototype {
    private int damage;
    private int range;
    private int castingTime;
    private int manaCost;

    public FireballSpell(int damage, int range, int castingTime, int manaCost) {
        this.damage = damage;
        this.range = range;
        this.castingTime = castingTime;
        this.manaCost = manaCost;
    }

    // Implement the clone method to create a copy of the Fireball spell
    public SpellPrototype clone() {
        return new FireballSpell(damage, range, castingTime, manaCost);
    }

    // Implement the cast method to display spell information
    public void cast() {
        System.out.println("Casting Fireball Spell:");
        System.out.println("Damage: " + damage);
        System.out.println("Range: " + range);
        System.out.println("Casting Time: " + castingTime);
        System.out.println("Mana Cost: " + manaCost);
    }
}

public class Main {
    public static void main(String[] args) {
        // Create a map to store spell prototypes
        Map<String, SpellPrototype> spellPrototypes = new HashMap<>();

        // Create a Fireball prototype and add it to the map
        FireballSpell fireballPrototype = new FireballSpell(50, 30, 3, 20);
        spellPrototypes.put("Fireball", fireballPrototype);

        // Clone and cast a Fireball spell from the prototype
        SpellPrototype fireballSpell = spellPrototypes.get("Fireball").clone();
        fireballSpell.cast();
    }
}
