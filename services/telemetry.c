/**
 * @file telemetry.c
 * @brief OrbitMesh telemetry service.
 *
 * Collects spacecraft status and prepares telemetry
 * for transmission to a ground station or simulator.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "orbitmesh/telemetry.h"

#include "orbitmesh/event_log.h"
#include "orbitmesh/health_monitor.h"
#include "orbitmesh/kernel.h"
#include "orbitmesh/telemetry_packet.h"


static om_telemetry_packet_t g_packet;


/**
 * @brief Initialize the telemetry service.
 */
void
om_telemetry_init(void)
{
    om_telemetry_packet_init(
        &g_packet
    );
}


/**
 * @brief Update the current telemetry packet.
 *
 * This function gathers the latest spacecraft state
 * from the kernel and service layer.
 */
void
om_telemetry_update(void)
{
    g_packet.uptime =
        om_kernel_get_uptime();

    g_packet.health =
        om_health_monitor_state();

    g_packet.event_count =
        om_event_log_count();

    om_telemetry_packet_finalize(
        &g_packet
    );
}


/**
 * @brief Get the latest telemetry packet.
 *
 * @return Pointer to the current telemetry packet.
 */
const om_telemetry_packet_t *
om_telemetry_packet(void)
{
    return &g_packet;
}


/**
 * @brief Transmit the current telemetry packet.
 *
 * The MVP implementation is intentionally transport
 * agnostic. Platform-specific code may forward the
 * packet over UART, CAN, Ethernet, RF, or another
 * communications interface.
 */
void
om_telemetry_send(void)
{
    /*
     * TODO:
     * Route the telemetry packet through the
     * selected communications backend.
     */
}
