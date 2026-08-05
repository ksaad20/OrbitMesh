/**
 * @file command.h
 * @brief OrbitMesh command processing service.
 *
 * Provides a lightweight command execution framework for spacecraft
 * operations and ground communication.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_COMMAND_H
#define ORBITMESH_COMMAND_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "orbitmesh/error.h"
#include "orbitmesh/types.h"

#include <stddef.h>
#include <stdint.h>


/*==============================================================================
 * Configuration
 *============================================================================*/

#ifndef OM_COMMAND_MAX_ARGUMENTS
#define OM_COMMAND_MAX_ARGUMENTS 32U
#endif


#ifndef OM_COMMAND_MAX_HANDLERS
#define OM_COMMAND_MAX_HANDLERS 32U
#endif


/*==============================================================================
 * Command Types
 *============================================================================*/

/**
 * @brief Command packet.
 */
typedef struct
{
    /**
     * Command identifier.
     */
    uint16_t id;


    /**
     * Command arguments.
     */
    uint8_t arguments[OM_COMMAND_MAX_ARGUMENTS];


    /**
     * Argument length.
     */
    uint16_t length;

} om_command_packet_t;


/**
 * @brief Command handler function.
 *
 * @param command Command packet.
 *
 * @return Command execution result.
 */
typedef om_error_t
(*om_command_handler_t)(
    const om_command_packet_t *command);


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize command service.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_command_init(void);


/**
 * @brief Register a command handler.
 *
 * @param id Command identifier.
 * @param handler Handler function.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_command_register(
    uint16_t id,
    om_command_handler_t handler);


/**
 * @brief Execute a command.
 *
 * @param command Command packet.
 *
 * @return Handler execution result.
 */
om_error_t
om_command_execute(
    const om_command_packet_t *command);


/**
 * @brief Process incoming command data.
 *
 * Reserved for future UART/radio integration.
 */
void
om_command_process(void);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_COMMAND_H */
