#include "HighResolutionTimer.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>

#include <cstdio>

#define TIMER TIM2

uint32_t HighResolutionTimer::_ticks;

void HighResolutionTimer::init() {
    rcc_periph_clock_enable(RCC_TIM2);
    nvic_enable_irq(NVIC_TIM2_IRQ);
    rcc_periph_reset_pulse(RST_TIM2);

    timer_disable_preload(TIMER);
    timer_continuous_mode(TIMER);

    // set to 10mhz
    timer_set_prescaler(TIMER, (rcc_apb1_frequency * 2) / 10000000 - 1);
    // count microseconds
    timer_set_period(TIMER, 10);

    timer_enable_update_event(TIMER);
    timer_enable_counter(TIMER);
    timer_enable_irq(TIMER, TIM_DIER_UIE);
}

void tim2_isr() {
    if (timer_get_flag(TIMER, TIM_SR_UIF)) {
        timer_clear_flag(TIMER, TIM_SR_UIF);
        HighResolutionTimer::tick();
    }
}
