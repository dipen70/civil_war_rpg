// ============================================================
//  main.cpp  —  Entry point for SHADOWS OF THE GRAY.
//  Uses a base-class pointer to drive derived characters:
//  that is runtime POLYMORPHISM in action.
// ============================================================
#include "Spy.h"
#include "RebelLeader.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "============================================\n"
              << "  SHADOWS OF THE GRAY Civil War, 1863\n"
              << "============================================\n"
              << "Choose your character:\n"
              << "  1) The Spy         (caught by rebels)\n"
              << "  2) The Rebel Leader (grilled in a Union office)\n"
              << "> ";

    int choice = 0;
    std::cin >> choice;

    // POLYMORPHISM: one base-class pointer holds either derived
    // object. Calls to introduce() / playScenario() dispatch to
    // the correct override at runtime.
    std::unique_ptr<Character> player; 
    if (choice == 1)
        player = std::make_unique<Spy>("Thomas Harrison", "Elias Webb");
    else
        player = std::make_unique<RebelLeader>("Colonel Whitmore", "Agent Fox");

    player->introduce();                    // virtual call, overridden
    player->speak();                        // overload #1
    player->speak("Keep your nerve.");      // overload #2
    player->speak("Not a word.", 2);        // overload #3

    player->playScenario();                 // pure-virtual impl runs

    return 0;
}
