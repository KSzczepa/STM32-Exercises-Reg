

/* Includes */
#include "stm32f4xx.h"
#include "bit_banding.h"
#include "conf_gpio.h"

/* Private macro */
/* Private variables */
uint32_t counterRealValue_u32 = 0;
uint32_t counterRealValue2_u32 = 0;
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

  /* TODO - Add your application code here */

  RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOAEN;
  RCC -> APB2ENR = RCC_APB2ENR_TIM1EN;
  RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
  __DSB();

  gpio_pin_cfg(GPIOB, PB13, gpio_mode_AF1_PP_LS); 	//blue diode
  gpio_pin_cfg(GPIOA, PA5, gpio_mode_AF1_PP_LS);	//yellow diode
 // gpio_pin_cfg(GPIOA, PA8, gpio_mode_AF1_PP_LS);	//external diode (to pin D7)


  TIM1 -> CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;  //OC1M - chosen PWM mode 1

 // TIM1 -> CCER |= TIM_CCER_CC1NP; // Captire/Compare 1 complementary output polarity (0: as active)
  TIM1 -> CCER |= TIM_CCER_CC1NE | TIM_CCER_CC1E; // Captire/Compare 1 complementary output enable

  TIM1 -> BDTR = TIM_BDTR_MOE; // MAin Output Enable

  TIM1 -> PSC = 70;
  TIM1 -> ARR = 49999;				//Counter Period
  TIM1 -> CCR1 = 20000;
  TIM1 -> EGR = TIM_EGR_UG;
  TIM1->CR1 = TIM_CR1_CEN;		//Timer activation



  TIM2 -> CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;  //OC1M - chosen PWM mode 1
  TIM2 -> CCER |= TIM_CCER_CC1E; // Captire/Compare 1 complementary output enable

  TIM2 -> BDTR = TIM_BDTR_MOE; // MAin Output Enable
  TIM2 -> PSC = 70;
  TIM2 -> ARR = 49999;				//Counter Period
  TIM2 -> CCR1 = 25000;
  TIM2 -> EGR = TIM_EGR_UG;
  TIM2-> CR1 = TIM_CR1_CEN;		//Timer activation

  /* Infinite loop */
  while (1)
  {
	i++;
	counterRealValue_u32 = TIM1 -> CNT;
	counterRealValue2_u32 = TIM2 -> CNT;
  }
}


