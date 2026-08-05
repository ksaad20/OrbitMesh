/**
 * @file telemetry.h
 * @brief OrbitMesh telemetry service.
 *
 * Provides spacecraft telemetry collection and packet generation.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_TELEMETRY_H
#define ORBITMESH_TELEMETRY_H

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

#ifndef OM_TELEMETRY_MAX_PAYLOAD_SIZE
#define OM_TELEMETRY_MAX_PAYLOAD_SIZE 128U
#endif


/*==============================================================================
 * Telemetry Types
 *============================================================================*/

/**
 * @brief Telemetry packet.
 */
typedef struct
{
    /**
     * Packet sequence number.
     */
    uint32_t sequence;


    /**
     * Timestamp in system ticks.
     */
    om_tick_t timestamp;


    /**
     * Payload length.
     */
    uint16_t length;


    /**
     * Telemetry payload.
     */
    uint8_t payload[OM_TELEMETRY_MAX_PAYLOAD_SIZE];

} om_telemetry_packet_t;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize telemetry service.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_telemetry_init(void);


/**
 * @brief Generate a telemetry packet.
 *
 * Collects current system information and packages it.
 *
 * @param packet Output packet.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_telemetry_generate(
    om_telemetry_packet_t *packet);


/**
 * @brief Get the latest sequence number.
 *
 * @return Current sequence number.
 */
uint32_t
om_telemetry_sequence(void);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TELEMETRY_H */
