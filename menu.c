#include "main.h"


extern char state = e_Dashboard,key;
char j,s_f;

void menu()
{
    char menu[][17]={"View log    ","Download log","Clear log   ","Set time    "};
    if(j<3)
    {
      clcd_print(menu[j],LINE1(2));
      clcd_print(menu[j+1],LINE2(2));  
    }
     
    if(s_f == 0)
    {
        clcd_print("*",LINE1(0));
        clcd_print(" ",LINE2(0));
    }
    else
    {
        clcd_print(" ",LINE1(0));
        clcd_print("*",LINE2(0));
    }
    
    if(key == SW2){
        if(s_f == 0)
        s_f = 1;
        else if(j<2)
        j++;
    }
    else if(key == SW1){
        if(s_f == 1)
        s_f = 0;
        else if(j>0)
        j--;
    }
    if(key == SW4)
    {
        CLEAR_DISP_SCREEN;
        if(j+s_f == 0) state = e_view;
        else if(j+s_f == 1) state = e_download;
        else if(j+s_f == 2) state = e_clear;
        else if(j+s_f == 3) state = e_set_time;
    }
    else if(key == SW5){
        CLEAR_DISP_SCREEN;
        state = e_Dashboard;
    }
}