#include "main.h"
char time[9] = "00:00:00";
void init_config()
{
    init_clcd();
    init_adc();
    init_mkp();
    init_uart();
    init_i2c();
    init_ds1307();
}
char state = e_Dashboard,key;



void main(void) 
{  
    init_config();
    
    while(1)
    {
        key = read_matrix_keypad(STATE);
        switch(state)
        {
        case e_Dashboard : 
            dashboard(); 
            break;
        case e_menu : 
            menu();
             break; 
        case e_view : 
            view();
            break;
        case e_download : 
            download_log();
            break;
        case e_clear : 
            clear_log();
            break;
        case e_set_time : 
            set_time();
            break;
    }
  }
}

