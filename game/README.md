
Introduction

	The goal of this project was to create an HTML5 Real-Time Strategy(RTS) game that could be played entirely in a web browser such as Google Chrome. At the beginning of the project, all members of the group decided that the work effort of the project be split according to functional tasks rather than sub-system focused development. Therefore each of the members of our group had to opportunity to design, develop, and test all aspects of the game including and not limited to the game engine, game UI, game play mechanics, computer controlled enemy AI and overall play balance. This allowed us the ability to work in collaboration on certain sections and for an overall better understanding of the project code base. This report will give a high level overview of how different aspects of the game were implemented and to provide a brief introduction of how to play the game.


Description of Program(User’s Perspective)

1. Description of the type of game

	The game we created is similar a tower defense type game, where units are created and released in time scheduled waves. The units will walk to an assigned queue location within their base, and wait for the wave trigger before they rush out. The units then march towards the enemy base, fighting the enemy units along the way, to try and destroy the other players base. It has aspects of a tradition RTS game as well, in that players are allowed to build buildings in their own base. In order to win, players must destroy the opposing teams “Keep”, which a special building that looks like a castle, located at their base.
There is some basic strategy involved in winning the game. Units and buildings require gold to create, which players can get at a steady rate per second. Players also get a small gold bonus for every unit they destroy. Additionally, units can be buffed through special buildings such as the armory and the arsenal. These special tech buildings allow units to upgrade their stats, creating an overall stronger army. Since there is limited space in the player's base, they may decide that they wish to forgo upgrades and build as many barracks as possible instead, so that they create a large army instead of a smaller stronger one.
	Players can choose different locations for the units to queue up before the next wave. Players can strategize by having all their units rush out of the gate in the front position, or perhaps they may decide to send defensive units in the front to soak up damage, while the units in the back deal most of the damage.
	The score is saved for wins and losses. And a top kill high score, which is the most unit kills a player has gotten in a single game. These stats are saved each time the player wins or loses. They are saved into local storage as cookies, and accessed at the start of each game.
	Finally, there are two modes for the players to choose from. Easy and hard mode. In easy mode, the enemy will only create one barracks and hire units at a slower rate. In hard mode, the enemy builds two barracks and creates units very quickly. The AI’s also choose different classes of units to hire, based on difficulty selected.


2. Game Objective and How to Win

	The game ends once either of the player’s(user controlled or computer AI controlled) “Keep” building is destroyed. The player can win by recruiting armies of units, and building special buildings that help upgrade their unit’s stats, such as defence, strength, and health. All the units have different types of strengths and weaknesses, so deciding which armies to build and up to upgrade them are very important factors in winning!


3. Basic Controls

Arrow Keys(Up arrow, Down arrow, Left arrow, Right arrow) - The player can control the game camera’s view and move it in any direction to see the rest of the map.

The “Build” Button-  Located in the upper left-hand corner, this button can be used to place buildings for your realm. This will initiate a “footprint” of the building to be placed. Use the mouse to drag this to a location. The footprint will turn red if the building cannot be placed.

Shortcut Keys - For Building there are shortcut keys. By initiating build with “b”, the user can subsequently select 1 for a “Barracks”, 2 for an “Armourer”, and 3 for a “Arsenal”


4. Description of Buildings/How to Build Buildings

There are 3 types of buildings which can be built and a fourth type that is the user’s main base building or “keep” as it is called. All buildings have a menu for further actions that is available upon clicking the building.

The “Keep” - This is the first building that automatically spawns in your realm. It is the focus of the game in that if you lose your keep, the game ends. The keep has the ability to upgrade your existing buildings, among other things.

The “Barracks” - The barracks is a placeable building, and can be placed multiple times.
It is used to build units for your regiments. By clicking on the building, you will be presented with options to build various unit types, as well as information about the building's condition and/or capabilities. The units are added to a building q, up to the building’s capacity, which can be increased by an upgrade function in the “keep” building.

The “Armourer” - The armourer is a placeable building, and can be placed multiple times. By clicking on the building, you will be presented with options to build various unit types, as well as information about the building's condition and/or capabilities.The capabilities can be used one time per building. They are added to a development queue, and become active when they are finished according to their build time. For the units being built or that will be built: The Armourer has three specific abilities: Increase armour, which increases your units defences in battle, increase health for for increased amount of damage a unit can take, and increase a scaling, which will multiply your unit’s current armour by the factor.

The “Arsenal” - The arsenal is a placeable building, and can be placed multiple times. By clicking on the building, you will be presented with options to add capabilities to your units, as well as information about the building's condition and/or capabilities.The capabilities can be used one time per building. They are added to a development queue, and become active when they are finished according to their build time. For the units being built or that will be built: The Arsenal has three specific abilities: Increase attack, which increases your units attack in battle, increase speed, and increase attack scaling, which will multiply your unit’s current attack by the factor.


5. Description of Units/How to Build Units/Unit Battle System

	Units are created after the player builds a barracks. They can click on the barracks when it's completely built, and a menu will display, allowing them a selection of several different units. Each unit has different strengths and weaknesses. Some units, such as the minotaur, are slow, but very strong. They have lots of HP and hit fairly hard, but tend to miss a lot and attack slowly. Other units such as the wizard, will deal a lot of damage, but have low health and defense. Rogues have a tendency to walk and attack very quickly, but deal less damage. Warriors are fairly well rounded in their stats, and walk at a medium pace. Slimes are the weakest of the units, but also cost the least.
	Units will fight to the death if they bump into each other. Once they have started attacking a target, they will continue to attack that target until the target is dead or they are dead.



6. Description of how Waves/Queueing Work

	The Wave Manager of the game is set to release both the user player and AI enemy player’s attacking waves at every 60 seconds. These opposing waves will then automatically walk towards each other attempting to fight any opposition units or buildings in the path of the other player’s “Keep”. These wave based attacks add a major strategy planning aspect of the game for the players. They will decide which units the wave army will contain and will be tasked with constructing this army in a limited period of time with only a limited amount of gold. The wave armies for both players are released from predetermined spawn queue locations(one located near the path out of the base and one located closer to the player’s own “Keep”). This gameplay mechanic is what makes this game a hybrid between a traditional RTS game and a Tower Defense game.


7. Description of Enemy AI Modes

We were tasked with created two different AI modes for this game, one “easy” and one “hard”. The difference between our easy and hard AI’s were created by controlling when and how often the AI player would do certain actions such as building an army.


8. Bug Notes

There is an issue that happens in rare occasions due to some issues with the MelonJS engine getting to a certain state and needing a hard refresh. If you ever load the game and your “Keep” building does not show up in  your player base(in tends to show up in the middle of the lane) do a hard refresh of the game engine. This can be done by leaving the page and reloading(ex: pressing the back arrow then the forward arrow. Simply pressing F5 or the refresh button will not fully restart the engine for the purpose of clearing this error.

If you have extremely large armies the engine is prone to frame rate deacy.


-------------------------------------------------------------------------------
Copyright (C) 2011 - 2015 Olivier Biot, Jason Oster, Aaron McLeod
melonJS is licensed under the [MIT License](http://www.opensource.org/licenses/mit-license.php)
