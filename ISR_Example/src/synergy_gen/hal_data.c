/* generated HAL source file - do not edit */
#include "hal_data.h"
#if (BSP_IRQ_DISABLED) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_timer0) && !defined(SSP_SUPPRESS_ISR_GPT0)
SSP_VECTOR_DEFINE_CHAN(gpt_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 0);
#endif
#endif
static gpt_instance_ctrl_t g_timer0_ctrl;
static const timer_on_gpt_cfg_t g_timer0_extend = { .gtioca = {
		.output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW }, .gtiocb = {
		.output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW } };
static const timer_cfg_t g_timer0_cfg = { .mode = TIMER_MODE_PERIODIC, .period =
		500, .unit = TIMER_UNIT_PERIOD_MSEC, .duty_cycle = 50,
		.duty_cycle_unit = TIMER_PWM_UNIT_RAW_COUNTS, .channel = 0, .autostart =
				true, .p_callback = NULL, .p_context = &g_timer0, .p_extend =
				&g_timer0_extend, .irq_ipl = (BSP_IRQ_DISABLED), };
/* Instance structure to use this module. */
const timer_instance_t g_timer0 = { .p_ctrl = &g_timer0_ctrl, .p_cfg =
		&g_timer0_cfg, .p_api = &g_timer_on_gpt };
#if (12) != BSP_IRQ_DISABLED
#if !defined(SSP_SUPPRESS_ISR_g_external_irq0) && !defined(SSP_SUPPRESS_ISR_ICU10)
SSP_VECTOR_DEFINE( icu_irq_isr, ICU, IRQ10);
#endif
#endif
static icu_instance_ctrl_t g_external_irq0_ctrl;
static const external_irq_cfg_t g_external_irq0_cfg = { .channel = 10,
		.trigger = EXTERNAL_IRQ_TRIG_FALLING, .filter_enable = false,
		.pclk_div = EXTERNAL_IRQ_PCLK_DIV_BY_64, .autostart = true,
		.p_callback = button_callback_SW5, .p_context = &g_external_irq0,
		.p_extend = NULL, .irq_ipl = (12), };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq0 = { .p_ctrl =
		&g_external_irq0_ctrl, .p_cfg = &g_external_irq0_cfg, .p_api =
		&g_external_irq_on_icu };
void g_hal_init(void) {
	g_common_init();
}
