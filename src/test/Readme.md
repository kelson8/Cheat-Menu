## Folder info
This folder will contain test code for the KCNet SA Mod menu that I may work on in the future.

For now I am adding this stuff to the Cheat Menu but I'm using this to learn a lot of C++.

# Features


## Main test page
* Train test (Check if player is in a train)
* Health pickup (Spawns a health pickup on the player) - Incomplete
* Money pickup (Spawns 50k around the player)
* Enter crane (This should make it possible to enter a crane but I don't know how to use it.)
* Play mission passed (Plays the mission passed tune)
* Current radio station (Prints the current radio station to a textbox)

## Hud test
* Toggle Radar (Turn on/off the radar)
* Toggle Hud (Turn on/off the hud)

## Markers test
* Show corona (Show a corona on the map at the players coords) - This isn't setup yet.
* Remove corona (Remove the corona) - This isn't setup yet.

## Ped test
* Suicide (Kill the player)
* Bomb (Spawn a explosive on the player)
* Sound (Play a sound from the list) - This doesn't play the sound yet and is incomplete.
* Show coords (Show your current coords in a text box)
* Show marker coords (Show current marker coords in a text box) - This isn't setup yet.
* Player drowns (Toggles player drowning on/off, if it's disabled you cannot drown underwater)
* Gravity (Change the gravity)
* Spawn ped (Spawn a random ped)
* Area check test (Check if player is in specified coords)
* Misc test (So far this just has toggle sprinting but it crashes the menu.)

## Vehicle test
* Blow up all cars (Runs the blow up all cars cheat)
* Search Light (Make the helicopter search lights show up) - This doesn't work
* Blow up current car (Blows up the car the player is in)
* Close doors (Close all doors, doesn't work for hood or trunk)
* Lock doors (Lock vehicle doors, I cannot figure out how to unlock them yet)
* Unlock doors (Unlock vehicle doors) - This isn't setup yet.
* Flying cars (Enables flying cars cheat)
* Invincible car (Enables invincibility for your current vehicle)
* Is car in water check (Prints "Your car is dry" if not in water or "Your car is in the water" if in the water)
* Radio test (Toggle the radio) - This is incomplete.
* Burst all tires (Burst all vehicle tires) - This one seems to work but always shows the tires have been burst for a car.

## World test
* Weather (Change current weather) - This one works but it doesn't set the weather to the one in the list.
* Create checkpoint (Create a checkpoint on the map) - Incomplete
* Remove checkpoint (Remove the checkpoint from the map) - Incomplete
* Create corona (Create a corona on the map) - Incomplete
* Remove corona (Remove a corona from the map) - Incomplete

# Functions

## Player functions
These are mostly used internally in the C++ code.
* IsPlayerInArea(x1, y1, z1, x2, y2, z2) (Check if the player is in the current coordinates)
* IsPlayerInTrain (Check if the player is in a train)
* Kill player (Kill the player)
* Set never wanted (Set never wanted on/off) - Incomplete
* Set invincible (Set incinbility on/off) - Incomplete
* Set infinite ammo (Set infinite ammo on/off) - Incomplete 