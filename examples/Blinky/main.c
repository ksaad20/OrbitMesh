/**
 * @file main.c
 * @brief OrbitMesh blinky example.
 *
 * Demonstrates a minimal OrbitMesh application
 * using GPIO and scheduler services.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/kernel.h"
#include "orbitmesh/task.h"
#include "orbitmesh/gpio.h"


/*==============================================================================
 * Configuration
 *============================================================================*/

#define LED_PIN 0U


/*==============================================================================
 * Task Functions
 *============================================================================*/

static void
blink_task(
    void *argument)
{
    (void)argument;


    while (1)
    {
        om_gpio_toggle(
            LED_PIN
        );


        om_task_delay(
            500U
        );
    }
}


/*==============================================================================
 * Application Entry
 *============================================================================*/

int
main(void)
{
    om_kernel_init();


    om_gpio_configure(
        LED_PIN,
        OM_GPIO_OUTPUT,
        OM_GPIO_NO_PULL
    );


    om_task_create(
        "blink",
        blink_task,
        NULL
    );


    om_kernel_start();


    while (1)
    {
    }


    return 0;
}
