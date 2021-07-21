

/* Includes */
#include "stm32f4xx.h"
#include "bit_banding.h"
#include "conf_gpio.h"

/* Private macro */
/* Private variables */
uint32_t counterRealValue = 0;
uint8_t a = 0;
uint8_t b = 0;
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
  RCC -> APB2ENR = RCC_APB2ENR_SYSCFGEN | RCC_APB2ENR_TIM1EN;
  __DSB();
  gpio_pin_cfg(GPIOB, PB13, gpio_mode_output_PP_LS);	//blue
  gpio_pin_cfg(GPIOA, PA8, gpio_mode_AF1_PP_PD_LS);

  BB(GPIOB -> ODR, PB13) ^= 1;



  TIM1 -> PSC = 0;
  TIM1 -> ARR = 9;				//Counter Period

  TIM1 -> CCMR1 |= TIM_CCMR1_CC1S_0; // 01: detect rising edges on the TI1

  TIM1 -> CCER |= TIM_CCER_CC1E; // channel is ON (CC1E = ‘1’ in TIMx_CCER).


  TIM1 -> SMCR |= TIM_SMCR_TS_0 | TIM_SMCR_TS_2;
  TIM1 -> SMCR |= TIM_SMCR_SMS;	 // SLAVE MODE EXTERNAL CLOCK MODE 1



  TIM1->DIER = TIM_DIER_UIE;	//Update Interrupt enable
  TIM1->CR1 = TIM_CR1_CEN;		//Timer activation

  SysTick_Config(800000);
  NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);


  /* TODO - Add your application code here */

  /* Infinite loop */
  while (1)
  {
	i++;
	counterRealValue = TIM1 -> CNT;
  }
}

__attribute__((interrupt)) void TIM1_UP_TIM10_IRQHandler(void)
{
	if (TIM1->SR & TIM_SR_UIF)
	{
		TIM1->SR = ~TIM_SR_UIF;
		BB(GPIOB -> ODR, PB13) ^= 1;
		b++;
	}
}

__attribute__((interrupt)) void SysTick_Handler(void)
{
	BB(GPIOA-> PUPDR, GPIO_PUPDR_PUPDR8_0) ^= 1;
	BB(GPIOA-> PUPDR, GPIO_PUPDR_PUPDR8_1) ^= 1;
}
