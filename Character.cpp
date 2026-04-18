// ============================================================
//  Character.cpp  —  Abstract Base Class Implementation
// ============================================================
#include "Character.h"
#include <algorithm>   // std::clamp

// ─── Constructor ──────────────────────────────────────────
Character::Character(const std::string& name, int health)
    : name(name), health(health), alive(true), suspicionLevel(0) {}

// ─── Getters ──────────────────────────────────────────────
const std::string& Character::getName()           const { return name;           }
int                Character::getHealth()         const { return health;         }
bool               Character::isAlive()           const { return alive;          }
int                Character::getSuspicionLevel() const { return suspicionLevel; }

// ─── Setters ──────────────────────────────────────────────
void Character::setSuspicionLevel(int level) {
    suspicionLevel = std::max(0, std::min(100, level));
}

void Character::increaseSuspicion(int amount) {
    setSuspicionLevel(suspicionLevel + amount);
}

void Character::setAlive(bool status) {
    alive = status;
}

// ─── Virtual: speak  (POLYMORPHISM — derived classes override) ──
void Character::speak(const std::string& message) const {
    std::cout << "[" << name << "]: " << message << "\n";
}

// ─── Virtual: displayStatus ────────────────────────────────
void Character::displayStatus() const {
    std::cout << "\n  Character : " << name
              << "\n  Role      : " << getRole()
              << "\n  Suspicion : " << suspicionLevel << "/100\n";
}
