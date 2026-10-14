#include <Servo.h>            //加载文件库
#include<SoftwareSerial.h>
#include <MsTimer2.h>
#define motor Serial3
#define motors Serial2
#define openmv Serial1
SoftwareSerial Scan_TJC(12,13);  // RX, TX
SoftwareSerial HWT101(11,10);  // RX, TX

#define FRAME_LENGTH 7
#define PACKET_SIZE 9
#define PACKET_HEADER 0xff
#define PACKET_FOOTER 0xFE

Servo servo1;//物料盘舵机
Servo servo2;//带盘舵机
Servo servo3;//机械爪舵机

// 命令定义 (数组长度自动计算)
const uint8_t unlock_register[] = {0xFF,0xAA,0x69,0x88,0xB5};
const uint8_t reset_z_axis[]    = {0xFF,0xAA,0x76,0x00,0x00};
const uint8_t save_settings[]   = {0xFF,0xAA,0x00,0x00,0x00};


// 数据包解析状态机
enum ParserState { 
  WAIT_HEADER1, 
  WAIT_HEADER2, 
  READING_DATA 
};
static ParserState state = WAIT_HEADER1;
static uint8_t packet[11];
static uint8_t idx = 0;
//volatile float currentYaw = 0.0;
float currentYaw = 0.0;
char data[2]={0,1};
char openmv_data;
const int dataLength = 7;  // 每次扫描的数据长度
char Data_scan[dataLength + 1];  // 用于存储接收到的数据，+1用于存储字符串结束符'\0'
//char Data_scan[7]={'1','2','3','+','3','2','1'};  // 用于存储接收到的数据，+1用于存储字符串结束符'\0'
char data_xjblg[7]={'1','3','2','+','3','1','2'};
int dataIndex = 0;  // 当前接收数据的索引
int flag=0;
unsigned long nowtime;
int i;
int x_adjust,y_adjust;
int adjust_flag=0;
int HWT101_flag=0;
int adjust_state=0;
int openmv_flag=0;
void setup() {
  Serial.begin(9600);
  motor.begin(115200);
  motors.begin(115200);

  Servo_open();
  Servo_Init();
  Servo_close();
  //Scan_TJC.begin(9600);
  HWT101.begin(9600);
  //TJC_Init();
  HWT101_Init();
  HWT101.end();
/*
  while (!Scan_TJC) {
    ;  // 等待串口连接
  }
  Serial.println("Ready to receive data...");*/
}

void loop() {
  xie();
  delay(1500);

  HWT101_flag=0;
  adjust_0();

  To_scan_area();
  delay(4000);
  adjust_0();

  Scan_TJC.begin(9600);//打开扫码和串口屏串口

  while(Data_scan[3]!='+'||(Data_scan[0]!='1'&&Data_scan[0]!='2'&&Data_scan[0]!='3') ||(Data_scan[1]!='1'&&Data_scan[1]!='2'&&Data_scan[1]!='3') ||(Data_scan[2]!='1'&&Data_scan[2]!='2'&&Data_scan[2]!='3')||(Data_scan[4]!='1'&&Data_scan[4]!='2'&&Data_scan[4]!='3')||(Data_scan[5]!='1'&&Data_scan[5]!='2'&&Data_scan[5]!='3')||(Data_scan[6]!='1'&&Data_scan[6]!='2'&&Data_scan[6]!='3'))   
  {
    Serial.println("1");
    Get_scan();
  }

  delay(100);
  if(flag==1){
  Send2Screen();
  delay(500);
  Send2Screen();
  flag=0;
  }
  Scan_TJC.end();

  To_cjg_area_1();//去到粗加工区
  delay(800);
  adjust_180();

  
  Servo_open();
  Location_outside();
  delay(800);
  Servo_close();
  delay(500);

  //int task_index=0
 // adjust_palate();//单一色圆的坐标和颜色
  Servo_open();
  for(i=0;i<3;i++)//按照任务一顺序在粗加工区夹取物料
  cjg_catch_color_1(data_xjblg[i],i);
  Servo_close();//关闭舵机失能
  delay(500);
  //adjust_180();

  go_left2();//远离暂存区
  delay(1000);
  adjust_180();

  To_zcq(data_xjblg[2]);//去到暂存区
  delay(2000);

  Servo_open();
  Location_outside();
  go_right_2();
  delay(1000);  
  Servo_close();
  adjust_90();
  
  //adjust_greenround();
  //adjust_palate();
  //openmv.end();

  Servo_open();//打开舵机使能
  for(i=0;i<3;i++)//按照任务一顺序在暂存区放物料
  cjg_put_color(data_xjblg[i],i);
  delay(500);
  Servo_close();//关闭舵机失能

  go_left2();
  delay(800);
  To_cpq();
  delay(800);
  adjust_180();

  Servo_open();
  Location_outside();
  delay(800);
  Servo_close();
  delay(500);

  int put_shunxu=1;
  int put_index=0;
  //int task_index=0
  adjust_palate();//单一色圆的坐标和颜色
  while(put_index!=1)
  {
    get_openmv();
    if(openmv_data==Data_scan[0]&&put_shunxu==1)
    {
      put();
      put_shunxu++;
    }
    else if(openmv_data==Data_scan[1]&&put_shunxu==2)
    {
      put();
      put_shunxu++;
    }
    else if(openmv_data==Data_scan[2]&&put_shunxu==3)
    {
      put();
      put_index=1;
    }
  }
  go_left2();//远离暂存区
  delay(1000);
  adjust_fu90();
  
  To_zcq(data_xjblg[2]);//去到暂存区
  delay(2000);

  Servo_open();
  Location_outside();
  go_right_2();
  delay(1000);  
  Servo_close();
  adjust_90();
//////////////////////////////////////////////////////////////////////

adjust_palate();//单一色圆的坐标和颜色
  Servo_open();
  for(i=4;i<7;i++)//按照任务一顺序在粗加工区夹取物料
  cjg_catch_color_1(data_xjblg[i],i);
  Servo_close();//关闭舵机失能
  delay(500);
  //adjust_180();

  go_left2();//远离暂存区
  delay(1000);
  adjust_180();

  To_zcq(data_xjblg[2]);//去到暂存区
  delay(2000);

  Servo_open();
  Location_outside();
  go_right_2();
  delay(1000);  
  Servo_close();
  adjust_90();
  
  //adjust_greenround();
  adjust_palate();
  openmv.end();

  Servo_open();//打开舵机使能
  for(i=4;i<7;i++)//按照任务一顺序在暂存区放物料
  cjg_put_color(Data_scan[i],i);
  delay(500);
  Servo_close();//关闭舵机失能

  go_left2();
  delay(800);
  To_cpq();
  delay(800);
  adjust_180();

  Servo_open();
  Location_outside();
  delay(800);
  Servo_close();
  delay(500);

  put_shunxu=1;
  put_index=0;
  //int task_index=0
  adjust_palate();//单一色圆的坐标和颜色
  while(put_index!=1)
  {
    get_openmv();
    if(openmv_data==Data_scan[4]&&put_shunxu==1)
    {
      put();
      put_shunxu++;
    }
    else if(openmv_data==Data_scan[5]&&put_shunxu==2)
    {
      put();
      put_shunxu++;
    }
    else if(openmv_data==Data_scan[6]&&put_shunxu==3)
    {
      put();
      put_index=1;
    }
  }
  go_left2();//远离暂存区
  delay(1000);
  adjust_fu90();

  to_end_js();
  while(1);


















  /*while(task_index!=3)
  {

  }*/
 // move_catch();

/*
  adjust_leftround();//移到左圆环，下降openmv，并校准机械爪位置
  openmv.end();

  Servo_open();//打开舵机使能
  for(i=0;i<3;i++)
  {
    zcq_move(Data_scan[i],i);
    zcq_read_color();
    zcq_catch_color(Data_scan[i],i,ground_color[i]);
  }

  delay(500);
*/

  //主程序
  /*
  xie();
  delay(1500);

  HWT101_flag=0;
  adjust_0();

  To_scan_area();
  //delay(1000);//走到扫码区
  //adjust_0();
  Scan_TJC.begin(9600);//打开扫码和串口屏串口

  while(Data_scan[3]!='+'||(Data_scan[0]!='1'&&Data_scan[0]!='2'&&Data_scan[0]!='3') ||(Data_scan[1]!='1'&&Data_scan[1]!='2'&&Data_scan[1]!='3') ||(Data_scan[2]!='1'&&Data_scan[2]!='2'&&Data_scan[2]!='3')||(Data_scan[4]!='1'&&Data_scan[4]!='2'&&Data_scan[4]!='3')||(Data_scan[5]!='1'&&Data_scan[5]!='2'&&Data_scan[5]!='3')||(Data_scan[6]!='1'&&Data_scan[6]!='2'&&Data_scan[6]!='3'))   
  {
    Serial.println("1");
    Get_scan();
  }
  Scan_TJC.end();

  To_Take_area();//走到取物物料盘

  Scan_TJC.begin(9600);
  delay(100);
  if(flag==1){
  Send2Screen();
  delay(500);
  Send2Screen();
  flag=0;
  }
  Scan_TJC.end();

  delay(1100);
  adjust_0();


  go_right_1();//贴近取物物料盘
  //delay(500);
  //adjust_0();

  Servo_open();//打开舵机使能
  Location_outside();
  delay(300);
  //adjust_palate();
  //openmv.end();
  //delay(1000);
  for(i=0;i<3;i++)//按任务一顺序抓取物料
  {
    catch_color(Data_scan[i]);
  }
  Location_inside();
  Open();
  delay(300);

  Servo_close();//关闭舵机失能
  openmv.end();
  Serial.println("抓取结束");
  out_palate();//远离取物物料盘
  delay(1000);

  To_cjg_area_1();//去到粗加工区
  delay(800);
  adjust_180();

  Servo_open();
  Location_outside();
  delay(800);
  Servo_close();
  delay(500);
  adjust_greenround();
  openmv.end();

  Servo_open();//打开舵机使能
  for(i=0;i<3;i++)//按照任务一顺序在粗加工区放物料
  cjg_put_color(Data_scan[i],i);//123+321    1 0

  delay(500);

  for(i=0;i<3;i++)//按照任务一顺序在粗加工区夹取物料
  cjg_catch_color_1(Data_scan[i],i);
  //Location_outside();
  //delay(500);
  Servo_close();//关闭舵机失能
  delay(500);
  //adjust_180();
  go_left2();//远离取物物料盘
  delay(1000);
  adjust_180();

  To_zcq(Data_scan[2]);//去到暂存区
  delay(2000);

  Servo_open();
  Location_outside();
  go_right_2();
  delay(1000);  
  Servo_close();
  adjust_90();
  
  adjust_greenround();
  openmv.end();

  Servo_open();//打开舵机使能
  for(i=0;i<3;i++)//按照任务一顺序在暂存区放物料
  cjg_put_color(Data_scan[i],i);
  delay(500);
  Servo_close();//关闭舵机失能

  back_2take_area(Data_scan[2]);//回到取物转盘

  //delay(500);
  //go_right();
  //delay(700);
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  //第二回合
  Servo_open();//打开舵机使能
  Location_outside();
  delay(700);
  adjust_palate();
  //openmv.end();
  for(i=4;i<7;i++)//按任务二顺序抓取物料
  {
    catch_color(Data_scan[i]);
  }
  //Location_inside();
  //delay(800);
  Servo_close();//关闭舵机失能
  //delay(1000);
  Serial.println("抓取结束");
  go_right_P();
  delay(1000);
  //go_left2();//远离取物物料盘
  //delay(1000);
  //adjust_0();
  adjust_0();
  To_cjg_area_2();//去到粗加工区
  delay(500);
  adjust_180();

  Servo_open();
  Location_outside();
  delay(800);
  Servo_close();

  adjust_greenround();//11111111111111
  openmv.end();

  Servo_open();//打开舵机使能
  for(i=4;i<7;i++)//按照任务2顺序在粗加工区放物料
  cjg_put_color(Data_scan[i],i);

  //delay(500);

  for(i=4;i<7;i++)//按照任务2顺序在粗加工区夹取物料
  cjg_catch_color_2(Data_scan[i],i);
  //Location_outside();
  //delay(500);
  Servo_close();//关闭舵机失能
  delay(500);
  //adjust_180();
  go_left2();//远离取物物料盘
  delay(1000);
  adjust_180();

  To_zcq(Data_scan[6]);//去到暂存区
  delay(2000);
  
  Servo_open();
  Location_outside();
  go_right_2();
  delay(1000);  
  Servo_close();
  
  adjust_90();
  adjust_greenround();
  openmv.end();

  Servo_open();//打开舵机使能
  for(i=4;i<7;i++)//按照任务2顺序在暂存区放物料
  zcq_put_color2(Data_scan[i],i);
  Servo_close();//关闭舵机失能
  
  To_end(Data_scan[6]);
  delay(10000);
  while(1);
*/
}




