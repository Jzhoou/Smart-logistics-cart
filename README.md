# 智能物流搬运小车下位机控制系统

这是一个团队协作完成的智能物流小车项目。本仓库重点展示我负责的**下位机电控部分**：Arduino 端的任务调度、底盘与执行机构控制，以及与扫码器、串口屏、HWT101 姿态传感器和 OpenMV 视觉模块之间的串口通信。机械结构、上位机或其他团队成员负责的内容不作为本仓库的个人贡献声明。

## 系统概览

主控程序采用 Arduino 多文件工程组织。`total.ino` 完成外设初始化并串联整车任务；其余 `.ino` 文件按传感、通信、运动和机械动作拆分。OpenMV 端运行 MicroPython 脚本，通过颜色阈值提取色块，把颜色类别与目标偏移量封装为串口数据交给 Arduino。

主要模块包括：

- **Arduino 主控与任务状态流**：接收并校验扫码任务，协调导航、抓取、颜色识别、放置和返回动作。
- **HWT101 姿态反馈**：初始化传感器、解析数据帧并获得航向角，用于若干方向校正动作。
- **OpenMV / MicroPython 视觉**：进行红、绿、蓝目标识别，计算目标相对画面中心的偏移，并与 Arduino 通信。
- **扫码任务解析**：接收形如 `123+321` 的任务字符串，检查颜色编号与分隔符后供两轮任务使用。
- **串口屏交互**：初始化显示页面，并把已接收的任务字符串发送到屏幕显示。
- **舵机与机械爪**：控制物料盘、机械爪伸缩机构和夹爪的预设位置，完成取放动作。
- **步进电机 / 底盘电机命令**：按驱动器协议组装速度、方向、位置、停止和多机同步命令，实现直行、横移、转向及区域间运动。

## 任务流程

整车控制逻辑可以概括为：

1. 小车前往扫码区域，读取并解析任务序列。
2. 前往取料区域，驱动舵机与机械爪抓取物料。
3. 通过 OpenMV 识别物料或目标色环颜色，并读取横纵方向偏差。
4. 按扫码任务指定的红、绿、蓝顺序进行移动、对准与分类处理。
5. 将处理后的物料送往暂存区，执行相应放置动作。
6. 完成一轮后返回取料区继续任务，最终按程序路线返回终点。

程序中的部分动作采用预先编排的路径与时序，视觉偏移和 HWT101 航向角用于特定环节的辅助校正。

## 文件地图

| 文件 | 作用 |
| --- | --- |
| `total.ino` | Arduino 工程入口；定义串口、全局状态和整车任务流程 |
| `Motor.ino` | 底盘电机协议命令、方向动作、区域间路线和姿态/视觉微调 |
| `HWT101.ino` | HWT101 初始化、数据帧接收校验与航向角解析 |
| `scan.ino` | 扫码字符串接收、终止符处理与任务数据解析 |
| `screen_Serial.ino` | 串口屏初始化与任务文本显示 |
| `servo.ino` | 物料盘、伸缩机构和夹爪舵机控制 |
| `Step_catch.ino` | 取放步骤、颜色顺序判断及加工区/暂存区动作编排 |
| `openmv.ino` | Arduino 端 OpenMV 数据包接收与偏移量解析 |
| `openmv.py` | OpenMV 端 MicroPython 颜色识别和串口数据发送 |

## 硬件与软件环境

- Arduino 兼容主控，使用多个硬件串口及 `SoftwareSerial`
- Arduino Servo 库
- HWT101 姿态传感器
- OpenMV 摄像头及其 MicroPython 固件
- 扫码模块、串口屏
- 舵机机械爪、物料盘机构和支持串口命令的电机驱动系统

使用时需先根据实际接线确认各串口、舵机引脚和波特率，再分别部署 Arduino 工程与 `openmv.py`。当前源码保留了车辆联调阶段的动作参数和流程编排，适合结合实车逐段验证，而不应直接视为任意底盘的通用参数。

## 标定说明

代码中的行驶距离、转角、脉冲数、舵机位置、延时、图像 ROI、颜色阈值及视觉中心偏移均依赖原车的机械尺寸、相机安装、光照、电机与驱动器设置。这些数值必须在目标车辆上重新标定。更换底盘、轮胎、减速比、摄像头位置或现场照明后，应从低速和短距离测试开始，逐项确认方向、限位和安全间隙。

## English summary

This team project implements an intelligent logistics cart. This repository highlights my contribution to the **low-level electrical control system**: Arduino-side task orchestration, chassis and actuator control, and serial integration with a barcode/QR scanner, display, HWT101 attitude sensor, and an OpenMV camera.

The OpenMV MicroPython script detects red, green, and blue targets and reports classification and image offsets. The Arduino program parses the scanned task, coordinates pickup, color-based handling, temporary storage, and return movements, and controls the servo-driven gripper and motor drivers. Motion distances, angles, pulse counts, servo positions, ROIs, and color thresholds are specific to the original vehicle and require recalibration for other hardware or environments.
