/**
 * @file telemetry_packet.h
 * @brief OrbitMesh telemetry packet definitions.
 *
 * Defines the standard telemetry packet used by the
 * OrbitMesh telemetry service.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_TELEMETRY_PACKET_H
#define ORBITMESH_TELEMETRY_PACKET_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#include "orbitmesh/health_monitor.h"


/**
 * @brief Standard OrbitMesh telemetry packet.
 *
 * This structure is intentionally compact so it can be
 * transmitted over UART, CAN, radio, Ethernet, or other
 * communication interfaces.
 */
typedef struct
{
    /**
     * @brief System uptime in milliseconds.
     */
    uint32_t uptime;

    /**
     * @brief Current system health state.
     */
    om_health_state_t health;

    /**
     * @brief Number of logged events.
     */
    uint32_t event_count;

    /**
     * @brief Packet checksum.
     */
    uint16_t checksum;

} om_telemetry_packet_t;


/**
 * @brief Initialize a telemetry packet.
 *
 * @param packet Packet to initialize.
 */
void
om_telemetry_packet_init(
    om_telemetry_packet_t *packet
);


/**
 * @brief Finalize a telemetry packet.
 *
 * Calculates the packet checksum prior to transmission.
 *
 * @param packet Packet to finalize.
 */
void
om_telemetry_packet_finalize(
    om_telemetry_packet_t *packet
);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TELEMETRY_PACKET_H */
