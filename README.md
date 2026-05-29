# Number Guessing Game — Upgraded

A terminal-based game written in C. Features difficulty levels, attempt limits, a score system, and replay — compiled with GCC, zero external dependencies.

---

## Table of Contents

1. [Features Overview](#features-overview)
2. [Difficulty Levels](#difficulty-levels)
3. [Score System](#score-system)
4. [Game Flow](#game-flow)

---

### Features Overview

| Feature | Description |
|---|---|
| Difficulty levels | Easy / Medium / Hard — different range and attempt limit per level |
| Limited attempts | Exhaust your tries and it's Game Over — the secret number is revealed |
| Score system | Fewer guesses → higher score, scaled by difficulty multiplier |
| Replay option | Win or lose, choose to restart instantly with a fresh round |
| Live hints | "Try higher number" / "Try lower number" after every guess, with remaining attempts shown |
| Pure C stdlib | Only `<stdio.h>`, `<stdlib.h>`, `<time.h>` — no external libraries needed |

---

## Difficulty Levels

| Level | Number Range | Max Attempts | Notes |
|---|---|---|---|
| Easy | 1 – 100 | 10 tries | Ideal for first run |
| Medium | 1 – 200 | 8 tries | Binary search pays off here |
| Hard | 1 – 500 | 6 tries | Near-impossible without strategy |

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

**Sample session:**

Welcome to the Number Guessing Game!
Choose difficulty: [1] Easy  [2] Medium  [3] Hard

2

Medium selected — guess a number between 1 and 100.
You have 8 attempts.

50   → Too low!
75   → Too high!
63   → Too low!
69   → 🎉 Correct! Solved in 4 guesses. Score: 500

Play again? (y/n): y

---

## Game Flow

1. **Seed the RNG** — `srand(time(NULL))` ensures a different number each run
2. **Player selects difficulty** — sets the number range and attempt limit via `scanf` input
3. **Secret number generated** — `rand() % range + 1` picks a number within the chosen difficulty
4. **Guess loop runs** — each guess prints "Too high", "Too low", or correct, plus remaining attempts
5. **Win or Game Over** — correct guess prints score; attempts exhausted reveals the number
6. **Replay prompt** — enter `y` to restart, `n` to exit


