/*
 * stm32f446xx.h
 *
 *  Created on: July 2, 2026
 *      Author: camontoy378
 */

#ifndef INC_STM32F446XX_H
#define INC_STM32F446XX_H

#include <stdio.h>
#include <stdint.h>

//Peripheral busses

#define AHB1_BUS_BASEADDR   0x40020000
#define APB1_BUS_BASEADDR   0x40000000

//Peripheral addresses AHB1
#define GPIOH_BASEADDR      ( AHB1_BUS_BASEADDR + 0x1C00 )
#define GPIOG_BASEADDR      ( AHB1_BUS_BASEADDR + 0x1800 )
#define GPIOF_BASEADDR      ( AHB1_BUS_BASEADDR + 0x1400 )
#define GPIOE_BASEADDR      ( AHB1_BUS_BASEADDR + 0x1000 )

#define GPIOD_BASEADDR      ( AHB1_BUS_BASEADDR + 0x0C00 )
#define GPIOC_BASEADDR      ( AHB1_BUS_BASEADDR + 0x0800 )
#define GPIOB_BASEADDR      ( AHB1_BUS_BASEADDR + 0x0400 )
#define GPIOA_BASEADDR      ( AHB1_BUS_BASEADDR + 0x0000 )

//Peripheral addresses APB1
#define DAC_BASEADDR        ( APB1_BUS_BASEADDR + 0x7400 )
#define PWR_BASEADDR        ( APB1_BUS_BASEADDR + 0x7000 )

#define HDMI_CEC_BASEADDR   ( APB1_BUS_BASEADDR + 0x6C00 )
#define CAN2_BASEADDR       ( APB1_BUS_BASEADDR + 0x6800 )
#define CAN1_BASEADDR       ( APB1_BUS_BASEADDR + 0x6400 )

#define I2C3_BASEADDR       ( APB1_BUS_BASEADDR + 0x5C00)
#define I2C2_BASEADDR       ( APB1_BUS_BASEADDR + 0x5800)
#define I2C1_BASEADDR       ( APB1_BUS_BASEADDR + 0x5400)
#define UART5_BASEADDR      ( APB1_BUS_BASEADDR + 0x5000 )

#define UART4_BASEADDR      ( APB1_BUS_BASEADDR + 0x4C00 )
#define USART3_BASEADDR     ( APB1_BUS_BASEADDR + 0x4800 )
#define USART2_BASEADDR     ( APB1_BUS_BASEADDR + 0x4400 )
#define SPDIF_RX_BASEADDR   ( APB1_BUS_BASEADDR + 0x4000 )

#define SPI3_I2S3_BASEADDR  ( APB1_BUS_BASEADDR + 0x3C00 )
#define SPI2_I2S2_BASEADDR  ( APB1_BUS_BASEADDR + 0x3800 )
#define IWDG_BASEADDR       ( APB1_BUS_BASEADDR + 0x3000 )

#define WWDG_BASEADDR       ( APB1_BUS_BASEADDR + 0x2C00 )
#define RTC_BKP_BASEADDR    ( APB1_BUS_BASEADDR + 0x2800 )
#define TIM14_BASEADDR      ( APB1_BUS_BASEADDR + 0x2000 )

#define TIM13_BASEADDR      ( APB1_BUS_BASEADDR + 0x1C00 )
#define TIM12_BASEADDR      ( APB1_BUS_BASEADDR + 0x1800 )
#define TIM7_BASEADDR       ( APB1_BUS_BASEADDR + 0x1400 )
#define TIM6_BASEADDR       ( APB1_BUS_BASEADDR + 0x1000 )

#define TIM5_BASEADDR       ( APB1_BUS_BASEADDR + 0x0C00 ) 
#define TIM4_BASEADDR       ( APB1_BUS_BASEADDR + 0x0800 )
#define TIM3_BASEADDR       ( APB1_BUS_BASEADDR + 0x0400 )
#define TIM2_BASEADDR       ( APB1_BUS_BASEADDR + 0x0000 )



//Peripheral register definition structs
//Peripheral register mappings

typedef struct{
    uint32_t MODER;                     //Offset 0x00: GPIO port mode register.
    uint32_t OTYPER;                    //Offset 0x04: GPIO port output type register.
    uint32_t OSPEEDR;                   //Offset 0x08: GPIO port output speed register.
    uint32_t PUPDR;                     //Offset 0x0C: GPIO port pull-up/pull-down register.
    uint32_t IDR;                       //Offset 0x10: GPIO port input data register.
    uint32_t ODR;                       //Offset 0x14: GPIO port output data register.
    uint32_t BSRR;                      //Offset 0x18: GPIO port bit set/reset register.
    uint32_t LCKR;                      //Offset 0x1C: GPIO port configuration lock register.
    uint32_t AFRL;                      //Offset 0x20: GPIO alternate function low register.
    uint32_t AFRH;                      //Offset 0x24: GPIO alternate function high register.
}GPIO_RegDef_t;

typedef struct{
    uint32_t CR1;                       //Offset 0x00: I2C control register 1
    uint32_t CR2;                       //Offset 0x04: I2C control register 2
    uint32_t OAR1;                      //Offset 0x08: I2C own address register 1
    uint32_t OAR2;                      //Offset 0x0C: I2C own address register 2
    uint32_t DR;                        //Offset 0x10: I2C data register
    uint32_t SR1;                       //Offset 0x14: I2C status register 1
    uint32_t SR2;                       //Offset 0x18: I2C status register 2
    uint32_t CCR;                       //Offset 0x1C: I2C clock control register
    uint32_t TRISE;                     //Offset 0x20: I2C TRISE register
    uint32_t FLTR;                      //Offset 0x24: I2C FLTR register
}I2C_RegDef_t;


//Peripheral base address typecast
#define GPIOA                           ((GPIO_RegDef_t *) GPIOA_BASEADDR)
#define GPIOB                           ((GPIO_RegDef_t *) GPIOB_BASEADDR)
#define GPIOC                           ((GPIO_RegDef_t *) GPIOC_BASEADDR)
#define GPIOD                           ((GPIO_RegDef_t *) GPIOD_BASEADDR)
#define GPIOE                           ((GPIO_RegDef_t *) GPIOE_BASEADDR)
#define GPIOF                           ((GPIO_RegDef_t *) GPIOF_BASEADDR)
#define GPIOG                           ((GPIO_RegDef_t *) GPIOG_BASEADDR)
#define GPIOH                           ((GPIO_RegDef_t *) GPIOH_BASEADDR)

#define I2C1                            ((I2C_RegDef_t *) I2C1_BASEADDR)
#define I2C2                            ((I2C_RegDef_t *) I2C2_BASEADDR)
#define I2C3                            ((I2C_RegDef_t *) I2C3_BASEADDR)


#endif


