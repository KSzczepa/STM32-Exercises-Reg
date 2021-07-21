/*
 * conf_gpio.c
 *
 *  Created on: 29.03.2021
 *      Author: klaud
 */


#include "conf_gpio.h"

void gpio_pin_cfg(GPIO_TypeDef * const __restrict__ port, GpioPin_t pin, GpioMode_t mode){
	if (mode & 0x100u) port->OTYPER |= pin;
	else port->OTYPER &= (uint32_t)~pin;

	pin = __builtin_ctz(pin)*2;

	uint32_t reset_mask = ~(0x03u << pin);
	uint32_t reg_val;

	reg_val = port->MODER;
	reg_val &= reset_mask;
	reg_val |= (((mode & 0x600u) >> 9u) << pin );

	port->MODER = reg_val;
	reg_val = port->PUPDR;
	reg_val &= reset_mask;
	reg_val |= (((mode & 0x30u) >> 4u) << pin );

	port->PUPDR = reg_val;
	reg_val = port->OSPEEDR;
	reg_val &= reset_mask;
	reg_val |= (((mode & 0xC0u) >> 6u) << pin);

	port->OSPEEDR = reg_val;
	volatile uint32_t * reg_adr;
	reg_adr = &port->AFR[0];
	pin*=2;

	if ( pin > 28){
		pin -= 32;
		reg_adr = &port->AFR[1];
	}
	reg_val = *reg_adr;
	reg_val &= ~(0x0fu << pin);
	reg_val |= (uint32_t)(mode & 0x0ful) << pin;
	*reg_adr = reg_val;
}
