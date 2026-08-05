/**
 * @file heartbeat.h
 * @brief OrbitMesh heartbeat service.
 *
 * Provides a lightweight heartbeat mechanism for satellite
 * health monitoring and service liveness tracking.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_HEARTBEAT_H
#define ORBITMESH_HEARTBEAT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "error.h"
#include "types.h"


/**
 * @brief Initialize heartbeat service.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_heartbeat_init(void);


/**
 * @brief Send heartbeat signal.
 *
 * Updates the heartbeat counter and timestamp.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_heartbeat_signal(void);


/**
 * @brief Get heartbeat count.
 *
 * @return Number of heartbeat signals generated.
 */
om_tick_t
om_heartbeat_count(void);


/**
 * @brief Reset heartbeat counter.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_heartbeat_reset(void);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_HEARTBEAT_H */
