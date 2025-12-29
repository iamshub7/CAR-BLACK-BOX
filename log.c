#include "main.h"
extern int count;
extern char state;
extern char address;
extern char key;
extern char time[9];
char i;
char data[15];

void view()
{
    if(count == 0)
    {
        CLEAR_DISP_SCREEN;
        clcd_print("NO Logs",LINE1(0));
        
        __delay_ms(2000);
        state = e_menu;
        CLEAR_DISP_SCREEN;
    }
    char flag = 0;
    if(key == ALL_RELEASED)
    {
        flag++;
    }
    else if(key == SW2 && i<(count-1))
    { 
        i++;
        flag++;
    }
    else if(key == SW1 && i>0)
    {
        i--;
        flag++;
    }
    char ind;
    if(flag)
    {
        ind = 0;
      for(char j=0;j<14;j++)
      {
        if(j==2 || j==5)
        {
            data[j]=':';
        }
        else if(j==8 || j==11)
        {
            data[j] = ' ';
        }
        else
        {
            data[j] = read_ext_eeprom((i*10)+ind++);
        }
      }
      data[14]='\0';
    }
      clcd_print("# Time     EV SP",LINE1(0));
      clcd_putch(i+'0',LINE2(0)); 
      clcd_print(data,LINE2(2));
      
      if(key == SW5)
      {
          CLEAR_DISP_SCREEN;
          state = e_menu;
      }
}

void clear_log(){
    clcd_print("  Logs Cleared  ",LINE1(0));
    clcd_print("  Successfully  ",LINE2(0));
        __delay_ms(2000);
        CLEAR_DISP_SCREEN;
        state = e_menu;
        count = address = i = 0;
}

void download_log(){
    char i=0;
    char data[15];
    clcd_print(" Downloaded Log ",LINE1(0));
    clcd_print("  Successfully  ",LINE2(0));
    __delay_ms(3000);
    puts("The logs are as follows:\n\r");
    while(i<count)
    {
        char ind = 0;
        for(char j=0;j<14;j++)
        {
        if(j==2 || j==5)
        {
            data[j]=':';
        }
        else if(j==8 || j==11)
        {
            data[j] = ' ';
        }
        else
        {
            data[j] = read_ext_eeprom((i*10)+ind++);
        }
      }  
        data[14]='\0';
        putch(i+'0');
        putch(' ');
        puts(data);
        puts("\n\r");
        i++;
    }
          CLEAR_DISP_SCREEN;
          state = e_menu;
}

unsigned char clock_reg[3];
void get_time(void)
{
	clock_reg[0] = read_ds1307(HOUR_ADDR);
	clock_reg[1] = read_ds1307(MIN_ADDR);
	clock_reg[2] = read_ds1307(SEC_ADDR);

	if (clock_reg[0] & 0x40)
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x01);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
	else
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x03);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
	time[2] = ':';
	time[3] = '0' + ((clock_reg[1] >> 4) & 0x0F);
	time[4] = '0' + (clock_reg[1] & 0x0F);
	time[5] = ':';
	time[6] = '0' + ((clock_reg[2] >> 4) & 0x0F);
	time[7] = '0' + (clock_reg[2] & 0x0F);
	time[8] = '\0';
    clcd_print(time, LINE2(0));
}

int min, hour, sec;
void set_time(void) 
{
    static int f_flag, delay, i, j;
    clcd_print("HH:MM:SS", LINE1(1));

    if (f_flag == 0) 
    {
        i = 1;
        j = 2;
    } 
    else if (f_flag == 1) 
    {
        i = 4;
        j = 5;
    } 
    else if (f_flag == 2) 
    {
        i = 7;
        j = 8;
    }

    if (delay++ <= 100) 
    {
        clcd_putch(' ', LINE2(i));
        clcd_putch(' ', LINE2(j));
    } 
    else if (delay <= 200) 
    {
        clcd_print(time, LINE2(1));
    } 
    else delay = 0;

    hour = ((time[0] - 48)*10) + (time[1] - 48);
    min = ((time[3] - 48)*10) + (time[4] - 48);
    sec = ((time[6] - 48)*10) + (time[7] - 48);

    if (key == SW2) 
    {
        f_flag++;
        if (f_flag == 3) f_flag = 0;
    }

    if (key == SW1 && f_flag == 0) 
    {
        hour++;
        if (hour == 24) hour = 0;
        time[0] = (hour / 10) + 48;
        time[1] = (hour % 10) + 48;
    } 
    else if (key == SW1 && f_flag == 1) 
    {
        min++;
        if (min == 60) min = 0;
        time[3] = (min / 10) + 48;
        time[4] = (min % 10) + 48;
    } 
    else if (key == SW1 && f_flag == 2) 
    {
        sec++;
        if (sec == 60) sec = 0;
        time[6] = (sec / 10) + 48;
        time[7] = (sec % 10) + 48;
    }

    if (key == SW4) 
    {
        write_ds1307(HOUR_ADDR, ((hour / 10) << 4) | (hour % 10));
        write_ds1307(MIN_ADDR, ((min / 10) << 4) | (min % 10));
        write_ds1307(SEC_ADDR, ((sec / 10) << 4) | (sec % 10));

        CLEAR_DISP_SCREEN;
        clcd_print("   SAVED", LINE1(1));
        __delay_ms(1000);
        state = e_menu;
        f_flag = 0;
    }
    if (key == SW5) 
    {
        state = e_menu;

        CLEAR_DISP_SCREEN;
        clcd_print("   EXITING", LINE1(1));
        __delay_ms(1000);
        f_flag = 0;
    }

}