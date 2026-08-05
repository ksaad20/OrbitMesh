"""
OrbitMesh Serial Monitor.

Provides a lightweight terminal monitor for OrbitMesh
hardware development and telemetry debugging.

Author:
    OrbitMesh Contributors

License:
    Apache License 2.0
"""

from __future__ import annotations

import argparse
import sys
import time

import serial


DEFAULT_BAUD_RATE = 115200


def create_parser() -> argparse.ArgumentParser:
    """
    Create command line argument parser.
    """

    parser = argparse.ArgumentParser(
        description="OrbitMesh UART serial monitor"
    )

    parser.add_argument(
        "port",
        help="Serial port device (example: /dev/ttyUSB0)",
    )

    parser.add_argument(
        "--baud",
        type=int,
        default=DEFAULT_BAUD_RATE,
        help="UART baud rate",
    )

    return parser


def monitor(
    port: str,
    baud: int,
) -> None:
    """
    Monitor OrbitMesh serial output.
    """

    try:
        connection = serial.Serial(
            port,
            baudrate=baud,
            timeout=1,
        )

    except serial.SerialException as error:
        print(
            f"Unable to open serial port: {error}",
            file=sys.stderr,
        )

        sys.exit(1)


    print(
        "OrbitMesh Serial Monitor"
    )

    print(
        f"Connected: {port} @ {baud}"
    )


    try:
        while True:
            data = connection.readline()

            if data:
                print(
                    data.decode(
                        "utf-8",
                        errors="replace",
                    ),
                    end="",
                )

            time.sleep(0.01)

    except KeyboardInterrupt:
        print(
            "\nMonitor stopped."
        )

    finally:
        connection.close()



def main() -> None:
    """
    Program entry point.
    """

    parser = create_parser()

    arguments = parser.parse_args()

    monitor(
        arguments.port,
        arguments.baud,
    )


if __name__ == "__main__":
    main()
