/**
 * @file types.h
 * @brief Fundamental data types for OrbitMesh.
 *
 * This header defines the core type aliases used throughout the OrbitMesh
 * operating system. It intentionally contains only basic type definitions to
 * minimize dependencies and prevent circular includes.
 *
 * @note
 * This header should remain lightweight and stable. Do not add configuration
 * macros, error codes, or utility functions here.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_TYPES_H
#define ORBITMESH_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Standard Library Headers
 *============================================================================*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*==============================================================================
 * Common Handles
 *============================================================================*/

/**
 * @brief Generic object handle.
 */
typedef void *om_handle_t;

/**
 * @brief Generic constant object handle.
 */
typedef const void *om_const_handle_t;

/*==============================================================================
 * Time Types
 *============================================================================*/

/**
 * @brief System tick type.
 *
 * Used by the scheduler and timer subsystem.
 */
typedef uint32_t om_tick_t;

/**
 * @brief Time value in milliseconds.
 */
typedef uint32_t om_time_ms_t;

/**
 * @brief Time value in microseconds.
 */
typedef uint32_t om_time_us_t;

/*==============================================================================
 * Memory Types
 *============================================================================*/

/**
 * @brief Memory size type.
 */
typedef size_t om_size_t;

/**
 * @brief Memory address type.
 */
typedef uintptr_t om_address_t;

/*==============================================================================
 * Identifier Types
 *============================================================================*/

/**
 * @brief Task identifier.
 */
typedef uint32_t om_task_id_t;

/**
 * @brief Timer identifier.
 */
typedef uint32_t om_timer_id_t;

/**
 * @brief Driver identifier.
 */
typedef uint32_t om_driver_id_t;

/**
 * @brief Device identifier.
 */
typedef uint32_t om_device_id_t;

/*==============================================================================
 * GPIO Types
 *============================================================================*/

/**
 * @brief GPIO pin identifier.
 *
 * The interpretation of the value is platform-specific.
 */
typedef uint32_t om_pin_t;

/**
 * @brief GPIO port identifier.
 */
typedef uint32_t om_port_t;

/*==============================================================================
 * Priority Types
 *============================================================================*/

/**
 * @brief Scheduler priority.
 *
 * Lower numerical values represent higher scheduling priority.
 */
typedef uint8_t om_priority_t;

/*==============================================================================
 * Status Types
 *============================================================================*/

/**
 * @brief Generic boolean state.
 */
typedef enum
{
    OM_STATE_DISABLED = 0,
    OM_STATE_ENABLED = 1
} om_state_t;

/**
 * @brief Generic execution state.
 */
typedef enum
{
    OM_STATUS_OK = 0,
    OM_STATUS_BUSY,
    OM_STATUS_TIMEOUT,
    OM_STATUS_ERROR
} om_status_t;

/*==============================================================================
 * Forward Declarations
 *============================================================================*/

/**
 * @brief Task control block.
 */
typedef struct om_task om_task_t;

/**
 * @brief Software timer object.
 */
typedef struct om_timer om_timer_t;

/**
 * @brief Queue object.
 */
typedef struct om_queue om_queue_t;

/**
 * @brief Mutex object.
 */
typedef struct om_mutex om_mutex_t;

/**
 * @brief Semaphore object.
 */
typedef struct om_semaphore om_semaphore_t;

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TYPES_H */
