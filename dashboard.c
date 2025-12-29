#include "main.h"

extern char time[9]; 
extern char key;
char gear,address;
int count;
extern char state;
void dashboard()
{
    get_time();
    char ev[9][3] = {"ON","GR","GN","G1","G2","G3","G4","G5","CO"};
    char data[10];
    unsigned short  adc_reg_val;
    char speed,flag = 0;
    clcd_print("Time     EV   SP",LINE1(0));
    clcd_print(time,LINE2(0));
    
    adc_reg_val = read_adc(CHANNEL4);
    speed = adc_reg_val/10.33;
    clcd_putch((speed%10) + '0',LINE2(15));
    clcd_putch((speed/10) + '0',LINE2(14));
    
    if(key == SW3)
    {
        gear = 8;
        flag++;
    }
    else if(key == SW1 && gear<7)
    {
        gear++;
        flag++;
    }
    else if(key == SW2 && (gear>1 && gear<8))
    {
        gear--;
        flag++;
    }
    if(gear == 8 && (key == SW1 || key == SW2))
    {
        gear = 2;
    }
    clcd_print(ev[gear],LINE2(9));
    
    if(flag)
    {
        if(count<10)
        {
            count++;
        }
        
        data[0] = time[0];data[1] = time[1];data[2] = time[3];data[3] = time[4];data[4] = time[6];data[5] = time[7];
        data[6] = ev[gear][0]; data[7] = ev[gear][1];
        data[8] = (speed/10)+'0';data[9] = (speed%10)+'0';
        
        if(count == 10)
        {
            for(char i=0;i<90;i++)
            {
                write_ext_eeprom(i,read_ext_eeprom(i+10));
            }
            address = 90;
        }
        for(char i=0;i<10;i++)
        {
            write_ext_eeprom(address++,data[i]);
        }
    }
    if(key == SW4)
    {
        CLEAR_DISP_SCREEN;
        state = e_menu;
    }
}
