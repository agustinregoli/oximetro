/*
 * maxim61861.c
 *
 *  Created on: 28 dic. 2022
 *      Author: rego_
 */


/*==================[inclusions]=============================================*/
#include "MAXM86161.h"

/*==================[macros and definitions]=================================*/

#define DELAY_CHARACTER 500000
//#define I2C_MASTER_SLAVE_ADDR_7BIT 0b1100011
/*==================[external functions definition]==========================*/


void maxm86161_software_reset(I2C_Type *base, i2c_master_transfer_t *xfer){
	uint8_t value = 7;
	//xfer->slaveAddress=I2C_MASTER_SLAVE_ADDR_7BIT;
	xfer->direction = kI2C_Read;
	xfer->subaddress = MAXM86161_REG_SYSTEM_CONTROL;
	xfer->subaddressSize = 1;
	xfer->data = &value;
	xfer->dataSize = 1;

	I2C_MasterTransferBlocking(base, xfer);
	    value= MAXM86161_SYS_CTRL_SW_RESET;

	    xfer->direction = kI2C_Write;
		xfer->subaddress = MAXM86161_REG_SYSTEM_CONTROL;
		xfer->subaddressSize = 1;
	    xfer->data = &value;
	    I2C_MasterTransferBlocking(base, xfer);
	  //prueba
uint8_t aux_value=13;
	    xfer->direction = kI2C_Read;
	 //   xfer->subaddress = MAXM86161_REG_SYSTEM_CONTROL;
	    xfer->subaddressSize = 1;
	    xfer->data = &aux_value;
	    xfer->dataSize = 1;

	    I2C_MasterTransferBlocking(base, xfer);
}



void maxm86161_flush_fifo(I2C_Type *base, i2c_master_transfer_t *xfer){
	uint8_t value = 0;

	xfer->direction = kI2C_Read;
	xfer->subaddress = MAXM86161_REG_FIFO_CONFIG2;
	xfer->subaddressSize = 1;
	xfer->data = &value;
	xfer->dataSize = 1;
	I2C_MasterTransferBlocking(base, xfer);

	value |= MAXM86161_FIFO_CFG_2_FLUSH_FIFO;
	xfer->direction = kI2C_Write;
	xfer->data = &value;
	I2C_MasterTransferBlocking(base, xfer);
}

void maxm86161_set_int_level(I2C_Type *base, i2c_master_transfer_t *xfer,uint8_t level){
	uint8_t value = 0;
	xfer->direction = kI2C_Write;
	xfer->subaddress = MAXM86161_REG_FIFO_CONFIG1;
	xfer->subaddressSize = 1;
	xfer->data = &value;
	xfer->dataSize = 1;
	value = 128 - level;
  	 I2C_MasterTransferBlocking(base,xfer);

  	 uint8_t avalue=13;
  	xfer->direction = kI2C_Read;
  		xfer->subaddress = MAXM86161_REG_FIFO_CONFIG1;
  		xfer->subaddressSize = 1;
  		xfer->data = &avalue;
  		xfer->dataSize = 1;
  	  	 I2C_MasterTransferBlocking(base,xfer);
}



void maxm86161_ppg_config(I2C_Type *base, i2c_master_transfer_t *xfer,maxm86161_ppg_cfg_t *ppg_cfg){
uint8_t value=0;
		xfer->direction = kI2C_Write;
		xfer->subaddress = MAXM86161_REG_PPG_CONFIG1;
		xfer->subaddressSize = 1;
		xfer->data = &value;
		xfer->dataSize = 1;
		value= (ppg_cfg->alc << MAXM86161_PPG_CFG_ALC ) |
				( ppg_cfg->offset << MAXM86161_PPG_CFG_OFFSET ) |
				( ppg_cfg->adc_range << MAXM86161_PPG_CFG_ADC_RANGE ) |
				( ppg_cfg->ppg_tint << MAXM86161_PPG_CFG_TINT );

		I2C_MasterTransferBlocking(base,xfer);
	value=0;
	xfer->direction = kI2C_Read;
		xfer->subaddress = MAXM86161_REG_PPG_CONFIG1;
		xfer->subaddressSize = 1;
		xfer->data = &value;
		xfer->dataSize = 1;
		I2C_MasterTransferBlocking(base,xfer);


	/*I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_PPG_CONFIG1, (
	                          ( ppg_cfg->alc << MAXM86161_PPG_CFG_ALC ) |
	                          ( ppg_cfg->offset << MAXM86161_PPG_CFG_OFFSET ) |
	                          ( ppg_cfg->adc_range << MAXM86161_PPG_CFG_ADC_RANGE ) |
	                          ( ppg_cfg->ppg_tint << MAXM86161_PPG_CFG_TINT ) ) );*/

	 xfer->subaddress = MAXM86161_REG_PPG_CONFIG2;
	 value=( ppg_cfg->smp_rate << MAXM86161_PPG_CFG_SMP_RATE ) |
           ( ppg_cfg->smp_freq << MAXM86161_PPG_CFG_SMP_AVG );
	  xfer->data = &value;

		I2C_MasterTransferBlocking(base,xfer);

	/*I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_PPG_CONFIG2, (
	                          ( ppg_cfg->smp_rate << MAXM86161_PPG_CFG_SMP_RATE ) |
	                          ( ppg_cfg->smp_freq << MAXM86161_PPG_CFG_SMP_AVG ) ) );*/
}


void maxm86161_led_pa_config_specific(I2C_Type *base, i2c_master_transfer_t *xfer,uint8_t ledx, uint8_t value){
	uint8_t HEARTRATE2_LED_1=0;
	xfer->direction = kI2C_Write;
	xfer->subaddress = MAXM86161_REG_PPG_CONFIG1;
	xfer->subaddressSize = 1;
	xfer->data = &value;
	xfer->dataSize = 1;
	switch (ledx){
	          case 1:
	        	  xfer->subaddress = MAXM86161_REG_LED1_PA;
	      		I2C_MasterTransferBlocking(base,xfer);
	            break;
	          case 2:
	        	  xfer->subaddress = MAXM86161_REG_LED2_PA;
	        	  	      		I2C_MasterTransferBlocking(base,xfer);
	            break;
	          case 3:
	        	  xfer->subaddress = MAXM86161_REG_LED3_PA;
	        	  	      		I2C_MasterTransferBlocking(base,xfer);
	            break;
}
}



void maxm86161_led_pa_config (I2C_Type *base, i2c_master_transfer_t *xfer, maxm86161_ledpa_t *ledpa){
	xfer->direction = kI2C_Write;
	xfer->subaddress = MAXM86161_REG_LED1_PA;
	xfer->subaddressSize = 1;
	xfer->data = &ledpa->green;
	xfer->dataSize = 1;
I2C_MasterTransferBlocking(base,xfer);


	xfer->data = &ledpa->ir;
 I2C_MasterTransferBlocking(base,xfer);


	xfer->data = &ledpa->red;
  I2C_MasterTransferBlocking(base,xfer);
	/*I2CM_WriteByte(pI2C,xfer, MAXM86161_REG_LED1_PA, ledpa->green );
	I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_LED2_PA, ledpa->ir );
	I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_LED3_PA, ledpa->red );*/
}




void maxm86161_led_range_config(I2C_Type *base, i2c_master_transfer_t *xfer,maxm86161_led_range_curr_t *led_range){
	uint8_t value=(led_range->green << MAXM86161_LED_RANGE_SHIFT_GREEN) |
			 	  (led_range->ir << MAXM86161_LED_RANGE_SHIFT_IR) |
				  (led_range->red << MAXM86161_LED_RANGE_SHIFT_RED);
	xfer->direction = kI2C_Write;
	xfer->subaddress = MAXM86161_REG_LED_RANGE1;
	xfer->subaddressSize = 1;
	xfer->data =&value;
	xfer->dataSize = 1;

	I2C_MasterTransferBlocking(base,xfer);

	/*I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_LED_RANGE1,(
            (led_range->green << MAXM86161_LED_RANGE_SHIFT_GREEN) |
            (led_range->ir << MAXM86161_LED_RANGE_SHIFT_IR) |
            (led_range->red << MAXM86161_LED_RANGE_SHIFT_RED)));
*/
}



void maxm86161_led_sequence_config(I2C_Type *base, i2c_master_transfer_t *xfer,maxm86161_ledsq_cfg_t *ledsq){
		uint8_t value=((ledsq->ledsq2 << MAXM86161_LEDSQ_SHIFT) | (ledsq->ledsq1));
		xfer->direction = kI2C_Write;
		xfer->subaddress = MAXM86161_REG_LED_SEQ1;
		xfer->subaddressSize = 1;
		xfer->data =&value;
		xfer->dataSize = 1;
		I2C_MasterTransferBlocking(base,xfer);
	/*I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_LED_SEQ1,
	                                ((ledsq->ledsq2 << MAXM86161_LEDSQ_SHIFT) | (ledsq->ledsq1)));
*/
	xfer->subaddress = MAXM86161_REG_LED_SEQ2;
	value=((ledsq->ledsq4 << MAXM86161_LEDSQ_SHIFT) | (ledsq->ledsq3));
    xfer->data = &value;
	I2C_MasterTransferBlocking(base,xfer);

	/*
	I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_LED_SEQ2,
	                                ((ledsq->ledsq4 << MAXM86161_LEDSQ_SHIFT) | (ledsq->ledsq3)));
*/
	xfer->subaddress = MAXM86161_REG_LED_SEQ3;
	value=((ledsq->ledsq6 << MAXM86161_LEDSQ_SHIFT)|(ledsq->ledsq5));
    xfer->data = &value;
		I2C_MasterTransferBlocking(base,xfer);

	uint8_t aux=13;
				xfer->direction = kI2C_Read;
				xfer->subaddress = MAXM86161_REG_LED_SEQ3;
				xfer->subaddressSize = 1;
				xfer->data =&aux;
				xfer->dataSize = 1;
				I2C_MasterTransferBlocking(base,xfer);

	/*
	I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_LED_SEQ3,
	                                ((ledsq->ledsq6 << MAXM86161_LEDSQ_SHIFT)|(ledsq->ledsq5)));
*/
}






void maxm86161_interupt_control(I2C_Type *base, i2c_master_transfer_t *xfer,maxm86161_int_t *int_ctrl){
	uint8_t value=((int_ctrl->full_fifo << MAXM86161_INT_SHIFT_FULL) |
            (int_ctrl->data_rdy << MAXM86161_INT_SHIFT_DATA_RDY) |
            (int_ctrl->alc_ovf << MAXM86161_INT_SHIFT_ALC_OVF) |
            (int_ctrl->proxy << MAXM86161_INT_SHIFT_PROXY) |
            (int_ctrl->led_compliant << MAXM86161_INT_SHIFT_LED_COMPLIANT) |
            (int_ctrl->die_temp << MAXM86161_INT_SHIFT_DIE_TEMEP));
			xfer->direction = kI2C_Write;
			xfer->subaddress = MAXM86161_REG_IRQ_ENABLE1;
			xfer->subaddressSize = 1;
			xfer->data =&value;
			xfer->dataSize = 1;
			I2C_MasterTransferBlocking(base,xfer);

			uint8_t aux=13;

			xfer->direction = kI2C_Read;
						xfer->subaddress = MAXM86161_REG_IRQ_ENABLE1;
						xfer->subaddressSize = 1;
						xfer->data =&aux;
						xfer->dataSize = 1;
						I2C_MasterTransferBlocking(base,xfer);


/*	I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_IRQ_ENABLE1, (
	                          (int_ctrl->full_fifo << MAXM86161_INT_SHIFT_FULL) |
	                          (int_ctrl->data_rdy << MAXM86161_INT_SHIFT_DATA_RDY) |
	                          (int_ctrl->alc_ovf << MAXM86161_INT_SHIFT_ALC_OVF) |
	                          (int_ctrl->proxy << MAXM86161_INT_SHIFT_PROXY) |
	                          (int_ctrl->led_compliant << MAXM86161_INT_SHIFT_LED_COMPLIANT) |
	                          (int_ctrl->die_temp << MAXM86161_INT_SHIFT_DIE_TEMEP)));
*/

			xfer->subaddress = MAXM86161_REG_IRQ_ENABLE2;
				value=(int_ctrl->sha << MAXM86161_INT_SHIFT_SHA);
			    xfer->data = &value;
					I2C_MasterTransferBlocking(base,xfer);

/*	I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_IRQ_ENABLE2, (
	                          (int_ctrl->sha << MAXM86161_INT_SHIFT_SHA)));
*/
}


void maxim86162_init_dev(I2C_Type *base, i2c_master_transfer_t *xfer,maxm86161_device_config_t global_cfg){

	  maxm86161_software_reset(base,xfer);
	  maxm86161_ppg_config(base,xfer,&global_cfg.ppg_cfg);
	  maxm86161_led_sequence_config(base,xfer,&global_cfg.ledsq_cfg);
	  maxm86161_interupt_control(base,xfer,&global_cfg.int_cfg);
	  maxm86161_led_pa_config(base,xfer,&global_cfg.ledpa_cfg);
	  maxm86161_set_int_level(base,xfer,global_cfg.int_level);

	  uint8_t value=(MAXM86161_FIFO_CFG_2_FULL_TYPE_RPT | MAXM86161_FIFO_CFG_2_FIFO_READ_DATA_CLR);
	  	  	  	xfer->direction = kI2C_Write;
	  			xfer->subaddress = MAXM86161_REG_FIFO_CONFIG2;
	  			xfer->subaddressSize = 1;
	  			xfer->data =&value;
	  			xfer->dataSize = 1;
	  			I2C_MasterTransferBlocking(base,xfer);

	  maxm86161_flush_fifo(base,xfer);
	 // I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_FIFO_CONFIG2, MAXM86161_FIFO_CFG_2_FULL_TYPE_RPT | MAXM86161_FIFO_CFG_2_FIFO_READ_DATA_CLR);
#ifdef PROXIMITY
	  			xfer->subaddress = MAXM86161_REG_LED_PILOT_PA;
	  							value=0x05;
	  						    xfer->data = &value;
	  								I2C_MasterTransferBlocking(base,xfer);

	  //I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_LED_PILOT_PA, 0x05);

	  xfer->subaddress = MAXM86161_REG_PROX_INT_THRESHOLD;
	  	  							value=0x01;
	  	  						xfer->data = &value;
	  	  								I2C_MasterTransferBlocking(base,xfer);

	 // I2CM_WriteByte(pI2C,xfer,MAXM86161_REG_PROX_INT_THRESHOLD, 0x01);  //threshold = 1*2048
#endif

}

//da los estados de las interrupciones
void maxm86161_get_irq_status(I2C_Type *base, i2c_master_transfer_t *xfer,maxm86161_int_t *int_status)
{
  uint8_t int_status_value;


				xfer->direction = kI2C_Read;
	  			xfer->subaddress = MAXM86161_REG_IRQ_STATUS1;
	  			xfer->subaddressSize = 1;
	  			xfer->data =&int_status_value;
	  			xfer->dataSize = 1;
	  			I2C_MasterTransferBlocking(base,xfer);

  int_status->pwr_rdy = ((int_status_value >> MAXM86161_INT_SHIFT_PWR_RDY) &
                                                MAXM86161_INT_MASK );
  int_status->die_temp = ((int_status_value >> MAXM86161_INT_SHIFT_DIE_TEMEP) &
                                                 MAXM86161_INT_MASK );
  int_status->led_compliant = ((int_status_value >> MAXM86161_INT_SHIFT_LED_COMPLIANT) &
                                                      MAXM86161_INT_MASK );
  int_status->proxy = ((int_status_value >> MAXM86161_INT_SHIFT_PROXY) &
                                              MAXM86161_INT_MASK );
  int_status->alc_ovf = ((int_status_value >> MAXM86161_INT_SHIFT_ALC_OVF ) &
                                                MAXM86161_INT_MASK );
  int_status->data_rdy = ((int_status_value >> MAXM86161_INT_SHIFT_DATA_RDY) &
                                                 MAXM86161_INT_MASK );
  int_status->full_fifo = ( ( int_status_value >> MAXM86161_INT_SHIFT_FULL) &
                                                  MAXM86161_INT_MASK);

  	  	  	  	xfer->direction = kI2C_Read;
  	  			xfer->subaddress = MAXM86161_REG_IRQ_STATUS2;
  	  			xfer->subaddressSize = 1;
  	  			xfer->data =&int_status_value;
  	  			xfer->dataSize = 1;
  	  			I2C_MasterTransferBlocking(base,xfer);



  int_status->sha = ((int_status_value >> MAXM86161_INT_SHIFT_SHA) &
                                            MAXM86161_INT_MASK);
}




bool maxm86161_read_samples_in_fifo(maxm86161_ppg_sample_t *sample,I2C_Type *base)
{
  uint32_t temp_data;
  uint8_t sample_cnt;
  uint8_t block_buf[3*128];
  int i = 0;
  maxm86161_fifo_data_t fifo;
  bool task_started = false; // we only start to tream to uart incase we meet perfect sample (means PPG1, PPG2, PPG3)
  bool task_completed = false;

  i2c_master_transfer_t xfer;

  xfer.direction = kI2C_Read;
  xfer.subaddress = 0x07;
  xfer.subaddressSize = 1;
  xfer.data = &sample_cnt;
  xfer.dataSize = 1;
  xfer.flags = kI2C_TransferNoStopFlag;

  I2C_MasterTransferBlocking(base, &xfer);


  xfer.direction = kI2C_Read;
  xfer.subaddress = MAXM86161_REG_FIFO_DATA;
  xfer.subaddressSize = 1;
  xfer.data = block_buf;
  xfer.dataSize = 3 * sample_cnt;
  xfer.flags = kI2C_TransferDefaultFlag;

  I2C_MasterTransferBlocking(base,&xfer);

  for (i = 0; i < sample_cnt; i++)
  {
    temp_data = 0x000000;
    temp_data = (block_buf[i*3 + 0] << 16 | block_buf[i*3+1] << 8 | block_buf[i*3+2] );
    fifo.data_val = temp_data & MAXM86161_REG_FIFO_DATA_MASK;
    fifo.tag = (temp_data >> MAXM86161_REG_FIFO_RES) & MAXM86161_REG_FIFO_TAG_MASK;

#if (PROX_SELECTION & PROX_USE_IR)
    if( fifo.tag == 1){
      task_started = true;
      sample->ppg2 = fifo.data_val;
    } else if(fifo.tag == 2){
        sample->ppg1 = fifo.data_val;
    } else if(fifo.tag == 3){
        sample->ppg3 = fifo.data_val;
        if(task_started)
          task_completed = true;
    }
#elif (PROX_SELECTION & PROX_USE_RED)
    if( fifo.tag == 1){
      task_started = true;
      sample->ppg3 = fifo.data_val;
    } else if(fifo.tag == 2){
        sample->ppg2 = fifo.data_val;
    } else if(fifo.tag == 3){
        sample->ppg1 = fifo.data_val;
        if(task_started)
          task_completed = true;
    }
#else // default use green led for proximity
    if( fifo.tag == 1){
      task_started = true;
      sample->ppg1 = fifo.data_val;
    } else if(fifo.tag == 2){
        sample->ppg2 = fifo.data_val;
    } else if(fifo.tag == 3){
        sample->ppg3 = fifo.data_val;
        if(task_started)
          task_completed = true;
    }
#endif
    if(task_completed && task_started)
    {
      task_completed = false;
      task_started = false;
      return true;
    }
  }
  return false;
}



/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
