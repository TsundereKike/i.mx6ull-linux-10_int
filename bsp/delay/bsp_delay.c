#include "bsp_delay.h"
/*
*@brief: 延时函数
*@param in:     n   延时循环次数
*@param out:    NULL
*@ret:          NULL
*/
void delay_short(volatile unsigned int n)
{
    while(n--){}
}
/*
*@brief: ms级延时函数,396MHz主频下大约延时时间为1ms
*@param in:      n      要延时的ms数
*@ret:           NULL*/
void delay_ms(volatile unsigned int n)
{
    while(n--)
    {
        delay_short(0x7ff);
    }
}

