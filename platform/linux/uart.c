/**
 * @file uart.c
 * @brief OrbitMesh Linux UART simulation.
 *
 * Provides a host implementation of UART operations
 * for simulator development.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/error.h"

#include <stdio.h>


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_uart_init(void)
{
    printf(
        "UART initialized\n"
    );

    return OM_SUCCESS;
}


om_error_t
om_uart_write(
    const char *data)
{
    if (data == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    printf(
        "%s",
        data
    );


    return OM_SUCCESS;
}
