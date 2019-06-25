/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

/* USER CODE BEGIN Private defines */
/*************************** REGISTER MAP ***************************/
#define ADXL313_DEVID_0			0x00		// Device ID
#define ADXL313_DEVID_1			0x01		// Device ID
#define ADXL313_PART_ID		    0x02		// Reserved. Do Not Access. 
#define ADXL313_REV_ID		    0x03        // revision ID
#define ADXL313_XID		        0x04        // semiunique serial number
#define ADXL313_SOFT_RESET      0x18        // Writing a value of 0x52 to Register 0x18 triggers the soft reset
#define ADXL313_OFSX			0x1E		// X-Axis Offset. 
#define ADXL313_OFSY			0x1F		// Y-Axis Offset.
#define ADXL313_OFSZ			0x20		// Z- Axis Offset.

#define ADXL313_THRESH_ACT		0x24		// Activity Threshold  . The scale factor is   15.625 mg/LSB. 
#define ADXL313_THRESH_INACT	0x25		// Inactivity Threshold
#define ADXL313_TIME_INACT		0x26		// Inactivity Time   scale factor is  1 sec/LSB
#define ADXL313_ACT_INACT_CTL	0x27		// Axis Enable Control for Activity and Inactivity Detection

#define ADXL313_BW_RATE			0x2C		// Data Rate and Power mode Control   see rates below
#define ADXL313_POWER_CTL		0x2D		// Power-Saving Features Control
#define ADXL313_INT_ENABLE		0x2E		// Interrupt Enable Control
#define ADXL313_INT_MAP			0x2F		// Interrupt Mapping Control   Any bits set to 0 in this register send their respective interrupts to  the INT1 pin     1 to INT2
#define ADXL313_INT_SOURCE		0x30		// Source of Interrupts    Bits set to 1 in this register indicate that their respective functions have triggered an event
#define ADXL313_DATA_FORMAT		0x31		// Data Format Control     set range etc ..d1 d0 0 1 is 1g for our application
#define ADXL313_DATAX0			0x32		// X-Axis Data 0
#define ADXL313_DATAX1			0x33		// X-Axis Data 1
#define ADXL313_DATAY0			0x34		// Y-Axis Data 0
#define ADXL313_DATAY1			0x35		// Y-Axis Data 1
#define ADXL313_DATAZ0			0x36		// Z-Axis Data 0
#define ADXL313_DATAZ1			0x37		// Z-Axis Data 1
#define ADXL313_FIFO_CTL		0x38		// FIFO Control
#define ADXL313_FIFO_STATUS		0x39		// FIFO Status
//Table 5. Current Consumption vs. Data Rates low 4bits in  #define ADXL313_BW_RATE	
#define ADXL313_BW_1600			0xF			// 1111		IDD = 40uA
#define ADXL313_BW_800			0xE			// 1110		IDD = 90uA
#define ADXL313_BW_400			0xD			// 1101		IDD = 140uA
#define ADXL313_BW_200			0xC			// 1100		IDD = 140uA
#define ADXL313_BW_100			0xB			// 1011		IDD = 140uA 
#define ADXL313_BW_50			0xA			// 1010		IDD = 140uA
#define ADXL313_BW_25			0x9			// 1001		IDD = 90uA
#define ADXL313_BW_12_5		    0x8			// 1000		IDD = 60uA 
#define ADXL313_BW_6_25			0x7			// 0111		IDD = 50uA
#define ADXL313_BW_3_13			0x6			// 0110		IDD = 45uA
#define ADXL313_BW_1_56			0x5			// 0101		IDD = 40uA
#define ADXL313_BW_0_78			0x4			// 0100		IDD = 34uA
#define ADXL313_BW_0_39			0x3			// 0011		IDD = 23uA
#define ADXL313_BW_0_20			0x2			// 0010		IDD = 23uA
#define ADXL313_BW_0_10			0x1			// 0001		IDD = 23uA
#define ADXL313_BW_0_05			0x0			// 0000		IDD = 23uA


 /************************** INTERRUPT PINS **************************/
#define ADXL313_INT1_PIN		0x00		//INT1: 0
#define ADXL313_INT2_PIN		0x01		//INT2: 1


 /********************** INTERRUPT BIT POSITION **********************/
#define ADXL313_INT_DATA_READY_BIT		0x07
#define ADXL313_INT_SINGLE_TAP_BIT		0x06
#define ADXL313_INT_DOUBLE_TAP_BIT		0x05
#define ADXL313_INT_ACTIVITY_BIT		0x04
#define ADXL313_INT_INACTIVITY_BIT		0x03
#define ADXL313_INT_FREE_FALL_BIT		0x02
#define ADXL313_INT_WATERMARK_BIT		0x01
#define ADXL313_INT_OVERRUNY_BIT		0x00

#define ADXL313_DATA_READY				0x07
#define ADXL313_SINGLE_TAP				0x06
#define ADXL313_DOUBLE_TAP				0x05
#define ADXL313_ACTIVITY				0x04
#define ADXL313_INACTIVITY				0x03
#define ADXL313_FREE_FALL				0x02
#define ADXL313_WATERMARK				0x01
#define ADXL313_OVERRUNY				0x00


 /****************************** ERRORS ******************************/
#define ADXL313_OK			1		// No Error
#define ADXL313_ERROR		0		// Error Exists

#define ADXL313_NO_ERROR	0		// Initial State
#define ADXL313_READ_ERROR	1		// Accelerometer Reading Error
#define ADXL313_BAD_ARG		2		// Bad Argument


/* USER CODE END Private defines */

void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
