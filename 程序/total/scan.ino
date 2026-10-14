void Get_scan()
{
  while (Scan_TJC.available() > 0) {
    char incomingChar = Scan_TJC.read();  // 读取一个字符
    // 如果接收到换行符或数据长度达到预期，则认为一条数据接收完成
    if (incomingChar == '\n' || dataIndex >= dataLength) {
      Data_scan[dataIndex] = '\0';  // 添加字符串结束符
      processData(Data_scan);  // 处理接收到的数据
      dataIndex = 0;  // 重置索引，准备接收下一条数据
    } else {
      Data_scan[dataIndex] = incomingChar;  // 存储接收到的字符
      dataIndex++;  // 增加索引
    }
    flag=1;
  }
}
void processData(char* data) {
  // 在这里处理接收到的数据
  Serial.print("Received data: ");
  Serial.println(data);
  // 你可以在这里对数据进行进一步处理，比如解析、计算等
}