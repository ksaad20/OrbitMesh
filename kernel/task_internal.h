/**
 * @file task_internal.h
 * @brief Internal task subsystem declarations.
 */

#ifndef ORBITMESH_TASK_INTERNAL_H
#define ORBITMESH_TASK_INTERNAL_H

#include "kernel_internal.h"
#include "task_control_block.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define OM_TASK_INVALID_ID ((om_task_id_t)0U)

/* Internal API */

om_error_t
om_task_init(void);

om_task_t *
om_task_idle(void);

void
om_task_tick(void);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_TASK_INTERNAL_H */
