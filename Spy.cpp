
//  Spy.cpp  —  Scenario for the captured Union spy.
#include "Spy.h"
#include <iostream>

Spy::Spy(const std::string& realName, const std::string& cover)
    : Character(realName), coverName(cover) {}

// OVERRIDING: spy-specific introduction.
void Spy::introduce() const {
    std::cout << "I am " << name
              << ", Union intelligence. Cover name: "
              << coverName << ".\n";
}

// Three rebel questions. Right answer = safe; wrong = +40 suspicion.
// 60 or more suspicion = executed.
void Spy::playScenario() {
    std::cout << "\n=== THE SPY — Captured by Rebels, Virginia, 1863 ===\n";
    std::cout << "You wake up tied to a chair. A rebel officer walks in.\n\n";

    int choice = 0;

    std::cout << "REBEL: \"What's your name, stranger?\"\n"
              << "  1) Elias Webb, traveling merchant.\n"
              << "  2) Uhh... Tom. Just Tom.\n> ";
    std::cin >> choice;
    if (choice != 1) suspicion += 40;

    std::cout << "\nREBEL: \"What's your business this deep in Virginia?\"\n"
              << "  1) Selling salt and cloth to the towns.\n"
              << "  2) Just passing through, sir.\n> ";
    std::cin >> choice;
    if (choice != 1) suspicion += 40;

    std::cout << "\nREBEL: \"We found coded notes in your coat. Explain.\"\n"
              << "  1) Tailor's shorthand — fabric counts and prices.\n"
              << "  2) I've never seen those before in my life!\n> ";
    std::cin >> choice;
    if (choice != 1) suspicion += 40;

    std::cout << "\n----------------------------------------------------\n";
    if (suspicion >= 60) {
        std::cout << "Your cover collapses. At dawn you are shot.\n"
                  << "*** MISSION FAILED ***\n";
    } else {
        std::cout << "The rebel shrugs. \"Get out of my sight, merchant.\"\n"
                  << "You slip away at dusk with the intelligence intact.\n"
                  << "*** MISSION COMPLETE ***\n";
    }
    std::cout << "Final suspicion: " << suspicion << "/100\n";
}
