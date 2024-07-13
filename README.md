# ChamberCrawler3000 (CC3K)
ChamberCrawler3000 (CC3K) is a text-based dungeon crawler Rogue game implemented in C++. This project showcases a variety of Object-Oriented Programming (OOP) principles and design patterns to create an engaging and extensible game environment.

## Features
Object-Oriented Programming: Utilizes multiple OOP principles such as class inheritance to model the game's characters and entities.
  - Class Inheritance: Characters, items, and other game elements are implemented through a well-defined class hierarchy, enabling code reuse and extensibility.
  - Design Patterns: Implements several design patterns to manage game logic and items effectively.
    * Observer Pattern: Used to handle the communication between game objects, ensuring that changes in the state of one object can automatically propagate to dependent objects.
    * Decorator Pattern: Allows dynamic addition of responsibilities to objects, such as adding enchantments to the map and potion effects to characters.
    * Strategy Pattern: Facilitates the definition of a family of algorithms, encapsulating each one and making them interchangeable. This is used for different movement behaviors of enemies, item generation strategies, and the switch between player's weapons.
Other Features: Incorporates advanced C++ features to manage the game's core functionalities.

# Getting Started
Follow these instructions to get a copy of the project up and running on your local machine.

- Prerequisites
  * C++20 or later
  * GNU Make 4.3 or later

- Installation
  1. clone the repository
     * $git clone https://github.com/MINGYISU/ChamberCrawler3000.git
     * $cd ChamberCrawler300
  3. Build the project using GNU Make (A Makefile has been provided)
     * $make
  5. run the game
     * $./cc3k

## Usage
- Player movements:
    * no,so,ea,we,ne,nw,se,sw: This is direction command that moves the player character one block in the appropriate cardinal direction
    * u [direction]: uses the potion indicated by the direction (Example Usage: u ea).
    * a direction: attacks the enemy in the specified direction, if the monster is in the immediately specified block (e.g. must
be one block north of the @).
    * s, d, v, g, t: specifies the race the player wishes to be when starting a game.
    * f: stops enemies from moving until this key is pressed again.
    * r: restarts the game. All stats, inventory, and gold are reset. A new race should be selected.
    * q: allows the player to admit defeat and exit the game.

The other features are waiting for you to explore! (Hint: Use the command $./cc3k dlc to play the DLC version of the game!)
