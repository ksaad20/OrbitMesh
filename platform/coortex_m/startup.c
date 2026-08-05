/**
 * @file startup.c
 * @brief ARM Cortex-M startup sequence.
 *
 * Provides the reset handler and early boot sequence
 * for OrbitMesh Cortex-M targets.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include "orbitmesh/kernel.h"

#include <stdint.h>


/*==============================================================================
 * External Symbols
 *============================================================================*/

extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;


/**
 * @brief System initialization.
 */
extern void
om_system_init(void);


/**
 * @brief Application entry point.
 */
extern int
main(void);


/*==============================================================================
 * Forward Declarations
 *============================================================================*/

void
Reset_Handler(void);

void
Default_Handler(void);


/*==============================================================================
 * Interrupt Handlers
 *============================================================================*/

void
NMI_Handler(void)
    __attribute__((weak, alias("Default_Handler")));

void
HardFault_Handler(void)
    __attribute__((weak, alias("Default_Handler")));

void
MemManage_Handler(void)
    __attribute__((weak, alias("Default_Handler")));

void
BusFault_Handler(void)
    __attribute__((weak, alias("Default_Handler")));

void
UsageFault_Handler(void)
    __attribute__((weak, alias("Default_Handler")));


/*==============================================================================
 * Reset Handler
 *============================================================================*/

void
Reset_Handler(void)
{
    uint32_t *source = &_sidata;

    uint32_t *destination = &_sdata;


    /*
     * Copy initialized data from flash to RAM.
     */
    while (destination < &_edata)
    {
        *destination = *source;

        destination++;

        source++;
    }


    /*
     * Clear zero-initialized memory.
     */
    destination = &_sbss;

    while (destination < &_ebss)
    {
        *destination = 0U;

        destination++;
    }


    /*
     * Initialize hardware.
     */
    om_system_init();


    /*
     * Start application.
     */
    main();


    /*
     * Should never return.
     */
    while (1)
    {
    }
}


/*==============================================================================
 * Default Handler
 *============================================================================*/

void
Default_Handler(void)
{
    while (1)
    {
        /*
         * Trap unexpected interrupts.
         */
    }
}
