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
>![flames-of-ice-navigation drawio (1)](https://github.com/user-attachments/assets/636f8a92-b3ca-4c7f-8c97-04c499ec37cc)

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
>![uml drawio (1)](https://github.com/user-attachments/assets/a5f64829-d93e-4d48-bc20-eed9e38e1f04)



The class diagram exemplifies inheritance, polymorphism, aggregation, and composition. Our Character class is our abstract class, and this is abstract because we have a virtual void function for damage. Each character is inherited from the Character class. The user is going to be interacting from the interface class as the main character, Theodore Pumpernickel. The interface is going to have a void function in order to display the main menu so that the user is able to quit/save their progress at any time. Each character is going to have a health bar and an integer representing how much health each character has. There are going to be stats for each character, specifying what type of element the character corresponds with, the damage they have, a check to see if the character is alive/ko’d after battle, and a confirmation that the health bar was updated properly. The update boolean function is used to update characters’ equipment as well as the characters themselves. This character abstract class has boolean functions to see the statistics of each character. The main character is going to be positioned in the x-y Cartesian Plane so that the user can moveLeft(), moveRight(), moveUp(), and moveDown(). As the user presses the appropriate keys (on the keyboard) to move Theodore, different characters, such as goblins and witches, will interact with the main character. The UML diagram has a Powers class, which each character aggregates from, as it is an association relationship. The enemies and main character will have their own powers, and this is represented as an enum. The user will equip their water/earth powers if the enemy they encounter is a fire/wind goblin. However, the character will not use the attack() function if the goblin has water/earth powers (as they are allies). If the character interacts with a witch, the witch will provide dialogue as a void function. The witch has a string of potions. Using the needsPotion boolean function, if their health is low, the main character will obtain this potion and the health will be fully/mostly filled up. As well as other characters, Theodore will bump into different swords and mushrooms, which are illustrated in the Inventory class. This Inventory class has a composition relationship with the main character class, as both inventory and the main character can exist without each other. The character has options to addPotion(), addSword(), removeSword(), and addMushroom(). Once the main character attacks and kills the correct goblins, there is a final boss, the Dragon, Ignus. Ignus inherits from the Enemy class as he is an enemy. Ignus has the ability to fly() and fireAttack(), as well as spit fireballs (represented as integers) which can be used against the main character. Each attack to either the main character or the enemy will change the integers of their respective health bars. As long as the main character's health is not 0, the player can keep playing. Once the integer reaches 0, the user will be prompted that they have lost, and the interface will return to the printMenu().

 
  ## Phase III
  
 ![please2 drawio](https://github.com/user-attachments/assets/50a83036-a907-441c-82ed-6b4aecdd541a)

We analyzed the SOLID principles in regards to our UML diagram and made the changes we saw necessary. For the Single-Responsibility Principle (SRP), we organized the display and the screen layout into separate output classes. This is so that classes such as the enemy and main character classes did not have excessive responsibilities. We did not feel as though our UML diagram was in violation in any aspect of the Open-Closed Principle (OCP).
For the Liskov Substitution Principle (LSP), we made it so our derived classes like Sword, can override the abstract class of Inventory.
We felt as though our UML diagram did not violate any aspect of the Interface Segregation Principle (ISP).
We felt as though our UML diagram did not violate any aspect of the Dependency Inversion Principle (DIP).

   * How did you apply it? i.e. describe the change.
The critical change applied to our code base was the separation of methods such as 
The group has noticed the original code base violated many of the Single Responsibility Principle with many classes such as the following: Main Character and Goblin class which inherit from the Character class. The Character class initially had methods such as getMovement(), setMovement(), getInventory() methods that led to the Goblin class inheriting these methods as well. The methods were then placed into the MainCharacter class in order to separate them

Another example that the group followed was the whole MenuPrinter class itself. The MenuPrinter class was made to only output lines and not take any input values to abide by the Single Responsibility Principle.


  * How did this change help you write better code?
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
 
