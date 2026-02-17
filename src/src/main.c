/**
 * @file    main.c
 * @brief   IoT Remote Monitoring - Main Entry Point
 * @platform STM32 / ARM Cortex-M
 * @author  Anjaneya Reddy Pondugula
 */

#include "FreeRTOS.h"
#include "task.h"
#include "sensor_task.h"
#include "mqtt_client.h"
#include <stdint.h>

#define AWS_BROKER_URL  "xxxxxx.iot.us-east-1.amazonaws.com"
#define DEVICE_ID       "stm32-iot-device-01"

static void hw_init(void)
{
    /* Initialize UART, SPI, I2C peripherals */
    /* Configure Wi-Fi module               */
    /* Setup system clock                   */
}

int main(void)
{
    hw_init();

    /* Connect to AWS IoT Core via MQTT */
    mqtt_init(AWS_BROKER_URL, DEVICE_ID);

    /* Create FreeRTOS tasks */
    xTaskCreate(task_sensor_acquisition,
                "SensorAcq",
                512,
                NULL,
                2,
                NULL);

    /* Start scheduler */
    vTaskStartScheduler();

    while (1) {}
    return 0;
}
