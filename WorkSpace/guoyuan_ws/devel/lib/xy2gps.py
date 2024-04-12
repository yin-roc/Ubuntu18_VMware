#!/usr/bin/env python
# encoding: utf-8
import math
#from typing_extensions import Self
import numpy as np
CONSTANTS_RADIUS_OF_EARTH = 6378137.     # meters (m)

def GPStoXY(lat, lon, ref_lat, ref_lon):
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

def XYtoGPS(x, y, ref_lat, ref_lon):
        x_rad = float(x) / CONSTANTS_RADIUS_OF_EARTH
        y_rad = float(y) / CONSTANTS_RADIUS_OF_EARTH
        c = math.sqrt(x_rad * x_rad + y_rad * y_rad)

        ref_lat_rad = math.radians(ref_lat)
        ref_lon_rad = math.radians(ref_lon)

        ref_sin_lat = math.sin(ref_lat_rad)
        ref_cos_lat = math.cos(ref_lat_rad)


        if abs(c) > 0:
            sin_c = math.sin(c)
            cos_c = math.cos(c)

            lat_rad = math.asin(cos_c * ref_sin_lat + (x_rad * sin_c * ref_cos_lat) / c)
            lon_rad = (ref_lon_rad + math.atan2(y_rad * sin_c, c * ref_cos_lat * cos_c - x_rad * ref_sin_lat * sin_c))

            lat = math.degrees(lat_rad)-27.27034
            lon = math.degrees(lon_rad)-89.9192

        else:
            lat = math.degrees(ref_lat)
            lon = math.degrees(ref_lon)

        return lat, lon
def gps_txt():

    # pc file
    file_pc = open('/home/itcast/workingSpaceSet/guoyuan_ws/devel/lib/path.txt') # txt文件所在目录
    data_pc = file_pc.readlines()

    f2=open('/home/itcast/workingSpaceSet/guoyuan_ws/devel/lib/initPoints.txt','r')
    ref_lon_1 = float(f2.readline())
    ref_lat_1 = float(f2.readline())
    print(ref_lon_1)
    print(ref_lat_1)

    opposite_x = []  # x
    opposite_y = []  # y

    for i in range(len(open('/home/itcast/workingSpaceSet/guoyuan_ws/devel/lib/path.txt').readlines())):
        if (i % 2) == 0:
            opposite_x.append(data_pc[i])
        else:
            opposite_y.append(data_pc[i])
    #print(len(opposite_x))
    path_cnt=int(round(len(open('/home/itcast/workingSpaceSet/guoyuan_ws/devel/lib/path.txt').readlines())/2))
    #print(path_cnt)
    gps_x=[0]*path_cnt
    gps_y=[0]*path_cnt
    for i in range(path_cnt-1):
        gps_x[i],gps_y[i]=XYtoGPS(opposite_y[i],opposite_x[i], ref_lon_1, ref_lat_1)##这两个数据是机器人起始位置的gps值，必须由GPS测得给定，因为x，y相对坐标都是以该点为坐标系原点进行计算
    #print(len(gps_x))
    f=open('/home/itcast/workingSpaceSet/guoyuan_ws/devel/lib/gps_path.txt','w')   #相对路径都要改一下
    for i in range(1,len(gps_x)-1):
        f.write(str(gps_y[i]))
        f.write('\n')
        f.write(str(gps_x[i]))   
        f.write('\n')
    f.close()
    print("gpspath:ok")
    return 0

if __name__ == '__main__':
    gps_txt()