

/* Includes */
#include "stm32f4xx.h"
#include "bit_banding.h"
#include "conf_gpio.h"

/* Private macro */
/* Private variables */
int counterRealValue = 0;
int counterValue = 0;
uint8_t a = 0;
/* Private function prototypes */
/* Private functions */

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  int i = 0;

  RCC -> AHB1ENR = RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOAEN;
  RCC -> APB2ENR = RCC_APB2ENR_TIM1EN;
  __DSB();
  gpio_pin_cfg(GPIOB, PB13, gpio_mode_output_PP_LS);	//blue
  gpio_pin_cfg(GPIOA, PA8, gpio_mode_AF1_PP_LS);
  gpio_pin_cfg(GPIOA, PA9, gpio_mode_AF1_PP_LS);

  //BB(GPIOA -> ODR, PA8) = 1;
  //BB(GPIOA -> ODR, PA9) = 1;
  BB(GPIOB -> ODR, PB13) ^= 1;

  TIM1 -> PSC = 0;
  TIM1 -> ARR = 9;				//Counter Period

  TIM1 -> CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0; //input mode: IC1FP1 is mapped to TI1 etc

  TIM1 -> CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E; //encoder enable

  TIM1 -> SMCR |= TIM_SMCR_TS_2;
  TIM1 -> SMCR |= TIM_SMCR_SMS_1;// | TIM_SMCR_SMS_0; //encoder mode on channel 1


  TIM1 -> DIER = TIM_DIER_UIE;	//Update Interrupt enable

  TIM1 -> CR1 = TIM_CR1_CEN;		//Timer activation

  NVIC_ClearPendingIRQ(TIM1_UP_TIM10_IRQn);
  NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);

  /* Infinite loop */
  while (1)
  {
	i++;
	counterRealValue = TIM1 -> CNT;

	if ((GPIOA -> IDR, PA8) == 1)
	{
		a = 1;
	}


  }
}

__attribute__((interrupt)) void TIM1_UP_TIM10_IRQHandler(void)
{
	if (TIM1->SR & TIM_SR_UIF)
	{
		TIM1->SR = ~TIM_SR_UIF;
		BB(GPIOB -> ODR, PB13) ^= 1;
	}
}

