OOP 2 - Project - Gold Miner Game - README
Presenters: Esther and Hanon 330002429 and Rachel Dekel 318754850
General explanation: The object of the game is to collect as much money as possible and go through the stages, for each stage there are several objects with different monetary value, bombs and moving objects. The objects can be collected by pulling the rope - the edge of the object, if we could not catch an object, the rope will pull faster. Each stage is assigned a minimum time and price to go through a stage, there is a shop where you can purchase objects at a cheaper price.
Controller - the main department of the game, responsible for the main screen where the stages take place, captures actions from the user, resets the stages, checks when each stage ends
Object A parent class that is responsible for all objects in the game, all objects inherit from it. Contains virtual functions of price weight and whether we eat
Toolbar - a department that is responsible for printing time, money, purpose
ManagerScreens A master class that is responsible for the game screens: opening screen, explanation screen, menu, game, stage goal, store, end of game.

Main The main file that runs the program (creates controller)
Level A department that is responsible for each stage, the amount of time objects and the amount of money left to pass
FileManager - Singleton's department responsible for music, fonts and game textures
Player - A department responsible for the player, saving his amount of life and the number of money he needs to reach in order to pass a stage
Gold - A class of the object that inherits from an object contains in the image builder, location, and monetary value
Rope - a class of objects
Diamond - A class of the diamond object that inherits from an object contains in the image builder, location, and monetary value
Present - A class of object that inherits from an object contains in the image builder, location, and monetary value
Rock - A class of object that inherits from an object contains an image builder, a location
Bomb - A class of the object that the explorer inherits from an object contains in the image builder, location, and monetary value
Bone - A class of the object object that inherits from an object contains in the image builder, location, and monetary value
Mouse - A class of object that inherits from an object contains in the image builder, location, and monetary value, moves the object
Rope - a department responsible for the object of the rope, checking what the limits of displacement and what the speed is.
Notable algorithms:
When taking an object, an intersection test is performed with the ROPE - there is a m_rect variable which is a square that follows the rope at each stage and it checks if a collision has taken place
Other notes:
Once an error is thrown out of the program (for example when it fails to open the TXT file of the step), the error is written into the Log file stored inside the Out folder

Which looks like this

Useful Links :
https://github.com/SFML/SFML/wiki/Tutorial%3A-Manage-different-Screens
