#pragma once
// ============================================================
//  RebelLeader.h  —  Derived Class (extends Character)
//  OOP Demonstrated:
//    • INHERITANCE   : RebelLeader IS-A Character
//    • POLYMORPHISM  : own speak() + displayStatus()
//    • ENCAPSULATION : leader-specific private data
// ============================================================
#include "Character.h"

class RebelLeader : public Character {    // ← INHERITANCE
private:
    // ENCAPSULATION: RebelLeader-specific hidden data
    std::string publicTitle;              // What rebels call him
    std::string secretHandlerName;        // Union contact name
    int         dealProgress;            // 0-100 % of arms deal completed
    bool        secretExposed;

public:
    RebelLeader(const std::string& realName,
                const std::string& publicTitle,
                const std::string& secretHandlerName);

    // RebelLeader-specific getters/setters
    const std::string& getPublicTitle()       const;
    const std::string& getSecretHandlerName() const;
    int                getDealProgress()      const;
    bool               isSecretExposed()      const;
    void               advanceDeal(int amount);
    void               exposeSecret();

    // ── POLYMORPHISM: override base class virtuals ──────────
    std::string getRole()        const override;
    std::string getCoverStory()  const override;
    std::string getMission()     const override;
    void        speak(const std::string& message) const override;
    void        displayStatus()                   const override;
};
