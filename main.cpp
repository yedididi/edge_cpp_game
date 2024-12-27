#include "device_driver.h"
#include "frog.h"
#include "car.h"

int score;
unsigned short colors[] = {RED, YELLOW, GREEN, BLUE, WHITE, BLACK};

extern volatile int TIM4_expired;
extern volatile int USART1_rx_ready;
extern volatile int USART1_rx_data;
extern volatile int Jog_key_in;
extern volatile int Jog_key;

extern "C" void abort(void)
{
  while (1);
}

static int Check_Collision(frog player, car thisCar)
{
	int col = 0;

	if((thisCar.getLocation_x() >= player.getLocation_x()) && ((player.getLocation_x() + FROG_STEP) >= thisCar.getLocation_x())) col |= 1<<0;
	else if((thisCar.getLocation_x() < player.getLocation_x()) && ((thisCar.getLocation_x() + CAR_STEP) >= player.getLocation_x())) col |= 1<<0;
	
	if((thisCar.getLocation_y() >= player.getLocation_y()) && ((player.getLocation_y() + FROG_STEP) >= thisCar.getLocation_y())) col |= 1<<1;
	else if((thisCar.getLocation_y() < player.getLocation_y()) && ((thisCar.getLocation_y() + CAR_STEP) >= player.getLocation_y())) col |= 1<<1;

	if(col == 3)
	{
		Uart_Printf("SCORE = %d\n", score);
		return GAME_OVER;
	}

	if((player.getDirection()== SCHOOL) && (player.getLocation_y() == Y_MIN)) 
	{
		Uart_Printf("SCHOOL\n");	
		player.setDirection(HOME);
	}

	if((player.getDirection() == HOME) && (player.getLocation_y() == LCDH - player.getSquareSize_height()))
	{
		player.setDirection(SCHOOL);
		score++;
		Uart_Printf("HOME, %d\n", score);
	}

	return 0;
}

void Sys_Init(void)
{
	Clock_Init();
	LED_Init();
	Uart_Init(115200);

	SCB->VTOR = 0x08003000;
	SCB->SHCSR = 7<<16;	
}

void game_Init(frog player, car *cars[5])
{
	score = 0;
	Lcd_Clr_Screen();

    car firstCar(0, 110, CAR_SIZE_X, CAR_SIZE_Y, CAR_COLOR, RIGHT, 0);
	// for (int i = 0; i < 5; i++)
	// 	cars[i] = *NULL;
	cars[0] = &firstCar;
	
    Lcd_Draw_Box(player.getLocation_x(), player.getLocation_y(), player.getSquareSize_width(), player.getSquareSize_height(), colors[player.getColor()]);
	Lcd_Draw_Box(firstCar.getLocation_x(), firstCar.getLocation_y(), firstCar.getSquareSize_width(), firstCar.getSquareSize_height(), colors[firstCar.getColor()]);
}

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
        game_Init(player, cars);
		TIM4_Repeat_Interrupt_Enable(1, TIMER_PERIOD*10);

		for(;;)
		{
			int game_over = 0;

			if (Jog_key_in)
			{
				Uart_Printf("KEY\n");
				player.setColor(BACK_COLOR);
				player.Draw_Object();
				player.Frog_Move(Jog_key);
				game_over = Check_Collision(player, *cars[0]);
				player.setColor(FROG_COLOR);
				player.Draw_Object();
				Jog_key_in = 0;	
			}

			if(TIM4_expired) 
			{
				for (int i = 0; i < 5; i++)
				{
					cars[i]->setColor(BACK_COLOR);
					cars[i]->Draw_Object();
					cars[i]->Car_Move();
					game_over = Check_Collision(player, *cars[0]);
					cars[i]->setColor(CAR_COLOR);
					cars[i]->Draw_Object();
					TIM4_expired = 0;
				}
			}

			if(game_over)
			{
				TIM4_Repeat_Interrupt_Enable(0, 0);
				Uart_Printf("Game Over, Please press any key to continue.\n");
				Jog_Wait_Key_Pressed();
				Jog_Wait_Key_Released();
				Uart_Printf("Game Start\n");
				break;
			}
		}
	}
}
