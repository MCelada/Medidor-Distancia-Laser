/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "uart.h"
#include "lidarvl53.h"
#include "ssd1306.h"
#include "ssd1306_tests.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c3;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
float milimetros;
float medicion;
float milimetrosCalib;
float valor_calibracion_100mm = 0.00;
float valor_calibracion_1900mm = 0.00;
float factorCalibracion = 1.00;
float y1 = 100.00;
float y2 = 1900.00;
float A=1.00;
float B=0.00;
int boton_presionado = 0;
float distancia;
char texto[100];
char texto2[100];
char texto3[100];
#define MAX_MUESTRAS 25
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
unsigned int acumulador = 0;
unsigned int contador = 0;
unsigned int milimetros_promedio = 0;
uint8_t y;


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  MX_I2C3_Init();
  /* USER CODE BEGIN 2 */

  lidar_init(dir_s1);
  ssd1306_Init();
  /* USER CODE END 2 */



  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  chequeoPulsador();

	   	milimetros=lidar_lee_mm(dir_s1);
	   	milimetrosCalib = milimetros * A + B;
	   	acumulador += milimetrosCalib;
	   	contador++;

	   	// Cada 20 muestras, calcular el promedio y reiniciar el acumulador y contador
	   	        if (contador == MAX_MUESTRAS) {
	   	            milimetros_promedio = acumulador / MAX_MUESTRAS;

	   	            	   	            // Reiniciar el acumulador y el contador
	   	            acumulador = 0;
	   	            contador = 0;
	   	        }

		        if (distancia<0)  uartx_write_text(&huart2, "SENSOR NO CONECTADO\r\n");
		        else
		        {
		      	  sprintf(texto,"%u mm\r\n",milimetros_promedio);
		            uartx_write_text(&huart2, texto);

		        }

		        HAL_Delay(10);

		        ssd1306_Reset();

		        y = 0;
		        ssd1306_Fill(Black);

		        #ifdef SSD1306_INCLUDE_FONT_16x26
		    	ssd1306_SetCursor(2, y);
		    	ssd1306_WriteString(&texto, Font_16x26, White);
		    	y += 26;
		    	#endif

		    	ssd1306_UpdateScreen();


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */


void chequeoPulsador(void){
	// Verificar si el botón B1 está presionado
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
	// El botón está presionado, leer el valor del sensor
	    HAL_Delay(100);  // Debounce del botón
	    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
	    // Seguro que el botón sigue presionado
	       boton_presionado = 1;

	       calibracion_100mm();

	       calibracion_1900mm();

	       Factor_Calibracion(valor_calibracion_100mm,valor_calibracion_1900mm,y1,y2,&A,&B);

	       sprintf(texto2,"Factor: %u mm \n",factorCalibracion);
		                  //uartx_write_text(&huart2, texto2);
	       HAL_UART_Transmit(&huart2, (uint8_t*)texto2, strlen(texto2), HAL_MAX_DELAY);

	       ssd1306_Reset();

	       uint8_t y = 0;
	       ssd1306_Fill(Black);

		#ifdef SSD1306_INCLUDE_FONT_16x26
	       ssd1306_SetCursor(2, y);
	       ssd1306_WriteString(&texto2, Font_16x26, White);
	       y += 26;
		#endif



	       ssd1306_UpdateScreen();

	    }
	} else {
		// El botón no está presionado
		boton_presionado = 0;

	}

}
void calibracion_100mm(void) {

	unsigned int acumulador = 0;
	unsigned int contador = 0;
	unsigned int milimetros_promedio = 0;

	sprintf(texto2,"C 100 mm OK");
	//uartx_write_text(&huart2, texto2);
	HAL_UART_Transmit(&huart2, (uint8_t*)texto2, strlen(texto2), HAL_MAX_DELAY);

	ssd1306_Reset();

	uint8_t y = 0;
	ssd1306_Fill(Black);

	#ifdef SSD1306_INCLUDE_FONT_11x18
	ssd1306_SetCursor(2, y);
	ssd1306_WriteString(&texto2, Font_11x18, White);
	y += 26;
	#endif

	ssd1306_UpdateScreen();
    // Esperar hasta que el botón esté presionado
    while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET) {
        // Puedes agregar un pequeño retardo aquí para evitar lecturas rápidas
        HAL_Delay(50);

        medicion=lidar_lee_mm(dir_s1);
        acumulador += medicion;
        contador++;

        // Cada 20 muestras, calcular el promedio y reiniciar el acumulador y contador
           if (contador == MAX_MUESTRAS) {
           milimetros_promedio = acumulador / MAX_MUESTRAS;

        // Reiniciar el acumulador y el contador
            acumulador = 0;
            contador = 0;
            }

           if (distancia<0)  uartx_write_text(&huart2, "SENSOR NO CONECTADO\r\n");
           else
              {
        	   sprintf(texto3,"%u mm\r\n",milimetros_promedio);
              }

	#ifdef SSD1306_INCLUDE_FONT_16x26
	   ssd1306_SetCursor(2, y);
	   ssd1306_WriteString(&texto3, Font_16x26, White);
	   //y += 26; // Puedes ajustar esta cantidad según el tamaño de fuente que estés usando
	#endif
	   ssd1306_UpdateScreen();
    }

    // Debounce del botón
    HAL_Delay(100);


    // Esperar hasta que el botón esté presionado de nuevo
    while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET) {
        // Puedes agregar un pequeño retardo aquí para evitar lecturas rápidas
        HAL_Delay(50);
    }

    // Ahora el botón está seguro de que está presionado, realizar la operación del sensor
    valor_calibracion_100mm = lidar_lee_mm(dir_s1);
}

void calibracion_1900mm(void)
{
	unsigned int acumulador = 0;
	unsigned int contador = 0;
	unsigned int milimetros_promedio = 0;

	sprintf(texto2,"C 1900 mm OK");
		//uartx_write_text(&huart2, texto2);
		HAL_UART_Transmit(&huart2, (uint8_t*)texto2, strlen(texto2), HAL_MAX_DELAY);

		ssd1306_Reset();

		uint8_t y = 0;
		ssd1306_Fill(Black);

	    #ifdef SSD1306_INCLUDE_FONT_11x18
	       ssd1306_SetCursor(2, y);
	       ssd1306_WriteString(&texto2, Font_11x18, White);
	       y += 26;
		#endif

	ssd1306_UpdateScreen();

	 // Esperar hasta que el botón esté presionado
	    while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET) {
	        // Puedes agregar un pequeño retardo aquí para evitar lecturas rápidas
	        HAL_Delay(50);
	        medicion=lidar_lee_mm(dir_s1);
	        acumulador += medicion;
	        contador++;

	        // Cada 20 muestras, calcular el promedio y reiniciar el acumulador y contador
	        if (contador == MAX_MUESTRAS) {
	        	milimetros_promedio = acumulador / MAX_MUESTRAS;

	          // Reiniciar el acumulador y el contador
	            acumulador = 0;
	            contador = 0;
	             }

	            if (distancia<0)  uartx_write_text(&huart2, "SENSOR NO CONECTADO\r\n");
	            else
	            {
	               sprintf(texto3,"%u mm\r\n",milimetros_promedio);
	            }

	        #ifdef SSD1306_INCLUDE_FONT_16x26
	           ssd1306_SetCursor(2, y);
	           ssd1306_WriteString(&texto3, Font_16x26, White);
	           //y += 26; // Puedes ajustar esta cantidad según el tamaño de fuente que estés usando
	        #endif
	           ssd1306_UpdateScreen();
	    }

	    // Debounce del botón
	    HAL_Delay(100);

	    // Esperar hasta que el botón esté presionado de nuevo
	    while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET) {
	        // Puedes agregar un pequeño retardo aquí para evitar lecturas rápidas
	        HAL_Delay(50);
	    }

	    // Ahora el botón está seguro de que está presionado, realizar la operación del sensor
	    valor_calibracion_1900mm = lidar_lee_mm(dir_s1);
}

// Función para resolver el sistema de ecuaciones
void Factor_Calibracion(float x1, float x2, float y1, float y2, float *A, float *B) {
    // Verificamos que (x2 - x1) no sea cero para evitar divisiones por cero
    if (x2 - x1 != 0) {
        // Resolvemos las ecuaciones para A y B
        *A = (y2 - y1) / (x2 - x1);
        *B = y1 - (*A * x1);
    } else {
        printf("Error: (x2 - x1) no puede ser cero.\n");
    }
}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C3_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
