# f-string使用方法

- f-string用大括号 {} 表示被替换字段，其中直接填入替换内容


```python
name = 'Zeros遇见'
game = '死亡细胞'
food = '苹果'
video = '毛骗'

print(f"{name}正在玩{game}")
```

>     Zeros遇见正在玩死亡细胞
>


## 多行字符串
- 使用"""即可实现字符串换行


```python
message = f"""
{name}一边玩{game}，
一边在youtube上看{video}，
还让老婆削{food}吃。
"""
print(message)
```

>
>     Zeros遇见一边玩死亡细胞，
>     一边在youtube上看毛骗，
>     还让老婆削苹果吃。
>


​    

## 字符串格式(常用)

### `datetime` 时间格式


```python
import datetime
e = datetime.datetime.today()
print(f'the time is {e:%Y-%m-%d (%a) %H:%M:%S}')   # 
```

>     the time is 2021-01-28 (Thu) 14:31:56
>

### 小数格式 `width.precision` :  整数 `width` 指定宽度，整数 `precision` 指定显示精度


```python
a = 123.456
b = 1234567890.098765
print(f'a is {a:20.2f}')
print(f'a is {a:020.2f}')
```

>     a is               123.46
>     a is 00000000000000123.46
>


### 千分位分隔符


```python
print(f'b is {b:,f}')
print(f'b is {b:_f}')
```

>     b is 1,234,567,890.098765
>     b is 1_234_567_890.098765
>

