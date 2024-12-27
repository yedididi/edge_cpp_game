#include "device_driver.h"
#include "init.h"
#include "frog.h"
#include "car.h"


extern "C" void Main()
{
	Sys_Init();
	Uart_Printf("Game Example\n");

	Lcd_Init();
	Jog_Poll_Init();
	Jog_ISR_Enable(1);
	Uart1_RX_Interrupt_Enable(1);

	for(;;)
	{
        frog player(150, 220, FROG_SIZE_X, FROG_SIZE_Y, FROG_COLOR, SCHOOL);
		car *cars[5];
        Game_Init(player, cars);
		TIM4_Repeat_Interrupt_Enable(1, TIMER_PERIOD*10);

		for(;;)
		{
			
		}
	}
}
