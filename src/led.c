#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <stdint.h>

#define MEMORIA 0
//uint8_t EEMEM storedValue;

void sequence(void)
{
  uint8_t newValue;

  for(uint8_t i = 0; i <= 15; i++)
  {
    PORTB = (PORTB & 0xF0) | (i & 0x0F);
    newValue = (PORTB & 0xF0) | (i & 0x0F);
    _delay_ms(1000);
    eeprom_update_byte((uint8_t*)MEMORIA, newValue); 
  } 
}
