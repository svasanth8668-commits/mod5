#include "sdk_project_config.h"
#include "peripherals_adc_pal_1.h"
uint16_t status;
int main(void)
 {
	CLOCK_DRV_Init(&clockMan1_InitConfig0);
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
	PWM_Init(&pwm_pal_1_instance,&pwm_pal_1_configs);
	ADC_Init(&adc_pal_1_instance,&adc_pal_1_config);
	while(1){
		ADC_StartGroupConversion(&adc_pal_1_instance,0U);
		status=adc_pal_1_results0[0];
		PWM_UpdateDuty(&pwm_pal_1_instance,0U,status);
	}
}
