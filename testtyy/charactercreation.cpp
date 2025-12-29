#include "charactercreation.h"
#include <iostream>

using namespace std;

character createCharacter() {
    character c;
    int points = 15;
    int growPoints = 5;
    int choice, value;

    cout << "=== Create Character ===\n";
    cout << "Name: ";
    getline(cin, c.name);

    c.lvl = 1;

    // base stats
    c.str = 0;
    c.agi = 0;
    c.intel = 0;

    // growth
    c.strGrow = 0;
    c.agiGrow = 0;
    c.intelGrow = 0;

    cout << "\nChoose Main Attribute:\n";
    cout << "1. Strength\n";
    cout << "2. Agility\n";
    cout << "3. Intelligence\n";
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 1: c.mainAttr = MAIN_STR; break;
        case 2: c.mainAttr = MAIN_AGI; break;
        case 3: c.mainAttr = MAIN_INT; break;
        default: c.mainAttr = MAIN_STR;
    }

    // ===== BASE STAT DISTRIBUTION =====
    while (points > 0) {
        cout << "\n[Base Stats] Remaining points: " << points << endl;
        cout << "1. STR  2. AGI  3. INT\n";
        cout << "Choose stat: ";
        cin >> choice;

        cout << "Add points: ";
        cin >> value;

        if (value <= 0 || value > points) {
            cout << "Invalid amount.\n";
            continue;
        }

        if (choice == 1) c.str += value;
        else if (choice == 2) c.agi += value;
        else if (choice == 3) c.intel += value;
        else {
            cout << "Invalid stat.\n";
            continue;
        }

        points -= value;
    }

    // ===== GROWTH DISTRIBUTION =====
    while (growPoints > 0) {
        cout << "\n[Growth] Remaining growth points: " << growPoints << endl;
        cout << "1. STR Growth  2. AGI Growth  3. INT Growth\n";
        cout << "Choose growth: ";
        cin >> choice;

        cout << "Add growth points: ";
        cin >> value;

        if (value <= 0 || value > growPoints) {
            cout << "Invalid amount.\n";
            continue;
        }

        if (choice == 1) c.strGrow += value;
        else if (choice == 2) c.agiGrow += value;
        else if (choice == 3) c.intelGrow += value;
        else {
            cout << "Invalid choice.\n";
            continue;
        }

        growPoints -= value;
    }

    // ===== DERIVED STATS =====
    c.hp = c.str * 10;
    c.def = c.agi * 1;
    c.mana = c.intel * 10;

    switch (c.mainAttr) {
        case MAIN_STR: c.attk = c.str * 2; break;
        case MAIN_AGI: c.attk = c.agi * 2; break;
        case MAIN_INT: c.attk = c.intel * 2; break;
    }

    cin.ignore();
    return c;
}



// ================= DISPLAY =================
void printCharacter(const character& c) {
    cout << "\n=== Character Info ===\n";
    cout << "Name  : " << c.name << endl;
    cout << "Level : " << c.lvl << endl;

    cout << "\nBase Stats\n";
    cout << "STR : " << c.str << endl;
    cout << "AGI : " << c.agi << endl;
    cout << "INT : " << c.intel << endl;

    cout << "\nMain Attribute: ";
    if (c.mainAttr == MAIN_STR) cout << "Strength\n";
    else if (c.mainAttr == MAIN_AGI) cout << "Agility\n";
    else cout << "Intelligence\n";

    cout << "\nDerived Stats\n";
    cout << "HP     : " << c.hp << endl;
    cout << "Attack : " << c.attk << endl;
    cout << "Defense: " << c.def << endl;
    cout << "Mana   : " << c.mana << endl;
}

// ================= UPDATE =================
void updateCharacter(character& c) {
    cout << "\nManual stat update not supported.\n";
    cout << "Stats are derived from attributes.\n";
}

// ================= MLL FUNCTIONS =================
void addCharacter(character_node*& head, const character& c) {
    character_node* newNode = new character_node;
    newNode->data = c;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    character_node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

character_node* findCharacter(character_node* head, const string& name) {
    while (head) {
        if (head->data.name == name)
            return head;
        head = head->next;
    }
    return nullptr;
}

void deleteCharacter(character_node*& head, const string& name) {
    if (!head) return;

    if (head->data.name == name) {
        character_node* del = head;
        head = head->next;
        delete del;
        return;
    }

    character_node* curr = head;
    while (curr->next && curr->next->data.name != name) {
        curr = curr->next;
    }

    if (curr->next) {
        character_node* del = curr->next;
        curr->next = del->next;
        delete del;
    }
}

void showCharacters(character_node* head) {
    if (!head) {
        cout << "\nNo characters available.\n";
        return;
    }

    while (head) {
        printCharacter(head->data);
        head = head->next;
    }
}