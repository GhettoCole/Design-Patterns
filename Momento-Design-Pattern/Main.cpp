#include <iostream>
#include <stack>
#include <string>
using namespace std;

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
private:
    string hat;
    string weapon;
    string armor;

public:
    Avatar() {
        // initial values
        hat = "No Hat";
        weapon = "No Weapon";
        armor = "No Armor";
    }

    // Methods/Functions to customize the avatar
    void equipHat(string hat) {
        this->hat = hat;
    }

    void equipWeapon(string weapon) {
        this->weapon = weapon;
    }

    void equipArmor(string armor) {
        this->armor = armor;
    }

    void displayAvatarInfo() {
        cout << "Current Avatar Configuration:" << endl;
        cout << "Hat: " << hat << endl;
        cout << "Weapon: " << weapon << endl;
        cout << "Armor: " << armor << endl;
        cout << endl;
    }

    // Momento: Inner class to store the state of the Avatar
    class AvatarMomento {
    private:
        string hatMomento;
        string weaponMomento;
        string armorMomento;

    public:
        AvatarMomento(string hat, string weapon, string armor) {
            this->hatMomento = hat;
            this->weaponMomento = weapon;
            this->armorMomento = armor;
        }

        string getHatMomento() {
            return hatMomento;
        }

        string getWeaponMomento() {
            return weaponMomento;
        }

        string getArmorMomento() {
            return armorMomento;
        }
    };

    // Caretaker: Keeps track of the Avatar's state using a Stack
    stack<AvatarMomento> stateHistory;

    void saveState() {
        stateHistory.push(AvatarMomento(hat, weapon, armor));
    }

    void undo() {
        if (!stateHistory.empty()) {
            AvatarMomento lastMomento = stateHistory.top();
            stateHistory.pop();
            hat = lastMomento.getHatMomento();
            weapon = lastMomento.getWeaponMomento();
            armor = lastMomento.getArmorMomento();
        }
    }
};

int main() {
    Avatar playerAvatar;
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

    return 0;
}
