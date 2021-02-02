# if-else的简化写法

#### 普通写法


```python
def isLen_1(strString):
    if len(strString) > 6:
        return True
    else:
        return False
```

#### 三元操作符写法


```python
def isLen_2(strString):
    return True if len(strString) > 6 else False
```

#### 简化写法，这里注意false和true的位置
其实就是一个列表，后面一个列表返回 `0` 则为 `false` ，返回 `1` 则为 `true`


```python
def isLen_3(strString):
    return [False, True][len(strString) > 6]
```

#### 运行结果


```python
test = 'test string'
print(isLen_1(test))
print(isLen_2(test))
print(isLen_3(test))
```

>     True
>     True
>     True
>

