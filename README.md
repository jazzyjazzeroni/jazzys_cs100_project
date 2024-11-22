 Authors: [Naira Farooqi](https://github.com/naira132) [Jasmyne Hardy](https://github.com/jazzyjazzeroni) [Emmanuel Gonzalez](https://github.com/EMan115) [Courtney Songco](https://github.com/teez-ai)


  ## Expectations

## Project Description

  * We wanted to create a game that was unique to the genre of RPG. Most games have become very reliant on high-end graphics and near-perfect mechanics that it has gotten to the point where a vast majority of games are very similar to each other. We are all passionate about gaming, as well, and we want to use our coding experience and capabilities to build a game that works properly.

  * We plan on using C++ implementation, as well as GitHub for our remote coding. C++ techniques: Polymorphism, Inheritance, Type Casting, Classes, Mutator and Accessor functions

  * Input: User chooses four options, attack, healing (healing potions), powers, items. Attack will deal damage to the enemies depending on how good the sword item is. Healing will heal the protagonist with a said amount of health, between 30-40 health points. Powers are super special, and they can deal massive amounts of damage to the enemy, possibly eliminating them in one shot.
  * Output: The program will display dialogue of the protagonist character using powers/items and what kind of damage/healing it will do. The dialogue prompts during battle sequences will provide information on what is happening during the fight, specifically attacks, heals, powers, and item changes. Powers are specific and the user will be prompted via dialogue if there is no match with the character with their powers or if the character type is the same.

  * What are the features that the project provides?

  * Protagonist: human with water and earth elemental type powers
Enemies: Fire and wind goblins
Hero health and enemy health (Hero health: 200, goblin health 50-75 starting out, 75-100 near the end)
Protagonist abilities: Healing oneself, attacking goblins, equipping swords, and powers
Enemy abilities: attack
Damage outputs: Protagonist does 20-40 damage, enemies do 20-30, boss does 50-70
Fireball Boss enemy, dragon Ignis (Boss Health: 500) *near the end, protagonist gains the ability to use both earth and water elemental powers to defeat the boss by a ice witch who so happens to be the boss' mom
Narrative dialogue: Prompts that provide the user with little quips and actions depending on choices made by the user. 
Setting (this RPG will be taking place in a world we call "Stormcrest")

  ## Phase II
The user/player will log in to the game and either press "start," "quit," or "display." In the display there will be getters and setters, one for showing swords, one for potions, one for health,  and another one for powers. In "quit" it just leaves and will end the game. If starting from the beginning, the narrator will give a lengthy description of the game. It will also give the option for tutorial gameplay. If the user starts from the middle or end, the player will pick up where they left off. 

Theodore will be bumping into other characters on his journey. This is where we utilize the other character classes. Goblins are the bad guys and they will have a class containing getters and setters. If the user dies the program will quit.

## User Interface Specification

### Navigation Diagram
![flames-of-ice-navigation drawio (1)](https://github.com/user-attachments/assets/636f8a92-b3ca-4c7f-8c97-04c499ec37cc)

### Screen Layouts
 
Title Screen/Main Menu: Displays the screen title and options (e.g., Start Game, Settings, Exit).

![image](https://github.com/user-attachments/assets/e5524e38-1183-4d27-8da4-9bce513d1787)

Settings Screen: Is shown when the player chooses settings.

![new settings](https://github.com/user-attachments/assets/34abd72d-cfb3-4f04-81b3-5dc7ed962ce0)

Change Language Screen: Is shown when the player chooses to change the language from the Settings menu.

![Language Options screen](https://github.com/user-attachments/assets/3f9dbbed-ea33-4109-874e-fa00c2611834)

Tutorial Prompt: Is shown when the player first starts a new game.

![tutorial prompt (1)](https://github.com/user-attachments/assets/5361d894-0d82-41cb-8264-0788c09214ba)

First Tutorial Screen: Explains how the levels work and prompts the player to choose a direction to move in.

![first tutorial screen (1)](https://github.com/user-attachments/assets/881bb461-06eb-4027-94aa-ecf8c850e950)

Overworld Screen: Is shown when the player is traversing the levels.

![overworld menu](https://github.com/user-attachments/assets/53e965f7-dba6-4029-b8c6-cc1e6795fac3)

Enemy Encounter Screen: Is shown when the player encounters an enemy.

![enemy encounter prompt (1)](https://github.com/user-attachments/assets/ea7a5b99-1b6e-41e4-9e3f-98b41661506c)

Player's Turn Screen: Is shown when it's the player's turn during battles.

![new players turn](https://github.com/user-attachments/assets/f934e509-7dce-493a-93b5-12290b944902)

Player's Attack Success Screen: Is shown after a player's attack hits.

![User attack success screen (1)](https://github.com/user-attachments/assets/75709406-3563-40fa-8b7b-7d77b5d0f6c7)

Enemy's Attack Screen: Is shown after an enemy's attack hits.

![enemy attack success screen (1)](https://github.com/user-attachments/assets/65c07031-5045-4465-9977-71866fd72b93)

Death Screen: Is shown when the player's health reaches zero (minus the skull emoji lol).

![death screen (2)](https://github.com/user-attachments/assets/807aa69b-c50b-42ab-8dd3-cb13d777aaa7)

Enemy defeated screen: Is shown when the enemy's health reaches zero.

![enemy defeated screen](https://github.com/user-attachments/assets/382bdbea-f72e-4598-bd4e-630b1ab9e5ee)

Last enemy/Level completion screen: Is shown when the last enemy in a level is defeated.

![level completion screen](https://github.com/user-attachments/assets/630d516d-c73b-4726-b97b-9ebdf40309ce)

Pause Menu: Is shown when the player pauses.

![pause menu (1)](https://github.com/user-attachments/assets/519217a9-d4b0-40fe-b3dc-6037c8fb6cb3)

Quit reassurance prompt: Is shown when the player chooses to save and quit from the pause menu.

![quit reassurance prompt (1)](https://github.com/user-attachments/assets/a97ed428-7ee4-49d4-8a60-7bfa3a8b6c85)

Inventory Menu: Is shown when the player presses 'i' for inventory.

![new inventory](https://github.com/user-attachments/assets/7b9bae58-08fd-43a6-ad19-27f429504a44)

## Class Diagram
![uml drawio (1)](https://github.com/user-attachments/assets/a5f64829-d93e-4d48-bc20-eed9e38e1f04)

The class diagram exemplifies inheritance, polymorphism, aggregation, and composition. Our Character class is our abstract class, and this is abstract because we have a virtual void function for damage. Each character is inherited from the Character class. The user is going to be interacting from the interface class as the main character, Theodore Pumpernickel. The interface is going to have a void function in order to display the main menu so that the user is able to quit/save their progress at any time. Each character is going to have a health bar and an integer representing how much health each character has. There are going to be stats for each character, specifying what type of element the character corresponds with, the damage they have, a check to see if the character is alive/ko’d after battle, and a confirmation that the health bar was updated properly. The update boolean function is used to update characters’ equipment as well as the characters themselves. This character abstract class has boolean functions to see the statistics of each character. The main character is going to be positioned in the x-y Cartesian Plane so that the user can moveLeft(), moveRight(), moveUp(), and moveDown(). As the user presses the appropriate keys (on the keyboard) to move Theodore, different characters, such as goblins and witches, will interact with the main character. The UML diagram has a Powers class, which each character aggregates from, as it is an association relationship. The enemies and main character will have their own powers, and this is represented as an enum. The user will equip their water/earth powers if the enemy they encounter is a fire/wind goblin. However, the character will not use the attack() function if the goblin has water/earth powers (as they are allies). If the character interacts with a witch, the witch will provide dialogue as a void function. The witch has a string of potions. Using the needsPotion boolean function, if their health is low, the main character will obtain this potion and the health will be fully/mostly filled up. As well as other characters, Theodore will bump into different swords and mushrooms, which are illustrated in the Inventory class. This Inventory class has a composition relationship with the main character class, as both inventory and the main character can exist without each other. The character has options to addPotion(), addSword(), removeSword(), and addMushroom(). Once the main character attacks and kills the correct goblins, there is a final boss, the Dragon, Ignus. Ignus inherits from the Enemy class as he is an enemy. Ignus has the ability to fly() and fireAttack(), as well as spit fireballs (represented as integers) which can be used against the main character. Each attack to either the main character or the enemy will change the integers of their respective health bars. As long as the main character's health is not 0, the player can keep playing. Once the integer reaches 0, the user will be prompted that they have lost, and the interface will return to the printMenu().

 
  ## Phase III
  ### Updated Navigation Diagram
![latestuml drawio](https://github.com/user-attachments/assets/bc4ebbcb-a2a1-4dd2-ba6f-47e8f56d8b42)


  ### Updated Class Diagram
![latestuml drawio](https://github.com/user-attachments/assets/e3d2b760-3882-41b2-abe1-9180a1698b15)


UML Diagram associations:
</br>Aggregation: The MenuPrinter is an aggregation of GameManager class
</br>Composition: Powers is a composite with MainCharacter and Goblin class
	- Battle class is a composition of Level class
	- GameMap is a composite class of Level
</br>Implementation: Sword and Potions is implemented from the Inventory class
</br>Inheritance: MainCharacter, Goblin, and Dragon is inheriting from the Character class
</br>Direct Association: The Character class is directly associated to the Battle class

For phase III, the group has implemented four (4) new features/classes, namely: MenuPrinter class, GameManager class, Level class, and GameMap class. We have also used functions for each object </n>that the user will encounter on this map. These objects include potions, swords, and goblins. This will implement each object to a space on our map grid. 

For the MenuPrinter class, this class contains static methods that’s responsible for mainly outputting all of the console text. This class does not take any input values to maintain code maintainability and the group decided it was best to have one class to be responsible for for all of the console outputs. From the client’s end, they will be able to start the game and the MenuPrinter class will display all information to the user. The client will only interact with this class and not directly with the others. As the user moves through the game, multiple different menus and screens will be outputted. For instance, if the client wants to see the status of the player's health, by inputting a char there will be a displayStatus() function used to output. 

A crucial implementation is the GameManager class, this class is the central system for the Text-Based RPG, Flames of Ice, itself. 
The game manager has the methods to start the game, as well as hold the data members of the different levels
Because the MenuPrinter class can exist out of the GameManager class it has an aggregation relationship. We have created this new relationship as the way our code will be implemented the MenuPrinter can exist without the other class.

A new feature that the group has implemented to the program are the different levels for the game all found in the Level class. The group has also implemented the Level class which is a composition to the GameManager. There will be four levels to the game and a final boss round which the main character, Theodore, get to battle with the dragon:

<ul>First Four Levels:
<li>Level 1: Easy Breezy </li>
<li>Level 2: Getting Heated</li>
<li>Level 3: Frigid Flights </li>
<li>Level 4: Earthbound </li>
</ul>
Initially, the main character will start off with wind powers. The mechanics of the game is that Theodore will fight goblins each round depending on their elements. 

<strong>Mechanics:</strong>
	<ul>
 	<li>Level 1: Easy Breezy - The game starts with the main character, Theodore having air elemental powers. He will only be able to fight Earth-type goblins in this round. Once Theodore is able to defeat 5 fire 		goblins, he will move to the next level.</li>
	<li>Level 2: Getting Heated - Theodore levels up and now has fire elemental powers. He can now fight Earth-type and Wind-type goblins. Theodore will have to battle 10 goblins to move to the next round. </li>
	<li>Level 3: Frigid Flights - Theodore has leveled-up to the third round and now has water-elemental powers. He is now able to fight Earth, Wind, and Fire type goblins. He will then be able to move on to the final stage 	once he defeats 15 goblins</li>
	<li>Level 4: Earthbound - Theodore has all elements (Earth, Wind, Fire, Water), he can fight all kinds of goblins and can finally move to the boss stage (Dragon’s stage) once he defeats 15 goblins. (Note: The group has 	decided on 15 goblins for this stage for less time-consumption on the client’s end)</li>
	</ul>
Once the player has completed all of the first four levels. They will now move on to the boss round. insert boss level name

Final Stage:
	Here, Theodore will battle Ignus, the dragon. The Final stage will have a back-and-forth combat and the player wins once Ignus is defeated.




Another Important class that we have now added is the GameMap class. There must be a x-y Cartesian Plane with a height and width, because the mainCharacter will be placed on this map and it is the client's role to move around by inputting WASD to either move left, right, up, or down. Because of the GameMap, each char the user inputs will correspond to a x or a y position. This class has an int of numGoblin, due to the composition relationship between GameMap and Levels. Each level has a different size map and a different amount of goblins on the plan that the client must fight off, GameMap class must have a different amount of goblins. This composition relationship between GameMap and Levels is imperative as GameMap depends heavily on the Level. In turn, if the Levels class were to be destroyed the entire GameMap class would also cease to exist. Our map is essentially a matrix that will have either empty spaces in a grid, a type of sword, a type of potion, or a type of goblin. We decided to use a mapping specifically vector<vector<Object>> mapMatrix that will be on each grid of our map. This interaction between the client and the different items or characters they will bump into is exemplified by our getters and setters for that object. The GameMap class will also be implemented to keep track of the amount of goblins killed and the amount still on the map by the getNumGoblins() getter and the getGoblinsKilled() getter. 

The class diagram exemplifies inheritance, polymorphism, aggregation, and composition. Our Character class is our abstract class, and this is abstract because we have a virtual void function for damage. For our Character class, each character is inherited from the Character class. The user is going to be interacting from the interface class as the main character, Theodore Pumpernickel. The interface is going to have a void function in order to display the main menu so that the user is able to quit/save their progress at any time. Each character is going to have a health bar and an integer representing how much health each character has. There are going to be stats for each character, specifying what type of element the character corresponds with, the damage they have, a check to see if the character is alive/ko’d after battle, and a confirmation that the health bar was updated properly. The update boolean function is used to update characters’ equipment as well as the characters themselves. This character abstract class has boolean functions to see the statistics of each character. The main character is going to be positioned in the x-y Cartesian Plane so that the user can use the keys WASD.

The UML diagram has a Powers class, which each character aggregates from, as it is an association relationship. The enemies and main character will have their own powers, and this is represented as an enum. The user will equip their water/earth powers if the enemy they encounter is a fire/wind goblin. However, the character will not use the attack() function if the goblin has water/earth powers (as they are not compatible for battle). If the character interacts with a witch, the witch will provide dialogue as a void function. The witch has a string of potions. Using the needsPotion boolean function, if their health is low, the main character will obtain this potion and the health will be fully/mostly filled up. As well as other characters, Theodore will bump into different swords and potions, which are illustrated in the Inventory class. This Inventory class has a composition relationship with the main character class, as both inventory and the main character can exist without each other. The character has options to addPotion(), addSword(), and removeSword(). Once the main character attacks and kills the correct goblins, there is a final boss, the Dragon, Ignus. Ignus inherits from the Enemy class as he is an enemy. Ignus has the ability to fly() and fireAttack(), as well as spit fireballs (represented as integers) which can be used against the main character. Each attack to either the main character or the enemy will change the integers of their respective health bars. As long as the main character's health is not 0, the player can keep playing. Once the integer reaches 0, the user will be prompted that they have lost, and the interface will return to the printMenu().

The Inventory class has been updated from our last UML class diagram. In the inventory, there will be two child classes that inherit from the Inventory class which are the Swords and Potion class. 

  Sword: Theodore will be equipped with a sword from the start of the game, and once the game    progresses, he will be able to find new swords that will be replaced from his old one.  The gameMap will be utilized in this context

Potion: In the game, there will be different potions that can be found all over the gameMap

These are all the new features that have been added to our Phase III.


We analyzed the SOLID principles in regards to our UML diagram and made the changes we saw necessary. For the Single-Responsibility Principle (SRP), we organized the display and the screen layout into separate output classes. This is so that classes such as the enemy and main character classes did not have excessive responsibilities. We did not feel as though our UML diagram was in violation in any aspect of the Open-Closed Principle (OCP).
For the Liskov Substitution Principle (LSP), we made it so our derived classes like Sword, can override the abstract class of Inventory.
We felt as though our UML diagram did not violate any aspect of the Interface Segregation Principle (ISP).
We felt as though our UML diagram did not violate any aspect of the Dependency Inversion Principle (DIP).

The critical change applied to our code base was the separation of methods such as 
The group has noticed the original code base violated many of the Single Responsibility Principle with many classes such as the following: Main Character and Goblin class which inherit from the Character class. The Character class initially had methods such as getMovement(), setMovement(), getInventory() methods that led to the Goblin class inheriting these methods as well. The methods were then placed into the MainCharacter class in order to separate them

Another example that the group followed was the whole MenuPrinter class itself. The MenuPrinter class was made to only output lines and not take any input values to abide by the Single Responsibility Principle

The group has noticed a violation in the Inventory class. This class goes against the Open-Closed Principle. The original plan was to implement the class with swords and potions as functions to this class. However, the group decided to implement Sword and Potion to its own class instead since the original implementation of Inventory class had to have several conditional statements that could potentially cause memory leakages and bugs. The group then made Sword and Potion to its own class with its own setter and getter functions in order not to pollute the Inventory class with several looping and if-else statements.

The SOLID principles provided a guide for a more efficient and organized structure that allowed for the foundation of our program to be more readable. These principles enabled us, as programmers, to practice clean and concise coding. 
While coding, the group has noticed that with other suboptimal programming practices (i.e. using methods that are not needed for other classes, declaring data types or values that cause inconspicuous errors to the code base. 
One principle that helped our group was the Single Responsibility Principle since we have encountered bugs in our program that were difficult to trace. However, when the group decided to separate the methods into different subclasses. We were able to backtrace where the bugs were coming from.

 
  ## Final deliverable
  All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
  Before the demo, you should do the following:
  * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
  * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
  * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
  Screenshots of the input/output after running your application
 ## Installation/Usage
  Instructions on installing and running your application
 ## Testing
  How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
