/**
 * @file error.h
 * @brief OrbitMesh error codes.
 *
 * Defines the common error codes returned by the OrbitMesh public API.
 * Error values are grouped by subsystem to simplify debugging and logging.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_ERROR_H
#define ORBITMESH_ERROR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

/*==============================================================================
 * Error Type
 *============================================================================*/

/**
 * @brief OrbitMesh error code.
 */
typedef int32_t om_error_t;

/*==============================================================================
 * Success
 *============================================================================*/

#define OM_SUCCESS                     ((om_error_t)0)

/*==============================================================================
 * Generic Errors (1–99)
 *============================================================================*/

#define OM_ERROR_UNKNOWN               ((om_error_t)1)
#define OM_ERROR_INVALID_ARGUMENT      ((om_error_t)2)
#define OM_ERROR_NULL_POINTER          ((om_error_t)3)
#define OM_ERROR_INVALID_STATE         ((om_error_t)4)
#define OM_ERROR_NOT_SUPPORTED         ((om_error_t)5)
#define OM_ERROR_NOT_IMPLEMENTED       ((om_error_t)6)
#define OM_ERROR_TIMEOUT               ((om_error_t)7)
#define OM_ERROR_BUSY                  ((om_error_t)8)
#define OM_ERROR_ALREADY_EXISTS        ((om_error_t)9)
#define OM_ERROR_NOT_FOUND             ((om_error_t)10)
#define OM_ERROR_PERMISSION_DENIED     ((om_error_t)11)
#define OM_ERROR_OUT_OF_MEMORY         ((om_error_t)12)
#define OM_ERROR_OVERFLOW              ((om_error_t)13)
#define OM_ERROR_UNDERFLOW             ((om_error_t)14)
#define OM_ERROR_CHECKSUM              ((om_error_t)15)

/*==============================================================================
 * Kernel Errors (100–199)
 *============================================================================*/

#define OM_ERROR_KERNEL_NOT_INITIALIZED    ((om_error_t)100)
#define OM_ERROR_KERNEL_ALREADY_RUNNING    ((om_error_t)101)
#define OM_ERROR_KERNEL_PANIC              ((om_error_t)102)
#define OM_ERROR_INVALID_TASK              ((om_error_t)103)
#define OM_ERROR_TASK_LIMIT                ((om_error_t)104)
#define OM_ERROR_INVALID_PRIORITY          ((om_error_t)105)
#define OM_ERROR_SCHEDULER                 ((om_error_t)106)

/*==============================================================================
 * Timer Errors (200–299)
 *============================================================================*/

#define OM_ERROR_TIMER_INVALID         ((om_error_t)200)
#define OM_ERROR_TIMER_RUNNING         ((om_error_t)201)
#define OM_ERROR_TIMER_STOPPED         ((om_error_t)202)
#define OM_ERROR_TIMER_EXPIRED         ((om_error_t)203)

/*==============================================================================
 * HAL Errors (300–399)
 *============================================================================*/

#define OM_ERROR_HAL                  ((om_error_t)300)
#define OM_ERROR_GPIO                 ((om_error_t)301)
#define OM_ERROR_UART                 ((om_error_t)302)
#define OM_ERROR_SPI                  ((om_error_t)303)
#define OM_ERROR_I2C                  ((om_error_t)304)
#define OM_ERROR_CLOCK                ((om_error_t)305)
#define OM_ERROR_INTERRUPT            ((om_error_t)306)

/*==============================================================================
 * Driver Errors (400–499)
 *============================================================================*/

#define OM_ERROR_DRIVER               ((om_error_t)400)
#define OM_ERROR_DEVICE_NOT_PRESENT   ((om_error_t)401)
#define OM_ERROR_DEVICE_BUSY          ((om_error_t)402)
#define OM_ERROR_DEVICE_FAILURE       ((om_error_t)403)

/*==============================================================================
 * Communication Errors (500–599)
 *============================================================================*/

#define OM_ERROR_BUFFER_FULL          ((om_error_t)500)
#define OM_ERROR_BUFFER_EMPTY         ((om_error_t)501)
#define OM_ERROR_FRAME                ((om_error_t)502)
#define OM_ERROR_CRC                  ((om_error_t)503)

/*==============================================================================
 * Platform Errors (600–699)
 *============================================================================*/

#define OM_ERROR_PLATFORM             ((om_error_t)600)
#define OM_ERROR_UNSUPPORTED_CPU      ((om_error_t)601)
#define OM_ERROR_UNSUPPORTED_BOARD    ((om_error_t)602)

/*==============================================================================
 * Utility Functions
 *============================================================================*/

/**
 * @brief Returns a human-readable error string.
 *
 * @param error Error code.
 *
 * @return Constant string describing the error.
 */
const char *om_error_string(om_error_t error);

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_ERROR_H */
