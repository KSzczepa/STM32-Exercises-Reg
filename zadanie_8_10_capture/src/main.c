

/* Includes */
#include "stm32f4xx.h"
#include "bit_banding.h"
#include "conf_gpio.h"

/* Private macro */
/* Private variables */
uint32_t timValue = 0;
uint32_t capturedValue = 0;
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
  //int i = 0;

  RCC -> AHB1ENR = RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;
  RCC -> APB2ENR = RCC_APB2ENR_TIM1EN;

  gpio_pin_cfg(GPIOA, PA1, gpio_mode_AF1_OD_LS);
  gpio_pin_cfg(GPIOB, PB13, gpio_mode_output_PP_LS);

  BB(GPIOB -> ODR, PB13) = 0;

  TIM1 -> CCMR1 |= TIM_CCMR1_CC1S_0;
  TIM1 -> CCMR1 |= TIM_CCMR1_IC1F_0 | TIM_CCMR1_IC1F_1;
  TIM1 -> CCER |= TIM_CCER_CC1E | TIM_CCER_CC1P;

  TIM1 -> PSC = 99;
  TIM1 -> ARR = 64999;

  TIM1 -> CR1 = TIM_CR1_CEN;

  /* TODO - Add your application code here */

  /* Infinite loop */
  while (1)
  {

	timValue = TIM1 -> CNT;
	capturedValue = TIM1 -> CCR1;
	if (BB(GPIOA -> IDR, PA1) == 1)
	{
		BB(GPIOB -> ODR, PB13) = 0;
	}
	else if (BB(GPIOA -> IDR, PA1) == 0)
	{
		BB(GPIOB -> ODR, PB13) = 1;
	}
  }
}
