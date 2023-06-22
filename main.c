#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <stdbool.h>

#include "process.h"

#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5

#define MEMORIA 0

void setup(void);
void loop(void);

int main(int argc, char **argv)
{
  setup();

  uint8_t value = eeprom_read_byte((const uint8_t*)MEMORIA);

  if(value > 0)
  {
    for(uint8_t i = value + 1; i > 0; i--)
    {
      PORTB = (PORTB & 0xF0) | (i & 0x0F);
      _delay_ms(1000);
    }
  }

  eeprom_update_byte((uint8_t*)MEMORIA, 0);

  while(true)
  {
    loop();
  }

  return 0;
}

void setup(void)
{
  DDRB |= (1 << LED_1) | (1 << LED_2) | (1 << LED_3) | (1 << LED_4);
  PORTB &= ~((1 << LED_1) | (1 << LED_2) | (1 << LED_3) | (1 << LED_4));
}

void loop(void)
{
  sequence();
}
