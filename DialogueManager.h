#pragma once
// ============================================================
//  DialogueManager.h  —  Dialogue Engine
//  Handles all in-game conversations, choice trees, and
//  outcome evaluation.  Demonstrates MODULAR PROGRAMMING by
//  isolating dialogue concerns from game logic.
// ============================================================
#include <string>
#include <vector>

// ─── Data Structures ──────────────────────────────────────

struct Choice {
    std::string text;           // The option displayed to the player
    bool        isCorrect;      // Does this advance the story safely?
    std::string consequence;    // Narrative response text
    int         suspicionDelta; // +ve = more suspicious; -ve = less
};

struct DialogueNode {
    std::string          situation;    // Scene description
    std::string          npcLine;      // NPC's spoken line
    std::vector<Choice>  choices;      // Four player options
};

// Result of processing a single dialogue node
struct DialogueResult {
    bool playerWins;        // true = continue / succeed
    bool gameover;          // true = player is caught
    int  suspicionChange;   // How much suspicion shifted
    std::string message;    // What happened
};

// ─── DialogueManager Class ────────────────────────────────

class DialogueManager {
private:
    // Pre-built dialogue trees for each character path
    std::vector<DialogueNode> spyDialogues;
    std::vector<DialogueNode> rebelDialogues;

    // Internal helpers
    void buildSpyDialogues();
    void buildRebelDialogues();
    void printDivider()              const;
    void printSituation(const DialogueNode& node) const;
    int  promptPlayerChoice(const DialogueNode& node) const;

public:
    DialogueManager();

    // Present a single dialogue node and collect player response
    DialogueResult runNode(int nodeIndex, bool isSpyPath) const;

    // Return total count of nodes for a given path
    int getNodeCount(bool isSpyPath) const;
};
