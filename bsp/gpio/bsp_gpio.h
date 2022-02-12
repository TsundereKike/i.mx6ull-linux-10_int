#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H
#include "MCIMX6Y2.h"
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "cc.h"

typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput = 0U,
    kGPIO_DigitalOutput = 1U,
}gpio_pin_direction_t;

typedef struct _gpio_pin_config
{
    gpio_pin_direction_t direction;
    uint8_t outputLogic;
}gpio_pin_config_t;
void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config);
void gpio_pin_wirte(GPIO_Type *base, int pin, int value);
int gpio_pin_read(GPIO_Type *base, int pin);
#endif