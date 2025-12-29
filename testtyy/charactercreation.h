#ifndef CHARACTER_CREATION_H
#define CHARACTER_CREATION_H

#include <string>
using namespace std;


// ================= MAIN ATTRIBUTE =================
enum MainAttr {
    MAIN_STR,
    MAIN_AGI,
    MAIN_INT
};

// ================= CHARACTER RECORD =================

struct character {
    string name;
    int lvl;

    // base stats
    int str;
    int agi;
    int intel;

    // growth per level
    int strGrow;
    int agiGrow;
    int intelGrow;

    MainAttr mainAttr;

    // derived stats
    int hp;
    int attk;
    int def;
    int mana;
};


// MLL: Parent (Character Node)
struct character_node {
    character data;
    character_node* next;   // next character
};

// === Character Creation ===
character createCharacter();
void printCharacter(const character& c);
void updateCharacter(character& c);

// === Character MLL (CRUD) ===
void addCharacter(character_node*& head, const character& c);
character_node* findCharacter(character_node* head, const string& name);
void deleteCharacter(character_node*& head, const string& name);
void showCharacters(character_node* head);

#endif
