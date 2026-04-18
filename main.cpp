// ============================================================
//  main.cpp  —  Program Entry Point
//  Keeps main() minimal — all logic lives in GameEngine.
//  This follows the principle of Separation of Concerns,
//  a cornerstone of MODULAR PROGRAMMING.
// ============================================================
#include "GameEngine.h"

int main() {
    GameEngine engine;
    engine.run();
    return 0;
}
