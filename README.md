# Tapdance-game-for-Circuit-Playground-Express
ENGR103 Final Project
Tapdance is a game played on the Adafruit Circuit Playground Express that utilizes the built-in speakers, serial monitor, pixel LEDs, buttons, and switch to build a short-form arcade-style game.

When the program is opened on the CPX, it will begin on standby mode. To leave standby, press either button to start the game. If the switch is enabled, the game goes into sleep mode and will wait until the switch is turned off before it will register any new inputs or LEDs.

When a button is pressed to start the game, one of the 10 LEDs on the board will light up. It is up to the player to press the button that is on the same side of the board as the lit LED before time runs out. With each correct button press, the game will choose a new LED to light up, give the player a point which is tracked on the serial monitor as "score", and reduce the time allowed to press the correct button.

If a player either presses the wrong button or waits to long to press a button, the game will flash red and play a sad beep, signaling the end of the game. The player's score will be reset and the board will be set back to standby mode to await for another button press to start the game


Sensor Used  | Function |	min |	max |	What is controlled? |	Thresh?	| Map? |
 
Left button	 | RISING   | 0	  | 1	  | leftButtonFlag, standbyFlag, progresses the game |	no |	No |

Right button |	RISING	| 0	  | 1	  | rightButtonFlag, standbyFlag, progresses the game |	no |	no |

switch       |	CHANGE 	| 0	  | 1	  | powerFlag, puts the device in rest mode |	no |	no |
