// ============================================================
//  RebelLeader.cpp  —  Derived Class Implementation
// ============================================================
#include "RebelLeader.h"

RebelLeader::RebelLeader(const std::string& realName,
                         const std::string& publicTitle,
                         const std::string& secretHandlerName)
    : Character(realName, 100),           // Call base constructor (INHERITANCE)
      publicTitle(publicTitle),
      secretHandlerName(secretHandlerName),
      dealProgress(0),
      secretExposed(false) {}

// ─── Getters / Setters ────────────────────────────────────
const std::string& RebelLeader::getPublicTitle()       const { return publicTitle;       }
const std::string& RebelLeader::getSecretHandlerName() const { return secretHandlerName; }
int                RebelLeader::getDealProgress()      const { return dealProgress;      }
bool               RebelLeader::isSecretExposed()      const { return secretExposed;     }

void RebelLeader::advanceDeal(int amount) {
    dealProgress = std::min(100, dealProgress + amount);
}
void RebelLeader::exposeSecret() { secretExposed = true; }

// ─── POLYMORPHISM: Overriding pure-virtual functions ──────
std::string RebelLeader::getRole() const {
    return "Confederate Colonel (Double Agent)";
}

std::string RebelLeader::getCoverStory() const {
    return "Fanatical Confederate leader seeking arms to fight the Union";
}

std::string RebelLeader::getMission() const {
    return "Complete the arms deal while secretly sabotaging it for the Union";
}

// ─── POLYMORPHISM: Leader speaks with commanding authority ─
void RebelLeader::speak(const std::string& message) const {
    std::cout << "  [Colonel " << getName() << "]: " << message << "\n";
}

// ─── POLYMORPHISM: displayStatus adds Leader-specific info ─
void RebelLeader::displayStatus() const {
    Character::displayStatus();   // Reuse base behaviour
    std::cout << "  Title     : " << publicTitle
              << "\n  Deal      : " << dealProgress << "% complete"
              << "\n  Exposed   : " << (secretExposed ? "YES — BLOWN!" : "No")
              << "\n";
}
