Maze Game (Raycasting Project)
Introduction
Welcome to the Maze Game built using raycasting techniques in C with the SDL2 library. This project simulates a 3D maze where a player navigates using raycasting to dynamically render walls as they explore.

Project Blog Article: [Link to the blog article explaining the project in detail]
Author LinkedIn: Njike Njiah Abednego's LinkedIn
Installation
To set up the project locally, follow these steps:

Clone the repository:

bash
Copy code
git clone https://github.com/yourusername/maze-game.git
cd maze-game
Install dependencies:

Make sure you have SDL2 installed:
bash
Copy code
sudo apt-get install libsdl2-dev
Build the project:

bash
Copy code
make
Run the game: Pass a map file as an argument:

bash
Copy code
./maze_game map.txt
The map.txt file should contain a map layout defined by integers or characters that the game engine can interpret to render the maze.

Usage
Once the game is running, the player can navigate through the maze using these controls:

W: Move forward
A: Move left
S: Move backward
D: Move right
To modify or create different maze layouts, simply update the map.txt file or create new map files.

Example map.txt:

Copy code
111111
100001
101101
100001
111111
1 represents walls.
0 represents empty spaces where the player can move.

Contributing
We welcome contributions! Here’s how you can contribute:

Fork the repository.
Create a new branch:
bash
Copy code
git checkout -b feature-branch
Make your changes and commit them.
Push to your branch:
bash
Copy code
git push origin feature-branch
Submit a pull request.
Related Projects
Raycasting Engine Tutorial
SDL2 Maze Game
Licensing
This project is licensed under the MIT License. For more details, see the LICENSE file.

