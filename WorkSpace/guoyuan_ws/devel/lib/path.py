#!/usr/bin/env python
# encoding: utf-8

import math
#from typing_extensions import Self
import numpy as np
CONSTANTS_RADIUS_OF_EARTH = 6378137. 

def GPStoXY(lat, lon, ref_lat, ref_lon):#根据gps坐标求距离的函数
        # input GPS and Reference GPS in degrees
        # output XY in meters (m) X:North Y:East
        lat_rad = math.radians(lat)
        lon_rad = math.radians(lon)
        ref_lat_rad = math.radians(ref_lat)
        ref_lon_rad = math.radians(ref_lon)

        sin_lat = math.sin(lat_rad)
        cos_lat = math.cos(lat_rad)
        ref_sin_lat = math.sin(ref_lat_rad)
        ref_cos_lat = math.cos(ref_lat_rad)

        cos_d_lon = math.cos(lon_rad - ref_lon_rad)

        arg = np.clip(ref_sin_lat * sin_lat + ref_cos_lat * cos_lat * cos_d_lon, -1.0, 1.0)
        c = math.acos(arg)

        k = 1.0
        if abs(c) > 0:
            k = (c / math.sin(c))

        x = float(k * (ref_cos_lat * sin_lat - ref_sin_lat * cos_lat * cos_d_lon) * CONSTANTS_RADIUS_OF_EARTH)
        y = float(k * cos_lat * math.sin(lon_rad - ref_lon_rad) * CONSTANTS_RADIUS_OF_EARTH)

        return x, y

def path_generate():
    f2=open('/home/itcast/workingSpaceSet/guoyuan_ws/devel/lib/initPoints.txt','r')
    line1=f2.readline()
    counts=1
    while line1:
        if counts>=9:
            break
        line1=float(f2.readline())
        counts+=1
    line2=float(f2.readline())
   # print(round(float(line1),0))
   # print(round(float(line2),0))
    n_x=30             # x轴点的个数，该值越大越精细
    n_y=20              # y轴点的个数，该值越大越精细
    width=100           #果园宽度
    length=round(float(line2 - 30), 0)          #果园长度
    # path_width=10       #陇间距 -----固定法
    # path_length=80      #陇长度
    path_width=5      #陇间距  -----txt文档读取
    path_length=round(float(line1) - 6,0)      #陇长度
    y_str=[0]*n_y       #y轴上是100个点
    x_str=[0]*n_x       #x轴上是300个点
    turn=int(round(length/path_width-1, 0))
    #print(turn)
    for i in range(n_y):
        y_str[i]=round(i*path_length/n_y,4)
    for i in range(n_x):
        x_str[i]=round(i*(length-path_width)/n_x,4)
    f=open('/home/itcast/workingSpaceSet/guoyuan_ws/devel/lib/path.txt','w')   #相对路径都要改一下
    for k in range(turn):
        if (k % 2) == 0:
            for i in range(n_y):        #所有y的点      
                f.write(str(x_str[k*int(round(n_x/turn))]))
                f.write('\n')
                f.write(str(y_str[i]))    #第一条竖线
                f.write('\n')
            for i in range(int(round((n_x/turn)))):  #x的一段点
                f.write(str(x_str[k*int(round(n_x/turn))+i]))
                f.write('\n')
                f.write(str(y_str[n_y-1]))  #第二条横线
                f.write('\n')
        else:
            for i in range(n_y):
                f.write(str(x_str[k*int(round(n_x/turn))]))
                f.write('\n')
                f.write(str(y_str[n_y-1-i]))  #第三条竖线
                f.write('\n')
            for i in range(int(round(n_x/turn))):
                f.write(str(x_str[k*int(round(n_x/turn))+i]))
                f.write('\n')
                f.write(str(y_str[0]))         #第四条横线
                f.write('\n')
    f.close()
    print("xy_path:ok")

if __name__ == '__main__':
    path_generate()
    #print(GPStoXY(31.3252,121.405,31.325,121.405))
