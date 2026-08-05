#include <stdint.h>

#include "orbitmesh/health_monitor.h"

/**
 * @file telemetry_packet.h
 * @brief OrbitMesh telemetry packet definitions.
 *
 * Defines the telemetry packet structure and helper
 * functions for constructing telemetry packets.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_TELEMETRY_PACKET_H
#define ORBITMESH_TELEMETRY_PACKET_H

#ifdef __cplusplus
extern "C" {
#endif

#include "orbitmesh/health_monitor.h"

#include <stdint.h>

/*==============================================================================
 * Telemetry Packet
 *============================================================================*/

/**
 * @brief OrbitMesh telemetry packet.
 */
typedef struct
{
    /**
     * @brief System uptime in ticks.
     */
    uint32_t uptime;

    /**
     * @brief Current health status.
     */
    om_health_state_t health;

    /**
     * @brief Number of recorded events.
     */
    uint32_t event_count;

    /**
     * @brief Packet checksum.
     */
    uint16_t checksum;
} om_telemetry_packet_t;

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize a telemetry packet.
 *
 * @param packet Packet to initialize.
 */
void
om_telemetry_packet_init(
    om_telemetry_packet_t *packet);

/**
 * @brief Finalize a telemetry packet.
 *
 * Computes the packet checksum before transmission.
 *
 * @param packet Packet to finalize.
 */
void
om_telemetry_packet_finalize(
    om_telemetry_packet_t *packet);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TELEMETRY_PACKET_H */
