#ifndef EEPROM_H
#define	EEPROM_H

unsigned char read_internal_eeprom(unsigned char addr);
void write_internal_eeprom(unsigned char addr,unsigned char data);

#endif	/* EEPROM_H */

