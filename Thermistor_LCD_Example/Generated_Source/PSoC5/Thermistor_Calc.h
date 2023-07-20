/*******************************************************************************
* File Name: Thermistor_Calc.h
* Version 1.20
*
* Description:
*  This header file provides registers and constants associated with the
*  ThermistorCalc component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_THERMISTOR_CALC_Thermistor_Calc_H)
#define CY_THERMISTOR_CALC_Thermistor_Calc_H

#include "cyfitter.h"
#include "CyLib.h"

#define Thermistor_Calc_IMPLEMENTATION         (0u)
#define Thermistor_Calc_EQUATION_METHOD        (0u)
#define Thermistor_Calc_LUT_METHOD             (1u)

#if (Thermistor_Calc_IMPLEMENTATION == Thermistor_Calc_EQUATION_METHOD)
    #include <math.h>
#endif /* (Thermistor_Calc_IMPLEMENTATION == Thermistor_Calc_EQUATION_METHOD) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Thermistor_Calc_REF_RESISTOR           (10000)
#define Thermistor_Calc_REF_RES_SHIFT          (0u)
#define Thermistor_Calc_ACCURACY               (10u)
#define Thermistor_Calc_MIN_TEMP               (0 * Thermistor_Calc_SCALE)


/***************************************
*        Function Prototypes
***************************************/

uint32 Thermistor_Calc_GetResistance(int16 vReference, int16 vThermistor)
                                      ;
int16 Thermistor_Calc_GetTemperature(uint32 resT) ;


/***************************************
*           API Constants
***************************************/

#define Thermistor_Calc_K2C                    (273.15)
#define Thermistor_Calc_SCALE                  (100)

#define Thermistor_Calc_THA               (0.004556448)
#define Thermistor_Calc_THB               (-0.000292425)
#define Thermistor_Calc_THC               (1.908193E-06)


#endif /* CY_THERMISTOR_CALC_Thermistor_Calc_H */


/* [] END OF FILE */
