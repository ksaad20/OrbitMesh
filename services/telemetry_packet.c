/**
 * @file telemetry_packet.c
 * @brief OrbitMesh telemetry packet implementation.
 *
 * Defines helper functions for constructing and
 * validating telemetry packets.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "orbitmesh/telemetry_packet.h"

#include <stddef.h>
#include <stdint.h>


/**
 * @brief Compute a simple packet checksum.
 *
 * @param packet Pointer to telemetry packet.
 *
 * @return 16-bit checksum.
 */
static uint16_t
om_telemetry_packet_checksum(
    const om_telemetry_packet_t *packet)
{
    const uint8_t *bytes =
        (const uint8_t *)packet;

    uint16_t checksum = 0U;

    for (
        size_t i = 0U;
        i < sizeof(om_telemetry_packet_t) - sizeof(packet->checksum);
        ++i)
    {
        checksum =
            (uint16_t)(checksum + bytes[i]);
    }

    return checksum;
}


/**
 * @brief Initialize a telemetry packet.
 *
 * @param packet Packet to initialize.
 */
void
om_telemetry_packet_init(
    om_telemetry_packet_t *packet)
{
    if (packet == NULL)
    {
        return;
    }

    packet->uptime = 0U;
    packet->health = OM_HEALTH_OK;
    packet->event_count = 0U;
    packet->checksum = 0U;
}


/**
 * @brief Finalize a telemetry packet.
 *
 * Computes the packet checksum before transmission.
 *
 * @param packet Packet to finalize.
 */
void
om_telemetry_packet_finalize(
    om_telemetry_packet_t *packet)
{
    if (packet == NULL)
    {
        return;
    }

    packet->checksum =
        om_telemetry_packet_checksum(
            packet
        );
}
