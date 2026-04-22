# Concepts Cheat-Sheet

A line-by-line guide to what to point at when you explain this
project. Each section lists the concept, the file and lines where
it lives, and a one-sentence explanation you can say out loud.

---

## 1. Encapsulation

> "The character's data is hidden from outside code — you can only
> touch it through the class's own methods."

**Where:** [Character.h](Character.h), lines 14–16 and 21–22.

```cpp
protected:
    std::string name;   // hidden
    int suspicion;      // hidden

public:
    std::string getName() const { return name; }
    int getSuspicion() const { return suspicion; }
```

- `name` and `suspicion` are `protected`: outside code cannot read
  or write them directly.
- `getName()` and `getSuspicion()` give *controlled* read access.
- Same idea in [Spy.h](Spy.h) (`coverName` is `private`) and
  [RebelLeader.h](RebelLeader.h) (`secretRank` is `private`).

**To say:** *"If I make these public, any code anywhere can corrupt
them. Keeping them private forces changes to go through the class."*

---

## 2. Inheritance

> "Spy and RebelLeader are both Characters — they inherit the
> name, suspicion, and speak() methods and add their own on top."

**Where:** [Spy.h:10](Spy.h#L10) and [RebelLeader.h:10](RebelLeader.h#L10)

```cpp
class Spy : public Character { ... };
class RebelLeader : public Character { ... };
```

Both derived classes reuse:
- the `name` / `suspicion` members from `Character`
- the three `speak()` overloads
- the `Character(const std::string&)` constructor, called from
  the derived constructor initialiser list (`: Character(realName)`)

**To say:** *"I wrote the shared data and behaviour once in
Character. Spy and RebelLeader just add what is specific to them."*

---

## 3. Polymorphism

> "One pointer, two possible objects — the right method runs
> depending on which object it actually points to."

**Where:** [main.cpp:25–30](main.cpp#L25-L30)

```cpp
std::unique_ptr<Character> player;
if (choice == 1)
    player = std::make_unique<Spy>("Thomas Harrison", "Elias Webb");
else
    player = std::make_unique<RebelLeader>("Colonel Whitmore", "Agent Fox");

player->introduce();     // runs Spy::introduce OR RebelLeader::introduce
player->playScenario();  // runs Spy::playScenario OR RebelLeader::playScenario
```

The `player` variable is typed `Character*` (under the smart
pointer). At runtime, C++ looks at what object it actually points
to and calls the matching override. That is **runtime polymorphism**,
made possible by the `virtual` keyword in `Character`.

**To say:** *"main.cpp never mentions Spy or RebelLeader after the
object is created — it only talks to a Character pointer. Adding a
new character type would not change main's logic at all."*

---

## 4. Abstraction

> "Character describes *what* a character does, not *how*. You
> cannot create a plain Character — each role must fill in the
> blank itself."

**Where:** [Character.h:44](Character.h#L44)

```cpp
virtual void playScenario() = 0;   // pure virtual
```

The `= 0` makes `Character` **abstract**. Try writing
`Character c("x");` — the compiler refuses, because there is no
body for `playScenario`.

`Spy::playScenario()` and `RebelLeader::playScenario()` supply the
missing implementation.

**To say:** *"Character is a contract: 'every character must have a
scenario.' The base class does not decide what happens in it."*

---

## 5. Function Overloading

> "Same function name, different parameter lists. The compiler
> picks which one to call based on the arguments."

**Where:** [Character.h:27–35](Character.h#L27-L35)

```cpp
void speak() const;                                     // 1
void speak(const std::string& line) const;              // 2
void speak(const std::string& line, int volume) const;  // 3
```

[main.cpp:33–35](main.cpp#L33-L35) calls all three:

```cpp
player->speak();                      // picks #1
player->speak("Keep your nerve.");    // picks #2
player->speak("Not a word.", 2);      // picks #3
```

**To say:** *"Overloading is resolved at **compile** time, by the
argument types. Do not confuse it with overriding, which happens at
**run** time based on the actual object."*

---

## 6. Function Overriding

> "A derived class replaces a virtual method from its base."

**Where:**
- [Character.h:38–40](Character.h#L38-L40) — the virtual method
- [Spy.cpp:12–16](Spy.cpp#L12-L16) — Spy's override
- [RebelLeader.cpp:12–16](RebelLeader.cpp#L12-L16) — RebelLeader's override

```cpp
// Base
virtual void introduce() const { std::cout << "I am " << name << ".\n"; }

// Spy
void Spy::introduce() const {
    std::cout << "I am " << name << ", Union intelligence. Cover name: "
              << coverName << ".\n";
}
```

The `override` keyword in the derived class is not required but is
a safety net — the compiler will complain if the signature does
not match a virtual method in the base.

**To say:** *"Overloading = different parameters, same class.
Overriding = same signature, derived class, replaces behaviour."*

---

## 7. Modular Programming

> "Each character is its own module. main.cpp only touches headers,
> never the internals."

**Where:** the file layout itself.

- `Character.h` — just the interface.
- `Spy.h` / `Spy.cpp` — declaration + implementation for one role.
- `RebelLeader.h` / `RebelLeader.cpp` — same for the other role.
- `main.cpp` — wiring. Includes `Spy.h` and `RebelLeader.h`. Never
  touches their `.cpp` files directly.

If you add a third character (say, `Sympathiser.h`/`Sympathiser.cpp`),
the existing modules do not need to change.

**To say:** *"Separation of concerns. Each file has one reason to
change. Smaller modules are easier to test, reason about, and reuse."*

---

## 8. Quick answers for likely questions

**"Why `virtual ~Character() = default;`?"**
Because we delete a derived object through a base pointer
(`std::unique_ptr<Character>`). A virtual destructor guarantees the
derived destructor also runs. Without it, you leak the derived
parts. Rule of thumb: *any* class with virtual methods needs a
virtual destructor.

**"Why `std::unique_ptr` and not a raw `new`?"**
`unique_ptr` owns the object and destroys it automatically when it
goes out of scope. No manual `delete`, no leaks.

**"Why is `Character` in a header only, with no `Character.cpp`?"**
Every method is either inline in the class body or pure virtual —
there is simply nothing to put in a `.cpp`. Nothing requires you
to split declaration and definition when there is no body to
separate.

**"What would change if you added a third role?"**
1. New pair `NewRole.h` / `NewRole.cpp` that inherits from
   `Character` and implements `playScenario()`.
2. A new `else if` branch in `main.cpp` that constructs it.
3. That is it — the existing classes do not change. That is the
   Open/Closed principle: open to extension, closed to modification.

**"Where is the 'game state'?"**
Inside the character object itself — `suspicion` is a member
variable. The scenario method reads and writes it directly. There
is no separate game engine; each role runs its own scenario.

**"Why three questions and a fixed threshold?"**
Deliberate simplicity: three wrongs at +40 each = 120, two wrongs
= 80 (still a loss), one wrong = 40 (survives). One mistake is
forgivable, two is fatal. Easy to tweak by changing the `+= 40`
constant or the `>= 60` threshold.
