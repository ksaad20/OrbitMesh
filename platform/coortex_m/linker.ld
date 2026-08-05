/*
 * @file linker.ld
 * @brief Generic ARM Cortex-M linker script.
 *
 * Defines flash and RAM layout for OrbitMesh firmware.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */


/*==============================================================================
 * Memory Layout
 *============================================================================*/

MEMORY
{
    FLASH
    (
        rx
    ) :
    ORIGIN = 0x08000000,
    LENGTH = 512K


    RAM
    (
        rwx
    ) :
    ORIGIN = 0x20000000,
    LENGTH = 128K
}


/*==============================================================================
 * Entry Point
 *============================================================================*/

ENTRY(Reset_Handler)


/*==============================================================================
 * Sections
 *============================================================================*/

SECTIONS
{

    /*
     * Interrupt vector table.
     */
    .isr_vector :
    {
        KEEP(*(.isr_vector))
    }
    > FLASH


    /*
     * Program code.
     */
    .text :
    {
        *(.text*)
        *(.rodata*)

        . = ALIGN(4);

    }
    > FLASH


    /*
     * Initialized data.
     */
    .data :
    {
        _sdata = .;

        *(.data*)

        . = ALIGN(4);

        _edata = .;

    }
    > RAM AT > FLASH


    /*
     * Initial data location in flash.
     */
    _sidata = LOADADDR(.data);


    /*
     * Zero initialized data.
     */
    .bss :
    {
        _sbss = .;

        *(.bss*)
        *(COMMON)

        . = ALIGN(4);

        _ebss = .;

    }
    > RAM


    /*
     * Stack top.
     */
    .stack :
    {
        . = ALIGN(8);

        . += 4096;

        _estack = .;

    }
    > RAM
}
