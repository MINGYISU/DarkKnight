# ChamberCrawler3000 (CC3K)

ChamberCrawler3000 (CC3K) is a text-based dungeon crawler Rogue game implemented in C++. This project showcases a variety of Object-Oriented Programming (OOP) principles and design patterns to create an engaging and extensible game environment.

## Getting Started

Follow these instructions to get a copy of the project up and running on your local machine.

- Prerequisites
  - C++20 or later
  - GNU Make 4.3 or later

- Installation
  1. clone the repository
     - $git clone <https://github.com/MINGYISU/ChamberCrawler3000.git>
     - $cd ChamberCrawler300/src
  2. Build the project using GNU Make (A Makefile has been provided)
     - $make
  3. run the game
     - $./cc3k

## Usage

- Player movements:
  - no,so,ea,we,ne,nw,se,sw: This is direction command that moves the player character one block in the appropriate cardinal direction
  - u [direction]: uses the potion indicated by the direction (Example Usage: u ea).
  - a direction: attacks the enemy in the specified direction, if the monster is in the immediately specified block (e.g. must
be one block north of the @).
  - s, d, v, g, t: specifies the race the player wishes to be when starting a game.
  - f: stops enemies from moving until this key is pressed again.
  - r: restarts the game. All stats, inventory, and gold are reset. A new race should be selected.
  - q: allows the player to admit defeat and exit the game.

The other features are waiting for you to explore! (Hint: Use the command $./cc3k dlc to play the DLC version of the game!)
