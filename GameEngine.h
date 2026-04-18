#pragma once
// ============================================================
//  GameEngine.h  —  Core Game Loop Controller
//  Demonstrates MODULAR PROGRAMMING: isolates game-state and
//  flow logic from dialogue content and character data.
//  Uses base-class pointers for POLYMORPHISM at runtime.
// ============================================================
#include "Character.h"
#include "Spy.h"
#include "RebelLeader.h"
#include "DialogueManager.h"
#include <memory>

class GameEngine {
private:
    // ── State ────────────────────────────────────────────
    bool        gameRunning;
    bool        playerWon;
    int         currentNode;
    bool        isSpyPath;

    // ── Characters ───────────────────────────────────────
    // POLYMORPHISM: base-class pointers hold derived objects
    std::unique_ptr<Character> playerCharacter;
    std::unique_ptr<Character> npcCharacter;

    // ── Subsystems ───────────────────────────────────────
    DialogueManager dialogueManager;

    // ── Private helpers ──────────────────────────────────
    void printBanner()          const;
    void printIntro()           const;
    void printEpilogue()        const;
    void chooseCharacter();
    void checkSuspicion();
    void printSuspicionBar()    const;

public:
    GameEngine();
    void run();
};
