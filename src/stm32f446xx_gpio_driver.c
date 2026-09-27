/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: September 13, 2026
 *      Author: camontoy378
 */

#include "stm32f446xx_gpio_driver.h"


 void GPIO_Init(GPIO_Handle_t *p_gpio_handle){
   
   //Temp variable use to assing struct variables.
   uint32_t temp;
   uint32_t move_bits_n_times;
   
   //Config pin mode
   temp              = 0;
   move_bits_n_times = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinNumber * 2;
   temp              = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinMode << move_bits_n_times;

   //Clear values because not all ports registers are set to 0 on reset.
   p_gpio_handle->p_GPIOx->MODER &= ~(0x3 << move_bits_n_times);

   //Set register
   p_gpio_handle->p_GPIOx->MODER |= temp;



   //Config Output port
   if(p_gpio_handle->GPIO_UserPinConfig.GPIO_PinMode == GPIO_MODE_OUTPUT){
      
      //Config Push-Pull or Open Drain
      temp              = 0;
      move_bits_n_times = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinNumber;
      temp              = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinOutType_PP_OD << move_bits_n_times;

      //Set register
      p_gpio_handle->p_GPIOx->OTYPER |= temp;


      //Config Speed
      temp              = 0;
      move_bits_n_times = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinNumber * 2; 
      temp              = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinSpeed << move_bits_n_times;

      //Clear values because not all ports registers are set to 0 on reset.
      p_gpio_handle->p_GPIOx->OSPEEDR &= ~(0x3 << move_bits_n_times);
     
      //Set register
      p_gpio_handle->p_GPIOx->OSPEEDR |= temp;  
   }



   //Config I/O Pull-Up or Pull-Down
   temp              = 0;
   move_bits_n_times = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinNumber * 2;
   temp              = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinPUPDR << move_bits_n_times;
   
   //Clear values because not all ports registers are set to 0 on reset.
   p_gpio_handle->p_GPIOx->PUPDR &= ~(0x3 << move_bits_n_times);
     
   //Set register
   p_gpio_handle->p_GPIOx->PUPDR |= temp;


   //Config ALternate function
   if(p_gpio_handle->GPIO_UserPinConfig.GPIO_PinMode == GPIO_MODE_ALT_FUNC){

      temp              = 0;
      move_bits_n_times = p_gpio_handle->GPIO_UserPinConfig.GPIO_PinNumber * 4;
      temp             |= p_gpio_handle->GPIO_UserPinConfig.GPIO_PinAltFunction << move_bits_n_times;

      if(p_gpio_handle->GPIO_UserPinConfig.GPIO_PinNumber < 8){

         p_gpio_handle->p_GPIOx->AFRL  |= temp;         
      }
      else{
         p_gpio_handle->p_GPIOx->AFRH  |= temp;
      }
   }

 }