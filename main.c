#include <stdio.h>
#include <math.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"

#define TEMP_SENSOR_ADC_CHANNEL ADC1_CHANNEL_6  // GPIO34

// Constants for 10k thermistor
#define BETA 3950.0         // Beta parameter
#define ROOM_TEMP_K 298.15  // 25°C in Kelvin
#define R0 10000.0          // Resistance at 25°C
#define SERIES_RESISTOR 10000.0  // 10k pull-up

void app_main(void) {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(TEMP_SENSOR_ADC_CHANNEL, ADC_ATTEN_DB_11);

    while (1) {
        int adc_raw = adc1_get_raw(TEMP_SENSOR_ADC_CHANNEL);

        float voltage = (adc_raw / 4095.0) * 3.3;

        // Calculate thermistor resistance
        float resistance = SERIES_RESISTOR * (voltage / (3.3 - voltage));


        // Apply B-parameter equation
        float tempK = 1.0 / ( (1.0 / ROOM_TEMP_K) + (1.0 / BETA) * log(resistance / R0) );
        float tempC = tempK - 273.15;

        printf("ADC: %d | Voltage: %.3f V | R: %.1f ohm | Temp: %.2f °C\n", adc_raw, voltage, resistance, tempC);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
