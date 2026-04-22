#pragma once
// ============================================================
//  Spy.h  —  Union spy captured by Confederate rebels.
//  Inherits from Character (INHERITANCE) and overrides
//  introduce() and playScenario() (OVERRIDING).
// ============================================================
#include "Character.h"

class Spy : public Character {
private:
    // ENCAPSULATION: coverName is private to Spy.
    std::string coverName;

public:
    Spy(const std::string& realName, const std::string& cover);

    // OVERRIDING: replaces Character::introduce().
    void introduce() const override;

    // Implements the abstract method from Character.
    void playScenario() override;
};
