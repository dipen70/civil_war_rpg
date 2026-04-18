#pragma once
// ============================================================
//  Spy.h  —  Derived Class (extends Character)
//  OOP Demonstrated:
//    • INHERITANCE   : Spy IS-A Character
//    • POLYMORPHISM  : overrides speak() and displayStatus()
//    • ENCAPSULATION : spy-specific private data
// ============================================================
#include "Character.h"

class Spy : public Character {           // ← INHERITANCE
private:
    // ENCAPSULATION: Spy-specific hidden data
    std::string coverIdentity;           // False name used in the field
    std::string agentCode;               // Secret identifier
    bool        identityExposed;

public:
    Spy(const std::string& realName,
        const std::string& coverIdentity,
        const std::string& agentCode);

    // Spy-specific getters
    const std::string& getCoverIdentity() const;
    const std::string& getAgentCode()     const;
    bool               isIdentityExposed()const;
    void               exposeIdentity();

    // ── POLYMORPHISM: override base class virtuals ──────────
    std::string getRole()        const override;
    std::string getCoverStory()  const override;
    std::string getMission()     const override;
    void        speak(const std::string& message) const override;
    void        displayStatus()                   const override;
};
