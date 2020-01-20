///////////DEVICE: STM32F407VG
///////////PROGRAM: Keil uVision5
#define USE_FULL_ASSERT
#include "stm32f4xx.h"                  // Device header
#include <stm32f4xx_rcc.h>
#include <misc.h>
#include <stm32f4xx_tim.h>
#include <stm32f4xx_gpio.h>
#include <softTimer.h>
uint8_t buton_input;     // unsigned tipte 8 bitlik degiskenleri tanimladik   
int debounce = 100;
int flagStart=0;
int startFlag=0;
int buttonPressedTime[2];
int startTime=0;
int endTime=0;
int changeFlag=0;

void delay_ms(int delay1)
{
	delay1 = delay1*4000;
	while (delay1--){	}
}

int msTicks;                      /* counts 1ms timeTicks       */

/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) {
  msTicks++;
}
/*----------------------------------------------------------------------------
  delays number of tick Systicks (happens every 1 ms)
 *----------------------------------------------------------------------------*/
void Delay (int dly) {                                              
  int curTicks;
  curTicks = msTicks;
  while ((msTicks - curTicks) < dly){
		buton_input = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
		if(buton_input==1 & startFlag==0){
			delay_ms(debounce);
			startFlag=1;
			startTime=curTicks;
		}
		else if(buton_input==0 & startFlag==1){
			endTime=curTicks;
			buttonPressedTime[0]=endTime - startTime;
			startFlag=0;
			changeFlag=1;
		}
	}
}

void GPIO_conf(void){
	GPIO_InitTypeDef LED;  // Led icin structure tanimlamasi
	GPIO_InitTypeDef BUTTON; // Buton icin structure tanimlamasi
 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); // Ledler icin clock
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); // Buton icin clock
	//LED CONF
	LED.GPIO_Pin  = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	LED.GPIO_Mode = GPIO_Mode_OUT;
	LED.GPIO_Speed = GPIO_Speed_100MHz;
	LED.GPIO_OType = GPIO_OType_PP;
	LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, & LED);
	//BUTON CONF
	BUTTON.GPIO_Pin  = GPIO_Pin_0;
	BUTTON.GPIO_Mode = GPIO_Mode_IN;
	BUTTON.GPIO_Speed = GPIO_Speed_100MHz;
	BUTTON.GPIO_OType = GPIO_OType_PP;
	BUTTON.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, & BUTTON);
}

void PressButton(int buttonStat){
	switch(buttonStat){
		//shortPressButton
		case 1:
			//1s
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]>3000 &changeFlag==1){
				changeFlag=0;
				PressButton(2);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]>300 &changeFlag==1){
				changeFlag=0;
				PressButton(2);
			}
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]>300 &changeFlag==1){
				changeFlag=0;
				PressButton(2);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]>300 &changeFlag==1){
				changeFlag=0;
				PressButton(2);
			}
			//2s
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(200);
			if (buttonPressedTime[0]>300 &changeFlag==1){
				changeFlag=0;
				PressButton(2);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(200);
			if (buttonPressedTime[0]>300 &changeFlag==1){
				changeFlag=0;
				PressButton(2);
			}
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(200);
			if (buttonPressedTime[0]>300 &changeFlag==1){
				changeFlag=0;
				PressButton(2);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(200);
			if (buttonPressedTime[0]>300 &changeFlag==1){
				changeFlag=0;
				PressButton(2);
			}
			PressButton(1);
			break;
		//longPressButton
		case 2:
			//1s
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(50);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(50);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(50);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(50);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(50);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(50);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(50);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(50);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			//2s
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			Delay(100);
			if (buttonPressedTime[0]<300 &changeFlag==1){
				changeFlag=0;
				PressButton(1);
			}
			PressButton(2);
			break;
		default:
			break;
	}
}

int main(){
	GPIO_conf();
	SystemCoreClockUpdate(); 	/* Get Core Clock Frequency   */
	if (SysTick_Config(SystemCoreClock / 1000)) { /* SysTick 1 msec interrupts  */
		while (1);   
	}
	while(1){
		PressButton(1);
	}
}



