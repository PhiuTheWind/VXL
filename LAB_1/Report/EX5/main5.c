#include "7SEG.h"
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

	  switch(num)
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


#define RED     0   // Định nghĩa trạng thái cho đèn đỏ
#define YELLOW  1   // Định nghĩa trạng thái cho đèn vàng
#define GREEN   2   // Định nghĩa trạng thái cho đèn xanh

int flag = 0;       // Biến cờ để theo dõi số lần đèn đã thay đổi
int countdown = 0;	// Biến đếm cho 7SEG LED
int led_color = RED; // Biến lưu trữ trạng thái hiện tại của đèn, bắt đầu là đèn đỏ

  while (1)
  {
	  switch(led_color)  // Kiểm tra trạng thái của đèn
	   {
	       case RED:  // Nếu đèn hiện tại là màu đỏ
	           HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, RESET);  // Bật đèn đỏ thứ 1
	           HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);  // Tắt đèn vàng thứ 1
	           HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);  // Tắt đèn xanh thứ 1

	           HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);  // Tắt đèn đỏ thứ 2
	           HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);  // Tắt đèn vàng thứ 2
	           HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, RESET);  // Bật đèn xanh thứ 2

	           countdown = 5 - flag;
	           display_7SEG(countdown);

	           flag++;  // Tăng biến cờ sau mỗi lần chuyển trạng thái
	           if(flag > 3)  // Nếu đèn đã ở trạng thái đỏ quá 3 lần
	           {
	               HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, SET);  // Tắt đèn đỏ thứ 2
	               HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, RESET);  // Bật đèn vàng thứ 2
	               HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);  // Tắt đèn xanh thứ 2
	           }

	           if (flag == 5)  // Sau 5 chu kỳ, chuyển sang đèn xanh
	           {
	               led_color = GREEN;  // Đổi trạng thái đèn sang xanh
	               flag = 0;  // Reset biến cờ
	           }
	           break;

	       case YELLOW:  // Nếu đèn hiện tại là màu vàng
	           HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);  // Tắt đèn đỏ thứ 1
	           HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, RESET);  // Bật đèn vàng thứ 1
	           HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, SET);  // Tắt đèn xanh thứ 1

	           HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, RESET);  // Bật đèn đỏ thứ 2
	           HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);  // Tắt đèn vàng thứ 2
	           HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);  // Tắt đèn xanh thứ 2

	           countdown = 2 - flag;
	           display_7SEG(countdown);

	           flag++;  // Tăng biến cờ
	           if (flag == 2)  // Sau 2 chu kỳ, chuyển sang đèn đỏ
	           {
	               led_color = RED;  // Đổi trạng thái đèn sang đỏ
	               flag = 0;  // Reset biến cờ
	           }
	           break;

	       case GREEN:  // Nếu đèn hiện tại là màu xanh
	           HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, SET);  // Tắt đèn đỏ thứ 1
	           HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, SET);  // Tắt đèn vàng thứ 1
	           HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, RESET);  // Bật đèn xanh thứ 1

	           HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, RESET);  // Bật đèn đỏ thứ 2
	           HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, SET);  // Tắt đèn vàng thứ 2
	           HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, SET);  // Tắt đèn xanh thứ 2

	           countdown = 3 - flag;
	           display_7SEG(countdown);

	           flag++;  // Tăng biến cờ
	           if (flag == 3)  // Sau 3 chu kỳ, chuyển sang đèn vàng
	           {
	               led_color = YELLOW;  // Đổi trạng thái đèn sang vàng
	               flag = 0;  // Reset biến cờ
	           }
	           break;

	       default:  // Trường hợp không xác định
	           break;
	   }
	   HAL_Delay(1000);  // Chờ 1 giây trước khi thực hiện chu kỳ tiếp theo
  }