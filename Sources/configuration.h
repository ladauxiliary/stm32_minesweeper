#ifndef configuration_H
    #define configuration_H

    #include <stm32f10x.h>

    void preconfigure_microcontroller(void);
    void enabling_clocks (void);
    void configuring_ports (void);
    void configuring_timers (void);

#endif