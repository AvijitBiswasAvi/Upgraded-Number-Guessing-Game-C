# Number Guessing Game — Upgraded

A terminal-based game written in C. Features difficulty levels, attempt limits, a score system, and replay — compiled with GCC, zero external dependencies.

---

## Table of Contents

1. [Features Overview](#features-overview)
2. [Difficulty Levels](#difficulty-levels)
3. [Score System](#score-system)
4. [Project Structure](#project-structure)
5. [Build & Run](#build--run)
6. [Game Flow](#game-flow)
7. [Roadmap](#roadmap)
8. [Contributing](#contributing)

---

## Features Overview

| Feature | Description |
|---|---|
| Difficulty levels | Easy / Medium / Hard — different range and attempt limit per level |
| Limited attempts | Exhaust your tries and it's Game Over — the secret number is revealed |
| Score system | Fewer guesses → higher score, scaled by difficulty multiplier |
| 🔁 Replay option | Win or lose, choose to restart instantly with a fresh round |
| 🔼🔽 Live hints | "Too high" / "Too low" after every guess, with remaining attempts shown |
| ⚙️ Pure C stdlib | Only `<stdio.h>`, `<stdlib.h>`, `<time.h>` — no external libraries needed |

---

## Difficulty Levels

| Level | Number Range | Max Attempts | Notes |
|---|---|---|---|
| Easy | 1 – 100 | 10 tries | Ideal for first run |
| Medium | 1 – 200 | 7 tries | Binary search pays off here |
| Hard | 1 – 500 | 5 tries | Near-impossible without strategy |

---
## Score System

Score is calculated after each successful round. Fewer guesses and harder difficulty yield more points.

score = (max_attempts - attempts_used + 1) x difficulty_multiplier 

| Difficulty | Multiplier |
|---|---|
| Easy | ×1 |
| Medium | ×2 |
| Hard | ×3 |

---

## Project Structure

number-guessing-game/
├── game.c          # all game logic — single source file
├── Makefile        # optional: build shortcut
├── README.md
└── LICENSE

---

## Build & Run

**Requirements:** GCC or Clang, any OS with a C99-compatible compiler.

```bash
# clone
git clone https://github.com/your-username/number-guessing-game
cd number-guessing-game

# compile with gcc
gcc -std=c99 -Wall -o game game.c

# or with clang
clang -std=c99 -Wall -o game game.c

# run
./game
```

**Optional Makefile:**

```makefile
CC     = gcc
CFLAGS = -std=c99 -Wall -Wextra

all:
	$(CC) $(CFLAGS) -o game game.c

clean:
	rm -f game
```

**Headers used:**

```c
#include <stdio.h>    // printf, scanf
#include <stdlib.h>   // rand, srand
#include <time.h>     // time() for srand seed
```

**Sample session:**

Welcome to the Number Guessing Game!
Choose difficulty: [1] Easy  [2] Medium  [3] Hard

2

Medium selected — guess a number between 1 and 100.
You have 7 attempts.

50   → Too low!
75   → Too high!
63   → Too low!
69   → 🎉 Correct! Solved in 4 guesses. Score: 8

Play again? (y/n): y

---

## Game Flow

1. **Seed the RNG** — `srand(time(NULL))` ensures a different number each run
2. **Player selects difficulty** — sets the number range and attempt limit via `scanf` input
3. **Secret number generated** — `rand() % range + 1` picks a number within the chosen difficulty
4. **Guess loop runs** — each guess prints "Too high", "Too low", or correct, plus remaining attempts
5. **Win or Game Over** — correct guess prints score; attempts exhausted reveals the number
6. **Replay prompt** — enter `y` to restart, `n` to exit

---

## Roadmap

### ✅ Completed
- `rand()` number generation
- Guess loop + hints
- Attempt counter
- Difficulty selection
- Attempt limit + Game Over
- Replay prompt
- Score calculation

### 🔄 Ideas to Add
- High score saved to file (`fwrite`)
- Input validation loop
- Hot/cold proximity hints
- Session leaderboard

### 🔮 Future Scope
- `ncurses` TUI interface
- Two-player mode
- Cross-platform Makefile
- Unit tests with CMocka

---

## Contributing

Contributions are welcome. Fork the repo, create a branch (`feature/your-idea`), and open a pull request. Keep code readable — descriptive variable names, comments on non-obvious logic — and make sure it compiles cleanly with `-Wall -Wextra` before submitting.

Found a bug? Open an issue with your OS, compiler version, and steps to reproduce.

---

MIT License · written in C99 · compiled with `gcc` · no external dependencies
