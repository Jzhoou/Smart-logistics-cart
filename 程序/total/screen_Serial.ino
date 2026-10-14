void TJC_Init(){
   //因为串口屏开机会发送88 ff ff ff,所以要清空串口缓冲区
   while (Scan_TJC.read() >= 0); //清空串口缓冲区
   Scan_TJC.print("page main\xff\xff\xff"); //发送命令让屏幕跳转到main页面
   nowtime = millis(); //获取当前已经运行的时间
   }
void Send2Screen()
{
char str[100];
   if (millis() >= nowtime + 500) {
     nowtime = millis(); //获取当前已经运行的时间
     //用sprintf来格式化字符串，给t0的txt属性赋值
     sprintf(str, "t0.txt=\"%s\"\xff\xff\xff", Data_scan);//把字符串发送出去
     Scan_TJC.print(str);
     delay(50);  //延时50ms,才能看清楚点击效果
   }
}