# EEPROM Memory
## main.c:

- It includes the necessary libraries for the AVR microcontroller and some standard functions.
- Defines constants for the LED pins (LED_1, LED_2, LED_3, LED_4) and the used EEPROM memory address (MEMORY).
- Declare the setup() and loop() functions.
- The main() function is the entry point of the program. Do the following:
- Call the setup() function to configure the LED pins.
- Read a byte from EEPROM memory using the eeprom_read_byte() function, storing the value in the value variable.
- If the value read from the EEPROM is greater than 0, it runs a loop to display a light sequence on the LEDs. Each LED lights up sequentially for 1 second, from the value read to 1.
- After the light sequence, update the value in EEPROM memory to 0 using the eeprom_update_byte() function.
- Enter an infinite loop by repeatedly calling the loop() function.

## led.c:

- It includes the necessary libraries for the AVR microcontroller and some standard functions.
- Defines the used EEPROM memory address (MEMORY).
- The sequence() function does the following:
- Declare the variable newValue to store the updated value of the output port of the LEDs.
- Runs a loop that iterates through values from 0 to 15.
- On each iteration of the loop, it updates the LED output port (PORTB) to display the current value, using bit operations to keep the bottom four bits unchanged.
- Stores the updated value in the newValue variable.
- Wait 1 second using the _delay_ms() function.
- Updates the EEPROM with the new value using the eeprom_update_byte() function.

## MAKEFILE:
If you want to generate all the build files, you need to run the **make** command in your terminal at the file address where the MAKEFILE file is located, running this file will create two important folders, the first one has all the build files and this one is called **build**, the second called **lib** has the static library generated from the **led.c** file
To run the code on the arduino, it must be connected to the computer, once connected to the terminal you must execute the **make flash** command, in this way the file will be compiled on the arduino, working.
If you want to delete the build files, all you have to do is write the **make clean** command, this way it removes the files from the build and lib folders, but it doesn't delete these folders.
