# Shadows of the Gray

A tiny C++ dialogue RPG set in the American Civil War, 1863.
Built as a teaching project: every file demonstrates a specific
Object-Oriented Programming concept.

## The game

Pick one of two characters and survive a three-question interrogation.

- **The Spy** — a Union agent captured by Confederate rebels. Lie
  about your identity, your business, and the coded notes in your
  coat. Fail and you are shot at dawn.
- **The Rebel Leader** — a Confederate colonel hidden inside a
  Union war office. A suspicious colleague grills you about your
  late-night visits and a Virginia seal in your drawer. Fail and
  you are arrested for treason.

Each wrong answer adds 40 to your *suspicion* score.
A suspicion of 60 or more means you lose.

## Build & run

On Windows with MinGW / g++:

```bash
g++ -std=c++17 *.cpp -o civil_war_rpg
./civil_war_rpg
```

Or inside VS Code, press `Ctrl+Alt+N` — the included
[.vscode/settings.json](.vscode/settings.json) configures the Code
Runner extension to compile all `.cpp` files in one shot.

## File layout

| File | Purpose |
|------|---------|
| `Character.h` | Abstract base class. Defines what every character has (name, suspicion) and what every character must do (`playScenario`). |
| `Spy.h` / `Spy.cpp` | The spy character: data, introduction, three-question scenario. |
| `RebelLeader.h` / `RebelLeader.cpp` | The rebel leader character: data, introduction, three-question scenario. |
| `main.cpp` | Menu, character selection, and the polymorphic game loop. |
| `CONCEPTS.md` | A walkthrough of where each OOP concept lives in the code. |

## OOP concepts demonstrated

- **Encapsulation** — `name` and `suspicion` are `protected`; access
  goes through getters.
- **Inheritance** — `Spy` and `RebelLeader` both `: public Character`.
- **Polymorphism** — `main.cpp` holds a `std::unique_ptr<Character>`
  that points at either derived object and calls virtual methods
  through it.
- **Abstraction** — `Character::playScenario()` is pure virtual, so
  `Character` can never be instantiated on its own.
- **Function overloading** — three versions of `speak()` with
  different parameter lists.
- **Function overriding** — `introduce()` and `playScenario()` are
  overridden in both derived classes.
- **Modular programming** — each character lives in its own
  `.h`/`.cpp` pair; `main.cpp` only sees the headers.
