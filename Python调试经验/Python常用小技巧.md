# Python常用小技巧

## 1. 原地交换两个数字


```python
x, y = 10, 20
print(x, y)
y, x = x, y
print(x, y)
```

>     10 20
>     20 10
>


## 2. 链状比较操作符


```python
n = 10
print(1 < n < 20)
print(1 > n <= 9)
```

>     True
>     False
>


## 3. 使用三元操作符来实现条件赋值
[表达式为真的返回值] if [表达式] else [表达式为假的返回值]


```python
y = 20
x = 9 if (y == 20) else 8
print(x)
```

>     9
>


## 4. 多行字符串


```python
multistr = "select * from multi_row \
where row_id < 5"
print(multistr)
```

>     select * from multi_row where row_id < 5
>



```python
multistr = """select * from multi_row
where row_id < 5"""
print(multistr)  # 能显示真正的多行
```

>     select * from multi_row
>     where row_id < 5
>



```python
multistr = ("select * from multi_row"
            "where row_id < 5"
            "order by age")
print(multistr)
```

>     select * from multi_rowwhere row_id < 5order by age
>


## 5. 存储列表元素到新的变量


```python
testList = [1, 2, 3]
x, y, z = testList  # 变量个数应该和列表长度严格一致
print(x, y, z)
testTuple = (3, 4, 5)
x, y, z = testTuple
print(x, y, z)
```

>     1 2 3
>     3 4 5
>


## 6. 打印引入模块的绝对路径


```python
import threading
import socket

print(threading)
print(socket)
```

>     <module 'threading' from 'c:\\users\\18320\\appdata\\local\\programs\\python\\python38\\lib\\threading.py'>
>     <module 'socket' from 'c:\\users\\18320\\appdata\\local\\programs\\python\\python38\\lib\\socket.py'>
>


## 7. 字典/集合推导


```python
testDic = {i: i * i for i in range(10)}
testSet = {i * 2 for i in range(10)}
print(testDic)
print(testSet)
```

>     {0: 0, 1: 1, 2: 4, 3: 9, 4: 16, 5: 25, 6: 36, 7: 49, 8: 64, 9: 81}
>     {0, 2, 4, 6, 8, 10, 12, 14, 16, 18}
>


## 8. 检查Python中的对象


```python
class A:
    def __init__(self):
        self.age = 10


a = A()
print(dir(a))
```

>     ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', 'age']
>


## 9. 关键字in


```python
m = 2
if m in [1, 2, 3, 4]:
    pass
```

## 10. 组合字符串join


```python
test = ["I", "Like", "Python"]
print(test)
print(" ".join(test))  # 前面的' '表示字符串中间的分隔符
```

>     ['I', 'Like', 'Python']
>     I Like Python
>


## 11. 关键字enumerate


```python
test = [10, 20, 30]
for i, value in enumerate(test):
    print(i, ':', value)
```

>     0 : 10
>     1 : 20
>     2 : 30
>


## 12. 使用*运算符解包函数参数


```python
def test(x, y, z):
    print(x, y, z)


testDic = {'x': 1, 'y': 2, 'z': 3}
testList = [10, 20, 30]
test(*testDic)  # 对于字典，*表示键，**表示值
test(**testDic)
test(*testList)
```

>     x y z
>     1 2 3
>     10 20 30
>


## 13. 找到列表中出现次数最多的数 count


```python
test = [5, 2, 3, 4, 2, 2, 3, 1, 4, 4, 4, 4]
print(f'集合：{set(test)}')
print(f'最大的数：{max(set(test))}')  # 找到最大的数
print(f'出现次数最多的数：{max(set(test), key=test.count)}')  # 找到出现次数最多的数
print(f'4在列表中的次数：{test.count(4)}')  # test.count(obj)统计某个元素在列表中的次数
```

>     集合：{1, 2, 3, 4, 5}
>     最大的数：5
>     出现次数最多的数：4
>     4在列表中的次数：5
>


## 14. 检查一个对象的内存使用
这个值包括该对象的数值、签名（包括数据类型、参数、调用方式等）等一系列数据所占总内存。可变对象所占内存可能极小，因为对象是指针，指向很大的数据。


```python
import sys

x = 1
print(sys.getsizeof(x)) # 单位：字节 (byte)
```

>     28
>


## 15. 从两个相关序列构建一个字典


```python
t1 = (1, 2, 3)
t2 = (10, 20, 30)
print(dict(zip(t1, t2)))
print(list(zip(t1, t2)))
```

>     {1: 10, 2: 20, 3: 30}
>     [(1, 10), (2, 20), (3, 30)]
>


## 16. 搜索字符串的多个前后缀


```python
print("http://localhost:8888/notebooks/Untitled6.ipynb".startswith(("http://", "https://")))
print("http://localhost:8888/notebooks/Untitled6.ipynb".endswith((".ipynb", ".py")))
```

>     True
>     True
>


## 17. 使用try-catch语句


```python
d = {'x': '5'}
try:
    value = int(d['x'])
    print(value)
except (KeyError, TypeError, ValueError):
    value = None
```

>     5
>

