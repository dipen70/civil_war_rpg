// ============================================================
//  Spy.cpp  —  Derived Class Implementation
// ============================================================
#include "Spy.h"

Spy::Spy(const std::string& realName,
         const std::string& coverIdentity,
         const std::string& agentCode)
    : Character(realName, 100),          // Call base constructor (INHERITANCE)
      coverIdentity(coverIdentity),
      agentCode(agentCode),
      identityExposed(false) {}

// ─── Spy-specific Getters ─────────────────────────────────
const std::string& Spy::getCoverIdentity() const { return coverIdentity;     }
const std::string& Spy::getAgentCode()     const { return agentCode;         }
bool               Spy::isIdentityExposed()const { return identityExposed;   }
void               Spy::exposeIdentity()         { identityExposed = true;   }

// ─── POLYMORPHISM: Overriding pure-virtual functions ──────
std::string Spy::getRole() const {
    return "Union Intelligence Agent";
}

std::string Spy::getCoverStory() const {
    return "Traveling merchant from Cincinnati dealing in dry goods";
}

std::string Spy::getMission() const {
    return "Infiltrate Confederate camp, identify troop movements, escape alive";
}

// ─── POLYMORPHISM: Spy speaks in hushed, guarded tones ────
void Spy::speak(const std::string& message) const {
    std::cout << "  [" << coverIdentity << " (Spy)]: " << message << "\n";
}

// ─── POLYMORPHISM: displayStatus adds Spy-specific info ──
void Spy::displayStatus() const {
    Character::displayStatus();   // Reuse base behaviour
    std::cout << "  Cover     : " << coverIdentity
              << "\n  Exposed   : " << (identityExposed ? "YES — BLOWN!" : "No")
              << "\n";
}
