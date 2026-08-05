/**
 * @file task_internal.h
 * @brief Internal task subsystem declarations.
 *
 * Private declarations shared by the OrbitMesh task subsystem.
 * This header is NOT part of the public API.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_TASK_INTERNAL_H
#define ORBITMESH_TASK_INTERNAL_H

#include "kernel_internal.h"
#include "task_control_block.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Internal Constants
 *============================================================================*/

/**
 * @brief Invalid task identifier.
 */
#define OM_TASK_INVALID_ID ((om_task_id_t)0U)

/*==============================================================================
 * Internal Task Storage
 *============================================================================*/

/**
 * @brief Static task table.
 */
extern om_task_t g_tasks[];

/**
 * @brief Allocation bitmap for task table.
 */
extern bool g_task_used[];

/**
 * @brief Currently running task.
 */
extern om_task_t *g_current_task;

/*==============================================================================
 * Internal API
 *============================================================================*/

/**
 * @brief Initialize the task subsystem.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_task_init(void);

/**
 * @brief Return the idle task.
 *
 * @return Pointer to idle task.
 */
om_task_t *
om_task_idle(void);

/**
 * @brief Advance delayed tasks by one scheduler tick.
 */
void
om_task_tick(void);

/**
 * @brief Find a task by identifier.
 *
 * @param id Task identifier.
 *
 * @return Pointer to task or NULL.
 */
om_task_t *
om_task_find(
    om_task_id_t id);

/**
 * @brief Reset all task subsystem state.
 */
void
om_task_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TASK_INTERNAL_H */
