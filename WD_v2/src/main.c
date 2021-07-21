

/* Includes */
#include "stm32f4xx.h"
#include "bit_banding.h"
#include "conf_gpio.h"

/* Private macro */
/* Private variables */
uint8_t reminder = 0;
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

	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC -> APB2ENR = RCC_APB2ENR_SYSCFGEN;
	gpio_pin_cfg(GPIOB, PB14, gpio_mode_output_PP_LS); //red led
	gpio_pin_cfg(GPIOB, PB15, gpio_mode_output_PP_LS); //green led
	__DSB();

	if (RCC -> CSR & RCC_CSR_WDGRSTF)
	  {
		  RCC -> CSR |= RCC_CSR_RMVF;
		  BB(GPIOB -> ODR, PB15) = 1;
		  BB(GPIOB -> ODR, PB14) = 0;
	  }


	  BB(RCC->CSR, RCC_CSR_LSION) = 1;				//Enable LSI clock
	  while ( BB(RCC->CSR, RCC_CSR_LSIRDY) == 0 );	//Wait for LSI clock start

	  WWDG -> CR |= WWDG_CR_WDGA;	//Watchdog enable

	  IWDG -> KR = 0x5555;			//Key register - enable access to PR and RLR registers
	  IWDG -> PR = 4;				//Prescaler
	  IWDG -> RLR = 1875;			//Reload Register
	  IWDG -> KR = 0xaaaa;			//Load up value to watchdog R;
	  IWDG -> KR = 0xcccc;			//Start watchdog

	  SysTick_Config(160000);

  /* Infinite loop */
  while (1)
  {

  }
}

__attribute__((interrupt)) void SysTick_Handler(void)
{
	reminder++;
	if (reminder == 200)
	{
		BB(GPIOB -> ODR, PB14) = 1;
		 BB(GPIOB -> ODR, PB15) = 0;
	}

}
