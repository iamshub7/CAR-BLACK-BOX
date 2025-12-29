#ifndef ext_eeprom_H
#define ext_eeprom_H

#define SLAVE_READ		0xA1
#define SLAVE_WRITE		0xA0

void write_ext_eeprom(unsigned char address1,  unsigned char data);
unsigned char read_ext_eeprom(unsigned char address1);

#endif