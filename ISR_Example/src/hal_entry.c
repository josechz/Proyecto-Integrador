/* HAL-only entry function */
#include "hal_data.h"

#define COUNTS_PER_MILLISECONDS (120E6 / 1000)
ioport_level_t led_0_level = IOPORT_LEVEL_HIGH;
bsp_leds_t Leds;

void hal_entry(void)
{
    /* TODO: add your own code here */
    bool isOn = true;

    timer_size_t counts = 0;

    g_timer0.p_api->open ( g_timer0.p_ctrl, g_timer0.p_cfg);
    g_timer0.p_api->start(g_timer0.p_ctrl);

    R_BSP_LedsGet(&Leds);
    g_external_irq0.p_api->open(g_external_irq0.p_ctrl,g_external_irq0.p_cfg);

    while(1)
    {
        g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00,isOn);

        isOn = !isOn;

        while(1)
        {
            g_timer0.p_api->counterGet(g_timer0.p_ctrl, &counts);

            if(counts > (250*COUNTS_PER_MILLISECONDS))
            {
                g_timer0.p_api->reset(g_timer0.p_ctrl);
                break;
            }
        }
    }
}

void button_callback_SW5(external_irq_callback_args_t *p_args)
{
    g_ioport.p_api->pinWrite(Leds.p_leds[0], led_0_level);
    g_ioport.p_api->pinWrite(Leds.p_leds[1], led_0_level);
    g_ioport.p_api->pinWrite(Leds.p_leds[2], led_0_level);

    led_0_level =!led_0_level;// 1 - led_0_level;
}
