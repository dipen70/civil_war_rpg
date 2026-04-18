# Shadows of the Gray — Civil War Intelligence RPG

A C++ command-line RPG set during the American Civil War (1863) that demonstrates all four pillars of Object-Oriented Programming and modular programming best practices.

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [File Structure](#file-structure)
3. [OOP Principles Demonstrated](#oop-principles-demonstrated)
4. [Gameplay Guide](#gameplay-guide)
5. [How to Compile and Run](#how-to-compile-and-run)
6. [Character Paths](#character-paths)
7. [Win / Lose Conditions](#win--lose-conditions)

---

## Project Overview

You play as one of two undercover operatives during the Civil War:

- **The Spy** — A Union intelligence agent captured by Confederate rebels. Survive interrogation and escape.
- **The Rebel Leader** — A Confederate colonel who is secretly a Union double agent. Complete an arms deal while sabotaging it from within.

The game progresses through 6 dialogue exchanges. Each scene presents 4 choices. Wrong choices raise suspicion; if suspicion reaches 100/100 or a critical blunder is made, the mission fails.

---

## File Structure

```
civil_war_rpg/
├── main.cpp              — Entry point (minimal, delegates to GameEngine)
├── Character.h/.cpp      — Abstract base class (Encapsulation + Abstraction)
├── Spy.h/.cpp            — Derived class (Inheritance + Polymorphism)
├── RebelLeader.h/.cpp    — Derived class (Inheritance + Polymorphism)
├── DialogueManager.h/.cpp— All story content and choice evaluation
├── GameEngine.h/.cpp     — Game loop, state management, UI
├── Makefile              — Build automation
└── README.md             — This file
```

---

## OOP Principles Demonstrated

### 1. Encapsulation
**Where:** `Character.h`, `Spy.h`, `RebelLeader.h`

Every class hides its data behind `private:` access specifiers. External code interacts only through controlled `public` getters and setters.

```cpp
// Character.h
private:
    std::string name;        // Cannot be accessed directly
    int         health;
    bool        alive;

public:
    const std::string& getName()   const;   // Controlled read access
    void setSuspicionLevel(int);            // Validated write access
```

The `setSuspicionLevel()` setter applies `std::clamp` to prevent invalid values (0–100), enforcing business logic at the boundary.

---

### 2. Abstraction
**Where:** `Character.h` — pure virtual functions

`Character` is an **abstract class** (cannot be instantiated directly). It declares a contract that all derived characters must fulfil. Users of the `Character*` pointer don't need to know which concrete type they're working with.

```cpp
// Character.h — pure virtual = abstract interface
virtual std::string getRole()       const = 0;
virtual std::string getCoverStory() const = 0;
virtual std::string getMission()    const = 0;
```

Neither `Spy` nor `RebelLeader` can skip implementing these — the compiler enforces the contract.

---

### 3. Inheritance
**Where:** `Spy.h`, `RebelLeader.h`

Both `Spy` and `RebelLeader` extend `Character` using `public` inheritance. They reuse the base class constructor, `speak()`, `displayStatus()`, and all getters/setters without duplicating code.

```cpp
class Spy : public Character {          // IS-A relationship
    // Spy adds: coverIdentity, agentCode, identityExposed
};

class RebelLeader : public Character {  // IS-A relationship
    // RebelLeader adds: publicTitle, dealProgress, secretExposed
};
```

Each derived class calls `Character::Character(name, health)` via the initializer list, respecting the base class invariants.

---

### 4. Polymorphism
**Where:** `GameEngine.cpp`, `Character.h/.cpp`, `Spy.cpp`, `RebelLeader.cpp`

`GameEngine` stores `playerCharacter` and `npcCharacter` as `std::unique_ptr<Character>` — base class pointers. At runtime, the actual type (`Spy` or `RebelLeader`) determines which `speak()` and `displayStatus()` run.

```cpp
// GameEngine.h
std::unique_ptr<Character> playerCharacter;   // base pointer
std::unique_ptr<Character> npcCharacter;

// GameEngine.cpp — runtime dispatch (POLYMORPHISM)
playerCharacter->speak("Keep your nerve.");   // Calls Spy::speak() or
                                              // RebelLeader::speak()
                                              // depending on actual type
```

Each derived class overrides `speak()` with a distinct format, so the same call produces different output depending on who the player chose.

---

## Gameplay Guide

1. **Choose your character** (1 = Spy, 2 = Rebel Leader)
2. **Read the scene** — each scene sets the atmosphere and presents the NPC's challenge
3. **Choose your response** — type 1, 2, 3, or 4 and press Enter
4. **Watch the suspicion bar** — it fills as you make riskier choices
5. **Survive all 6 scenes** to win

**Suspicion Levels:**
| Range     | Status        | Meaning                          |
|-----------|---------------|----------------------------------|
| 0–24      | LOW           | Cover is solid                   |
| 25–49     | MODERATE      | They have doubts                 |
| 50–74     | HIGH          | You are being watched closely    |
| 75–99     | CRITICAL      | One mistake ends everything      |
| 100       | BLOWN         | Immediate game over              |

A single choice with `suspicionDelta >= 45` also triggers immediate game over — some answers are simply fatal.

---

## How to Compile and Run

### Requirements
- A C++17-compatible compiler (`g++` recommended, version 7+)
- `make` (optional, for Makefile use)

### Option 1: Using Make (recommended)
```bash
cd civil_war_rpg
make          # Compile all files
./civil_war_rpg
```

Other Makefile targets:
```bash
make run      # Compile and run immediately
make clean    # Remove all .o files and the binary
```

### Option 2: Manual Compilation
```bash
g++ -std=c++17 -Wall -O2 \
    main.cpp Character.cpp Spy.cpp RebelLeader.cpp \
    DialogueManager.cpp GameEngine.cpp \
    -o civil_war_rpg

./civil_war_rpg
```

### Option 3: Windows (MinGW)
```cmd
g++ -std=c++17 -Wall -O2 main.cpp Character.cpp Spy.cpp RebelLeader.cpp DialogueManager.cpp GameEngine.cpp -o civil_war_rpg.exe
civil_war_rpg.exe
```

---

## Character Paths

### Path 1 — The Spy (Agent Thomas Harrison)
- **Cover identity:** Elias Webb, dry-goods merchant
- **Opponent NPC:** Colonel Whitmore
- **6 scenes:**
  1. Initial interrogation — establish cover
  2. The suspicious map — explain compromising evidence
  3. Trade route knowledge test — prove you are a merchant
  4. A soldier claims to recognise you — deflect the accusation
  5. A telegraph exposes your cover story — negotiate your way out
  6. A sentry blocks the escape route — bluff your way past

### Path 2 — The Rebel Leader (Colonel James Whitmore)
- **Secret role:** Union double agent
- **Opponent NPC:** Viktor Schell, arms dealer
- **6 scenes:**
  1. Establish trust with the arms dealer
  2. Schell tests your loyalty — stay calm
  3. Steer the delivery to the Union ambush route
  4. Your own soldier grows suspicious — manage him
  5. Schell demands proof of Confederate authorization
  6. The shipment reaches Harper's Ferry — walk away clean

---

## Win / Lose Conditions

| Condition                              | Result       |
|----------------------------------------|--------------|
| Complete all 6 scenes correctly        | MISSION COMPLETE |
| Choose an answer with delta >= 45      | IMMEDIATE GAME OVER |
| Suspicion bar reaches 100              | GAME OVER (blown cover) |
| Reach final scene with correct answer  | WIN          |

---

## Design Notes

- `DialogueManager` is intentionally separate from `GameEngine` — story content and game logic are independent modules. Swapping the dialogue content requires no changes to the engine.
- `Character` uses a virtual destructor to ensure correct cleanup when deleting derived objects through a base pointer.
- `std::unique_ptr` is used for automatic memory management — no manual `delete` calls needed.
- `std::clamp` in `setSuspicionLevel()` demonstrates defensive programming inside a setter.

---

*Compile. Choose a side. Don't get caught.*
