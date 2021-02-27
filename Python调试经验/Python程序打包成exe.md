# Python打包成exe

## 安装 `Pyinstaller`

```python
pip install -i https://pypi.tuna.tsinghua.edu.cn/simple pyinstaller
```

## 打包

使用CMD进入当前目录下，输入如下代码
```python
Pyinstaller -F -w -i chengzi.ico py_word.py
```

需要打包的文件：`py_word.py`

图标文件：`chengzi.ico`

参数说明：`-F` 表示制作独立可执行程序，`-w` 指程序启动时不会打开命令行，如果程序里存在 `print()` 函数，则不能使用这个参数，会报错。`-i chengzi.ico` 指设置自己的图标。

打包成的 `exe` 在 `dist`文件夹下。

ps:程序路径最好全部都是英文，否则可能会出现莫名其妙的问题。

使用这种方法生成的 `exe` 文件有点大

## 压缩打包

本质就是只包含自己需要的库。

### conda虚拟环境

```python
#创建虚拟环境
conda create -n aotu python=3.6

#激活虚拟环境
conda activate aotu

#Pyinstaller打包
Pyinstaller -F -w -i apple.ico py_word.py

conda deactivate #退出虚拟环境

conda remove -n aotu--all # 删除虚拟环境
```

### 更改spec文件

`pyinstaller` 除了会打包 `test.py` 使之成为一个 `exe` 之外，还会创建一的后缀名为 **.spec** 的文件。

![Snipaste_2021-02-06_19-22-08](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/20210206192220.jpg)

然后就可以愉快的在第13行的"[]"里面输入自己不需要的库。

重新打包 exe

```python3
Pyinstaller --clean -F -w -i chengzi.ico py_word.py
```

ps：像 `requests` 这些库是和 `urllib` 有关联的 这也就是为什么 `exclude urllib` 可能会有错误产生的原因

### 其他方法

除此以外还有嵌入式 `python` 方法，`Nuitka` 包代替 `Pyinstaller` 等