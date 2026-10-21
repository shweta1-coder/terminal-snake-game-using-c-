# terminal-snake-game-using-c-
a retro terminal snake game built from scratch in vanilla C
"I built a retro Snake game entirely from scratch in vanilla C that runs directly inside a text-based terminal. Instead of using heavy graphics libraries or game engines, I used fundamental programming logic—like a 2D coordinate grid, custom structures, and a continuous game loop—to handle real-time movement, collision detection, and score tracking."

Breakdown :
The Interface: It uses character-based rendering (# for walls, O for the snake head, and * for food) inside a 2D array grid.

The Logic: A while loop controls the game state—it takes user input (w/a/s/d), updates the snake's body segments trailing behind the head, and redraws the screen.

Collision & Scoring: It tracks coordinates to instantly trigger a game-over if the snake hits the walls or itself, and uses rand() to spawn food and increase the score dynamically.
