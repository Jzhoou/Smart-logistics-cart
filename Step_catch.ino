//byte Speed_Motor[]={0x01,0xF6,0x01,0x05,0xDC,0x7A,0x00,0x6B};//命令格式：地址 + 0xF6 + 方向 + 速度 + 加速度 + 多机同步标志 + 校验字节
/*byte Location1_Motor[]={0x01,0xFD,0x01,0x02,0x00,0xFF,0x00,0x00,0x35,0x62,0x01,0x00,0x6B};//32 62 3F//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到地面高度
byte Location_put_Motor[]={0x01,0xFD,0x01,0x01,0x00,0x8F,0x00,0x00,0x36,0xE0,0x01,0x00,0x6B};//32 62 3F//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到地面高度
byte Location2_Motor[]={0x01,0xFD,0x01,0x02,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///拿到最高处
byte Location3_Motor[]={0x01,0xFD,0x01,0x02,0x00,0xFF,0x00,0x00,0x0E,0xF0,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///放到车上物料盘
byte Location4_Motor[]={0x01,0xFD,0x01,0x03,0x00,0xFF,0x00,0x00,0x1D,0x60,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
byte Location5_Motor[]={0x01,0xFD,0x01,0x02,0x00,0xFF,0x00,0x00,0x20,0x00,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
byte Stop_Motor[]={0x01,0xFE,0x98,0x00,0x6B};//命令格式：地址 + 0xFE + 0x98 + 多机同步标志 + 校验字节
*/
byte Location1_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x37,0x62,0x01,0x00,0x6B};//32 62 3F//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到地面高度
byte Location_put_Motor[]={0x01,0xFD,0x01,0x01,0x00,0x8F,0x00,0x00,0x35,0x62,0x01,0x00,0x6B};//32 62 3F//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到地面高度
byte Location2_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///拿到最高处
byte Location3_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x0B,0xF0,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///放到车上物料盘
byte Location4_Motor[]={0x01,0xFD,0x01,0x01,0x00,0xFF,0x00,0x00,0x1C,0x60,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
byte Location_put_Motor_js[]={0x01,0xFD,0x01,0x01,0x00,0x8F,0x00,0x00,0x1C,0x60,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度

byte Location5_Motor[]={0x01,0xFD,0x01,0x02,0x00,0xFF,0x00,0x00,0x1F,0x00,0x01,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节///降到取物物料盘高度
byte Stop_Motor[]={0x01,0xFE,0x98,0x00,0x6B};//命令格式：地址 + 0xFE + 0x98 + 多机同步标志 + 校验字节
void up_down_Init()
{
  //motor.write(Location4_Motor,sizeof(Location4_Motor));
  
  motor.write(Location5_Motor,sizeof(Location5_Motor));
  delay(1000);
}
void down()
{
  //motor.write(Location4_Motor,sizeof(Location4_Motor));
  
  motor.write(Location_put_Motor,sizeof(Location_put_Motor));
  delay(1000);
}
//////////////////////////
//在物料盘取物
/*void catch_color(char color)//1-red;2-green;3-blue
{
  int catch_index=0;
  Location_outside();
  Open();
  delay(500);
  
  motor.write(Location4_Motor,sizeof(Location4_Motor));
  delay(800);
  

  data[0]=9;
  openmv.begin(115200);
  for(int i=0;i<2;i++)
  openmv.write(data[i]);
  delay(200);

  data[0]=(int)color;
  while(catch_index==0)
  {
    get_openmv();
    delay(50);
    Serial.print("卡在循环里，现在任务是：");
    Serial.println(color);
  if(openmv_data==color)
  {

  Serial.print("进来抓取了，现在抓：");
  Serial.print(openmv_data);
  Serial.print("||||||");
  Serial.println(color);

  switch(color){
  case '1':Location_redplate();break;
  case '2':Location_greenplate();break;
  case '3':Location_blueplate();break;}
  delay(500);

  Catch();
  delay(300);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(100);


  Location_inside();
  delay(500);

  motor.write(Location3_Motor,sizeof(Location3_Motor));
  delay(50);

  Open();
  delay(100);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(200);

  Location_outside();
  delay(200);
  catch_index=1;
  Serial.println(999);
  }
  }

}*/
void catch_color(char color)//1-red;2-green;3-blue
{
  int catch_index=0;
  Location_outside();
  Open();
  delay(200);
  motor.write(Location4_Motor,sizeof(Location4_Motor));
  delay(100);
  //delay(300);
  

  data[0]=9;
  openmv.begin(115200);
  for(int i=0;i<2;i++)
  openmv.write(data[i]);
  delay(500);

  data[0]=(int)color;
  while(catch_index==0)
  {
    get_openmv();
    delay(50);
    // Serial.print("卡在循环里，现在任务是：");
    // Serial.println(color);
    if(openmv_data==color)
    {

    // Serial.print("进来抓取了，现在抓：");
    // Serial.print(openmv_data);
    // Serial.print("||||||");
    // Serial.println(color);

    switch(color){
    case '1':Location_redplate();break;
    case '2':Location_greenplate();break;
    case '3':Location_blueplate();break;}
    //delay(1000);

  // motor.write(Location4_Motor,sizeof(Location4_Motor));
    //delay(300);

    Catch();
    delay(400);

    motor.write(Location2_Motor,sizeof(Location2_Motor));
    delay(100);


    Location_inside();
    delay(500);

    motor.write(Location3_Motor,sizeof(Location3_Motor));
    //motor.write(Location4_Motor,sizeof(Location4_Motor));
    delay(100);

    Open_take_area();
    delay(300);

    motor.write(Location2_Motor,sizeof(Location2_Motor));
    delay(50);

    //Location_outside();
    //delay(800);
    catch_index=1;
    Serial.println(999);
    }
  }

}
///////////////////////
//在粗加工区放置物料
/*
void cjg_put_color(char color,int index)
{
  //motor.write(Location2_Motor,sizeof(Location2_Motor));
  //delay(500);

  Location_inside();
  switch(color){
  case '1':{
    Location_redplate();
    if(index==0||index==4)To_cjg_green2redround();
    else if(Data_scan[index-1]=='2')To_cjg_green2redround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2redround();
    break;
  }
  case '2':{
    Location_greenplate();
    if(index==0||index==4);
    else if(Data_scan[index-1]=='1')To_cjg_red2greenround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2greenround();
    break;
  }
  case '3':{
    Location_blueplate();
    if(index==0||index==4)To_cjg_green2blueround();
    else if(Data_scan[index-1]=='1')To_cjg_red2blueround();
    else if(Data_scan[index-1]=='2')To_cjg_green2blueround();
    break;
    }
  }
  delay(700);
  motor.write(Location3_Motor,sizeof(Location3_Motor));
  delay(300);

  Catch();
  delay(500);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(500);

  Location_outside();
  delay(500);

  motor.write(Location1_Motor,sizeof(Location1_Motor));
  delay(500);

  Open();
  delay(100);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(600);
}*/


void cjg_put_color(char color,int index)
{
  //motor.write(Location2_Motor,sizeof(Location2_Motor));
  //delay(500);
  
  Location_inside();
  switch(color){
  case '1':{
    Location_redplate();
    if(index==0||index==4);
    else if(Data_scan[index-1]=='2')To_cjg_green2redround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2redround();
    break;
  }
  case '2':{
    Location_greenplate();
    if(index==0||index==4)To_cjg_red2greenround();
    else if(Data_scan[index-1]=='1')To_cjg_red2greenround();
    //else if(Data_scan[index-1]=='2')To_cjg_green2greenround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2greenround();
    break;
  }
  case '3':{
    Location_blueplate();
    if(index==0||index==4)To_cjg_red2blueround();
    else if(Data_scan[index-1]=='1')To_cjg_red2blueround();
    else if(Data_scan[index-1]=='2')To_cjg_green2blueround();
    //else if(Data_scan[index-1]=='3')To_cjg_blue2blueround();
    break;
    }
  }
  Open_take_area();
  delay(1000);
  motor.write(Location3_Motor,sizeof(Location3_Motor));
  delay(1000);

  Catch();
  delay(500);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(500);

  Location_outside();
  delay(500);

  motor.write(Location_put_Motor,sizeof(Location_put_Motor));
  delay(2500);

  Open_take_area();
  delay(500);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(500);
  Location_inside();
}
///////////////////////
//第二轮任务在暂存区放置物料
/*void zcq_put_color2(char color,int index)
{
  //motor.write(Location2_Motor,sizeof(Location2_Motor));
  //delay(500);

  Location_inside();
  switch(color){
  case '1':{
    Location_redplate();
    if(index==0||index==4)To_cjg_green2redround();
    else if(Data_scan[index-1]=='2')To_cjg_green2redround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2redround();
    break;
  }
  case '2':{
    Location_greenplate();
    if(index==0||index==4);
    else if(Data_scan[index-1]=='1')To_cjg_red2greenround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2greenround();
    break;
  }
  case '3':{
    Location_blueplate();
    if(index==0||index==4)To_cjg_green2blueround();
    else if(Data_scan[index-1]=='1')To_cjg_red2blueround();
    else if(Data_scan[index-1]=='2')To_cjg_green2blueround();
    break;
    }
  }
  delay(700);
  motor.write(Location3_Motor,sizeof(Location3_Motor));
  delay(100);

  Catch();
  delay(300);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(100);

  Location_outside();
  delay(500);

  motor.write(Location5_Motor,sizeof(Location5_Motor));
  delay(400);

  Open();
  delay(300);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(500);

  Location_inside();
  delay(500);
}*/
void zcq_put_color2(char color,int index)
{
  //motor.write(Location2_Motor,sizeof(Location2_Motor));
  //delay(500);
  Location_inside();
  switch(color){
  case '1':{
    Location_redplate();
    if(index==0||index==4);
    else if(Data_scan[index-1]=='2')To_cjg_green2redround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2redround();
    break;
  }
  case '2':{
    Location_greenplate();
    if(index==0||index==4)To_cjg_red2greenround();
    else if(Data_scan[index-1]=='1')To_cjg_red2greenround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2greenround();
    break;
  }
  case '3':{
    Location_blueplate();
    if(index==0||index==4)To_cjg_red2blueround();
    else if(Data_scan[index-1]=='1')To_cjg_red2blueround();
    else if(Data_scan[index-1]=='2')To_cjg_green2blueround();
    break;
    }
  }
  delay(1000);
  motor.write(Location3_Motor,sizeof(Location3_Motor));
  delay(500);

  Catch();
  delay(300);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(50);

  Location_outside();
  delay(500);

  motor.write(Location5_Motor,sizeof(Location5_Motor));
  delay(400);

  Open_take_area();
  delay(300);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(50);

  Location_inside();
  delay(100);
}
////////////////////////
//在粗加工区夹取物料
void cjg_catch_color_1(int color,int index)//123 312
{
  //motor.write(Location2_Motor,sizeof(Location2_Motor));
  //delay(500);
  // Location_outside();
  // switch(color){
  // case '1':{
  //   Location_redplate();
  //   if(index==0||index==4){
  //     if(Data_scan[2]=='1');
  //     else if(Data_scan[2]=='2')To_cjg_green2redround();
  //     else if(Data_scan[2]=='3')To_cjg_blue2redround();
  //   }
  //   else if(Data_scan[index-1]=='2')To_cjg_green2redround();
  //   else if(Data_scan[index-1]=='3')To_cjg_blue2redround();
  //   break;
  // }
  // case '2':{
  //   Location_greenplate();
  //   if(index==0||index==4){
  //     if(Data_scan[2]=='1')To_cjg_red2greenround();
  //     else if(Data_scan[2]=='2');
  //     else if(Data_scan[2]=='3')To_cjg_blue2greenround();
  //   }
  //   else if(Data_scan[index-1]=='1')To_cjg_red2greenround();
  //   else if(Data_scan[index-1]=='3')To_cjg_blue2greenround();
  //   break;
  // }
  // case '3':{
  //   Location_blueplate();
  //   if(index==0||index==4){
  //     if(Data_scan[2]=='1')To_cjg_red2blueround();
  //     else if(Data_scan[2]=='2')To_cjg_green2blueround();
  //     else if(Data_scan[2]=='3');
  //   }
  //   else if(Data_scan[index-1]=='1')To_cjg_red2blueround();
  //   else if(Data_scan[index-1]=='2')To_cjg_green2blueround();
  //   break;
  //   }
  
    /*Location_blueplate();
    if(index==0||index==4){
      switch(Data_scan[6])
      {
        case '1':To_cjg_red2blueround();break;
        case '2':To_cjg_green2blueround();break;
      }
      
    }
    else if(Data_scan[index-1]=='1')To_cjg_red2blueround();
    else if(Data_scan[index-1]=='2')To_cjg_green2blueround();
    break;
    }
  }*/
    Location_outside();
  switch(color){
  case '1':{
    Location_redplate();
    if(index==0||index==4)To_cjg_green2redround();
    else if(Data_scan[index-1]=='2')To_cjg_green2redround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2redround();
    break;
  }
  case '2':{
    Location_greenplate();
    if(index==0||index==4);
    else if(Data_scan[index-1]=='1')To_cjg_red2greenround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2greenround();
    break;
  }
  case '3':{
    Location_blueplate();
    if(index==0||index==4)To_cjg_green2blueround();
    else if(Data_scan[index-1]=='1')To_cjg_red2blueround();
    else if(Data_scan[index-1]=='2')To_cjg_green2blueround();
    break;
    }
  }
  delay(200);
  delay(1000);
  motor.write(Location1_Motor,sizeof(Location1_Motor));
  delay(1000);

  Catch();
  delay(500);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(1000);

  Location_inside();
  delay(1000);

  motor.write(Location3_Motor,sizeof(Location3_Motor));
  delay(600);

  Open();
  delay(500);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(500);

  //Location_outside();
  //delay(500);
}
////////////////////////
//第二轮任务在粗加工区夹取物料
void cjg_catch_color_2(int color,int index)
{
  //motor.write(Location2_Motor,sizeof(Location2_Motor));
  //delay(500);
  Location_outside();
  switch(color){
  case '1':{
    Location_redplate();
    if(index==0||index==4){
      if(Data_scan[6]=='1');
      else if(Data_scan[6]=='2')To_cjg_green2redround();
      else if(Data_scan[6]=='3')To_cjg_blue2redround();
    }
    else if(Data_scan[index-1]=='2')To_cjg_green2redround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2redround();
    break;
  }
  case '2':{
    Location_greenplate();
    if(index==0||index==4){
      if(Data_scan[6]=='1')To_cjg_red2greenround();
      else if(Data_scan[6]=='2');
      else if(Data_scan[6]=='3')To_cjg_blue2greenround();
    }
    else if(Data_scan[index-1]=='1')To_cjg_red2greenround();
    else if(Data_scan[index-1]=='3')To_cjg_blue2greenround();
    break;
  }
  case '3':{
    Location_blueplate();
    if(index==0||index==4){
      if(Data_scan[6]=='1')To_cjg_red2blueround();
      else if(Data_scan[6]=='2')To_cjg_green2blueround();
      else if(Data_scan[6]=='3');
    }
    else if(Data_scan[index-1]=='1')To_cjg_red2blueround();
    else if(Data_scan[index-1]=='2')To_cjg_green2blueround();
    break;
    }
    /*Location_blueplate();
    if(index==0||index==4){
      switch(Data_scan[6])
      {
        case '1':To_cjg_red2blueround();break;
        case '2':To_cjg_green2blueround();break;
      }
      
    }
    else if(Data_scan[index-1]=='1')To_cjg_red2blueround();
    else if(Data_scan[index-1]=='2')To_cjg_green2blueround();
    break;
    }*/
  }
  delay(400);
  motor.write(Location1_Motor,sizeof(Location1_Motor));
  delay(500);

  Catch();
  delay(300);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(200);

  Location_inside();
  delay(500);

  motor.write(Location3_Motor,sizeof(Location3_Motor));
  delay(200);

  Open();
  delay(200);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(50);
  //Location_outside();
  //delay(1000);
}







void move_catch()
{
  data[0]=9;
  openmv.begin(115200);
  for(int i=0;i<2;i++)
  openmv.write(data[i]);
  delay(500);
  for(int z=0;z<20;z++)
  {
    get_openmv();
    delay(50);
    //if(openmv_data==)
  
  }


}










void put()
{
  Location_inside();
  delay(1000);
  Open_take_area();
  delay(1000);
  motor.write(Location3_Motor,sizeof(Location3_Motor));
  delay(1000);

  Catch();
  delay(500);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(500);

  Location_outside();
  delay(1000);

  motor.write(Location_put_Motor_js,sizeof(Location_put_Motor_js));
  //motor.write(Location4_Motor,sizeof(Location4_Motor));
  delay(2500);

  Open_take_area();
  delay(500);

  motor.write(Location2_Motor,sizeof(Location2_Motor));
  delay(1000);
  Location_inside();
}