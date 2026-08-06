/**
 * @file heartbeat.c
 * @brief OrbitMesh heartbeat service implementation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "orbitmesh/heartbeat.h"

static om_tick_t heartbeat_counter = 0U;

/**
 * @brief Initialize the heartbeat service.
 */
om_error_t
om_heartbeat_init(void)
{
    heartbeat_counter = 0U;

    return OM_SUCCESS;
}

/**
 * @brief Update the heartbeat.
 */
void
om_heartbeat_update(void)
{
    heartbeat_counter++;
}

/**
 * @brief Return the heartbeat count.
 */
om_tick_t
om_heartbeat_count(void)
{
    return heartbeat_counter;
}

/**
 * @brief Reset the heartbeat counter.
 */
om_error_t
om_heartbeat_reset(void)
{
    heartbeat_counter = 0U;

    return OM_SUCCESS;
}
