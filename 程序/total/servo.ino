void Servo_open()//使能舵机
{
  servo2.attach(5, 500, 2500);          //修正脉冲宽度
  servo1.attach(3, 500, 2500);          //修正脉冲宽度
  servo3.attach(7, 500, 2500);          //修正脉冲宽度
}
void Servo_Init()//舵机初始化
{

  Open();
  //Catch();
  //up_down_Init();
  Location_inside();
  //Location_outside();
  delay(700);
 
  //delay(2000);
}
void Servo_close()//失能舵机
{
  servo1.detach();  
  servo2.detach();  
  servo3.detach(); 
}

/////////////////////////////////////////////////////////
//物料盘舵机应用函数
void Location_redplate()//车上物料盘转至红色区
{
  servo1.write(0);
}
void Location_blueplate()//车上物料盘转至蓝色区
{
  servo1.write(80);
}
void Location_greenplate()//车上物料盘转至绿色区
{
  servo1.write(160);
}
void Location_angle1(int angle)
{
  servo1.write(angle*2/3);
}
/////////////////////////////////////////////////////////////
//带盘舵机应用函数
void Location_angle2(int angle)
{
  servo2.write(angle*2/3);
}
void Location_outside()//带盘（机械爪）向外
{
  servo2.write(20);
}
void Location_inside()//带盘（机械爪）向内
{
  servo2.write(135);
}
//////////////////////////////////////////////////////////////
//机械爪舵机应用函数
void Location_angle3(int angle)
{
  servo3.write(angle*2/3);
}

void Open_take_area()//抓取区时机械爪张开到最大
{
servo3.write(110);

}
void Open()//机械爪张开
{
  servo3.write(110);
}
void Catch()//机械爪夹取
{
  servo3.write(40);
}