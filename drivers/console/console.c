/**
 * @file console.c
 * @brief OrbitMesh serial console driver implementation.
 *
 * Implements the developer console using the UART HAL.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "console.h"

#include "orbitmesh/uart.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/*==============================================================================
 * Private Configuration
 *============================================================================*/

#ifndef OM_CONSOLE_UART_ID
#define OM_CONSOLE_UART_ID 0U
#endif


#ifndef OM_CONSOLE_BAUD_RATE
#define OM_CONSOLE_BAUD_RATE 115200U
#endif


/*==============================================================================
 * Private State
 *============================================================================*/

static bool g_console_initialized = false;


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_console_init(void)
{
    om_uart_config_t config =
    {
        .id = OM_CONSOLE_UART_ID,
        .baud_rate = OM_CONSOLE_BAUD_RATE,
        .data_bits = 8U,
        .parity = OM_UART_PARITY_NONE,
        .stop_bits = OM_UART_STOP_BITS_1
    };


    om_error_t result =
        om_uart_configure(&config);


    if (result != OM_SUCCESS)
    {
        return result;
    }


    g_console_initialized = true;


    return OM_SUCCESS;
}


om_error_t
om_console_putc(
    char character)
{
    if (!g_console_initialized)
    {
        return OM_ERROR_INVALID_STATE;
    }


    return om_uart_write_byte(
        OM_CONSOLE_UART_ID,
        (uint8_t)character);
}


om_error_t
om_console_write(
    const char *text)
{
    if (text == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    if (!g_console_initialized)
    {
        return OM_ERROR_INVALID_STATE;
    }


    return om_uart_write(
        OM_CONSOLE_UART_ID,
        (const uint8_t *)text,
        strlen(text));
}


om_error_t
om_console_printf(
    const char *format,
    ...)
{
    if (format == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    char buffer[OM_CONSOLE_BUFFER_SIZE];


    va_list arguments;

    va_start(
        arguments,
        format);


    int length =
        vsnprintf(
            buffer,
            sizeof(buffer),
            format,
            arguments);


    va_end(arguments);


    if (length < 0)
    {
        return OM_ERROR_INTERNAL;
    }


    return om_console_write(buffer);
}


om_error_t
om_console_getc(
    char *character)
{
    if (character == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    if (!g_console_initialized)
    {
        return OM_ERROR_INVALID_STATE;
    }


    uint8_t value = 0U;


    om_error_t result =
        om_uart_read_byte(
            OM_CONSOLE_UART_ID,
            &value);


    if (result != OM_SUCCESS)
    {
        return result;
    }


    *character = (char)value;


    return OM_SUCCESS;
}
