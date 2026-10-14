void HWT101_Init()
{
  HWT101.write(unlock_register, sizeof(unlock_register));
  delay(120);  // 略大于数据手册要求的最小间隔
  HWT101.write(reset_z_axis, sizeof(reset_z_axis));
  delay(120);
  HWT101.write(save_settings, sizeof(save_settings));
  delay(120);
  HWT101.flush();  // 清空可能存在的残余数据
  delay(200);
}


void Get_angle()
{
  while (HWT101.available()) {
    uint8_t c = HWT101.read();
    
    switch(state) {
      case WAIT_HEADER1:
        if(c == 0x55) { 
          state = WAIT_HEADER2;
          packet[0] = c;
        }
        break;
        
      case WAIT_HEADER2:
        if(c == 0x52 || c == 0x53) {  // 支持两种数据包类型
          state = READING_DATA;
          packet[1] = c;
          idx = 2;
        } else {
          state = WAIT_HEADER1;  // 包头校验失败
        }
        break;
        
      case READING_DATA:
        packet[idx++] = c;
        if(idx >= sizeof(packet)) {
          processPacket(packet);
          state = WAIT_HEADER1;
        }
        break;
    }
  }
}
// 数据包处理函数
void processPacket(const uint8_t* pkt) {
  uint8_t sum = 0;
  for(int i=0; i<10; i++) sum += pkt[i];  // 计算校验和
  
  if(sum != pkt[10]) {
    Serial.println("CRC Error");
    return;
  }

  if(pkt[0]==0x55 && pkt[1]==0x52) {      // 角速度包
    //int16_t Wy = (pkt[5]<<8) | pkt[4];    // 注意数据字节顺序
    //int16_t Wz = (pkt[7]<<8) | pkt[6];
    
    //float fWy = Wy / 32768.0 * 2000.0;    // 转换为物理量
    //float fWz = Wz / 32768.0 * 2000.0;
    
    //Serial.print("Wy:"); Serial.print(fWy);
    //Serial.print(" Wz:"); Serial.println(fWz);
    
  } else if(pkt[0]==0x55 && pkt[1]==0x53) { // 欧拉角包
    int16_t Yaw = ((pkt[7]<<8) | pkt[6]);     // 注意数据字节顺序
    currentYaw = Yaw / 32768.0 * 180.0;
    //int16_t V   = (pkt[9]<<8) | pkt[8];
    
    //float fYaw = Yaw / 32768.0 * 180.0;
    //float fV   = V / 32768.0 * 2000.0;
    
    Serial.print("Yaw:"); Serial.println(currentYaw);
    HWT101_flag=1;
    //Serial.print(" V:"); Serial.println(fV);
  }
}