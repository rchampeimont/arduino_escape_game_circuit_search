# arduino_escape_game_circuit_search
Used in an escape game where players had to find 3 circuits and solder their wires to a "main computer" (Arduino and its main circuit). When this is done, a code in morse is releaved using the buzzer.

Each circuit can have a lot of useless components just for the story-telling but the only thing that really matters is its resistance (the only really connected components are resistor(s)). Each circuit has a different resistance (1 kΩ, 10 kΩ, 100 kΩ) allowing the Arduino to check wether the correct circuits are connected to the right wires.

When each circuit is connected on the right wires, an LED with light up to show connection is good. When all 3 are connected, the buzzer will play a secret password in morse code.

## Schematic
The circuits that players are supposed to find and connect are resistors R5, R7 and R9 in the schematic. Matching resistors R4, R6 and R8 are on the Arduino-attached main circuit (like all other components) and allow to check that an equivalent resistance is connected by checking that the voltage in the middle point is half of the reference voltage.
![Schematic](escape_game_circuit_search_schematic_schem.png?raw=true)
