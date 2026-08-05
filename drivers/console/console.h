/**
 * @file console.h
 * @brief OrbitMesh serial console driver.
 *
 * Provides a simple text console interface built on top of the UART HAL.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_CONSOLE_H
#define ORBITMESH_CONSOLE_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "orbitmesh/error.h"

#include <stddef.h>
#include <stdint.h>

/*==============================================================================
 * Configuration
 *============================================================================*/

/**
 * @brief Maximum formatted message length.
 */
#ifndef OM_CONSOLE_BUFFER_SIZE
#define OM_CONSOLE_BUFFER_SIZE 256U
#endif


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the console driver.
 *
 * Configures the default debug UART.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_console_init(void);


/**
 * @brief Write a character to the console.
 *
 * @param character Character to send.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_console_putc(
    char character);


/**
 * @brief Write a string to the console.
 *
 * @param text Null-terminated string.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_console_write(
    const char *text);


/**
 * @brief Write a formatted message.
 *
 * @param format printf-style format string.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_console_printf(
    const char *format,
    ...);


/**
 * @brief Read a character from the console.
 *
 * @param character Output character.
 *
 * @return OM_SUCCESS if a character is available.
 */
om_error_t
om_console_getc(
    char *character);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_CONSOLE_H */
