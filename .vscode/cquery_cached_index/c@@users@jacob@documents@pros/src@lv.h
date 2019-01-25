/**
 * @file lv_tutorial_hello_world
 *
 */

#ifndef LV
#define LV

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lvgl.h"
#include "lv_ex_conf.h"
#else
#endif

#if USE_LV_TUTORIALS

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_tutorial_hello_world(void);

/**********************
 *      MACROS
 **********************/

#endif /*USE_LV_TUTORIALS*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_TUTORIAL_HELLO_WORLD_H*/
