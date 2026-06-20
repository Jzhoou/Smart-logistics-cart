/*byte Speed1_left_Motor[]={0x01,0xF6,0x01,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed2_left_Motor[]={0x02,0xF6,0x00,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed3_left_Motor[]={0x03,0xF6,0x01,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed4_left_Motor[]={0x04,0xF6,0x00,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed1_right_Motor[]={0x01,0xF6,0x00,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed2_right_Motor[]={0x02,0xF6,0x01,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed3_right_Motor[]={0x03,0xF6,0x00,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed4_right_Motor[]={0x04,0xF6,0x01,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed1_front_Motor[]={0x01,0xF6,0x00,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed2_front_Motor[]={0x02,0xF6,0x00,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed3_front_Motor[]={0x03,0xF6,0x01,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed4_front_Motor[]={0x04,0xF6,0x01,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed1_behind_Motor[]={0x01,0xF6,0x01,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed2_behind_Motor[]={0x02,0xF6,0x01,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed3_behind_Motor[]={0x03,0xF6,0x00,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Speed4_behind_Motor[]={0x04,0xF6,0x00,0x00,0x01,0x00,0x01,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
byte Stop1_Motor[]={0x01,0xFE,0x98,0x01,0x6B};//命令格式：地址 + 0xFE + 0x98 + 多机同步标志 + 校验字节
byte Stop2_Motor[]={0x02,0xFE,0x98,0x01,0x6B};//命令格式：地址 + 0xFE + 0x98 + 多机同步标志 + 校验字节
byte Stop3_Motor[]={0x03,0xFE,0x98,0x01,0x6B};//命令格式：地址 + 0xFE + 0x98 + 多机同步标志 + 校验字节
byte Stop4_Motor[]={0x04,0xFE,0x98,0x01,0x6B};//命令格式：地址 + 0xFE + 0x98 + 多机同步标志 + 校验字节*/
byte together_Motor[]={0x00,0xFF,0x66,0x6B};//命令格式：地址 + 0xFF + 0x66 + 校验字节
byte Location_Motor[]={0x01,0xFD,0x00,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00,0x01,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节

//byte set_addid[]={0x03,0xAE,0x4B,0x01,0x02,0x6B};


void go_line()//向前走
{
  set_Motor(0x02,0x00,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void go_back()//向后走
{
  set_Motor(0x02,0x01,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void go_left()//向左走
{
  set_Motor(0x02,0x00,0x01,0xDC,0x4F,0x00,0x00,0x0A,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x01,0xDC,0x4F,0x00,0x00,0x0A,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x01,0xDC,0x4F,0x00,0x00,0x0A,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x01,0xDC,0x4F,0x00,0x00,0x0A,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void go_left2()//向左走
{
  set_Motor(0x02,0x00,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}
void out_palate()
{
  set_Motor(0x02,0x00,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void go_right()//向右走
{
  set_Motor(0x02,0x01,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x03,0xDC,0x6F,0x00,0x00,0x02,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}
 void go_right_1()//向右走
{
  set_Motor(0x02,0x01,0x03,0xDC,0x6F,0x00,0x00,0x01,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x03,0xDC,0x6F,0x00,0x00,0x01,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xDC,0x6F,0x00,0x00,0x01,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x03,0xDC,0x6F,0x00,0x00,0x01,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}
 void go_right_P()//向右走
{
  set_Motor(0x02,0x00,0x03,0xDC,0x6F,0x00,0x00,0x00,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0xDC,0x6F,0x00,0x00,0x00,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x03,0xDC,0x6F,0x00,0x00,0x00,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0xDC,0x6F,0x00,0x00,0x00,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}
void go_right_2()//向右走
{
  set_Motor(0x02,0x01,0x03,0xDC,0x6F,0x00,0x00,0x01,0x60,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x03,0xDC,0x6F,0x00,0x00,0x01,0x60,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xDC,0x6F,0x00,0x00,0x01,0x60,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x03,0xDC,0x6F,0x00,0x00,0x01,0x60,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void turn_left()//左转
{
  set_Motor(0x02,0x01,0x01,0xDC,0x1C,0x00,0x00,0x0C,0x31,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x01,0xDC,0x1C,0x00,0x00,0x0C,0x31,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x01,0xDC,0x1C,0x00,0x00,0x0C,0x31,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x01,0xDC,0x1C,0x00,0x00,0x0C,0x31,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}


void turn_right()//右转
{
  set_Motor(0x02,0x00,0x01,0xDC,0x1C,0x00,0x00,0x0C,0x31,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x01,0xDC,0x1C,0x00,0x00,0x0C,0x31,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x01,0xDC,0x1C,0x00,0x00,0x0C,0x31,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x01,0xDC,0x1C,0x00,0x00,0x0C,0x31,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void adjust_left()//陀螺仪角度左转微调整
{
  set_Motor(0x02,0x01,0x04,0xDC,0x3C,0x00,0x00,0x00,0x02,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(5);
  set_Motor(0x01,0x01,0x04,0xDC,0x3C,0x00,0x00,0x00,0x02,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(5);
  set_Motor(0x03,0x01,0x04,0xDC,0x3C,0x00,0x00,0x00,0x02,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(5);
  set_Motor(0x04,0x01,0x04,0xDC,0x3C,0x00,0x00,0x00,0x02,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(5);
  motors.write(together_Motor,sizeof(together_Motor));
}

void adjust_right()//陀螺仪角度右转微调整
{
  set_Motor(0x02,0x00,0x04,0xDC,0x3C,0x00,0x00,0x00,0x02,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(5);
  set_Motor(0x01,0x00,0x04,0xDC,0x3C,0x00,0x00,0x00,0x02,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(5);
  set_Motor(0x03,0x00,0x04,0xDC,0x3C,0x00,0x00,0x00,0x02,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(5);
  set_Motor(0x04,0x00,0x04,0xDC,0x3C,0x00,0x00,0x00,0x02,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(5);
  motors.write(together_Motor,sizeof(together_Motor));
}

void xie()//斜出起点
{
  set_Motor(0x02,0x00,0x05,0xDC,0x5C,0x00,0x00,0x0F,0x85,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x05,0xDC,0x5C,0x00,0x00,0x0F,0x85,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x05,0xDC,0x5C,0x00,0x00,0x00,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x05,0xDC,0x5C,0x00,0x00,0x00,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void xie_end()//斜入终点
{
  set_Motor(0x02,0x01,0x04,0xDC,0x3C,0x00,0x00,0x0F,0x85,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x04,0xDC,0x3C,0x00,0x00,0x0F,0x85,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x04,0xDC,0x3C,0x00,0x00,0x00,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x04,0xDC,0x3C,0x00,0x00,0x00,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}



void To_Take_area()//去取物转盘区
{
  set_Motor(0x02,0x00,0x05,0xBC,0x8C,0x00,0x00,0x1C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x05,0xBC,0x8C,0x00,0x00,0x1C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x05,0xBC,0x8C,0x00,0x00,0x1C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x05,0xBC,0x8C,0x00,0x00,0x1C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}
void To_cjg_area_1()//去粗加工区
{
  set_Motor(0x02,0x01,0x02,0xDC,0x8C,0x00,0x00,0x13,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x02,0xDC,0x8C,0x00,0x00,0x13,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x02,0xDC,0x8C,0x00,0x00,0x13,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x02,0xDC,0x8C,0x00,0x00,0x13,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(1200);

  turn_left();

  delay(1500);
  adjust_90();

  set_Motor(0x02,0x00,0x05,0xBC,0x8C,0x00,0x00,0x44,0xD0,0x00);//5D37
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x05,0xBC,0x8C,0x00,0x00,0x44,0xD0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x05,0xBC,0x8C,0x00,0x00,0x44,0xD0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x05,0xBC,0x8C,0x00,0x00,0x44,0xD0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
    
  delay(2500);

  turn_left();
  delay(1500);
  go_right();


}
void To_cjg_area_2()//去粗加工区
{
  set_Motor(0x02,0x01,0x02,0xDC,0x8C,0x00,0x00,0x10,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x02,0xDC,0x8C,0x00,0x00,0x10,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x02,0xDC,0x8C,0x00,0x00,0x10,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x02,0xDC,0x8C,0x00,0x00,0x10,0xB0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(1200);

  turn_left();

  delay(1500);
  adjust_90();

  set_Motor(0x02,0x00,0x05,0xBC,0x8C,0x00,0x00,0x46,0x20,0x00);//5D37
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x05,0xBC,0x8C,0x00,0x00,0x46,0x20,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x05,0xBC,0x8C,0x00,0x00,0x46,0x20,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x05,0xBC,0x8C,0x00,0x00,0x46,0x20,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
    
  delay(2500);

  turn_left();
  delay(1500);
  go_right();


}


void To_cjg_green2blueround()//在粗加工区从绿环处去蓝环
{  
  set_Motor(0x02,0x00,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void To_cjg_red2blueround()//在粗加工区从红环处去蓝环
{  
  set_Motor(0x02,0x00,0x00,0xDC,0x6C,0x00,0x00,0x0C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x00,0xDC,0x6C,0x00,0x00,0x0C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x00,0xDC,0x6C,0x00,0x00,0x0C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x00,0xDC,0x6C,0x00,0x00,0x0C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void To_cjg_red2greenround()//在粗加工区从红环处去绿环
{
  set_Motor(0x02,0x00,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor)); 
}

void To_cjg_blue2greenround()//在粗加工区从蓝环处去绿环
{
  set_Motor(0x02,0x01,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void To_cjg_blue2redround()//在粗加工区从蓝环处去红环
{
  set_Motor(0x02,0x01,0x00,0xDC,0x6C,0x00,0x00,0x0C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x00,0xDC,0x6C,0x00,0x00,0x0C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x00,0xDC,0x6C,0x00,0x00,0x0C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x00,0xDC,0x6C,0x00,0x00,0x0C,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void To_cjg_green2redround()//在粗加工区从绿环处去红环
{
  set_Motor(0x02,0x01,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x00,0xDC,0x6C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));    
}

void From_blue2zcq()//在粗加工区从蓝环处去暂存区前的直角转弯点
{
  set_Motor(0x02,0x01,0x03,0xBC,0x5C,0x00,0x00,0x28,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0xBC,0x5C,0x00,0x00,0x28,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xBC,0x5C,0x00,0x00,0x28,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0xBC,0x5C,0x00,0x00,0x28,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}
void From_green2zcq()//在粗加工区从绿环处去暂存区前的直角转弯点
{
  set_Motor(0x02,0x01,0x03,0xBC,0x5C,0x00,0x00,0x22,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0xBC,0x5C,0x00,0x00,0x22,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xBC,0x5C,0x00,0x00,0x22,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0xBC,0x5C,0x00,0x00,0x22,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void From_red2zcq()//在粗加工区从红环处去暂存区前的直角转弯点
{
  set_Motor(0x02,0x01,0x03,0xBC,0x5C,0x00,0x00,0x1C,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0xBC,0x5C,0x00,0x00,0x1C,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xBC,0x5C,0x00,0x00,0x1C,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0xBC,0x5C,0x00,0x00,0x1C,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void To_zcq(char final_task)//从暂存区前的直角转弯点去暂存区绿环
{
  switch(final_task)
  {
    case '1':From_red2zcq();break;
    case '2':From_green2zcq();break;
    case '3':From_blue2zcq();break;
  }
  delay(2500);
  set_Motor(0x02,0x01,0x03,0xBC,0x5C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0xBC,0x5C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xBC,0x5C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0xBC,0x5C,0x00,0x00,0x06,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(3000);
  //adjust_180();
  turn_right();
  delay(1500);
  adjust_90();

  set_Motor(0x02,0x01,0x03,0xBC,0x5C,0x00,0x00,0x21,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0xBC,0x5C,0x00,0x00,0x21,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xBC,0x5C,0x00,0x00,0x21,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0xBC,0x5C,0x00,0x00,0x21,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}

void back_2take_area(char final_task)//第一轮任务结束回到取物转盘
{
  go_left2();
  delay(800);
  adjust_90();
  switch(final_task)
  {
    case '1':{
      set_Motor(0x02,0x01,0x03,0xBC,0x5C,0x00,0x00,0x1F,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x01,0x01,0x03,0xBC,0x5C,0x00,0x00,0x1F,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x03,0x00,0x03,0xBC,0x5C,0x00,0x00,0x1F,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x04,0x00,0x03,0xBC,0x5C,0x00,0x00,0x1F,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      motors.write(together_Motor,sizeof(together_Motor));
      break;
    }
      case '2':{
      set_Motor(0x02,0x01,0x03,0xBC,0x5C,0x00,0x00,0x25,0x00,0x00);//0780
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x01,0x01,0x03,0xBC,0x5C,0x00,0x00,0x25,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x03,0x00,0x03,0xBC,0x5C,0x00,0x00,0x25,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x04,0x00,0x03,0xBC,0x5C,0x00,0x00,0x25,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      motors.write(together_Motor,sizeof(together_Motor));
      break;
    }
      case '3':{
      set_Motor(0x02,0x01,0x03,0xBC,0x5C,0x00,0x00,0x2B,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x01,0x01,0x03,0xBC,0x5C,0x00,0x00,0x2B,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x03,0x00,0x03,0xBC,0x5C,0x00,0x00,0x2B,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x04,0x00,0x03,0xBC,0x5C,0x00,0x00,0x2B,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      motors.write(together_Motor,sizeof(together_Motor));
      break;
    }
  }
  delay(2500);
  adjust_90();

  turn_right();
  delay(1500);
  adjust_0();

  set_Motor(0x02,0x01,0x03,0xBC,0x5C,0x00,0x00,0x10,0xAF,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0xBC,0x5C,0x00,0x00,0x10,0xAF,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xBC,0x5C,0x00,0x00,0x10,0xAF,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0xBC,0x5C,0x00,0x00,0x10,0xAF,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(2000);
  adjust_0();

/*
  //右平移贴近物料盘
  set_Motor(0x02,0x01,0x04,0xDC,0xBF,0x00,0x00,0x03,0xC6,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x04,0xDC,0xBF,0x00,0x00,0x03,0xC6,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x04,0xDC,0xBF,0x00,0x00,0x03,0xC6,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x04,0xDC,0xBF,0x00,0x00,0x03,0xC6,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(500);*/
  //adjust_0();
}

void adjust_0()//陀螺仪0°调整
{
  //////////////////////////////////////////
  /*
    HWT101.begin(9600);
  Get_angle();
  for(i=0;i<150;i++)
  {
    Get_angle();
    Serial.println("调整中");
    if(currentYaw>0.1)
    adjust_right();
    else if(currentYaw<-0.1)
    adjust_left();
  }
  Serial.println("调整完");
  delay(200);
  HWT101.end();

  */
  ////////////////////////////////////////////
  //Get_angle();
  //for(i=0;i<50;i++)
  //{

    
    while(adjust_state!=1)
    {
    HWT101.begin(9600);
    Serial.println(HWT101_flag);
    while(HWT101_flag!=1)
    {
    Get_angle();
    }
    HWT101_flag=0;
    HWT101.end();
    Serial.println("调整中");
    if(currentYaw>0.1)
    adjust_right();
    else if(currentYaw<-0.1)
    adjust_left();    
    else
    adjust_state=1;
    }
    adjust_state=0;
  //}
  Serial.println("调整完");
  delay(200);
  HWT101.end();
  

  /*
  HWT101.begin(9600);
      while(adjust_state!=1)
    {
    
    Serial.println(HWT101_flag);
    while(HWT101_flag!=1)
    {
    Get_angle();
    }
    HWT101_flag=0;
    //HWT101.end();
    Serial.println("调整中");
    if(currentYaw>0.1)
    adjust_right();
    else if(currentYaw<-0.1)
    adjust_left();    
    else
    adjust_state=1;
    }
    adjust_state=0;
  //}
  Serial.println("调整完");
  delay(200);
  HWT101.end();*/
}
void adjust_fu90()//陀螺仪-90°调整
{
  ////////////////////////////////////
  /*
HWT101.begin(9600);
  Get_angle();
  for(i=0;i<150;i++)
  {
    Get_angle();
    Serial.println("调整中");
    if(currentYaw>-89.9)
    adjust_right();
    else if(currentYaw<-90.1)
    adjust_left();
  }
  Serial.println("调整完");
  delay(200);
  HWT101.end();
*/
////////////////////////////////////


  // HWT101.begin(9600);
  // Get_angle();
  //for(i=0;i<50;i++)
  //{
    
    while(adjust_state!=1)
    {
     HWT101.begin(9600);
     Serial.println(HWT101_flag);
    while(HWT101_flag!=1)
    {
    Get_angle();
    }
    HWT101_flag=0;
    HWT101.end();
    Serial.println("调整中");
    if(currentYaw>-89.9)
    adjust_right();
    else if(currentYaw<-90.1)
    adjust_left();
    else
    adjust_state=1;
    }
    adjust_state=0;
  //}
  Serial.println("调整完");
  delay(200);
  HWT101.end();
  /*
       HWT101.begin(9600);
  while(adjust_state!=1)
    {

     Serial.println(HWT101_flag);
    while(HWT101_flag!=1)
    {
    Get_angle();
    }
    HWT101_flag=0;
    Serial.println("调整中");
    if(currentYaw>-89.9)
    adjust_right();
    else if(currentYaw<-90.1)
    adjust_left();
    else
    adjust_state=1;
    }
    adjust_state=0;
  //}
  Serial.println("调整完");
  delay(200);
  HWT101.end();*/
}

void adjust_90()//陀螺仪90°调整
{
  ////////////////////////////
  /*
  HWT101.begin(9600);
  Get_angle();
  for(i=0;i<150;i++)
  {
    Get_angle();
    Serial.println("调整中");
    if(currentYaw>90.1)
    adjust_right();
    else if(currentYaw<89.9)
    adjust_left();
  }
  Serial.println("调整完");
  delay(200);
  HWT101.end();
*/
/////////////////////////////////

  // HWT101.begin(9600);
  // Get_angle();
  //for(i=0;i<50;i++)
  //{
    
    while(adjust_state!=1)
    {
     HWT101.begin(9600);
     Serial.println(HWT101_flag);
    while(HWT101_flag!=1)
    {
    Get_angle();
    }
    HWT101_flag=0;
    HWT101.end();
    Serial.println("调整中");
    if(currentYaw>90.1)
    adjust_right();
    else if(currentYaw<89.9)
    adjust_left();
    else
    adjust_state=1;
    }
    adjust_state=0;
  //}
  Serial.println("调整完");
  delay(200);
  HWT101.end();
  /*
  HWT101.begin(9600);
  while(adjust_state!=1)
    {
     
     Serial.println(HWT101_flag);
    while(HWT101_flag!=1)
    {
    Get_angle();
    }
    HWT101_flag=0;
    
    Serial.println("调整中");
    if(currentYaw>90.1)
    adjust_right();
    else if(currentYaw<89.9)
    adjust_left();
    else
    adjust_state=1;
    }
    adjust_state=0;
  //}
  Serial.println("调整完");
  delay(200);
  HWT101.end();*/
}
void adjust_180()//陀螺仪180°调整
{
  //////////////////////////
  /*
HWT101.begin(9600);
  Get_angle();
  for(i=0;i<150;i++)
  {
    Get_angle();
    Serial.println("调整中");
    if(currentYaw<179.9&&currentYaw>0)
    adjust_left();
    if(currentYaw>179.99)
    adjust_right();
    if(currentYaw>-179.9&&currentYaw<0)
    adjust_right();
    if(currentYaw<-179.99)
    adjust_left();
  }
  Serial.println("调整完");
  delay(200);
  HWT101.end();
*/
////////////////////////////////

  // HWT101.begin(9600);
  // Get_angle();
  //for(i=0;i<50;i++)
  //{
    
    while(adjust_state!=1)
    {
     HWT101.begin(9600);
     Serial.println(HWT101_flag);
    while(HWT101_flag!=1)
    {
    Get_angle();
    }
    HWT101_flag=0;
    HWT101.end();
    Serial.println("调整中");
    if(currentYaw<179.97&&currentYaw>0)
    adjust_left();
    //else if(currentYaw>179.99)
    //adjust_right();
    else if(currentYaw>-179.97&&currentYaw<0)
    adjust_right();
    //else if(currentYaw<-179.99)
    //adjust_left();
    else
    adjust_state=1;
    }
    adjust_state=0;
  //}
  //}
  Serial.println("调整完");
  delay(200);
  HWT101.end();
  /*
  HWT101.begin(9600);
  while(adjust_state!=1)
    {
     
     Serial.println(HWT101_flag);
    while(HWT101_flag!=1)
    {
    Get_angle();
    }
    HWT101_flag=0;
    
    Serial.println("调整中");
    if(currentYaw<179.97&&currentYaw>0)
    adjust_left();
    //else if(currentYaw>179.99)
    //adjust_right();
    else if(currentYaw>-179.97&&currentYaw<0)
    adjust_right();
    //else if(currentYaw<-179.99)
    //adjust_left();
    else
    adjust_state=1;
    }
    adjust_state=0;
  //}
  //}
  Serial.println("调整完");
  delay(200);
  HWT101.end();*/
}

void adjust_2left()//绿环处向左微调
{/*
  motors.write(Speed1_left_Motor,sizeof(Speed1_left_Motor));
  delay(10);
  motors.write(Speed2_left_Motor,sizeof(Speed2_left_Motor));
  delay(10);
  motors.write(Speed3_left_Motor,sizeof(Speed3_left_Motor));
  delay(10);
  motors.write(Speed4_left_Motor,sizeof(Speed4_left_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  */
  set_Motor(0x02,0x00,0x03,0xDC,0x5C,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x01,0x00,0x03,0xDC,0x5C,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x03,0x01,0x03,0xDC,0x5C,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x04,0x01,0x03,0xDC,0x5C,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  
}

void adjust_2right()//绿环处向右微调
{/*
  motors.write(Speed1_right_Motor,sizeof(Speed1_right_Motor));
  delay(10);
  motors.write(Speed2_right_Motor,sizeof(Speed2_right_Motor));
  delay(10);
  motors.write(Speed3_right_Motor,sizeof(Speed3_right_Motor));
  delay(10);
  motors.write(Speed4_right_Motor,sizeof(Speed4_right_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  */
  set_Motor(0x02,0x01,0x03,0x5C,0xCC,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x01,0x01,0x03,0x5C,0xCC,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x03,0x00,0x03,0x5C,0xCC,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x04,0x00,0x03,0x5C,0xCC,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  
}
void adjust_2front()//绿环处向前微调
{/*
  motors.write(Speed1_front_Motor,sizeof(Speed1_front_Motor));
  delay(10);
  motors.write(Speed2_front_Motor,sizeof(Speed2_front_Motor));
  delay(10);
  motors.write(Speed3_front_Motor,sizeof(Speed3_front_Motor));
  delay(10);
  motors.write(Speed4_front_Motor,sizeof(Speed4_front_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  */
  set_Motor(0x02,0x01,0x03,0xDC,0x5F,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x01,0x00,0x03,0xDC,0x5F,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x03,0x00,0x03,0xDC,0x5F,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x04,0x01,0x03,0xDC,0x5F,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  
}
void adjust_2behind()//绿环处向后微调
{/*
  motors.write(Speed1_behind_Motor,sizeof(Speed1_behind_Motor));
  delay(10);
  motors.write(Speed2_behind_Motor,sizeof(Speed2_behind_Motor));
  delay(10);
  motors.write(Speed3_behind_Motor,sizeof(Speed3_behind_Motor));
  delay(10);
  motors.write(Speed4_behind_Motor,sizeof(Speed4_behind_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  */
  
  set_Motor(0x02,0x00,0x03,0xDC,0x5F,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x01,0x01,0x03,0xDC,0x5F,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x03,0x01,0x03,0xDC,0x5F,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x04,0x00,0x03,0xDC,0x5F,0x00,0x00,0x00,0x10,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  
}

void adjust_2left_p()//绿环处向左微调
{/*
  motors.write(Speed1_left_Motor,sizeof(Speed1_left_Motor));
  delay(10);
  motors.write(Speed2_left_Motor,sizeof(Speed2_left_Motor));
  delay(10);
  motors.write(Speed3_left_Motor,sizeof(Speed3_left_Motor));
  delay(10);
  motors.write(Speed4_left_Motor,sizeof(Speed4_left_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  */
  set_Motor(0x02,0x00,0x03,0xDC,0x5C,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x01,0x00,0x03,0xDC,0x5C,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x03,0x01,0x03,0xDC,0x5C,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x04,0x01,0x03,0xDC,0x5C,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  
}

void adjust_2right_p()//绿环处向右微调
{/*
  motors.write(Speed1_right_Motor,sizeof(Speed1_right_Motor));
  delay(10);
  motors.write(Speed2_right_Motor,sizeof(Speed2_right_Motor));
  delay(10);
  motors.write(Speed3_right_Motor,sizeof(Speed3_right_Motor));
  delay(10);
  motors.write(Speed4_right_Motor,sizeof(Speed4_right_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  */
  set_Motor(0x02,0x01,0x03,0x5C,0xCC,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x01,0x01,0x03,0x5C,0xCC,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x03,0x00,0x03,0x5C,0xCC,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x04,0x00,0x03,0x5C,0xCC,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  
}
void adjust_2front_p()//绿环处向前微调
{/*
  motors.write(Speed1_front_Motor,sizeof(Speed1_front_Motor));
  delay(10);
  motors.write(Speed2_front_Motor,sizeof(Speed2_front_Motor));
  delay(10);
  motors.write(Speed3_front_Motor,sizeof(Speed3_front_Motor));
  delay(10);
  motors.write(Speed4_front_Motor,sizeof(Speed4_front_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  */
  set_Motor(0x02,0x01,0x03,0xDC,0x5F,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x01,0x00,0x03,0xDC,0x5F,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x03,0x00,0x03,0xDC,0x5F,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x04,0x01,0x03,0xDC,0x5F,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  
}
void adjust_2behind_p()//绿环处向后微调
{/*
  motors.write(Speed1_behind_Motor,sizeof(Speed1_behind_Motor));
  delay(10);
  motors.write(Speed2_behind_Motor,sizeof(Speed2_behind_Motor));
  delay(10);
  motors.write(Speed3_behind_Motor,sizeof(Speed3_behind_Motor));
  delay(10);
  motors.write(Speed4_behind_Motor,sizeof(Speed4_behind_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  */
  
  set_Motor(0x02,0x00,0x03,0xDC,0x5F,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x01,0x01,0x03,0xDC,0x5F,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x03,0x01,0x03,0xDC,0x5F,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  set_Motor(0x04,0x00,0x03,0xDC,0x5F,0x00,0x00,0x00,0x30,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(10);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(100);
  
}
void test111()//测试小车前走一米距离
{  
  set_Motor(0x02,0x00,0x00,0x3C,0xCC,0x00,0x00,0x35,0x0D,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x00,0x3C,0xCC,0x00,0x00,0x35,0x0D,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x00,0x3C,0xCC,0x00,0x00,0x35,0x0D,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x00,0x3C,0xCC,0x00,0x00,0x35,0x0D,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
  
}

void adjust_palate()//171,129//调整小车机械爪到绿环中心
{
  /*byte Locationx_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x14,0x30,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
  motor.write(Locationx_Motor,sizeof(Locationx_Motor));
  delay(50);*/

  data[0]=9;
  openmv.begin(115200);
  delay(100);
  for(int i=0;i<2;i++)
  openmv.write(data[i]);
  
  adjust_flag=0;
  Serial.println(adjust_flag);
  while(adjust_flag!=1)
  {
    get_openmv();
    if(openmv_flag!=0)
    {
      if(x_adjust<=160&&y_adjust<=90)//138 149
      {
        adjust_2left_p();
        delay(200);
        adjust_2front_p();
        openmv_flag=0;
      }
      else if(x_adjust<=160&&y_adjust>=110)
      {
        adjust_2left_p();
        delay(200);
        adjust_2behind_p();
        openmv_flag=0;
      }
      else if(x_adjust>=182&&y_adjust<=90)
      {
        adjust_2right_p();
        delay(200);
        adjust_2front_p();
        openmv_flag=0;
      }
      else if(x_adjust>=182&&y_adjust>=110)
      {
        adjust_2right_p();
        delay(200);
        adjust_2behind_p();
        openmv_flag=0;
      }
      else if((x_adjust<182&&x_adjust>160)&&y_adjust<=90)
      {
        adjust_2front_p();
        openmv_flag=0;
        }
      else if((x_adjust<182&&x_adjust>160)&&y_adjust>=110)
      {
        adjust_2behind_p();
        openmv_flag=0;
        }
      else if(x_adjust<=160&&(y_adjust>90&&y_adjust<110))
      {
        adjust_2left_p();
        openmv_flag=0;
        }
      else if(x_adjust>=182&&(y_adjust>90&&y_adjust<110))
      {
        adjust_2right_p();
        openmv_flag=0;
        }
      else if(y_adjust>=90&&y_adjust<=110&&x_adjust<=182&&x_adjust>=160)
      {
        adjust_flag=1;  
        openmv_flag=0;
      }
    }
    else;
    
    Serial.println("调整中");
  }
  adjust_flag=0;
  Serial.println("调整完毕");
  byte Locationxx_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
  motor.write(Locationxx_Motor,sizeof(Locationxx_Motor));
  delay(200);

}/*
void adjust_greenround()//85,53//调整小车机械爪到绿环中心
{
  To_cjg_green2redround();
  delay(1000);
  byte Locationx_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x17,0x30,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
  motor.write(Locationx_Motor,sizeof(Locationx_Motor));
  delay(50);
  

  data[0]=5;
  openmv.begin(115200);
  delay(100);
  for(int i=0;i<2;i++)
  openmv.write(data[i]);
  
  adjust_flag=0;
  Serial.println(adjust_flag);
  while(adjust_flag!=1)
  {
    get_openmv();
    if(openmv_flag!=0)
    {
      if(x_adjust<=82&&y_adjust<=53)
      {
        adjust_2left();
        delay(200);
        adjust_2front();
        openmv_flag=0;
      }
      else if(x_adjust<=82&&y_adjust>=55)
      {
        adjust_2left();
        delay(200);
        adjust_2behind();
        openmv_flag=0;
      }
      else if(x_adjust>=84&&y_adjust<=53)
      {
        adjust_2right();
        delay(200);
        adjust_2front();
        openmv_flag=0;
      }
      else if(x_adjust>=84&&y_adjust>=55)
      {
        adjust_2right();
        delay(200);
        adjust_2behind();
        openmv_flag=0;
      }
      else if((x_adjust<84&&x_adjust>82)&&y_adjust<=53)
      {
        adjust_2front();
        openmv_flag=0;
        }
      else if((x_adjust<84&&x_adjust>82)&&y_adjust>=55)
      {
        adjust_2behind();
        openmv_flag=0;
        }
      else if(x_adjust<=82&&(y_adjust>53&&y_adjust<55))
      {
        adjust_2left();
        openmv_flag=0;
        }
      else if(x_adjust>=84&&(y_adjust>53&&y_adjust<55))
      {
        adjust_2right();
        openmv_flag=0;
        }
      else if(y_adjust>53&&y_adjust<55&&x_adjust<84&&x_adjust>82)
      {
        adjust_flag=1;  
        openmv_flag=0;
      }
    }
    else;
    
    Serial.println("调整中");
  }
  adjust_flag=0;
  Serial.println("调整完毕");
  byte Locationxx_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
  motor.write(Locationxx_Motor,sizeof(Locationxx_Motor));
  delay(200);

}*/
void adjust_greenround()//85,53//调整小车机械爪到绿环中心
{
  To_cjg_green2redround();
  delay(1000);
  byte Locationx_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x17,0x30,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
  motor.write(Locationx_Motor,sizeof(Locationx_Motor));
  delay(50);
  

  data[0]=5;
  openmv.begin(115200);
  delay(100);
  for(int i=0;i<2;i++)
  openmv.write(data[i]);
  
  adjust_flag=0;
  Serial.println(adjust_flag);
  while(adjust_flag!=1)
  {
    get_openmv();
    if(openmv_flag!=0)
    {
      if(x_adjust<=83&&y_adjust<=53)
      {
        adjust_2left();
        delay(200);
        adjust_2front();
        openmv_flag=0;
      }
      else if(x_adjust<=83&&y_adjust>=55)
      {
        adjust_2left();
        delay(200);
        adjust_2behind();
        openmv_flag=0;
      }
      else if(x_adjust>=85&&y_adjust<=53)
      {
        adjust_2right();
        delay(200);
        adjust_2front();
        openmv_flag=0;
      }
      else if(x_adjust>=85&&y_adjust>=55)
      {
        adjust_2right();
        delay(200);
        adjust_2behind();
        openmv_flag=0;
      }
      else if((x_adjust<85&&x_adjust>83)&&y_adjust<=53)
      {
        adjust_2front();
        openmv_flag=0;
        }
      else if((x_adjust<85&&x_adjust>83)&&y_adjust>=55)
      {
        adjust_2behind();
        openmv_flag=0;
        }
      else if(x_adjust<=83&&(y_adjust>53&&y_adjust<55))
      {
        adjust_2left();
        openmv_flag=0;
        }
      else if(x_adjust>=85&&(y_adjust>53&&y_adjust<55))
      {
        adjust_2right();
        openmv_flag=0;
        }
      else if(y_adjust>53&&y_adjust<55&&x_adjust<85&&x_adjust>83)
      {
        adjust_flag=1;  
        openmv_flag=0;
      }
    }
    else;
    
    Serial.println("调整中");
  }
  adjust_flag=0;
  Serial.println("调整完毕");
  byte Locationxx_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
  motor.write(Locationxx_Motor,sizeof(Locationxx_Motor));
  delay(200);

}

void To_end(char final_task)//返回起点
{
  go_left2();
  delay(1000);
  adjust_90();
  switch(final_task)
  {
    case '1':{
      set_Motor(0x02,0x01,0x00,0xDC,0x6C,0x00,0x00,0x1D,0x00,0x00);//-0200
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x01,0x01,0x00,0xDC,0x6C,0x00,0x00,0x1D,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x03,0x00,0x00,0xDC,0x6C,0x00,0x00,0x1D,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x04,0x00,0x00,0xDC,0x6C,0x00,0x00,0x1D,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      motors.write(together_Motor,sizeof(together_Motor));
      break;
    }
      case '2':{
      set_Motor(0x02,0x01,0x00,0xDC,0x6C,0x00,0x00,0x23,0x00,0x00);//0780
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x01,0x01,0x00,0xDC,0x6C,0x00,0x00,0x23,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x03,0x00,0x00,0xDC,0x6C,0x00,0x00,0x23,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x04,0x00,0x00,0xDC,0x6C,0x00,0x00,0x23,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      motors.write(together_Motor,sizeof(together_Motor));
      break;
    }
      case '3':{
      set_Motor(0x02,0x01,0x00,0xDC,0x6C,0x00,0x00,0x29,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x01,0x01,0x00,0xDC,0x6C,0x00,0x00,0x29,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x03,0x00,0x00,0xDC,0x6C,0x00,0x00,0x29,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      set_Motor(0x04,0x00,0x00,0xDC,0x6C,0x00,0x00,0x29,0x00,0x00);
      motors.write(Location_Motor,sizeof(Location_Motor));
      delay(50);
      motors.write(together_Motor,sizeof(together_Motor));
      break;
    }
  }
  delay(2000);
  adjust_90();

  turn_right();
  delay(1500);
  adjust_0();

  set_Motor(0x02,0x01,0x03,0x5C,0x75,0x00,0x00,0x43,0xA0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x01,0x03,0x5C,0x75,0x00,0x00,0x43,0xA0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0x5C,0x75,0x00,0x00,0x43,0xA0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x00,0x03,0x5C,0x75,0x00,0x00,0x43,0xA0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(3500);
  adjust_0();

  xie_end();
}





void To_scan_area()//去扫码区
{
  set_Motor(0x02,0x00,0x06,0xBC,0x8C,0x00,0x00,0x35,0x70,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x06,0xBC,0x8C,0x00,0x00,0x35,0x70,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x06,0xBC,0x8C,0x00,0x00,0x35,0x70,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x06,0xBC,0x8C,0x00,0x00,0x35,0x70,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
}
void adjust_zcj_round()
{

}

void To_cpq()
{
  turn_left();
  delay(2000);
  adjust_0();

  set_Motor(0x02,0x00,0x05,0xBC,0x8C,0x00,0x00,0x44,0xD0,0x00);//5D37
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x05,0xBC,0x8C,0x00,0x00,0x44,0xD0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x05,0xBC,0x8C,0x00,0x00,0x44,0xD0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x05,0xBC,0x8C,0x00,0x00,0x44,0xD0,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
    
  delay(2500);

  turn_right();
  delay(1500);
  go_right();

}
void to_end_js()
{
  set_Motor(0x02,0x00,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x01,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(3000);
  set_Motor(0x02,0x01,0x03,0xDC,0x6F,0x00,0x00,0x01,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x01,0x00,0x03,0xDC,0x6F,0x00,0x00,0x01,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x03,0x00,0x03,0xDC,0x6F,0x00,0x00,0x01,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  set_Motor(0x04,0x01,0x03,0xDC,0x6F,0x00,0x00,0x01,0x00,0x00);
  motors.write(Location_Motor,sizeof(Location_Motor));
  delay(50);
  motors.write(together_Motor,sizeof(together_Motor));
  delay(2000);
}
void set_Motor(byte ID,byte dir,byte v1,byte v2,byte a,byte distance1,byte distance2,byte distance3,byte distance4,byte absolute)//设置电机参数（距离）
{
  Location_Motor[0]=ID;
  Location_Motor[2]=dir;
  Location_Motor[3]=v1;
  Location_Motor[4]=v2;
  Location_Motor[5]=a;
  Location_Motor[6]=distance1;
  Location_Motor[7]=distance2;
  Location_Motor[8]=distance3;
  Location_Motor[9]=distance4;
  Location_Motor[10]=absolute;

}