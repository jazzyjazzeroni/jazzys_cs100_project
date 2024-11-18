> Authors: [Naira Farooqi](https://github.com/naira132) [Jasmyne Hardy](https://github.com/jazzyjazzeroni) [Emmanuel Gonzalez](https://github.com/EMan115) [Courtney Songco](https://github.com/teez-ai)


 > ## Expectations

## Project Description

>  * We wanted to create a game that was unique to the genre of RPG. Most games have become very reliant on high-end graphics and near-perfect mechanics that it has gotten to the point where a vast majority of games are very similar to each other. We are all passionate about gaming, as well, and we want to use our coding experience and capabilities to build a game that works properly.

>  * We plan on using C++ implementation, as well as GitHub for our remote coding. C++ techniques: Polymorphism, Inheritance, Type Casting, Classes, Mutator and Accessor functions

>  * Input: User chooses four options, attack, healing (healing potions), powers, items. Attack will deal damage to the enemies depending on how good the sword item is. Healing will heal the protagonist with a said amount of health, between 30-40 health points. Powers are super special, and they can deal massive amounts of damage to the enemy, possibly eliminating them in one shot.
>  * Output: The program will display dialogue of the protagonist character using powers/items and what kind of damage/healing it will do. The dialogue prompts during battle sequences will provide information on what is happening during the fight, specifically attacks, heals, powers, and item changes. Powers are specific and the user will be prompted via dialogue if there is no match with the character with their powers or if the character type is the same.

 > * What are the features that the project provides?

>  * Protagonist: human with water and earth elemental type powers
Enemies: Fire and wind goblins
Hero health and enemy health (Hero health: 200, goblin health 50-75 starting out, 75-100 near the end)
Protagonist abilities: Healing oneself, attacking goblins, equipping swords, and powers
Enemy abilities: attack
Damage outputs: Protagonist does 20-40 damage, enemies do 20-30, boss does 50-70
Fireball Boss enemy, dragon Ignis (Boss Health: 500) *near the end, protagonist gains the ability to use both earth and water elemental powers to defeat the boss by a ice witch who so happens to be the boss' mom
Narrative dialogue: Prompts that provide the user with little quips and actions depending on choices made by the user. 
Setting (this RPG will be taking place in a world we call "Stormcrest")

  ## Phase II
 > The user/player will log in to the game and either press "start," "quit," or "display." In the display there will be getters and setters, one for showing swords, one for potions, one for health,  and another one for powers. In "quit" it just leaves and will end the game. If starting from the beginning, the narrator will give a lengthy description of the game. It will also give the option for tutorial gameplay. If the user starts from the middle or end, the player will pick up where they left off. 

>Theodore will be bumping into other characters on his journey. This is where we utilize the other character classes. Goblins are the bad guys and they will have a class containing getters and setters. If the user dies the program will quit.

## User Interface Specification

### Navigation Diagram
>![image](https://github.com/user-attachments/assets/e5ca3f36-b454-428e-a420-3d2365621e10)


### Screen Layouts
 
> General Layout
>Most screens in the game share a common layout structure, with variations based on their specific >functions. The general layout includes:
>Title Screen/Main Menu: Displays the screen title and options (e.g., Start Game, Settings, Exit).

>![image](https://github.com/user-attachments/assets/e5524e38-1183-4d27-8da4-9bce513d1787)

>Content Area: The main area where game content and interactions appear.

>![image](https://github.com/user-attachments/assets/9aeff9d8-be0b-4777-ba51-aafe662b2aaa)

>Status Bar: Shows player status, such as health, mana, and inventory items.

>![image](https://github.com/user-attachments/assets/fdb88c22-0a24-43b0-b21a-543b01b7463f)


> Main Menu Screen
Title: Displays the game title "Flames of Ice".
Start Button: Starts a new game.
Load Button: Loads a saved game.
Settings Button: Opens the settings menu.
Exit Button: Exits the game.


> Settings Screen
Change the name of the character
Back Button: Returns to the main menu.

> Game Screen
Character Info: Displays protagonist's health, mana, and equipped items.
Enemy Info: Displays enemy health and status.
Action Menu: Provides options for attack, healing, powers, and items.
Dialogue Box: Shows narrative dialogue and battle prompts.
Inventory Screen
Items List: Lists all the items in the player's inventory such as mushrooms, potions, and swords.
Item Details: Shows details of the selected item.
Use/Equip Button: Uses or equips the selected item.
Unequip Button: Player can go back if item is not needed at the moment.
Back Button: Returns to the game screen.

> Battle Screen
Protagonist and Enemy Sprites: Visual representation of the protagonist and enemies.
Action Menu: Options for attack, healing, powers, and items.
Battle Log: Displays the sequence of actions and outcomes in the battle

## Class Diagram
>![uml drawio (1)](https://github.com/user-attachments/assets/a5f64829-d93e-4d48-bc20-eed9e38e1f04)



> The class diagram exemplifies inheritance, polymorphism, aggregation, and composition. Our Character class is our abstract class, and this is abstract because we have a virtual void function for damage. Each character is inherited from the Character class. The user is going to be interacting from the interface class as the main character, Theodore Pumpernickel. The interface is going to have a void function in order to display the main menu so that the user is able to quit/save their progress at any time. Each character is going to have a health bar and an integer representing how much health each character has. There are going to be stats for each character, specifying what type of element the character corresponds with, the damage they have, a check to see if the character is alive/ko’d after battle, and a confirmation that the health bar was updated properly. The update boolean function is used to update characters’ equipment as well as the characters themselves. This character abstract class has boolean functions to see the statistics of each character. The main character is going to be positioned in the x-y Cartesian Plane so that the user can moveLeft(), moveRight(), moveUp(), and moveDown(). As the user presses the appropriate keys (on the keyboard) to move Theodore, different characters, such as goblins and witches, will interact with the main character. The UML diagram has a Powers class, which each character aggregates from, as it is an association relationship. The enemies and main character will have their own powers, and this is represented as an enum. The user will equip their water/earth powers if the enemy they encounter is a fire/wind goblin. However, the character will not use the attack() function if the goblin has water/earth powers (as they are allies). If the character interacts with a witch, the witch will provide dialogue as a void function. The witch has a string of potions. Using the needsPotion boolean function, if their health is low, the main character will obtain this potion and the health will be fully/mostly filled up. As well as other characters, Theodore will bump into different swords and mushrooms, which are illustrated in the Inventory class. This Inventory class has a composition relationship with the main character class, as both inventory and the main character can exist without each other. The character has options to addPotion(), addSword(), removeSword(), and addMushroom(). Once the main character attacks and kills the correct goblins, there is a final boss, the Dragon, Ignus. Ignus inherits from the Enemy class as he is an enemy. Ignus has the ability to fly() and fireAttack(), as well as spit fireballs (represented as integers) which can be used against the main character. Each attack to either the main character or the enemy will change the integers of their respective health bars. As long as the main character's health is not 0, the player can keep playing. Once the integer reaches 0, the user will be prompted that they have lost, and the interface will return to the printMenu().

> ![flames-of-ice-navigation drawio](https://github.com/user-attachments/assets/1a5e38bd-e305-4128-93ec-84d420c0f6d0)


 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
