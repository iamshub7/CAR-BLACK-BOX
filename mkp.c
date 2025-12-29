#include "main.h"

void init_mkp(void)
{
    //configure rows as output
    TRISB = TRISB & 0x1F;
    //configure cols as input
    TRISB = TRISB | 0x1E;
    
    //portb pull up
    RBPU = 0;
}
unsigned char scan_key(void)
{
    //scan SW1, SW4, SW7, SW10
    R1 = 0;
    R2 = 1;
    R3 = 1;
    
    if(C1 == 0) return SW1;
    if(C2 == 0) return SW4;
    if(C3 == 0) return SW7;
    if(C4 == 0) return SW10;
    
    //scan SW2, SW4, SW8, SW11
    R1 = 1;
    R2 = 0;
    R3 = 1;
    
    if(C1 == 0) return SW2;
    if(C2 == 0) return SW5;
    if(C3 == 0) return SW8;
    if(C4 == 0) return SW11;
    
    //scan SW3, SW6, SW9, SW12
    R1 = 1;
    R2 = 1;
    R3 = 0;
    R3 = 0;     /*giving suffient time to assign*/
    
    if(C1 == 0) return SW3;
    if(C2 == 0) return SW6;
    if(C3 == 0) return SW9;
    if(C4 == 0) return SW12;
    
    return ALL_RELEASED;
}
unsigned char read_matrix_keypad(unsigned char detection_type)
{
    static int once = 1;
    unsigned char key;
    if(detection_type == LEVEL)
    {
        return scan_key();
    }
    else if(detection_type == STATE)
    {
        key = scan_key();
        if( key != ALL_RELEASED && once)
        {
            once = 0;
            return key;
        }
        if(key == ALL_RELEASED)
            once = 1;
    }
    return ALL_RELEASED;
}