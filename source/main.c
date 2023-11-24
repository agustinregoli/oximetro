/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*  Standard C Included Files */
//#include "MAXM86161.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"
#include"app.h"
//#include "fsl_i2c.h"
#include "fsl_debug_console.h"
#include "fsl_clock.h"
#include"pin_mux.h"
#include "fsl_pint.h"
#include "fsl_syscon.h"

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


#define DEMO_PINT_PIN_INT0_SRC kSYSCON_GpioPort0Pin12ToPintsel

/*#define PROX_USE_IR  (1 << 0)  // utiliza el led IR para la medición de proximidad
#define PROX_USE_RED (1 << 1)  // utiliza el led rojo para la medición de proximidad
#define PROX_SELECTION (PROX_USE_IR | PROX_USE_RED)*/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
//uint8_t g_master_txBuff[I2C_DATA_LENGTH];
//uint8_t g_master_rxBuff[I2C_DATA_LENGTH];

/*******************************************************************************
 * Code

 ******************************************************************************/

/*!
 * @brief Call back for PINT Pin interrupt 0-7.
 */
uint8_t flag_irq;
void pint_intr_callback(pint_pin_int_t pintr, uint32_t pmatch_status)
{
 flag_irq=true;
}

//defino la variable donde recupero los datos
//maxm86161_ppg_sample_t datos;
/*!
 * @brief Main function
 */
int main(void)
{
    /* Select the main clock as source clock of I2C0. */
	CLOCK_Select(kMAINCLK_From_Irc);
    /* Enable clock of i2c0. */
    CLOCK_EnableClock(kCLOCK_I2c0);

    BOARD_InitPins();
    BOARD_BootClockIRC12M();
    BOARD_InitDebugConsole();

//inicio el modulo maxm86161
    //hrm_init_app();

       /* Connect trigger sources to PINT */
    //linkeo el pin de gpio como interrupcion
      // SYSCON_AttachSignal(SYSCON, kPINT_PinInt0, DEMO_PINT_PIN_INT0_SRC);
       /* Initialize PINT */
       //PINT_Init(PINT);

       /* Setup Pin Interrupt 0 for rising edge */
       //PINT_PinInterruptConfig(PINT, kPINT_PinInt0, kPINT_PinIntEnableFallEdge, pint_intr_callback);
       /* Enable callbacks for PINT0 by Index */
       //PINT_EnableCallbackByIndex(PINT, kPINT_PinInt0);

 while (1)    {

	 //hrm_loop();

	 if(flag_irq){
		//de hrm_process_event(flag_irq);
	 }

	 flag_irq=false;
	// GPIO_PortClearInterruptFlags(EXAMPLE_GPIO_MASTER, 0, 0x01);

    }
        return 0;
}


