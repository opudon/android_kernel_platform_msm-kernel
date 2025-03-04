/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2020-2021, The Linux Foundation. All rights reserved.
 */

#ifndef __LEDS_QTI_FLASH_H
#define __LEDS_QTI_FLASH_H

#include <linux/leds.h>

#define ENABLE_REGULATOR		BIT(0)
#define DISABLE_REGULATOR		BIT(1)
#define QUERY_MAX_AVAIL_CURRENT		BIT(2)

/**
 * struct flash_led_param: QTI flash LED parameter data
 * @on_time_ms	: Time to wait before strobing the switch
 * @off_time_ms	: Time to wait to turn off LED after strobing switch
 */
struct flash_led_param {
	u64 on_time_ms;
	u64 off_time_ms;
};

#if IS_ENABLED(CONFIG_LEDS_QTI_FLASH)
int qti_flash_led_prepare(struct led_trigger *trig,
			int options, int *max_current);
int qti_flash_led_set_param(struct led_trigger *trig,
			struct flash_led_param param);

#ifdef OPLUS_FEATURE_CAMERA_COMMON
int set_flash_max_current_mA(int max_current_mA);
#endif
		
#else
static inline int qti_flash_led_prepare(struct led_trigger *trig,
					int options, int *max_current)
{
	return -EINVAL;
}

static inline int qti_flash_led_set_param(struct led_trigger *trig,
			struct flash_led_param param)
{
	return -EINVAL;
}
#endif

#if IS_ENABLED(CONFIG_BACKLIGHT_QCOM_SPMI_WLED)
int wled_flash_led_prepare(struct led_trigger *trig, int options,
					int *max_current);
#else
static inline int wled_flash_led_prepare(struct led_trigger *trig, int options,
					int *max_current)
{
	return -EINVAL;
}
#endif
#endif
