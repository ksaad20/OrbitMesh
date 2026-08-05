/**
 * @file telemetry.c
 * @brief OrbitMesh telemetry service implementation.
 *
 * Implements deterministic telemetry packet generation.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "telemetry.h"

#include "services/health/health.h"

#include "orbitmesh/kernel.h"

#include <string.h>

/*==============================================================================
 * Private State
 *============================================================================*/

/**
 * @brief Telemetry sequence counter.
 */
static uint32_t g_sequence = 0U;


/**
 * @brief Telemetry initialization state.
 */
static bool g_initialized = false;


/*==============================================================================
 * Public API
 *============================================================================*/

om_error_t
om_telemetry_init(void)
{
    g_sequence = 0U;

    g_initialized = true;

    return OM_SUCCESS;
}


om_error_t
om_telemetry_generate(
    om_telemetry_packet_t *packet)
{
    if (packet == NULL)
    {
        return OM_ERROR_NULL_POINTER;
    }


    if (!g_initialized)
    {
        return OM_ERROR_INVALID_STATE;
    }


    om_health_report_t health;


    om_error_t result =
        om_health_get_report(
            &health);


    if (result != OM_SUCCESS)
    {
        return result;
    }


    memset(
        packet,
        0,
        sizeof(*packet));


    packet->sequence = g_sequence++;

    packet->timestamp =
        om_kernel_uptime();


    /*
     * Simple binary payload layout:
     *
     * Bytes 0-3:
     *     Heartbeat counter
     *
     * Bytes 4-7:
     *     Fault count
     *
     * Byte 8:
     *     Health status
     */

    memcpy(
        &packet->payload[0],
        &health.heartbeat,
        sizeof(uint32_t));


    memcpy(
        &packet->payload[4],
        &health.fault_count,
        sizeof(uint32_t));


    packet->payload[8] =
        (uint8_t)health.status;


    packet->length = 9U;


    return OM_SUCCESS;
}


uint32_t
om_telemetry_sequence(void)
{
    return g_sequence;
}
