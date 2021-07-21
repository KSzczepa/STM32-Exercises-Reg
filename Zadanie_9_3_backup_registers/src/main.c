

/* Includes */
#include "stm32f4xx.h"
#include "bit_banding.h"
#include "conf_gpio.h"

/* Private macro */
/* Private variables */
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
	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC -> APB1ENR |= RCC_APB1ENR_PWREN;

	gpio_pin_cfg(GPIOB, PB14, gpio_mode_output_PP_LS);
	gpio_pin_cfg(GPIOB, PB15, gpio_mode_output_PP_LS);

	BB(GPIOB -> ODR, PB14) ^= 1;
	BB(GPIOB -> ODR, PB15) ^= 1;

	RCC -> CSR |= RCC_CSR_LSION;
	while ( ! (RCC -> CSR |= RCC_CSR_LSION));
	RCC -> BDCR |= RCC_BDCR_RTCSEL_1 | RCC_BDCR_RTCEN;
	__DSB();

	PWR -> CR = PWR_CR_DBP;
	RTC -> TAFCR = RTC_TAFCR_TAMPPRCH | RTC_TAFCR_TAMPFLT | RTC_TAFCR_TAMPFREQ_2 | RTC_TAFCR_TAMPIE;

	if ((RTC -> BKP0R == 152) && (RTC -> BKP1R == 348))
	{
		BB(GPIOB -> ODR, PB14) = 1;
	}
	else
	{
		RTC -> BKP0R = 152;
		RTC -> BKP1R = 348;
		BB(GPIOB -> ODR, PB15) = 1;
	}



  /* TODO - Add your application code here */

  /* Infinite loop */
  while (1)
  {
	  if (RTC -> ISR & RTC_ISR_TAMP1F)
	  {
		  BB(GPIOB -> ODR, PB14) = 1;
		  BB(GPIOB -> ODR, PB15) = 1;

		  BB(RTC -> ISR, RTC_ISR_TAMP1F) = 0;

		  BB(RTC -> TAFCR, RTC_TAFCR_TAMP1E) = 0;
		  BB(RTC -> TAFCR, RTC_TAFCR_TAMP1E) = 1;
	  }

  }
}
