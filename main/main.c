#include <stdio.h>
#include <string.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <unistd.h>

#include "sdkconfig.h"

#define LED_1 CONFIG_LED_1_GPIO
#define LED_2 CONFIG_LED_2_GPIO



void task_led1(void* params){
    int num_tarea = *(int*)params;  // ✅ casteo correcto

    printf("Parametro:%d\n", num_tarea);

    gpio_set_level(LED_1, 0);   

    while(1){
        gpio_set_level(LED_1, 1);   
        vTaskDelay(100 / portTICK_PERIOD_MS);

        gpio_set_level(LED_1, 0);
        vTaskDelay(30 / portTICK_PERIOD_MS);

        printf("tarea:%d\n", num_tarea);
    }
}

void task_led2(void* params){
    int num_tarea = *(int*)params;  // ✅ corregido

    printf("Parametro:%d\n", num_tarea);

    gpio_set_level(LED_2, 0);   

    while(1){
        gpio_set_level(LED_2, 1);   
        vTaskDelay(200 / portTICK_PERIOD_MS);

        gpio_set_level(LED_2, 0);
        vTaskDelay(150 / portTICK_PERIOD_MS);

        printf("tarea:%d\n", num_tarea);
    }
}

void app_main(void)
{
    gpio_set_direction(LED_1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_2, GPIO_MODE_OUTPUT);

    static int num1 = 45;  // ⚠️ mejor static para evitar problemas de scope
    static int num2 = 40;

    xTaskCreate(task_led1, "task led1", 4000, (void*)&num1, 1, NULL);
    xTaskCreate(task_led2, "task led2", 4000, (void*)&num2, 1, NULL);
    printf("Secuencia\n");
}