Project Title: Carrot Chase – 2D Infinite Runner Game
1. Project Overview

Carrot Chase is a 2D infinite runner game developed using C++ and the SFML library. The objective of the project was to apply Object-Oriented Programming (OOP) principles to create a scalable and modular game engine.
+3

In the game, the player controls a bunny character that runs automatically through an infinitely generated world. The player must jump, slide, and avoid obstacles while collecting items like carrots, coins, and mushrooms to increase their score. The game features dynamic platform generation, ensuring that no two runs are exactly the same.
+4

2. Technical Architecture & OOP Implementation
The project heavily utilizes OOP concepts to ensure code reusability and modularity:
+1

Encapsulation: Major systems (Player, Platform, Animation) are separated into distinct classes. For example, the Player class manages its own velocity and state, protecting internal data from external modification.
+1

Inheritance: We implemented a base Entity class, which the Collectible class inherits from. This allows different items (carrots, coins) to share common attributes like position and collision logic while extending specific behaviors.

Polymorphism: The game loop treats all collectibles as generic Entity objects. When a collision occurs, the specific onCollect() function triggers different effects (e.g., adding score vs. activating a combo) depending on the object type.
+2


State Design Pattern: The game utilizes a Stack-based State Machine to manage transitions between MenuState, PlayingState, PauseState, and GameOverState.

3. My Technical Contributions (Lead Gameplay Logic & UI)

Role: Gameplay Mechanics, UI, and Game Logic.

As the team member responsible for the core mechanics and user interface, my specific contributions included:

A. Core Gameplay Mechanics


Auto-Run Logic: I refactored the player movement to remove manual left/right controls, enforcing constant forward momentum to strictly emulate the "Endless Runner" genre.
+1

Health & Damage System: I transitioned the game from a "One-Hit-Death" mechanic to a 3-Life System (represented by sun icons). This allows players to recover from mistakes, ending the game only when all lives are lost.
+1


Directional Locking: Implemented logic to lock the player's facing direction, preventing sprite flipping errors during collisions to ensure visual consistency.

B. Physics & Collision Engineering


Collision Resolution: I fixed AABB collision detection issues to prevent the player from falling through platforms.


"Snap-to-Surface" Algorithm: To solve the issue of the player "jittering" or vibrating when standing on moving platforms, I implemented a snap-to-surface logic that aligns the player's Y-position perfectly with the platform top.

C. UI & State Management


State Machine: I designed and implemented the State Design Pattern, creating the MenuState, PauseState, and GameOverState classes to handle smooth scene transitions.


Dynamic HUD: I built the Heads-Up Display (HUD) to show real-time scores and health indicators that dynamically update or fade when damage is taken.


Audio Integration: I integrated the audio system, adding sound effects for jumping, taking damage, and collecting items to provide immediate feedback to the player.

4. Tools Used

Language: C++ 


Library: SFML (Simple and Fast Multimedia Library) 


IDE: Visual Studio


