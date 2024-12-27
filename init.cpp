#include "init.h"
#include "car.h"
#include "frog.h"

static void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);

	SCB->VTOR = 0x08003000;
	SCB->SHCSR = 7<<16;	
}

static void Game_Init(frog player, car *cars[5])
{
	score = 0;
	Lcd_Clr_Screen();

    car firstCar(0, 110, CAR_SIZE_X, CAR_SIZE_Y, CAR_COLOR, RIGHT, 0);
    cars[0] = &firstCar;
	
    Lcd_Draw_Box(player.getLocation_x(), player.getLocation_y(), player.getSquareSize_width(), player.getSquareSize_height(), color[player.getSquareSize_color()]);
	Lcd_Draw_Box(firstCar.getLocation_x(), firstCar.getLocation_y(), firstCar.getSquareSize_width(), firstCar.getSquareSize_height(), color[firstCar.getSquareSize_color()]);
}

