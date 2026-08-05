/**
 * @file telemetry.h
 * @brief OrbitMesh telemetry service interface.
 *
 * Provides the public API for collecting, updating,
 * and transmitting spacecraft telemetry.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_TELEMETRY_H
#define ORBITMESH_TELEMETRY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "orbitmesh/telemetry_packet.h"

/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize the telemetry service.
 */
void
om_telemetry_init(void);

/**
 * @brief Update the current telemetry packet.
 *
 * Collects the latest spacecraft state from the
 * kernel and OrbitMesh services.
 */
void
om_telemetry_update(void);

/**
 * @brief Return the latest telemetry packet.
 *
 * @return Pointer to the current telemetry packet.
 */
const om_telemetry_packet_t *
om_telemetry_packet(void);

/**
 * @brief Transmit the current telemetry packet.
 *
 * The transport implementation is platform-specific.
 */
void
om_telemetry_send(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TELEMETRY_H */
