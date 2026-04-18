#pragma once
// ============================================================
//  Character.h  —  Abstract Base Class
//  OOP Demonstrated:
//    • ENCAPSULATION  : private data + public getters/setters
//    • ABSTRACTION    : pure-virtual interface forces derived
//                       classes to define their own behaviour
// ============================================================
#include <string>
#include <iostream>

class Character {
private:
    // ── ENCAPSULATION: data hidden from the outside world ──
    std::string name;
    int         health;
    bool        alive;

protected:
    // Shared among derived classes but not public
    int suspicionLevel;   // 0-100; reaching 100 = game over

public:
    // ─── Constructor / Destructor ──────────────────────────
    Character(const std::string& name, int health);
    virtual ~Character() = default;

    // ─── Getters (ENCAPSULATION) ───────────────────────────
    const std::string& getName()          const;
    int                getHealth()        const;
    bool               isAlive()          const;
    int                getSuspicionLevel()const;

    // ─── Setters (ENCAPSULATION) ───────────────────────────
    void setSuspicionLevel(int level);
    void increaseSuspicion(int amount);
    void setAlive(bool status);

    // ─── Pure Virtual Functions (ABSTRACTION) ──────────────
    // Every concrete character MUST provide these
    virtual std::string getRole()        const = 0;
    virtual std::string getCoverStory()  const = 0;
    virtual std::string getMission()     const = 0;

    // ─── Virtual Functions (POLYMORPHISM) ──────────────────
    // Derived classes may override for custom behaviour
    virtual void speak(const std::string& message) const;
    virtual void displayStatus()                   const;
};
