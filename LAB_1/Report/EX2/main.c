#include "7SEG.h"
int counter = 0;
void display_7SEG (int num)
{
	  //Turn off all of the segment first
	  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
	  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
	  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, SET);
	  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
	  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);

	  switch(counter)
	  {
	  	  case 0:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
	  		  break;

	  	  case 1:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
	  		  break;

	  	  case 2:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 3:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 4:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 5:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 6:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 7:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
	  		  break;

	  	  case 8:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  case 9:
	  		  HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	  		  HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	  		  HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
	  		  break;

	  	  default:
	  		  break;
	  }

}

  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if (counter >= 10) counter = 0;
	  display_7SEG(counter++);
	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}