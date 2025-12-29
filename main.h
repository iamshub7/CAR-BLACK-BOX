#ifndef MAIN_H
#define	MAIN_H

#include<xc.h>
#include"clcd.h"
#include"mkp.h"
#include "adc.h"
#include "eeprom.h"
#include"ds1307.h"
#include "ext_eeprom.h"
#include"i2c.h"
#include "uart.h"

enum mode
{
    e_view,
    e_download,
    e_clear,
    e_set_time,
    e_Dashboard,
    e_menu
};

void dashboard(void);
void view(void);
void download_log(void);
void clear_log(void);
void set_time(void);
void menu(void) ;
void get_time(void);
void display_time(void);
#endif	/* MAIN_H */

