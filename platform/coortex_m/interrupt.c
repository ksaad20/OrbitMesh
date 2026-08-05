/**
 * @file interrupt.c
 * @brief ARM Cortex-M interrupt control.
 *
 * Provides low-level interrupt operations required
 * by the OrbitMesh kernel.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#include <stdint.h>


/*==============================================================================
 * Cortex-M Intrinsic Operations
 *============================================================================*/

/**
 * @brief Enable global interrupts.
 */
static inline void
enable_interrupts(void)
{
    __asm volatile(
        "cpsie i"
    );
}


/**
 * @brief Disable global interrupts.
 */
static inline void
disable_interrupts(void)
{
    __asm volatile(
        "cpsid i"
    );
}


/*==============================================================================
 * Public API
 *============================================================================*/

void
om_interrupt_init(void)
{
    /*
     * Interrupts remain disabled during
     * early hardware initialization.
     *
     * Enabled after kernel startup.
     */
}


void
om_interrupt_enable(void)
{
    enable_interrupts();
}


void
om_interrupt_disable(void)
{
    disable_interrupts();
}


uint32_t
om_interrupt_save(void)
{
    uint32_t state;


    __asm volatile(
        "mrs %0, primask\n"
        "cpsid i\n"
        : "=r"(state)
        :
        : "memory"
    );


    return state;
}


void
om_interrupt_restore(
    uint32_t state)
{
    __asm volatile(
        "msr primask, %0\n"
        :
        : "r"(state)
        : "memory"
    );
}
