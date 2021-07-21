/*
 * bit_banding.h
 *
 *  Created on: 29.03.2021
 *      Author: klaud
 */

#ifndef BIT_BANDING_H_
#define BIT_BANDING_H_

enum { SRAM_BB_REGION_START = 0x20000000 };
enum { SRAM_BB_REGION_END = 0x200fffff };
enum { SRAM_BB_ALIAS = 0x22000000 };
enum { PERIPH_BB_REGION_START = 0x40000000 };
enum { PERIPH_BB_REGION_END = 0x400fffff };
enum { PERIPH_BB_ALIAS = 0x42000000 };
#define SRAM_ADR_COND(adres) ( (uint32_t)&adres >= SRAM_BB_REGION_START && (uint32_t)&adres <= SRAM_BB_REGION_END )
#define PERIPH_ADR_COND(adres) ( (uint32_t)&adres >= PERIPH_BB_REGION_START && (uint32_t)&adres <= PERIPH_BB_REGION_END )
#define BB_SRAM2(adres, bit)( SRAM_BB_ALIAS + ((uint32_t)&adres - SRAM_BB_REGION_START)*32u + (uint32_t)(bit*4u) )
#define BB_PERIPH(adres, bit)( PERIPH_BB_ALIAS + ((uint32_t)&adres - PERIPH_BB_REGION_START)*32u + (uint32_t)(__builtin_ctz(bit))*4u)
/* bit - bit mask, not bit position! */
#define BB(adres, bit) *(__IO uint32_t *)( SRAM_ADR_COND(adres) ? BB_SRAM2(adres, bit) : \
( PERIPH_ADR_COND(adres) ? BB_PERIPH(adres, bit) : 0 ))
#define BB_SRAM(adres, bit) *(__IO uint32_t *)BB_SRAM2(adres, bit)

#endif /* BIT_BANDING_H_ */
