/**
 * @file telemetry.h
 * @brief OrbitMesh telemetry service.
 *
 * Public interface for the telemetry subsystem.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_TELEMETRY_H
#define ORBITMESH_TELEMETRY_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "orbitmesh/telemetry_packet.h"


/**
 * @brief Initialize the telemetry service.
 */
void
om_telemetry_init(void);


/**
 * @brief Update the current telemetry packet.
 */
void
om_telemetry_update(void);


/**
 * @brief Get the current telemetry packet.
 *
 * @return Pointer to the current telemetry packet.
 */
const om_telemetry_packet_t *
om_telemetry_packet(void);


/**
 * @brief Transmit the current telemetry packet.
 */
void
om_telemetry_send(void);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TELEMETRY_H */
