/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef struct {
	uint8_t speed;
	uint8_t gear;
	uint16_t rpm;
	uint8_t T_water;
	uint8_t T_oil;
	uint8_t throttle_perc;
	uint8_t brake_perc;
	float P_oil;
	int RES;
	bool LC;
	bool CLT;
	float battery_v;
	/* TODO: String variables */
} displayInfo;

typedef enum {
  MISSION_MANUAL,
  MISSION_TRACKDRIVE,
  MISSION_ACCELERATION
} MissionType;

typedef struct {
  MissionType missionType;
} guiToMainMsg;

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define STEERING_RIGHT_RED_BUTTON_Pin GPIO_PIN_4
#define STEERING_RIGHT_RED_BUTTON_GPIO_Port GPIOB
#define STEERING_RIGHT_RED_BUTTON_EXTI_IRQn EXTI4_IRQn
#define MCU_ACTIVE_Pin GPIO_PIN_12
#define MCU_ACTIVE_GPIO_Port GPIOG
#define STEERING_LEFT_RED_BUTTON_Pin GPIO_PIN_8
#define STEERING_LEFT_RED_BUTTON_GPIO_Port GPIOA
#define STEERING_LEFT_RED_BUTTON_EXTI_IRQn EXTI9_5_IRQn
#define STEERING_GEAR_DOWN_Pin GPIO_PIN_7
#define STEERING_GEAR_DOWN_GPIO_Port GPIOC
#define STEERING_GEAR_DOWN_EXTI_IRQn EXTI9_5_IRQn
#define STEERING_GEAR_UP_Pin GPIO_PIN_6
#define STEERING_GEAR_UP_GPIO_Port GPIOC
#define STEERING_GEAR_UP_EXTI_IRQn EXTI9_5_IRQn
#define STEERING_GREEN_BUTTON_Pin GPIO_PIN_13
#define STEERING_GREEN_BUTTON_GPIO_Port GPIOB
#define STEERING_GREEN_BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define FRAME_RATE_Pin GPIO_PIN_1
#define FRAME_RATE_GPIO_Port GPIOA
#define VSYNC_FREQ_Pin GPIO_PIN_2
#define VSYNC_FREQ_GPIO_Port GPIOA
#define RENDER_TIME_Pin GPIO_PIN_6
#define RENDER_TIME_GPIO_Port GPIOA
#define STEERING_BLACK_BUTTON_Pin GPIO_PIN_5
#define STEERING_BLACK_BUTTON_GPIO_Port GPIOA
#define STEERING_BLACK_BUTTON_EXTI_IRQn EXTI9_5_IRQn
#define MCP2515_CS_Pin GPIO_PIN_6
#define MCP2515_CS_GPIO_Port GPIOH

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
