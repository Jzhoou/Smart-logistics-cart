void get_openmv() {

  // 检查是否有可用的串口数据

  
  if (openmv.available() > 0) {
    // 读取一个字节
    byte incomingByte = openmv.read();
    Serial.print("Raw HEX: ");
    Serial.println(incomingByte, HEX);  // 打印所有收到的字

    // 判断是否是包头
    if (incomingByte == PACKET_HEADER) {
      // 开始接收数据
      bool packetComplete = false;
      byte packetData[64]; // 假设数据包最大长度为64字节
      int packetIndex = 0;

      // 等待接收完整的数据包
      while (!packetComplete) {
        if (openmv.available() > 0) {
          incomingByte = openmv.read();

          // 判断是否是包尾
          if (incomingByte == PACKET_FOOTER) {
            packetComplete = true; // 数据包接收完成
          } else {
            // 存储数据
            packetData[packetIndex] = incomingByte;
            packetIndex++;

            // 防止数据溢出
            if (packetIndex >= 64) {
              packetComplete = true; // 强制结束
            }
          }
        }
      }

      // 处理接收到的数据
      if (packetComplete) {
        //Serial.println("Received a complete packet:");
        for (int i = 0; i < packetIndex; i++) {
          //Serial.print(packetData[i], HEX); // 以16进制打印数据
          //Serial.print(" ");
          
        }
        openmv_data=(int)packetData[3]+'0';
        x_adjust=(int)packetData[0];
        y_adjust=(int)packetData[1];
        Serial.println(x_adjust);
        Serial.println(y_adjust);
        openmv_flag=1;
        //Serial.println();
        //Serial.println(openmv_data);
        
      }
    }
  }
      while (openmv.available() > 0) {
    openmv.read();}
}