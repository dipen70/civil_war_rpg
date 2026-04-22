//  RebelLeader.cpp  —  Scenario for the hidden rebel leader.
#include "RebelLeader.h"
#include <iostream>

RebelLeader::RebelLeader(const std::string& publicName, const std::string& rank)
    : Character(publicName), secretRank(rank) {}

// OVERRIDING: rebel leader–specific introduction.
void RebelLeader::introduce() const {
    std::cout << "I am " << name
              << ", clerk of the War Department. (Secretly: "
              << secretRank << ".)\n";
}

// Three colleague questions inside a Union gov office.
// Right lie = safe; wrong answer = +40 suspicion.
// 60 or more suspicion = arrested for treason.
void RebelLeader::playScenario() {
    std::cout << "\n=== THE REBEL LEADER — Washington War Office, 1863 ===\n";
    std::cout << "A colleague from the next desk leans over, curious.\n\n";

    int choice = 0;

    std::cout << "COLLEAGUE: \"You were in the records room late last night. Why?\"\n"
              << "  1) Filing the Tennessee supply reports, as ordered.\n"
              << "  2) I... wanted some quiet to think.\n> ";
    std::cin >> choice;
    if (choice != 1) suspicion += 40;

    std::cout << "\nCOLLEAGUE: \"Who were you writing to on Department paper?\"\n"
              << "  1) My sister in Ohio — she worries.\n"
              << "  2) Nobody. You must be mistaken.\n> ";
    std::cin >> choice;
    if (choice != 1) suspicion += 40;

    std::cout << "\nCOLLEAGUE: \"I saw a Virginia seal in your drawer. Explain.\"\n"
              << "  1) A souvenir from the captured mail we logged Tuesday.\n"
              << "  2) That drawer isn't mine.\n> ";
    std::cin >> choice;
    if (choice != 1) suspicion += 40;

    std::cout << "\n----------------------------------------------------\n";
    if (suspicion >= 60) {
        std::cout << "Your colleague calls the guards. You are arrested\n"
                  << "and tried for treason within the week.\n"
                  << "*** MISSION FAILED ***\n";
    } else {
        std::cout << "Your colleague nods, satisfied, and returns to work.\n"
                  << "Your cover holds. The rebellion still has its man inside.\n"
                  << "*** MISSION COMPLETE ***\n";
    }
    std::cout << "Final suspicion: " << suspicion << "/100\n";
}
