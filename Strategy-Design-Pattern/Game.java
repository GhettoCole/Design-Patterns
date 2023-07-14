// Author - Given Lepita

/*
 * Let's imagine that you are working on a simulation game where players can control different types of characters such as warriors, mages, and archers.
 * Each character has a unique set of abilities and strategies for combat. 
 * The game allows players to switch between characters during gameplay. 
 * To handle the diverse strategies efficiently, you decide to use the Strategy Design Pattern.
 */


public class Game {
    interface CombatStrategy {
        void performAttack();
        void performDefense();
    }

    static class AggressiveStrategy implements CombatStrategy {
        @Override
        public void performAttack() {
            System.out.println("Performs a powerful attack!");
            
        }

        @Override
        public void performDefense() {
            System.out.println("Doesn't focus on defense.");
            
        }
    }

    static class DefensiveStrategy implements CombatStrategy {
        @Override
        public void performAttack() {
            System.out.println("Focuses on defense and counters attacks.");
            
        }

        @Override
        public void performDefense() {
            System.out.println("Uses defensive tactics to protect and mitigate damage.");
            
        }
    }

    static class Character {
        private CombatStrategy combatStrategy;

        public void setCombatStrategy(CombatStrategy combatStrategy) {
            this.combatStrategy = combatStrategy;
        }

        public void attack() {
            combatStrategy.performAttack();
        }

        public void defend() {
            combatStrategy.performDefense();
        }
    }

    public static void main(String[] args) {
        // Character
        Character given = new Character();

        // Assign an aggressive combat strategy to given
        given.setCombatStrategy(new AggressiveStrategy());

        // Player controls given
        given.attack();  
        given.defend();  

        // Player switches to a different character
        Character lepita = new Character();

        // Assign a defensive combat strategy to lepita
        lepita.setCombatStrategy(new DefensiveStrategy());

        // Player controls lepita
        lepita.attack();
        lepita.defend();  
    }
}
