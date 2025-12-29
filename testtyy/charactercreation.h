#ifndef CHARACTER_CREATION_H
#define CHARACTER_CREATION_H

#include <string>
using namespace std;


// Main Attribute
enum MainAttr {
    MAIN_STR,
    MAIN_AGI,
    MAIN_INT
};

// Character Stuff

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

    // output stats
    int hp;
    int attk;
    int def;
    int mana;
};


// Character list
struct character_node {
    character data;
    character_node* next;   // next character
};

// Character Creation Stuff
character createCharacter();
void printCharacter(const character& c);
void updateCharacter(character& c);

// Character CRUD 
void addCharacter(character_node*& head, const character& c);
character_node* findCharacter(character_node* head, const string& name);
void deleteCharacter(character_node*& head, const string& name);
void showCharacters(character_node* head);

#endif
