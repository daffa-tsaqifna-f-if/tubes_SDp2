#include <iostream>
#include "charactercreation.h"

using namespace std;

int main() {
    character_node* head = nullptr;
    int choice;
    string name;

    do {
        cout << "\n=== Welcome to Text RPG ===\n";
        cout << "1. Play (coming soon)\n";
        cout << "2. Show Character List\n";
        cout << "3. Make a New Character\n";
        cout << "4. Delete Character\n";
        cout << "5. Find Character\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n[Play feature not implemented yet]\n";
                break;

            case 2:
                showCharacters(head);
                break;

            case 3: {
                character c = createCharacter();
                addCharacter(head, c);
                cout << "\nCharacter created successfully!\n";
                break;
            }

            case 4:
                cout << "Enter character name to delete: ";
                cin >> name;
                deleteCharacter(head, name);
                cout << "Delete operation completed.\n";
                break;

            case 5: {
                cout << "Enter character name to find: ";
                cin >> name;
                character_node* found = findCharacter(head, name);
                if (found)
                    printCharacter(found->data);
                else
                    cout << "Character not found.\n";
                break;
            }

            case 0:
                cout << "\nExiting game...\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}