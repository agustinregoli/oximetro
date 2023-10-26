/*
 * MAXM86161.h
 *
 *  Created on: 28 dic. 2022
 *      Author: rego_
 */

#ifndef MAXM86161_I2C_H_
#define MAXM86161_I2C_H_


/*==================[inclusions]=============================================*/
#include <stdint.h>
#include "fsl_i2c.h"
/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
/** \brief true */
#define true      1
/** \brief false */
#define false     0
/** \brief bool
 **
 ** bool is not a type but a macro exapnded to _Bool
 **/
/*@-namechecks@*/
#define bool   _Bool
/** \brief Bool, true and false are defined */
#define __bool_true_false_are_defined  1
/*@=namechecks@*/

/*==================[typedef]================================================*/
#define MAXM86161_EN_GPIO_PORT    0   // Puerto 0
#define MAXM86161_EN_GPIO_PIN     0   // Pin 0
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
void maxm86161_i2c_write_byte_data(uint8_t dir,uint8_t data);
void maxm86161_i2c_read_byte_data(uint8_t dir,uint8_t data);
//void maxm86161_i2c_write_i2c_block_data(uint8_t dir,uint8_t *data,uint8_t length);
//void maxm86161_i2c_read_i2c_block_data(uint8_t dir,uint8_t *data,uint8_t length);
void maxm86161_i2c_read_from_register(uint8_t dir,uint8_t data);
void maxm86161_i2c_write_to_register(uint8_t dir,uint8_t data);
void maxm86161_i2c_block_write(uint8_t dir,uint16_t length,uint8_t *data);
void maxm86161_i2c_block_read(uint8_t dir,uint16_t length,uint8_t *data);

#endif /* #ifndef CIAAPOSIX_STDBOOL_H */
/* Communicate with the MAXM86161 over I2C or SPI */
/*/*#define MAXM86161_I2C   0
#define MAXM86161_SPI   1
#define MAXM86161_BUS   MAXM86161_I2C

#define MAXM86161_SLAVE_ADDRESS         0x62
/*#define MIKROE_I2C                      I2C1

#define MAXM86161_EN_GPIO_PORT          gpioPortC
#define MAXM86161_EN_GPIO_PIN           3

#define MAXM86161_INT_GPIO_PORT         gpioPortB
#define MAXM86161_INT_GPIO_PIN          3*/

 /** Button 0 for start and pause measurement */
/*#define MAXM86161_BTN0_GPIO_PORT        gpioPortC
#define MAXM86161_BTN0_GPIO_PIN         7*/

#define MIKROE_I2C_INIT_DEFAULT                                               \
{                                                                             \
    MIKROE_I2C,  /* Use I2C instance */                                       \
    gpioPortD,    /* SCL port */                                              \
    2,     /* SCL pin */                                                      \
    gpioPortD,    /* SDA port */                                              \
    3,     /* SDA pin */                                                      \
    0,                         /* Use currently configured reference clock */ \
    I2C_FREQ_STANDARD_MAX,     /* Set to standard rate  */                    \
    i2cClockHLRStandard,       /* Set to use 4:4 low/high duty cycle */       \
};

/*typedef struct Max86161PortConfig
{
#if (MAXM86161_BUS == MAXM86161_I2C)
  //I2C_TypeDef       *i2cPort;   /**< I2C port Maxm86161 is connected to */
  //uint8_t           i2cAddress; /**< I2C address of Maxm86161 */
/*#elif (MAXM86161_BUS == MAXM86161_SPI)
  SPIDRV_Handle_t   spiHandle;   /**< SPI Handle Maxm86161 is connected to */
  //SPIDRV_Init_t     *spiPortConfig;  /**< SPIDRV Initialization struct. */

//#endif
 // GPIO_Port_TypeDef irqPort;    /**< Port for Maxm86161 INT pin */
  //int               irqPin;     /**< Pin for Maxm86161 INT pin */
//} Max86161PortConfig_t;*/


//#endif


//#endif /*MAXM86161_H_*/
