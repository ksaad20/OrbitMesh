/**
 * @file spi.h
 * @brief OrbitMesh SPI Hardware Abstraction Layer.
 *
 * Provides a hardware-independent SPI interface for embedded peripherals.
 *
 * @author OrbitMesh Contributors
 * @copyright Apache License 2.0
 */

#ifndef ORBITMESH_SPI_H
#define ORBITMESH_SPI_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================================================
 * Dependencies
 *============================================================================*/

#include "error.h"
#include "types.h"

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/*==============================================================================
 * SPI Types
 *============================================================================*/

/**
 * @brief SPI clock polarity.
 */
typedef enum
{
    OM_SPI_CPOL_LOW = 0,
    OM_SPI_CPOL_HIGH
} om_spi_cpol_t;


/**
 * @brief SPI clock phase.
 */
typedef enum
{
    OM_SPI_CPHA_FIRST_EDGE = 0,
    OM_SPI_CPHA_SECOND_EDGE
} om_spi_cpha_t;


/**
 * @brief SPI configuration.
 */
typedef struct
{
    /**
     * SPI peripheral identifier.
     */
    om_spi_id_t id;

    /**
     * Clock frequency in Hz.
     */
    uint32_t frequency;

    /**
     * Clock polarity.
     */
    om_spi_cpol_t polarity;

    /**
     * Clock phase.
     */
    om_spi_cpha_t phase;

    /**
     * Bits transmitted per word.
     */
    uint8_t bits_per_word;

} om_spi_config_t;


/*==============================================================================
 * Public API
 *============================================================================*/

/**
 * @brief Initialize SPI subsystem.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_spi_init(void);


/**
 * @brief Configure SPI peripheral.
 *
 * @param config SPI configuration.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_spi_configure(
    const om_spi_config_t *config);


/**
 * @brief Transfer data over SPI.
 *
 * Transmits and receives simultaneously.
 *
 * @param id SPI identifier.
 * @param tx_data Transmit buffer.
 * @param rx_data Receive buffer.
 * @param length Number of bytes.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_spi_transfer(
    om_spi_id_t id,
    const uint8_t *tx_data,
    uint8_t *rx_data,
    size_t length);


/**
 * @brief Write data over SPI.
 *
 * @param id SPI identifier.
 * @param data Data buffer.
 * @param length Number of bytes.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_spi_write(
    om_spi_id_t id,
    const uint8_t *data,
    size_t length);


/**
 * @brief Read data over SPI.
 *
 * @param id SPI identifier.
 * @param data Receive buffer.
 * @param length Number of bytes.
 *
 * @return OM_SUCCESS on success.
 */
om_error_t
om_spi_read(
    om_spi_id_t id,
    uint8_t *data,
    size_t length);


#ifdef __cplusplus
}
#endif

#endif /* ORBITMESH_SPI_H */
