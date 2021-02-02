# time和datetime包使用

## time包获得的是时间戳
`time` 包主要使用四个函数，`time.time()`、 `time.localtime()`和 `time.sleep()` 以及静态方法 `time.strftime()`
- `time.time()` 用于返回时间戳，以秒为单位。后续可以创建时间实例
- `time.localtime()` 用于返回当前时间戳对应的时间实例，后续可以用于格式化时间
- `time.sleep()` 用于设定程序的等待时间，以秒为单位
- `time.strftime` 用于格式化时间，通常的格式化字符串为 `"%Y-%m-%d %H:%M:%S"`


```python
import time

time_now = time.time()
print('时间戳：', time_now)
time_now = time.localtime()
print('时间实例', time_now)

print('休眠5秒，请等待...')
time.sleep(5)

time_format = "%Y-%m-%d %H:%M:%S"
time_now = time.strftime(time_format, time.localtime()) 
print('格式化时间实例：', time_now)
```

    时间戳： 1612251976.7267215
    时间实例 time.struct_time(tm_year=2021, tm_mon=2, tm_mday=2, tm_hour=15, tm_min=46, tm_sec=16, tm_wday=1, tm_yday=33, tm_isdst=0)
    休眠5秒，请等待...
    格式化时间实例： 2021-02-02 15:46:21
    

## datetime包获得时间日期
`datetime` 包中主要使用两个模块， `datetime` 模块和 `timedelta` 模块

### datetime.datetime 实例属性及常用方法：
```python
datetime.year
datetime.month
datetime.day
datetime.hour
datetime.minute
datetime.second
datetime.strftime(format) # 按照 format 进行格式化输出
```

### datetime的主要静态方法
```python
datetime.today() # 当前时间，localtime
datetime.now()   # 当前时间默认 localtime
datetime.strptime(date_string, format) # 给定时间格式解析字符串
```


```python
from datetime import datetime, timedelta
time_now = datetime.now()    # 这里获得的时间会包含微秒，因此会有小数
print(time_now)
time_string = time_now.strftime('%Y-%m-%d %H:%M:%S')
print(time_string)
```

    2021-02-02 15:52:04.099112
    2021-02-02 15:52:04
    

### timedelta 主要用于计算时间跨度
注意这里运算的两个变量都是时间类型，而不能是格式化字符串（如 `time_string`）


```python
delta = timedelta(hours=1)
print(time_now + delta)
print(time_now - delta)
```

    2021-02-02 16:52:04.099112
    2021-02-02 14:52:04.099112
    
