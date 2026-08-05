/**
 * @file vector_table.c
 * @brief ARM Cortex-M interrupt vector table.
 *
 * Defines exception and interrupt entry points
 * for OrbitMesh Cortex-M targets.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include <stdint.h>


/*==============================================================================
 * External Symbols
 *============================================================================*/

/**
 * @brief Initial stack pointer.
 */
extern uint32_t _estack;


/**
 * @brief Reset handler.
 */
extern void
Reset_Handler(void);


/**
 * @brief Default interrupt handler.
 */
extern void
Default_Handler(void);


/*==============================================================================
 * Exception Handlers
 *============================================================================*/

extern void
NMI_Handler(void);

extern void
HardFault_Handler(void);

extern void
MemManage_Handler(void);

extern void
BusFault_Handler(void);

extern void
UsageFault_Handler(void);


/*==============================================================================
 * Vector Table
 *============================================================================*/

/**
 * @brief Cortex-M vector table.
 *
 * Placed at the beginning of flash memory.
 */
__attribute__((section(".isr_vector")))
const void *g_vector_table[] =
{
    /*
     * Initial stack pointer.
     */
    &_estack,


    /*
     * Cortex-M exceptions.
     */
    Reset_Handler,

    NMI_Handler,

    HardFault_Handler,

    MemManage_Handler,

    BusFault_Handler,

    UsageFault_Handler,


    /*
     * Reserved exception entries.
     */
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,


    /*
     * Supervisor call.
     */
    Default_Handler,


    /*
     * Debug monitor.
     */
    Default_Handler,


    /*
     * Reserved.
     */
    Default_Handler,


    /*
     * PendSV.
     */
    Default_Handler,


    /*
     * System tick.
     */
    Default_Handler,


    /*
     * External interrupts.
     *
     * Device-specific interrupt vectors
     * extend this table.
     */
    Default_Handler,
};
