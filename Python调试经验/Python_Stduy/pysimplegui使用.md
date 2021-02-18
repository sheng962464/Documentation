# pysimplegui使用


```python
import PySimpleGUI as sg
sg.popup_ok('默认弹窗')
```




    'OK'



![Snipaste_2021-02-18_09-16-27](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/Snipaste_2021-02-18_09-16-27.png)

## 简单弹窗类型

- `sg.popup('注意！') // sg.popup_ok('默认弹窗')`
- `sg.popup_yes_no('带Yes和No按钮的弹窗')`
- `sg.popup_cancel('带cancel按钮的弹窗')`
- `sg.popup_ok_cancel('带OK和cancel按钮的弹窗')`
- `sg.popup_error('带红色error按钮的弹窗')`
- `sg.popup_auto_close('2秒后自动关闭的弹窗')`

### 简单弹窗参数

| 类型                 | 名称                  | 作用                                 |
| -------------------- | --------------------- | ------------------------------------ |
| 任意                 | 开头任意参数          | 显示的消息（多个字符串默认换行）      |
| `str`                | `title`               | 窗口标题（如果窗口短，则显示不出来） |
| `(str,str)`          | `button_color`        | 按钮颜色（前景色，背景色）           |
| `int`                | `line_width`          | 一行几个字                           |
| `bool`               | `auto_close`          | 如果为 `true` ，则自动关闭           |
| `int` 或 `float`     | `auto_close_duration` | 自动关闭的延时（秒）                 |
| `(str,str)` 或 `str` | `custom_text`         | 自定义显示按钮的文字                 |
| `(int,int)`          | `location`            | 窗口出现在屏幕的位置                 |
| `str`                | `background_color`    | 背景色                               |
| `str`                | `text_color`          | 文字颜色                             |
| `bool`               | `no_titlebar`         | 如果为 `true` ，则没有标题栏         |
| `bool`               | `grab_anywhere`       | 如果为 `true` ，则可以拖拽窗口       |
| `bool`               | `keep_on_top`         | 如果为 `true` ，则窗口置于最上方     |
| `(str,str)` 或 `str` | `font`                | 指定字体                             |
| `str` 或 `bytes`     | `image`               | 在窗口内要显示的图片，在文字上方显示 |


```python
sg.popup(
  '这是弹窗',
  title='Hello',
  button_color=('#A81B0C', '#FFFFFF'),
  background_color='#F47264',
  line_width=2,
  custom_text=' 好的 '
)
```




    ' 好的 '



![Snipaste_2021-02-18_09-46-52](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/Snipaste_2021-02-18_09-46-52.png)

------

## 文字内容弹窗

采用`popup_scrolled()`方法，括号中添加要显示的内容即可


```python
text = '''大家好，
我们一起来学习PySimpleGUI制作简单的图形用户界面。'''
sg.popup_scrolled(text,title='Hello')
```




    'OK'



![Snipaste_2021-02-18_09-49-57](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/Snipaste_2021-02-18_09-49-57.png)

### 文字内容弹窗额外参数

| 类型        | 名称     | 作用                                             |
| ----------- | -------- | ------------------------------------------------ |
| `bool`      | `yes_no` | 如果为 `true` ，则为 `yes no` 按钮而非 `ok` 按钮 |
| `(int,int)` | `size`   | 宽度和高度                                       |

------

## 获取用户输入的弹窗

采用`popup_get_text()`方法，括号内容有点类似`input()`语句中的提示语，提醒用户输入。如果是点击`Cancel`，输出端为`None`。


```python
text1 = sg.popup_get_text('请输入文字1')
print(text1) 
```

    None
    

![Snipaste_2021-02-18_09-55-04](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/Snipaste_2021-02-18_09-55-04.png)

### 获取用户输入弹窗额外参数

| 类型  | 名称            | 作用                               |
| ----- | --------------- | ---------------------------------- |
| `str` | `message`       | 提示用户的信息                     |
| `str` | `default_text`  | 默认文字                           |
| `str` | `password_char` | 替换文字显示的符号（用于密码输入） |

------

## 文件选择弹窗

直接采用`sg.popup_get_file()`方法，括号里面的内容也是输入的提示语


```python
text1 = sg.popup_get_file('请选择文件')
print(text1)
```

    None
    

![Snipaste_2021-02-18_10-01-15](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/Snipaste_2021-02-18_10-01-15.png)

### 文件选择弹窗额外参数

| 类型                   | 名称             | 作用                                                     |
| ---------------------- | ---------------- | -------------------------------------------------------- |
| `str`                  | `message`        | 提示用户的信息                                           |
| `str`                  | `default_path`   | 默认显示的路径                                           |
| `bool`                 | `save_as`        | 如果为 `true` ，则是另存为对话框，覆盖文件时提示用户确认 |
| `bool`                 | `multiple_files` | 是否允许多选文件                                         |
| `((类型名称,后缀),……)` | `file_types`     | 允许用户选择文件的类型                                   |
| `str`                  | `initial_folder` | 开始选择文件的初始文件夹路径                             |

-----

## 文件夹选择窗口


```python
text1 = sg.popup_get_folder('请选择文件夹')
print(text1)
```

    None
    

![Snipaste_2021-02-18_10-10-25](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/Snipaste_2021-02-18_10-10-25.png)

------

## 进度条弹窗

采用`sg.one_line_progress_meter()`方法，括号中输入相关的参数设置内容


```python
for i in range(1000):
  sg.one_line_progress_meter(
    '进度条',
    i + 1,
    1000,
    '该进度条key',
    '这是一个进度条'
  )
```

![Snipaste_2021-02-18_10-12-52](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/Snipaste_2021-02-18_10-12-52.png)

### 进度条弹窗额外参数

| 类型                   | 名称            | 作用                                     |
| ---------------------- | --------------- | ---------------------------------------- |
| `str`                  | `title`         | 标题                                     |
| `int`                  | `current_value` | 当前数值                                 |
| `int`                  | `max_value`     | 最大数值                                 |
| `str,int,tuple,object` | `key`           | 进度条框的 key ，用于区分不同的进度条    |
| 任意                   | 任意个参数      | 显示的消息                               |
| `'h'` 或者 `'v'`       | `orientation`   | 进度条的方向，`'h'` 为水平，`'v'` 为竖直 |
| `(str,str)`            | `bar_color`     | 进度条颜色                               |
