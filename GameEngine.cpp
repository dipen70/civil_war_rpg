// ============================================================
//  GameEngine.cpp  —  Core Game Loop Implementation
// ============================================================
#include "GameEngine.h"
#include <iostream>
#include <string>
#include <limits>
#include <thread>
#include <chrono>

// ─── Utility: brief pause for atmosphere ──────────────────
static void pause(int ms = 800) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// ─── Constructor ──────────────────────────────────────────
GameEngine::GameEngine()
    : gameRunning(false), playerWon(false),
      currentNode(0), isSpyPath(true) {}

// ─── Banner ───────────────────────────────────────────────
void GameEngine::printBanner() const {
    std::cout << R"(
╔══════════════════════════════════════════════════════════╗
║                                                          ║
║      S H A D O W S   O F   T H E   G R A Y              ║
║      A Civil War Intelligence RPG  •  1863               ║
║                                                          ║
╚══════════════════════════════════════════════════════════╝
)";
}

// ─── Introduction ─────────────────────────────────────────
void GameEngine::printIntro() const {
    std::cout << R"(
The American Civil War, 1863.
Battlefields roar with cannon fire — but the war is also
fought in shadows, across candlelit tables and midnight roads.

You are about to step into one of those shadows.
Choose your role carefully. One wrong word ends everything.

)";
}

// ─── Character selection ──────────────────────────────────
void GameEngine::chooseCharacter() {
    std::cout << "══════════════════════════════════════════════════════════\n";
    std::cout << "  SELECT YOUR CHARACTER\n";
    std::cout << "══════════════════════════════════════════════════════════\n\n";

    std::cout << "  [1]  THE SPY — Agent Thomas Harrison\n"
              << "       Cover name : Elias Webb, traveling merchant\n"
              << "       Situation  : Captured by Confederate rebels.\n"
              << "                    Must survive interrogation and escape.\n\n";

    std::cout << "  [2]  THE REBEL LEADER — Colonel James Whitmore\n"
              << "       Secret      : A Union double agent.\n"
              << "       Situation   : Negotiating an arms deal.\n"
              << "                    Must complete the deal AND sabotage it.\n\n";

    std::cout << "Your choice (1 or 2): ";

    int choice = 0;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  Please enter 1 or 2: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    if (choice == 1) {
        // POLYMORPHISM: Spy stored as Character pointer
        isSpyPath = true;
        playerCharacter = std::make_unique<Spy>(
            "Thomas Harrison", "Elias Webb", "CARDINAL-7");
        npcCharacter    = std::make_unique<RebelLeader>(
            "Whitmore", "Colonel Whitmore", "Agent Fox");

        std::cout << "\n  >> You chose: The Spy\n\n";
        pause();
        playerCharacter->speak("Keep your cover. Keep your nerve. Get out alive.");
        pause();
        std::cout << "\n  Mission: " << playerCharacter->getMission() << "\n";
        std::cout << "  Cover  : " << playerCharacter->getCoverStory() << "\n\n";

    } else {
        // POLYMORPHISM: RebelLeader stored as Character pointer
        isSpyPath = false;
        playerCharacter = std::make_unique<RebelLeader>(
            "Whitmore", "Colonel Whitmore", "Agent Fox");
        npcCharacter    = std::make_unique<Spy>(
            "Thomas Harrison", "Elias Webb", "CARDINAL-7");

        std::cout << "\n  >> You chose: The Rebel Leader\n\n";
        pause();
        playerCharacter->speak("Play the rebel. Think like the Union. Trust no one.");
        pause();
        std::cout << "\n  Mission: " << playerCharacter->getMission() << "\n";
        std::cout << "  Cover  : " << playerCharacter->getCoverStory() << "\n\n";
    }

    pause(1200);
}

// ─── Suspicion bar ────────────────────────────────────────
void GameEngine::printSuspicionBar() const {
    int level = playerCharacter->getSuspicionLevel();
    int bars  = level / 5;
    std::cout << "\n  Suspicion [";
    for (int i = 0; i < 20; ++i)
        std::cout << (i < bars ? '#' : '.');
    std::cout << "] " << level << "/100\n";

    if (level >= 75)
        std::cout << "  *** CRITICAL — One wrong move and it's over ***\n";
    else if (level >= 50)
        std::cout << "  ** HIGH — They are watching you closely **\n";
    else if (level >= 25)
        std::cout << "  * MODERATE — Stay calm and consistent *\n";
    else
        std::cout << "  LOW — Your cover is holding\n";
}

// ─── Suspicion check after each node ─────────────────────
void GameEngine::checkSuspicion() {
    if (playerCharacter->getSuspicionLevel() >= 100) {
        std::cout << "\n╔══════════════════════════════════════════════════════╗\n";
        std::cout << "║            SUSPICION MAXIMUM — GAME OVER             ║\n";
        std::cout << "╚══════════════════════════════════════════════════════╝\n";
        std::cout << "\nYour cover has collapsed under accumulated suspicion.\n"
                  << "They know who you are. The mission ends here.\n\n";
        gameRunning = false;
        playerWon   = false;
    }
}

// ─── Ending screen ────────────────────────────────────────
void GameEngine::printEpilogue() const {
    if (playerWon) {
        std::cout << "\n╔══════════════════════════════════════════════════════╗\n";
        std::cout << "║                  MISSION COMPLETE                    ║\n";
        std::cout << "╚══════════════════════════════════════════════════════╝\n\n";

        if (isSpyPath) {
            std::cout <<
                "You reach the Union lines three hours before dawn.\n"
                "The intelligence you carry — troop positions, supply routes,\n"
                "the identity of a Confederate general open to bribery — is\n"
                "worth more than a regiment.\n\n"
                "Colonel Whitmore's decision to let you walk is never explained\n"
                "in any official report. Some secrets survive even historians.\n\n"
                "Agent Harrison is promoted to Senior Field Officer.\n"
                "He never returns to Virginia.\n\n";
        } else {
            std::cout <<
                "The Union soldiers take the wagons and the rifles without\n"
                "a single Confederate casualty — because none of Whitmore's\n"
                "real men were at the crossing.\n\n"
                "Schell disappears into Europe. Crabb is transferred to Texas.\n"
                "The Confederate command blames a leak in Richmond.\n\n"
                "Colonel Whitmore rides north the following week,\n"
                "officially 'on leave.' He does not come back.\n\n"
                "The war ends two years later. The double agent who helped\n"
                "is mentioned in no history book. That was always the arrangement.\n\n";
        }
    } else {
        std::cout << "\n╔══════════════════════════════════════════════════════╗\n";
        std::cout << "║                   MISSION FAILED                     ║\n";
        std::cout << "╚══════════════════════════════════════════════════════╝\n\n";

        if (isSpyPath) {
            std::cout <<
                "Agent Harrison's real identity is confirmed within the week.\n"
                "He is tried as a spy under Confederate law and executed\n"
                "at dawn on a cold October morning.\n\n"
                "His name appears on no Union memorial.\n"
                "The mission dies with him.\n\n";
        } else {
            std::cout <<
                "Colonel Whitmore's double life is exposed.\n"
                "He is arrested by Confederate forces and executed\n"
                "for treason before Union agents can intervene.\n\n"
                "The arms deal goes through a different channel.\n"
                "The rifles reach Confederate lines two months later.\n\n";
        }
    }
    std::cout << "  Final Character Status:\n";
    playerCharacter->displayStatus();
    std::cout << "\nThank you for playing SHADOWS OF THE GRAY.\n\n";
}

// ─── Main Game Loop ───────────────────────────────────────
void GameEngine::run() {
    printBanner();
    pause(600);
    printIntro();
    chooseCharacter();

    gameRunning = true;
    int totalNodes = dialogueManager.getNodeCount(isSpyPath);

    std::cout << "\n  Press ENTER to begin your mission...";
    std::cin.get();

    while (gameRunning && currentNode < totalNodes) {
        printSuspicionBar();
        pause(400);

        DialogueResult result = dialogueManager.runNode(currentNode, isSpyPath);

        // Apply suspicion delta via polymorphic setter
        playerCharacter->increaseSuspicion(result.suspicionChange);

        pause(600);
        checkSuspicion();

        if (!gameRunning) break;   // Suspicion maxed

        if (result.gameover) {
            playerWon   = result.playerWins;
            gameRunning = false;
        } else {
            ++currentNode;

            if (currentNode < totalNodes) {
                std::cout << "\n  Press ENTER to continue...\n";
                std::cin.get();
            }
        }
    }

    // Reached end of dialogue tree without game-over
    if (gameRunning && currentNode >= totalNodes) {
        playerWon   = true;
        gameRunning = false;
    }

    printEpilogue();
}
