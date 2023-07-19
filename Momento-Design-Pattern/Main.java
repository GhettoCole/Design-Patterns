import java.util.Stack;

// Author - Given Lepita
/*
 * Imagine you are developing a video game that includes a character customization feature.
 * The game allows players to create and customize their own avatars with various accessories, such as hats, weapons, and armor.
 * To implement this feature, you want to ensure that the customization process is flexible and allows players to undo and redo their changes easily.
 * Momento Design Pattern Explanation: The Momento Design Pattern is used to capture
 * and store the internal state of an object without exposing its internal structure.
 * It enables you to save the current state of an object (the "Originator") and later restore it to that state.
 * This pattern is perfect for implementing undo/redo functionality,
 * as it allows you to save the state of the avatar customization before applying changes and revert back to the previous state if needed.
 */

class Avatar {
    private String hat;
    private String weapon;
    private String armor;

    public Avatar() {
        // initial values
        hat = "No Hat";
        weapon = "No Weapon";
        armor = "No Armor";
    }

    // Methods/Functions to customize the avatar
    public void equipHat(String hat) {
        this.hat = hat;
    }

    public void equipWeapon(String weapon) {
        this.weapon = weapon;
    }

    public void equipArmor(String armor) {
        this.armor = armor;
    }

    public void displayAvatarInfo() {
        System.out.println("Current Avatar Configuration:");
        System.out.println("Hat: " + hat);
        System.out.println("Weapon: " + weapon);
        System.out.println("Armor: " + armor);
        System.out.println();
    }

    // Momento: Inner class to store the state of the Avatar
    private class AvatarMomento {
        private String hatMomento;
        private String weaponMomento;
        private String armorMomento;

        public AvatarMomento(String hat, String weapon, String armor) {
            this.hatMomento = hat;
            this.weaponMomento = weapon;
            this.armorMomento = armor;
        }

        public String getHatMomento() {
            return hatMomento;
        }

        public String getWeaponMomento() {
            return weaponMomento;
        }

        public String getArmorMomento() {
            return armorMomento;
        }
    }

    // Caretaker: Keeps track of the Avatar's state using a Stack
    private Stack<AvatarMomento> stateHistory = new Stack<>();

    public void saveState() {
        stateHistory.push(new AvatarMomento(hat, weapon, armor));
    }

    public void undo() {
        if (!stateHistory.isEmpty()) {
            AvatarMomento lastMomento = stateHistory.pop();
            hat = lastMomento.getHatMomento();
            weapon = lastMomento.getWeaponMomento();
            armor = lastMomento.getArmorMomento();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Avatar playerAvatar = new Avatar();
        playerAvatar.displayAvatarInfo();

        playerAvatar.equipHat("Cool Hat");
        playerAvatar.saveState();
        playerAvatar.displayAvatarInfo();

        playerAvatar.equipWeapon("Powerful Sword");
        playerAvatar.saveState();
        playerAvatar.displayAvatarInfo();

        playerAvatar.equipArmor("Shiny Armor");
        playerAvatar.saveState();
        playerAvatar.displayAvatarInfo();

        playerAvatar.undo();
        playerAvatar.displayAvatarInfo();

        playerAvatar.undo();
        playerAvatar.displayAvatarInfo();

        playerAvatar.undo();
        playerAvatar.displayAvatarInfo();
    }
}
