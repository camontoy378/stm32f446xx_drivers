/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: September 13, 2026
 *      Author: camontoy378
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H
#define INC_STM32F446XX_GPIO_DRIVER_H


#include "stm32f446xx.h"

//Add structs and handles for GPIO
typedef struct {
    uint8_t GPIO_PinNumber;                         //Pin number to configure.
    uint8_t GPIO_PinMode;                           //Config GPIOx_MODER. Select the I/O direction (input, output, AF, analog). 15 pins per port. Ports: A-H
    uint8_t GPIO_PinOutType_PP_OD;                  //Config GPIOx_OTYPER. Config output pin to Push-Pull or Open Drain.
    uint8_t GPIO_PinSpeed;                          //Config GPIOx_OSPEEDR. Set output pin speed.
    uint8_t GPIO_PinPUPDR;                          //Config GPIOx_PUPDR. Configure I/O pull-up or pull-down resistors.
    uint8_t GPIO_PinAltFunction;                    //Config GPIOx_AFRL(Pins 0-7) or GPIOx_AFRH(Pins 8-15). Configure Alternate function mode.

}GPIO_UserPinConfig_t;

//Handle structure for GPIO pins
typedef struct{
    GPIO_RegDef_t           *p_GPIOx;               //Holds base address of GPIO port of a particular pin
    GPIO_UserPinConfig_t    GPIO_UserPinConfig;     //Pin configuration settings provided by user.
} GPIO_Handle_t;


//GPIO Pin Numbers
#define GPIO_PIN_0          0
#define GPIO_PIN_1          1
#define GPIO_PIN_2          2
#define GPIO_PIN_3          3
#define GPIO_PIN_4          4
#define GPIO_PIN_5          5
#define GPIO_PIN_6          6
#define GPIO_PIN_7          7
#define GPIO_PIN_8          8
#define GPIO_PIN_9          9
#define GPIO_PIN_10         10
#define GPIO_PIN_11         11
#define GPIO_PIN_12         12
#define GPIO_PIN_13         13
#define GPIO_PIN_14         14
#define GPIO_PIN_15         15

//MODE register config data
#define GPIO_MODE_INPUT      0
#define GPIO_MODE_OUTPUT     1
#define GPIO_MODE_ALT_FUNC   2
#define GPIO_MODE_ANALOG     3


//OTYPER register config data
//Output pin type
#define GPIO_PUSH_PULL      0
#define GPIO_OPEN_DRAIN     1

//GPIOx_OSPEEDR register config data
//Output pin speed
#define GPIO_SPEED_LOW      0
#define GPIO_SPEED_MEDIUM   1
#define GPIO_SPEED_FAST     2
#define GPIO_SPEED_HIGH     3

//GPIOx_PUPDR register config data
//Pull-Up, Pull-Down resistor settings
#define GPIO_NO_PIN_PUPD    0
#define GPIO_PIN_PU         1
#define GPIO_PIN_PD         2



 void GPIO_Init(GPIO_Handle_t *p_gpio_handle);


 #endif