#include "imx6u.h"
#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_delay.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
uint16_t cnt_num = 0;
uint16_t LED_STATUS = OFF;
uint16_t BEEP_STATUS = OFF;
int main(void)
{
    int_init();
    imx6u_clk_init();
    clk_enable();
    led_init();
    beep_init();
    key_init();
    while(1)
    {
        cnt_num++;
        if(get_key_value()==KEY0_VALUE)
        {
            BEEP_STATUS = !BEEP_STATUS;
            beep_switch(BEEP_STATUS);
        }
        if(cnt_num==50)
        {
            cnt_num = 0;
            LED_STATUS = !LED_STATUS;
            led_switch(LED0,LED_STATUS);
        }
        delay_ms(10);
    }
    return 0;
}
