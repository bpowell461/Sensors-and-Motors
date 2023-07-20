/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "math.h"
#include "float.h"

#define MUX_CHANNEL_0   0U
#define MUX_CHANNEL_1   1U
#define HIGH            1U
#define LOW             0U
#define R_VAL_OHMS      10000U
#define PERIOD_1HZ      1000U

void IC_Init();
int16 Read_Thermistor_Val(uint8_t Mux_Channel);
void LCD_Print_In_Degrees(int16 temperature);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    IC_Init();
    
    int16 thermistor_mV, R1_mV, temperature;
    uint32_t thermistor_R;
    
    for(;;)
    {
        
        thermistor_mV = Read_Thermistor_Val(MUX_CHANNEL_0);
        R1_mV         = Read_Thermistor_Val(MUX_CHANNEL_1);
        
        thermistor_R = Thermistor_Calc_GetResistance(R1_mV, thermistor_mV);
        
        temperature = Thermistor_Calc_GetTemperature(thermistor_R);
        
        LCD_Print_In_Degrees(temperature);
        
        CyDelay(PERIOD_1HZ);
    }
}

void IC_Init()
{
    ADC_DelSig_1_Start();
    AMux_1_Start();
    LCD_Char_1_Start();
    LCD_Char_1_Position(0,0);
}

int16 Read_Thermistor_Val(uint8_t Mux_Channel)
{
    int16 ADC_Result;
    int16 ADC_Result_mV;
    
    Pin3_3_Write(HIGH);
        
    AMux_1_Select(Mux_Channel);
    ADC_DelSig_1_StartConvert();
    
    // Blocking call to poll for end of ADC Conversion
    ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT);
    
    Pin3_3_Write(LOW);
    
    ADC_Result = ADC_DelSig_1_GetResult16();
    ADC_Result_mV = (int16) ADC_DelSig_1_CountsTo_mVolts(ADC_Result);
    
    return (ADC_Result_mV);
}

void LCD_Print_In_Degrees(int16 temperature)
{
    LCD_Char_1_PrintNumber(temperature / 100);
    LCD_Char_1_Position(1,2);
    LCD_Char_1_PrintString(".");
    LCD_Char_1_PrintNumber(temperature % 100);
}


/* [] END OF FILE */
