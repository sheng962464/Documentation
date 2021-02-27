# Python装饰器

## 装饰器简介
装饰器放在一个函数开始定义的地方，它就像一顶帽子一样戴在这个函数的头上。和这个函数绑定在一起。在我们调用这个函数的时候，第一件事并不是执行这个函数，而是将这个函数做为参数传入它头顶上这顶帽子，这顶帽子我们称之为 **装饰器** 。基本格式如下：
```python
def decorator(func):
    def wrapper(*args, **kw):
        return func()
    return wrapper

@decorator
def function():
    print("hello, decorator")
```




## 日志打印装饰器


```python
# 这是装饰器函数，参数 func 是被装饰的函数
def logger(func):
    def wrapper(*args, **kw):
        print('主人，我准备开始执行：{} 函数了:'.format(func.__name__))

        # 真正执行的是这行。
        func(*args, **kw)

        print('主人，我执行完啦。')
    return wrapper

@logger
def add(x, y):
    print('{} + {} = {}'.format(x, y, x+y))
    
    
if __name__ == '__main__':
    add(200,50)
```

    主人，我准备开始执行：add 函数了:
    200 + 50 = 250
    主人，我执行完啦。
    

## 时间计时器


```python
import time


# 这是装饰函数
def timer(func):
    def wrapper(*args, **kw):
        t1=time.time()
        # 这是函数真正执行的地方
        func(*args, **kw)
        t2=time.time()

        # 计算下时长
        cost_time = t2-t1 
        print(f"花费时间：{cost_time}秒")
    return wrapper

@timer
def add(x, y):
    print('{} + {} = {}'.format(x, y, x+y))
    
    
if __name__ == '__main__':
    add(200,50)
```

    200 + 50 = 250
    花费时间：0.0秒
    

## 带参数的装饰器


```python
from functools import wraps
import logging

def logged(level, name=None, message=None):
    """
    给函数添加log日志。包含等级，名字，信息。如果没有指定名字和信息，则默认为函数的模块和名字
    """
    def decorate(func):
        logname = name if name else func.__module__
        log = logging.getLogger(logname)
        logmsg = message if message else func.__name__

        @wraps(func)
        def wrapper(*args, **kwargs):
            log.log(level, logmsg)
            return func(*args, **kwargs)
        return wrapper
    return decorate

# Example use
@logged(logging.WARN)# WARN会显示为红色，Debug不会提示
def add(x, y):
    return x + y

@logged(logging.CRITICAL, message='example')# CRITICAL会显示为红色
def spam():
    print('Spam!')
    

if __name__ == '__main__':
    add(200,50)
    spam()
```

    add
    example
    

    Spam!
    

## 不带参数的类装饰器
基于类装饰器的实现，必须实现 `__call__` 和 `__init__`两个内置函数。 `__init__` ：接收被装饰函数 `__call__` ：实现装饰逻辑。


```python
class logger(object):
    def __init__(self, func):
        self.func = func

    def __call__(self, *args, **kwargs):
        print("[INFO]: the function {self.func.__name__}() is running...")
        return self.func(*args, **kwargs)

@logger
def say(something):
    print(f"say {something}!")

say("hello")
```

    [INFO]: the function {self.func.__name__}() is running...
    say hello!
    

## 带参数的类装饰器

上面不带参数的例子，只能打印`INFO`级别的日志，正常情况下，我们还需要打印`DEBUG` `WARNING`等级别的日志。 这就需要给类装饰器传入参数，给这个函数指定级别了。

带参数和不带参数的类装饰器有很大的不同。

`__init__` ：不再接收被装饰函数，而是接收传入参数。 `__call__` ：接收被装饰函数，实现装饰逻辑。


```python
class logger(object):
    def __init__(self, level='INFO'):
        self.level = level

    def __call__(self, func): # 接受函数
        def wrapper(*args, **kwargs):
            print("[{level}]: the function {func}() is running..."\
                .format(level=self.level, func=func.__name__))
            func(*args, **kwargs)
        return wrapper  #返回函数

@logger(level='WARNING')
def say(something):
    print(f"say {something}!")

say("hello")
```

    [WARNING]: the function say() is running...
    say hello!
    

装饰器还有很多门道，暂时只更新这些，后面需要用到再来更新
```Python
todo
```
