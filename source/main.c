/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*  Standard C Included Files */
#include "MAXM86161.h"
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "fsl_i2c.h"
//#include "chip.h"
#include "fsl_debug_console.h"
#include "fsl_clock.h"
#include"pin_mux.h"
#include"LPC812.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define EXAMPLE_I2C_MASTER_BASE    (I2C0_BASE)
#define I2C_MASTER_CLOCK_FREQUENCY (200000)
#define WAIT_TIME                  100U
#define EXAMPLE_I2C_MASTER ((I2C_Type *)EXAMPLE_I2C_MASTER_BASE)

#define I2C_MASTER_SLAVE_ADDR_7BIT  0x62// 0b1100010 //0x62//
#define I2C_BAUDRATE               9600//100000U
#define I2C_DATA_LENGTH            33U

/*#define PROX_USE_IR  (1 << 0)  // utiliza el led IR para la medición de proximidad
#define PROX_USE_RED (1 << 1)  // utiliza el led rojo para la medición de proximidad
#define PROX_SELECTION (PROX_USE_IR | PROX_USE_RED)*/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t g_master_txBuff[I2C_DATA_LENGTH];
uint8_t g_master_rxBuff[I2C_DATA_LENGTH];

/*******************************************************************************
 * Code

 ******************************************************************************/
maxm86161_device_config_t default_maxim_config = {
    3,//interrupt level
    {
#if (PROX_SELECTION & PROX_USE_IR)
        0x02,//LED2 - IR
        0x01,//LED1 - green
        0x03,//LED3 - RED
#elif (PROX_SELECTION & PROX_USE_RED)
        0x03,//LED3 - RED
        0x02,//LED2 - IR
        0x01,//LED1 - green
#else // default use GREEN
        0x01,//LED1 - green
        0x02,//LED2 - IR
        0x03,//LED3 - RED
#endif
        0x00,
        0x00,
        0x00,
    },
    {
        0x20,// green
        0x15,// IR
        0x10,// LED
    },
    {
        MAXM86161_PPG_CFG_ALC_DS,
        MAXM86161_PPG_CFG_OFFSET_NO,
        MAXM86161_PPG_CFG_TINT_117p3_US,
        MAXM86161_PPG_CFG_LED_RANGE_16k,
        MAXM86161_PPG_CFG_SMP_RATE_P1_24sps,
        MAXM86161_PPG_CFG_SMP_AVG_1
    },
    {
        MAXM86161_INT_ENABLE,//full_fifo
        MAXM86161_INT_DISABLE,//data_rdy
        MAXM86161_INT_DISABLE,//alc_ovf
#ifdef PROXIMITY
        MAXM86161_INT_ENABLE,//proximity
#else
        MAXM86161_INT_DISABLE,
#endif
        MAXM86161_INT_DISABLE,//led_compliant
        MAXM86161_INT_DISABLE,//die_temp
        MAXM86161_INT_DISABLE,//pwr_rdy
        MAXM86161_INT_DISABLE//sha
    }
};

//inicializo la variable de comunicación i2c
//defino la funcion de interupcion
bool flag_irq=false;
void I2C0_IRQHandler(void){
    	 flag_irq=true;
       }
//defino la variable donde recupero los datos
maxm86161_ppg_sample_t datos;
/*!
 * @brief Main function
 */
int main(void)
{
    /* Select the main clock as source clock of I2C0. */
	CLOCK_Select(kMAINCLK_From_Irc);
    /* Enable clock of i2c0. */
    CLOCK_EnableClock(kCLOCK_I2c0);
   // Board_Init();
    BOARD_InitPins();
    BOARD_BootClockIRC12M();
    BOARD_InitDebugConsole();
    //habilitar la interrupcion
    /* Enable I2C interrupt */
       NVIC_SetPriority(PIN_INT2_IRQn, 2);
       NVIC_ClearPendingIRQ(PIN_INT2_IRQn);
       NVIC_EnableIRQ(PIN_INT2_IRQn);

       i2c_master_transfer_t xfer={
       		  .slaveAddress = I2C_MASTER_SLAVE_ADDR_7BIT,
       		  .direction = kI2C_Write,
       		  .subaddress = 0,
       		  .subaddressSize = 0,
       		  .data = NULL,
       		  .dataSize = 0,
       		  .flags = kI2C_TransferDefaultFlag,
       		};


       i2c_master_config_t masterConfig;
       I2C_MasterGetDefaultConfig(&masterConfig);
       masterConfig.baudRate_Bps = I2C_BAUDRATE;
       I2C_MasterInit(EXAMPLE_I2C_MASTER, &masterConfig, I2C_MASTER_CLOCK_FREQUENCY);
    /*
    GPIO_PinInit(MAXM86161_INT_GPIO, MAXM86161_INT_PIN, &int_pin_config);
*/
       maxim86162_init_dev(EXAMPLE_I2C_MASTER,&xfer,default_maxim_config);




        while (1)
    {

if(flag_irq){
	maxm86161_read_samples_in_fifo(&datos,EXAMPLE_I2C_MASTER);
	flag_irq=false;


    }}
        return 0;
}


