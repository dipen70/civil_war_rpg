#pragma once 
// ============================================================
//  Character.h  —  Abstract base class for every playable role.
//  Demonstrates ABSTRACTION (pure virtual method) and is the
//  anchor for INHERITANCE and POLYMORPHISM in this project.
// ============================================================
#include <string>
#include <iostream>

class Character {
protected:
    // ENCAPSULATION: data is hidden from outside code.
    // Derived classes can read/write these through protected access.
    std::string name; 
    int suspicion;

public:
    Character(const std::string& n) : name(n), suspicion(0) {}
    virtual ~Character() = default;

    // ENCAPSULATION: controlled read-only access via getters.
    std::string getName() const { return name; }
    int getSuspicion() const { return suspicion; }

    // FUNCTION OVERLOADING: three speak() versions, same name,
    // different parameter lists. The compiler picks the match.
    void speak() const {
        std::cout << name << " says nothing.\n";
    }
    void speak(const std::string& line) const { 
        std::cout << name << ": \"" << line << "\"\n";
    }
    void speak(const std::string& line, int volume) const {
        std::cout << name << " (vol " << volume << "): \"" << line << "\"\n";
    }

    // OVERRIDING (virtual): derived classes may replace this.
    virtual void introduce() const { 
        std::cout << "I am " << name << ".\n";
    }

    // ABSTRACTION: pure virtual — Character on its own cannot
    // be instantiated. Each role MUST provide its own scenario.
    virtual void playScenario() = 0;
};
