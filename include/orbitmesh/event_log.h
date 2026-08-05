/**
 * @file event_log.h
 * @brief OrbitMesh event logging service.
 *
 * Public interface for the OrbitMesh event log.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ORBITMESH_EVENT_LOG_H
#define ORBITMESH_EVENT_LOG_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>


/**
 * @brief Event severity.
 */
typedef enum
{
    OM_EVENT_INFO = 0,
    OM_EVENT_WARNING,
    OM_EVENT_ERROR,
    OM_EVENT_CRITICAL

} om_event_severity_t;


/**
 * @brief OrbitMesh event.
 */
typedef struct
{
    /**
     * @brief System uptime when the event occurred.
     */
    uint32_t timestamp;

    /**
     * @brief Event identifier.
     */
    uint16_t id;

    /**
     * @brief Event severity.
     */
    om_event_severity_t severity;

} om_event_t;


/**
 * @brief Initialize the event log.
 */
void
om_event_log_init(void);


/**
 * @brief Add an event to the log.
 *
 * @param event Event to record.
 */
void
om_event_log_add(
    om_event_t event
);


/**
 * @brief Get the number of recorded events.
 *
 * @return Number of stored events.
 */
uint32_t
om_event_log_count(void);


/**
 * @brief Get an event by index.
 *
 * @param index Event index.
 *
 * @return Pointer to the event, or NULL if the index is invalid.
 */
const om_event_t *
om_event_log_get(
    uint32_t index
);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_EVENT_LOG_H */
