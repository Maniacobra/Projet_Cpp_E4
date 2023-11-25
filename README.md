# Introduction
This is the repository related to an **ESIEE** project which aims at programming a game, more precisely a space shooter, using SFML library and **ECS** architecture *(entity component system)*.
The aim of this project was to learn how to program on ECS code architectures.

# Implemented features
You can directly read the history of the repository to find implemented features. They are listed also below, in the same order as in the assignment:
* Rendering
* Background image display
* Movements
* Scene implementation, scene transition, menu scene
* Tag implementation
* Shooting system, **used by player as well as enemies**
* Missiles shots cooldown (Clock implementation that will be useful for other features too)
* Enemies, enemies spawner system.
* Collision and health management.
* Enemy movements and chasing.
* Health bar display.
* Countdown timer and its display.
* Scoring mechanism, score scene, score scene transition.
* Pause/Resume.
* Audio, sound effects and background music. **Note that you need OpenAL32 shared library in the same path as the executable binary**

It's important to note that some features might not be connected to entities, systems and components of the same name as in the assignment, but still made to respect the ECS architecture.

# List of systems
To make the structure of the project clearer, here is a list of all the systems and their purposes:
* AudioSystem: Used for playing music and SFX.
* ClockSystem: Used for player shooting, enemy shooting, timers, and enemy spawning.
* ColliderSystem: Detects collisions between player and enemy projectiles, as well as between enemies and player projectiles. It does not manage health or scene changes, only marks entities as hit.
* ControllerSystem: Connects the player ship's behavior to user inputs (changes the velocity based on arrow keys, and activates the player's shooting if the E key is pressed).
* EnemyControllerSystem: Manages how enemies move and chase the player.
* EnemySpawnSystem: Uses a clock to continually spawn enemies.
* HealthDisplaySystem: Displays the health bar of the player (entities tagged as Player).
* HealthSystem: Decreases health when entities are marked as hit, and switches to the game over (score) screen.
* InputSystem: Updates the input components according to SFML key press detection.
* MovementSystem: Moves entities in the direction of their velocity. Note that this doesn't manage player input (this is done in ControllerSystem).
* OOBSystem: Stands for "Out of Bounds" system, either removes sprites outside the window (missiles) or restricts positions of them (player) based on their "oobAct" attribute.
* RenderingSystem: Initializes and displays standard sprites with textures.
* ShapeSystem: Displays circle shapes (missiles), note that this could be extended to other shapes (like rectangles, etc.).
* ShootingSystem: Used for player and enemy shooting, makes the entity shoot a projectile from its center and in a direction.
* TextSystem: Displays text, either from their center position or top-left corner.
* TimerSystem: Updates the timer text based on the clock, and switches to score scene if it reaches zero.
* WaitKeySystem: Waits for a keyboard input to switch to another scene.

# Inputs
Use **arrow** keys to move the player, **E** to shoot enemies and **Escape** to pause / resume.

# Notes
As no bonus is accorded to the gameplay part, the focus isn't on the latter, no complex features nor good balance are implemented.
The focus on this project is only on the technical perspective.

# Known bugs
No known bugs exist, manual testing was done upon each feature implementation and corresponding bugs were fixed, if you notice any please let us know.
