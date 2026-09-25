/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: September 13, 2026
 *      Author: camontoy378
 */

#include "stm32f446xx_gpio_driver.h"


 void GPIO_Init(GPIO_Handle_t *p_gpio_handle){
   
   //Temp variable use to assing struct variables.
   uint32_t temp = 0;
   
   //Set GPIO port mode register
   uint32_t reg_bit_loc = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinNumber * 2;
   temp &= p_gpio_handle->GPIO_UserPinConfig.GPIO_PinMode << reg_bit_loc;

 }