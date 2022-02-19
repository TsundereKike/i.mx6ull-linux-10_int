#include "imx6u.h"
#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_delay.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
uint8_t LED_STATUS = OFF;
int main(void)
{
    int_init();
    imx6u_clk_init();
    clk_enable();
    led_init();
    beep_init();
    key_init();
    exti_init();
    while(1)
    {
        LED_STATUS = !LED_STATUS;
        led_switch(LED0,LED_STATUS);
        delay_ms(500);
    }
    return 0;
}
