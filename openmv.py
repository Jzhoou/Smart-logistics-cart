#库文件引用
import sensor, image, ustruct,time,utime,os,  math, uos, gc
from pyb import UART
from pyb import LED
from pyb import Pin, Timer
from ulab import numpy as np
#摄像头基本初始化
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
#sensor.skip_frames(time = 2000)
sensor.set_auto_gain(True)
clock = time.clock()

#tim = Timer(4, freq=500)

#Block_Roi=[70, 10, 190, 230] #用于色块寻找的感兴趣区
Block_Roi=[70, 30, 160, 160] #用于色块寻找的感兴趣区
roi = (130, 40, 100, 100)  # (x, y, w, h)
data=[0,0]
#地面色环调节
red_circle_threshold =(0, 59, 86, 11, 31, -19)
green_circle_threshold =(100, 0, -15, -128, 1, 127)
blue_circle_threshold =(9, 50, 56, -75, -14, -98)
gray_threshold=[(100,255)]


#转盘色块的阈值变量
thresholds = [(100, 0, 6, 59, -3, 62), # red_thresholds
              (42, 95, -86, -28, -30, 54), # green_thresholds
              (100, 0, -128, 127, -13, -128),# blue_thresholds
              (18, 38, -8, -128, 3, 127)] #dark green_thresholds



#函数定义
#比较色块大小函数

#二维码串口发送函数
uart = UART(3, 115200, timeout_char=1000)

#色环识别发送函数
def send_data_Colorround(Color_task):
     global uart;
     data = ustruct.pack("<bbbbbbbbbb",
                  0x03,
                  int(Color_task),
                  0xFE,
                  )
     uart.write(data);

#色环色块矫正发送函数
def send_data_adjustment_Colorround(x_dir,y_dir):
     global uart;
     data = ustruct.pack("<bbbbbbbbbb",
                  0xff,
                  int(x_dir),
                  int(y_dir),
                  0xFE)
     uart.write(data);
     #print(y_dir,x_dir)
#色块发送函数


def send(y_distance,x_distance):
     global uart;
     data = ustruct.pack("<bbbbbbbbbb",
                   #一号摄像头
                  0xff,  #任务一代码
                  int(y_distance),
                  int(x_distance),
                  0xFE,
                 )
     uart.write(data);

def send2(y_distance,x_distance,code,code1):
     global uart;
     data = ustruct.pack("<bbbbbbbbbb",
                   #一号摄像头
                  0xff,  #任务一代码
                  int(y_distance),
                  int(x_distance),
                  int(code),
                  int(code1),
                  0xFE,
                 )
     uart.write(data);
def send1(y_distance,x_distance,code):
  global uart;
  data = ustruct.pack("<bbbbbbbbbb",
                #一号摄像头
               0xff,  #任务一代码
               int(y_distance),
               int(x_distance),
               int(code),
               0xFE,
              )
  uart.write(data);

def find_max_circle(circles):
    max_size = 0
    for circle in circles:
        if circle.r()>max_size:
            max_circle = circle
            max_size = circle.r()
    return max_circle

def ring(a):
    sensor.set_framesize(sensor.QQVGA)
    sum_x = 0
    sum_y = 0
    count = 0

    for _ in range(23):  # 循环50次
        if a == "r":
            img = sensor.snapshot()
            img.lens_corr(1.0)
            #circles = img.find_circles(x_stride=3, y_stride=1, threshold=2000, x_margin=10, y_margin=10, r_margin=10,
            #                           r_min=10, r_max=30, r_step=2)
            circles = img.find_circles( threshold=1430, r_margin=45, x_margin=40, y_margin=40,
                                       r_min=1, r_max=18)
            if circles:
                max_circle = find_max_circle(circles)   # 找到最大的圆
                area = (max_circle.x()-max_circle.r(), max_circle.y()-max_circle.r(), 2*max_circle.r(), 2*max_circle.r())
                blob = img.find_blobs([red_circle_threshold], roi=area)  # 目标颜色
                if blob:
                    for b in blob:
                        sum_x += max_circle.x()
                        sum_y += max_circle.y()
                        count += 1
                        img.draw_circle(max_circle.x(), max_circle.y(), max_circle.r(), color=(250, 0, 0))
                        img.draw_cross(max_circle.x(), max_circle.y())

        elif a == "g":
            img = sensor.snapshot().lens_corr(1.0)
            #circles = img.find_circles(x_stride=2, y_stride=2, threshold=1130, x_margin=45, y_margin=30, r_margin=25,
            #                           r_min=10, r_max=20, r_step=1)
            circles = img.find_circles( threshold=1430, r_margin=45, x_margin=30, y_margin=30,
                                       r_min=1, r_max=20)
            if circles:
                max_circle = find_max_circle(circles)   # 找到最大的圆
                area = (max_circle.x()-max_circle.r(), max_circle.y()-max_circle.r(), 2*max_circle.r(), 2*max_circle.r())
                blob = img.find_blobs([green_circle_threshold], roi=area)  # 目标颜色
                if blob:
                    for b in blob:
                        sum_x += max_circle.x()
                        sum_y += max_circle.y()
                        count += 1
                        img.draw_circle(max_circle.x(), max_circle.y(), max_circle.r(), color=(250, 0, 0))
                        img.draw_cross(max_circle.x(), max_circle.y())

        elif a == "b":
            img = sensor.snapshot().lens_corr(1.0)
            circles = img.find_circles(x_stride=4, y_stride=1, threshold=2050, x_margin=25, y_margin=25, r_margin=35,
                                       r_min=10, r_max=30, r_step=2)
            if circles:
                max_circle = find_max_circle(circles)   # 找到最大的圆
                area = (max_circle.x()-max_circle.r(), max_circle.y()-max_circle.r(), 2*max_circle.r(), 2*max_circle.r())
                blob = img.find_blobs([blue_circle_threshold], roi=area)  # 目标颜色
                if blob:
                    for b in blob:
                        sum_x += max_circle.x()
                        sum_y += max_circle.y()
                        count += 1
                        img.draw_circle(max_circle.x(), max_circle.y(), max_circle.r(), color=(250, 0, 0))
                        img.draw_cross(max_circle.x(), max_circle.y())
        gc.collect()

    if count > 0:  # 确保至少识别到一个圆环
        avg_x = sum_x // count
        avg_y = sum_y // count
        if a == "r":
            send_data_adjustment_Colorround(avg_x, avg_y)  # 发送红色数据
            print(avg_x, avg_y)
        elif a == "g":
            send_data_adjustment_Colorround(avg_x, avg_y)  # 发送绿色数据
            print(avg_x, avg_y)#正中心坐标85，44
        elif a == "b":
            send_data_adjustment_Colorround(avg_x, avg_y)  # 发送蓝色数据
    else:
        print("No circles found.")


while(True):
    img = sensor.snapshot()
    clock.tick()

    if uart.any():
        data = uart.read(2)
        print(data)
    data=[5,1]
    #if data[0] == 1 or data[0] == 2 or data[0] == 3:#任务一物料盘区，直接根据任务颜色顺序夹取（仅识别颜色）
     #   sensor.set_framesize(sensor.QVGA)
      #  img = sensor.snapshot()
       # img.lens_corr(1.0)
        #blobs = img.find_blobs([thresholds[data[0] - 1]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)
        #for blob in blobs:
         #   img.draw_cross(blob.cx(), blob.cy())
          #  #print(blob.cx(), blob.cy())
          #  #if (blob.cx() - 170 < 10) and (blob.cy() - 90 < 17 )and (blob.cx() - 170 > -10) and (blob.cy() - 90 > -20):#目标色物料到达机械爪下
           # if (blob.cx() - 170 < 80) and (blob.cy() - 90 < 80 )and (blob.cx() - 170 > -80) and (blob.cy() - 90 > -80):#目标色物料到达机械爪下
            #    send_data_Colorround(data[0])#发送指令给下位机准备抓取
             #   print(blob.cx(), blob.cy())
              #  print(data[0])
    if data[0] == 5:#粗加工区：返回r红色圆环平均中心坐标供调整位置
        ring("r")
    #if data[0] == 6 or data[0] == 7 or data[0] == 8:###############任务2在物料盘根据2.1物料中心坐标定位
     #   sensor.set_framesize(sensor.QVGA)
      #  img = sensor.snapshot()
       # img.lens_corr(1.0)
        #blobs = img.find_blobs([thresholds[data[0] - 6]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)
        #for blob in blobs:
         #   img.draw_cross(blob.cx(), blob.cy())
         #   send(blob.cx(), blob.cy())
          #  print(blob.cx(), blob.cy())
    #if  data[0] == 21 or data[0] == 22 or data[0] == 23:#任务2物料盘区，直接根据任务颜色顺序夹取（仅识别颜色）
     #   sensor.set_framesize(sensor.QVGA)
      #  img = sensor.snapshot()
       # img.lens_corr(1.0)
        #blobs = img.find_blobs([thresholds[data[0] - 21]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)
        #for blob in blobs:
         #   img.draw_cross(blob.cx(), blob.cy())
          #  print(blob.cx(), blob.cy())
           # if (blob.cx() - 125 < 60) and (blob.cy() - 108 < 60) and (blob.cx() - 125 > -60) and (blob.cy() - 108 > -60):
            #    send_data_Colorround(data[0])
             #   print(data[0])
    if data[0] == 9:
        sensor.set_framesize(sensor.QVGA)
        img = sensor.snapshot()
        img.lens_corr(1.0)
        blobs_1 = img.find_blobs([thresholds[0]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)  # 找红色
        blobs_2 = img.find_blobs([thresholds[1]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)  # 找绿色
        blobs_3 = img.find_blobs([thresholds[2]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)  # 找蓝色
        blobs_4 = img.find_blobs([thresholds[3]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)  # 找深绿色
        if blobs_1:
            for blob_1 in blobs_1:  # 使用不同的变量名
                img.draw_cross(blob_1.cx(), blob_1.cy())
                #if (blob_1.cx() - 170 < 30) and (blob_1.cy() - 90 < 20) and (blob_1.cx() - 170 > -40) and (blob_1.cy() - 90 > -25):
                if (blob_1.cx() - 170 < 70) and (blob_1.cy() - 90 < 70) and (blob_1.cx() - 170 > -75) and (blob_1.cy() - 90 > -70):
                    send2(blob_1.cx(), blob_1.cy(),data[0],1)
                    print(blob_1.cx(), blob_1.cy())
        if blobs_2:
            for blob_2 in blobs_2:  # 使用不同的变量名
                img.draw_cross(blob_2.cx(), blob_2.cy())
                #if (blob_2.cx() - 170 < 30) and (blob_2.cy() - 90 < 20) and (blob_2.cx() - 170 > -40) and (blob_2.cy() - 90 > -25):
                if (blob_2.cx() - 170 < 70) and (blob_2.cy() - 90 < 70) and (blob_2.cx() - 170 > -75) and (blob_2.cy() - 90 > -70):
                    send2(blob_2.cx(), blob_2.cy(),data[0],2)
                    print(blob_2.cx(), blob_2.cy())
        if blobs_3:
            for blob_3 in blobs_3:  # 使用不同的变量名
                img.draw_cross(blob_3.cx(), blob_3.cy())
                #if (blob_3.cx() - 170 < 30) and (blob_3.cy() - 90 < 20) and (blob_3.cx() - 170 > -40) and (blob_3.cy() - 90 > -25):
                if (blob_3.cx() - 170 < 70) and (blob_3.cy() - 90 < 70) and (blob_3.cx() - 170 > -75) and (blob_3.cy() - 90 > -70):
                    send2(blob_3.cx(), blob_3.cy(),data[0],3)
                    print(blob_3.cx(), blob_3.cy())
        if blobs_4:
            for blob_4 in blobs_4:  # 使用不同的变量名
                img.draw_cross(blob_4.cx(), blob_4.cy())
                #if (blob_2.cx() - 170 < 30) and (blob_2.cy() - 90 < 20) and (blob_2.cx() - 170 > -40) and (blob_2.cy() - 90 > -25):
                if (blob_4.cx() - 170 < 70) and (blob_4.cy() - 90 < 70) and (blob_4.cx() - 170 > -75) and (blob_4.cy() - 90 > -70):
                    send2(blob_4.cx(), blob_4.cy(),data[0],2)
                    print(blob_4.cx(), blob_4.cy())
    #if data[0] == 4:
    #    sensor.set_framesize(sensor.QVGA)
     #   img = sensor.snapshot()
     #   img.lens_corr(1.0)
     #  blobs_1 = img.find_blobs([thresholds[0]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)  # 找红色
     #   blobs_2 = img.find_blobs([thresholds[1]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)  # 找绿色
     #   blobs_3 = img.find_blobs([thresholds[2]], roi=Block_Roi, pixels_threshold=2025, area_threshold=1600, merge=True)  # 找蓝色
      #  if blobs_1 and data[1]!=1:
      #      for blob_1 in blobs_1:  # 使用不同的变量名
      #          img.draw_cross(blob_1.cx(), blob_1.cy())
      #          if (blob_1.cx() - 125 < 40) and (blob_1.cy() - 108 < 40) and (blob_1.cx() - 125 > -40) and (blob_1.cy() - 108 > -40):
     #               send1(blob_1.cx(), blob_1.cy(),data[0])
        #            print(blob_1.cx(), blob_1.cy(),data[0])
       # if blobs_2 and data[1]!=2:
      #      for blob_2 in blobs_2:  # 使用不同的变量名
          #      img.draw_cross(blob_2.cx(), blob_2.cy())
         #       if (blob_2.cx() - 125 < 40) and (blob_2.cy() - 108 < 40) and (blob_2.cx() - 125 > -40) and (blob_2.cy() - 108 > -40):
           #         send1(blob_2.cx(), blob_2.cy(),data[0])
            #        print(blob_2.cx(), blob_2.cy(),data[0])
    #    if blobs_3 and data[1]!=3:
     #       for blob_3 in blobs_3:  # 使用不同的变量名
      #          img.draw_cross(blob_3.cx(), blob_3.cy())
       #         if (blob_3.cx() - 125 < 40) and (blob_3.cy() - 108 < 40) and (blob_3.cx() - 125 > -40) and (blob_3.cy() - 108 > -40):
        #            send1(blob_3.cx(), blob_3.cy(),data[0])
         #           print(blob_3.cx(), blob_3.cy(),data[0])


