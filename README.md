# 前言

**注意：浇水由LED1的亮灭进行模拟**

源码参考：

&nbsp;&nbsp;&nbsp;&nbsp;[步进电机28BYJ-48的驱动程序(stm32f103c8t6)](https://blog.csdn.net/qq_17280755/article/details/78459842)

&nbsp;&nbsp;&nbsp;&nbsp;正点原子按键实验

开发板：正点原子 STM32F103 精英版

语言：C语言

开发环境：Keil5

**开发板**使用了 LED KEY 步进电机28BYJ-48  ULN2003驱动

## 代码下载：

[码云](https://gitee.com/ikaros-521/STM32_28BYJ-48_demo) [GitHub](https://github.com/Ikaros-521/STM32_28BYJ-48_demo)

## 功能介绍：

LED1约1秒1反转。

按KEY0，翻转LED1，电机反转1圈

按KEY1，翻转LED1，电机正转1圈

按KEY_UP，翻转LED1，电机正转半圈

# 参考资料

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210510155935841.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210510160002540.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210510160015101.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210510161941806.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

# 接线

```c
+    —>   5V
-    —>   GND
IN1  —>   PF1
IN2  —>   PF2
IN3  —>   PF3
IN4  —>   PF4
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210510160720782.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

# 效果图

按下KEY0，LED1翻转，电机反转一圈。风车折法参考 [传送门](https://jingyan.baidu.com/article/3aed632ea9e8583011809112.html)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210510161517723.gif#pic_center)
