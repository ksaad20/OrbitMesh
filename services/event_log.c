/**
 * @file event_log.c
 * @brief OrbitMesh event logging service.
 *
 * Stores system events in a fixed-size circular buffer.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "orbitmesh/event_log.h"

#include <stddef.h>
#include <stdint.h>


/**
 * @brief Maximum number of events retained.
 */
#define OM_EVENT_LOG_CAPACITY 64U


/**
 * @brief Event log storage.
 */
static om_event_t
g_event_log[OM_EVENT_LOG_CAPACITY];


/**
 * @brief Number of stored events.
 */
static uint32_t
g_event_count = 0U;


/**
 * @brief Next write index.
 */
static uint32_t
g_event_head = 0U;


/**
 * @brief Initialize the event log.
 */
void
om_event_log_init(void)
{
    g_event_count = 0U;
    g_event_head = 0U;
}


/**
 * @brief Record an event.
 *
 * @param event Event to record.
 */
void
om_event_log_add(
    om_event_t event)
{
    g_event_log[g_event_head] = event;

    g_event_head =
        (g_event_head + 1U) %
        OM_EVENT_LOG_CAPACITY;

    if (g_event_count < OM_EVENT_LOG_CAPACITY)
    {
        ++g_event_count;
    }
}


/**
 * @brief Get the number of stored events.
 *
 * @return Event count.
 */
uint32_t
om_event_log_count(void)
{
    return g_event_count;
}


/**
 * @brief Retrieve an event by index.
 *
 * @param index Event index.
 *
 * @return Pointer to the event, or NULL if invalid.
 */
const om_event_t *
om_event_log_get(
    uint32_t index)
{
    if (index >= g_event_count)
    {
        return NULL;
    }

    return &g_event_log[index];
}
