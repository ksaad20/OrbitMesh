/**
 * @file heartbeat.c
 * @brief OrbitMesh heartbeat service implementation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "orbitmesh/heartbeat.h"


static om_tick_t heartbeat_counter = 0U;


/**
 * @brief Initialize heartbeat service.
 */
om_error_t
om_heartbeat_init(void)
{
    heartbeat_counter = 0U;

    return OM_SUCCESS;
}


/**
 * @brief Generate heartbeat.
 */
om_error_t
om_heartbeat_signal(void)
{
    heartbeat_counter++;

    return OM_SUCCESS;
}


/**
 * @brief Return heartbeat count.
 */
om_tick_t
om_heartbeat_count(void)
{
    return heartbeat_counter;
}


/**
 * @brief Reset heartbeat counter.
 */
om_error_t
om_heartbeat_reset(void)
{
    heartbeat_counter = 0U;

    return OM_SUCCESS;
}
