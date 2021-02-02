# strip方法使用

Python中有三个去除头尾字符、空白符的函数，它们依次为:

- strip： 用来去除头尾字符、空白符(包括\n、\r、\t、' '，即：换行、回车、制表符、空格)

- lstrip：用来去除开头字符、空白符(包括\n、\r、\t、' '，即：换行、回车、制表符、空格)

- rstrip：用来去除结尾字符、空白符(包括\n、\r、\t、' '，即：换行、回车、制表符、空格)

注意：这些函数都只会删除头和尾的字符，中间的不会删除。


```python
# 加一个#来显示字符串到哪里结束
name = '         python              '
print(name.strip(), '#')
```

>     python #
>



```python
name = '         python              '
print(name.lstrip(), '#')
```

>     python               #
>



```python
name = '         python              '
print(name.rstrip(), '#')
```

>              python #
>



```python
name = '    1     python      1        '
print(name.strip(), '#')
```

>     1     python      1 #
>



```python
# 当strip函数中存在参数时，把参数视为一个一个字符，删除开头和结尾的字符
name = '00000000011100000000111000200000python000002000011100000111100000000000000000'
print(name.strip('01'))
```

>     200000python000002
>

