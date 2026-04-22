#pragma once

//  RebelLeader.h  —  Confederate leader hiding inside a
//  Union government office. Inherits from Character and
//  overrides its virtual methods.

#include "Character.h"

class RebelLeader : public Character {
private:
    // ENCAPSULATION: secret rank is private to RebelLeader.
    std::string secretRank;

public:
    RebelLeader(const std::string& publicName, const std::string& rank);

    // OVERRIDING: role-specific introduction.
    void introduce() const override;

    // Implements the abstract method from Character.
    void playScenario() override;
};
