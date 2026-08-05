/**
 * @file command.c
 * @brief OrbitMesh command processing implementation.
 *
 * Implements command registration and execution.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "command.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>


/*==============================================================================
 * Private State
 *============================================================================*/

/**
 * @brief Command registry entry.
 */
typedef struct
{
    bool active;

    uint16_t id;

    om_command_handler_t handler;

} om_command_entry_t;


/**
 * @brief Command handler registry.
 */
static om_command_entry_t
    g_command_registry[OM_COMMAND_MAX_HANDLERS];


/**
 * @brief Initialization state.
 */
static bool g_initialized = false;


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_command_init(void)
{
    memset(
        g_command_registry,
        0,
        sizeof(g_command_registry));


    g_initialized = true;


    return OM_SUCCESS;
}


om_error_t
om_command_register(
    uint16_t id,
    om_command_handler_t handler)
{
    if (handler == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    if (!g_initialized)
    {
        return OM_ERROR_INVALID_STATE;
    }


    for (size_t i = 0U;
         i < OM_COMMAND_MAX_HANDLERS;
         ++i)
    {
        if (!g_command_registry[i].active)
        {
            g_command_registry[i].active = true;

            g_command_registry[i].id = id;

            g_command_registry[i].handler = handler;


            return OM_SUCCESS;
        }
    }


    return OM_ERROR_NO_RESOURCES;
}


om_error_t
om_command_execute(
    const om_command_packet_t *command)
{
    if (command == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    if (!g_initialized)
    {
        return OM_ERROR_INVALID_STATE;
    }


    for (size_t i = 0U;
         i < OM_COMMAND_MAX_HANDLERS;
         ++i)
    {
        if (!g_command_registry[i].active)
        {
            continue;
        }


        if (g_command_registry[i].id == command->id)
        {
            return g_command_registry[i].handler(command);
        }
    }


    return OM_ERROR_NOT_FOUND;
}


void
om_command_process(void)
{
    /*
     * MVP placeholder.
     *
     * Future versions will connect this to:
     *
     * UART
     * Radio driver
     * Ground station protocol
     */
}
