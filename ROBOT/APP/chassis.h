#ifndef __CHASSIS_H__
#define __CHASSIS_H__

#include "main.h"

#define CHASSIS_SPEED_PID_P 3.0f	//����PID����
#define CHASSIS_SPEED_PID_I 0.035f
#define CHASSIS_SPEED_PID_D 0
#define CHASSIS_SPEED_MAXOUT 8000
#define CHASSIS_SPEED_MAXINPUT 8200
#define CHASSIS_SPEED_MER 3200
#define CHASSIS_SPEED_DEAD 0
#define CHASSIS_SPEED_I_MAX 2500/CHASSIS_SPEED_PID_I

//���̵���ٶȻ�PID����
#define PID_CHASSIS_SPEED_DEFAULT \
{\
	CHASSIS_SPEED_PID_P,\
	CHASSIS_SPEED_PID_I,\
  CHASSIS_SPEED_PID_D,\
	CHASSIS_SPEED_MER,\
	-CHASSIS_SPEED_MAXINPUT,\
	CHASSIS_SPEED_MAXINPUT,\
	-CHASSIS_SPEED_MAXOUT,\
	CHASSIS_SPEED_MAXOUT,\
	CHASSIS_SPEED_I_MAX,\
	{0.0,0.0},\
	0.0,\
	0.0,\
	0.0,\
	CHASSIS_SPEED_DEAD,\
}\

#define CHASSIS_FOLLOW_PID_P 0.6f//0.43f
#define CHASSIS_FOLLOW_PID_I 0
#define CHASSIS_FOLLOW_PID_D 17
#define CHASSIS_FOLLOW_PID_MAXINPUT 6000	//��̨���Χ��4450-5350
#define CHASSIS_FOLLOW_PID_MAXOUT 400
#define CHASSIS_FOLLOW_PID_MER 600
#define CHASSIS_FOLLOW_PID_DEAD 8//10
#define CHASSIS_FOLLOW_PID_I_MAX 0

//���̸����ٶȻ�PID����
#define PID_CHASSIS_FOLLOW_DEFAULT \
{\
	CHASSIS_FOLLOW_PID_P,\
	CHASSIS_FOLLOW_PID_I,\
  CHASSIS_FOLLOW_PID_D,\
	CHASSIS_FOLLOW_PID_MER,\
	-CHASSIS_FOLLOW_PID_MAXINPUT,\
	CHASSIS_FOLLOW_PID_MAXINPUT,\
	-CHASSIS_FOLLOW_PID_MAXOUT,\
	CHASSIS_FOLLOW_PID_MAXOUT,\
	CHASSIS_FOLLOW_PID_I_MAX,\
	{0.0,0.0},\
	0.0,\
	0.0,\
	0.0,\
	CHASSIS_FOLLOW_PID_DEAD,\
}\


#define YAW_FOLLOW_FILTER_DEFAULT \
{\
	0.5f,\
	1,\
	0,\
	7,\
	{0,0},\
	0.0,\
}\

typedef struct
{
	 int32_t lf_wheel_fdbV; //201 
	 int32_t rf_wheel_fdbV; //202
	 int32_t lb_wheel_fdbV; //203
	 int32_t rb_wheel_fdbV;	//204	  
	
   int32_t lf_wheel_tarV;
	 int32_t rf_wheel_tarV;
	 int32_t lb_wheel_tarV;
	 int32_t rb_wheel_tarV;
	  
   int32_t lf_wheel_fdbP;
	 int32_t rf_wheel_fdbP;
	 int32_t lb_wheel_fdbP;
	 int32_t rb_wheel_fdbP;
	 
	 int32_t lf_wheel_tarP;
	 int32_t rf_wheel_tarP;
	 int32_t lb_wheel_tarP;
	 int32_t rb_wheel_tarP;
	 
	 int32_t lf_wheel_output;
	 int32_t rf_wheel_output;	
	 int32_t lb_wheel_output;
	 int32_t rb_wheel_output;
	
}CHASSIS_DATA;	//CAN2

void Remote_Task(void);
void Extended_Integral_PID(CHASSIS_DATA* chassis_data);	//��չ������PID�����������⶯������	2018.4.19
void Overall_Motion_Ratio_Protect(CHASSIS_DATA* chassis_data);	//�������ٱ�������,һ��Ҫ�����������ٽ��������

#endif
