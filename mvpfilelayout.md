orbitmesh/
├── CMakeLists.txt
├── LICENSE
├── README.md
├── .gitignore
│
├── cmake/
│   └── toolchains/
│
├── docs/
│   ├── architecture.md
│   ├── getting_started.md
│   └── porting_guide.md
│
├── include/
│   └── orbitmesh/
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
│       ├── health.h
│       └── config.h
│
├── kernel/
│   ├── scheduler.c
│   ├── task.c
│   ├── timer.c
│   ├── kernel.c
│   └── startup.c
│
├── hal/
│   ├── hal.c
│   ├── gpio.c
│   ├── uart.c
│   ├── spi.c
│   ├── i2c.c
│   └── timer.c
│
├── drivers/
│   ├── gpio/
│   │   └── gpio_driver.c
│   ├── uart/
│   │   └── uart_driver.c
│   ├── spi/
│   │   └── spi_driver.c
│   ├── i2c/
│   │   └── i2c_driver.c
│   └── timer/
│       └── timer_driver.c
│
├── platform/
│   ├── cortex-m/
│   │   ├── startup.c
│   │   ├── interrupt.c
│   │   └── system.c
│   │
│   ├── riscv/
│   │   ├── startup.c
│   │   ├── interrupt.c
│   │   └── system.c
│   │
│   └── linux/
│       ├── simulator.c
│       └── platform.c
│
├── services/
│   ├── console.c
│   ├── heartbeat.c
│   ├── health_monitor.c
│   └── software_timer.c
│
├── examples/
│   ├── blinky/
│   ├── uart_echo/
│   ├── telemetry/
│   ├── heartbeat/
│   └── sensor_polling/
│
├── tests/
│   ├── kernel/
│   ├── hal/
│   ├── services/
│   └── drivers/
│
├── scripts/
│   ├── build.sh
│   ├── format.sh
│   └── lint.sh
│
└── tools/
    └── simulator/
