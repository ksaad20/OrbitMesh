```

orbitmesh/
├── .clang-format
├── .clang-tidy
├── .editorconfig
├── .gitignore
├── CMakeLists.txt
├── LICENSE
├── README.md
│
├── cmake/
│   ├── arm-gcc-toolchain.cmake
│   ├── riscv-toolchain.cmake
│   ├── linux-toolchain.cmake
│   └── orbitmesh.cmake
│
├── docs/
│   ├── architecture.md
│   ├── build.md
│   ├── coding_style.md
│   ├── contributing.md
│   ├── getting_started.md
│   ├── hal.md
│   ├── kernel.md
│   ├── porting.md
│   ├── scheduler.md
│   ├── services.md
│   └── roadmap.md
│
├── include/
│   └── orbitmesh/
│       ├── config.h
│       ├── kernel.h
│       ├── scheduler.h
│       ├── task.h
│       ├── timer.h
│       ├── hal.h
│       ├── gpio.h
│       ├── uart.h
│       ├── spi.h
│       ├── i2c.h
│       ├── console.h
│       ├── heartbeat.h
│       ├── health_monitor.h
│       ├── log.h
│       ├── assert.h
│       ├── version.h
│       ├── error.h
│       ├── types.h
│       ├── list.h
│       ├── queue.h
│       └── macros.h
│
├── kernel/
│   ├── kernel.c
│   ├── kernel_init.c
│   ├── scheduler.c
│   ├── scheduler_idle.c
│   ├── task.c
│   ├── task_create.c
│   ├── task_delay.c
│   ├── task_priority.c
│   ├── timer.c
│   ├── tick.c
│   ├── startup.c
│   ├── interrupt.c
│   ├── panic.c
│   └── version.c
│
├── hal/
│   ├── hal.c
│   ├── clock.c
│   ├── gpio.c
│   ├── uart.c
│   ├── spi.c
│   ├── i2c.c
│   ├── timer.c
│   ├── interrupt.c
│   ├── power.c
│   └── reset.c
│
├── drivers/
│   ├── gpio_driver.c
│   ├── uart_driver.c
│   ├── spi_driver.c
│   ├── i2c_driver.c
│   ├── timer_driver.c
│   ├── led_driver.c
│   ├── button_driver.c
│   └── watchdog_driver.c
│
├── services/
│   ├── console.c
│   ├── logger.c
│   ├── software_timer.c
│   ├── heartbeat.c
│   ├── health_monitor.c
│   ├── uptime.c
│   ├── diagnostics.c
│   └── watchdog.c
│
├── platform/
│   ├── cortex_m/
│   │   ├── startup.c
│   │   ├── system.c
│   │   ├── interrupt.c
│   │   ├── vector_table.c
│   │   ├── clock.c
│   │   └── linker.ld
│   │
│   ├── riscv/
│   │   ├── startup.c
│   │   ├── system.c
│   │   ├── interrupt.c
│   │   ├── trap.c
│   │   ├── clock.c
│   │   └── linker.ld
│   │
│   └── linux/
│       ├── simulator.c
│       ├── platform.c
│       ├── timer.c
│       ├── uart.c
│       └── gpio.c
│
├── examples/
│   ├── blinky/
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   │
│   ├── uart_echo/
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   │
│   ├── heartbeat/
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   │
│   ├── telemetry/
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   │
│   └── sensor_polling/
│       ├── CMakeLists.txt
│       └── main.c
│
├── tests/
│   ├── CMakeLists.txt
│   ├── test_kernel.c
│   ├── test_scheduler.c
│   ├── test_task.c
│   ├── test_timer.c
│   ├── test_gpio.c
│   ├── test_uart.c
│   ├── test_spi.c
│   ├── test_i2c.c
│   ├── test_console.c
│   ├── test_health_monitor.c
│   └── test_heartbeat.c
│
├── scripts/
│   ├── build.sh
│   ├── clean.sh
│   ├── format.sh
│   ├── lint.sh
│   ├── test.sh
│   ├── flash.sh
│   └── run_simulator.sh
│
├── tools/
│   ├── simulator/
│   │   ├── simulator.c
│   │   └── CMakeLists.txt
│   │
│   └── telemetry/
│       ├── serial_monitor.py
│       └── telemetry_parser.py
│
└── .github/
    └── workflows/
        ├── ci.yml
        ├── codeql.yml
        ├── formatting.yml
        └── release.yml
