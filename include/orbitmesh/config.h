/**
 * @file config.h
 * @brief Compile-time configuration for OrbitMesh.
 *
 * This header defines the default compile-time configuration for the OrbitMesh
 * operating system. Every option may be overridden by defining the same macro
 * before including this header or via the compiler command line.
 *
 * The defaults are intentionally conservative to support resource-constrained
 * embedded systems.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_CONFIG_H
#define ORBITMESH_CONFIG_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Kernel Configuration
 *============================================================================*/

#ifndef OM_CONFIG_MAX_TASKS
#define OM_CONFIG_MAX_TASKS                16U
#endif

#ifndef OM_CONFIG_IDLE_TASK_ENABLED
#define OM_CONFIG_IDLE_TASK_ENABLED        1U
#endif

#ifndef OM_CONFIG_TICK_RATE_HZ
#define OM_CONFIG_TICK_RATE_HZ             1000U
#endif

#ifndef OM_CONFIG_DEFAULT_STACK_SIZE
#define OM_CONFIG_DEFAULT_STACK_SIZE       1024U
#endif

#ifndef OM_CONFIG_MIN_STACK_SIZE
#define OM_CONFIG_MIN_STACK_SIZE           256U
#endif

#ifndef OM_CONFIG_MAX_PRIORITY
#define OM_CONFIG_MAX_PRIORITY             31U
#endif

#ifndef OM_CONFIG_USE_PREEMPTION
#define OM_CONFIG_USE_PREEMPTION           0U
#endif

/*==============================================================================
 * Software Timers
 *============================================================================*/

#ifndef OM_CONFIG_MAX_TIMERS
#define OM_CONFIG_MAX_TIMERS               16U
#endif

#ifndef OM_CONFIG_TIMER_RESOLUTION_MS
#define OM_CONFIG_TIMER_RESOLUTION_MS      1U
#endif

/*==============================================================================
 * Memory
 *============================================================================*/

#ifndef OM_CONFIG_DYNAMIC_MEMORY
#define OM_CONFIG_DYNAMIC_MEMORY           0U
#endif

#ifndef OM_CONFIG_HEAP_SIZE
#define OM_CONFIG_HEAP_SIZE                (8U * 1024U)
#endif

/*==============================================================================
 * Logging
 *============================================================================*/

#define OM_LOG_LEVEL_NONE                  0U
#define OM_LOG_LEVEL_ERROR                 1U
#define OM_LOG_LEVEL_WARNING               2U
#define OM_LOG_LEVEL_INFO                  3U
#define OM_LOG_LEVEL_DEBUG                 4U

#ifndef OM_CONFIG_LOG_LEVEL
#define OM_CONFIG_LOG_LEVEL                OM_LOG_LEVEL_INFO
#endif

#ifndef OM_CONFIG_ENABLE_CONSOLE
#define OM_CONFIG_ENABLE_CONSOLE           1U
#endif

/*==============================================================================
 * Assertions
 *============================================================================*/

#ifndef OM_CONFIG_ENABLE_ASSERTS
#define OM_CONFIG_ENABLE_ASSERTS           1U
#endif

/*==============================================================================
 * Health Monitoring
 *============================================================================*/

#ifndef OM_CONFIG_ENABLE_HEALTH_MONITOR
#define OM_CONFIG_ENABLE_HEALTH_MONITOR    1U
#endif

#ifndef OM_CONFIG_HEALTH_PERIOD_MS
#define OM_CONFIG_HEALTH_PERIOD_MS         1000U
#endif

/*==============================================================================
 * HAL
 *============================================================================*/

#ifndef OM_CONFIG_ENABLE_GPIO
#define OM_CONFIG_ENABLE_GPIO              1U
#endif

#ifndef OM_CONFIG_ENABLE_UART
#define OM_CONFIG_ENABLE_UART              1U
#endif

#ifndef OM_CONFIG_ENABLE_SPI
#define OM_CONFIG_ENABLE_SPI               1U
#endif

#ifndef OM_CONFIG_ENABLE_I2C
#define OM_CONFIG_ENABLE_I2C               1U
#endif

#ifndef OM_CONFIG_ENABLE_TIMERS
#define OM_CONFIG_ENABLE_TIMERS            1U
#endif

/*==============================================================================
 * Driver Configuration
 *============================================================================*/

#ifndef OM_CONFIG_UART_BUFFER_SIZE
#define OM_CONFIG_UART_BUFFER_SIZE         256U
#endif

#ifndef OM_CONFIG_CONSOLE_BUFFER_SIZE
#define OM_CONFIG_CONSOLE_BUFFER_SIZE      256U
#endif

/*==============================================================================
 * Platform
 *============================================================================*/

#ifndef OM_CONFIG_CPU_CLOCK_HZ
#define OM_CONFIG_CPU_CLOCK_HZ             48000000UL
#endif

#ifndef OM_CONFIG_SYSTEM_CLOCK_HZ
#define OM_CONFIG_SYSTEM_CLOCK_HZ          OM_CONFIG_CPU_CLOCK_HZ
#endif

/*==============================================================================
 * Version Checks
 *============================================================================*/

#if (OM_CONFIG_MAX_TASKS == 0U)
#error "OM_CONFIG_MAX_TASKS must be greater than zero."
#endif

#if (OM_CONFIG_MAX_PRIORITY == 0U)
#error "OM_CONFIG_MAX_PRIORITY must be greater than zero."
#endif

#if (OM_CONFIG_TICK_RATE_HZ == 0U)
#error "OM_CONFIG_TICK_RATE_HZ must be greater than zero."
#endif

#if (OM_CONFIG_DEFAULT_STACK_SIZE < OM_CONFIG_MIN_STACK_SIZE)
#error "Default stack size cannot be smaller than minimum stack size."
#endif

#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_CONFIG_H */
