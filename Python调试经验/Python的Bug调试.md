# Python的Bug调试

## 2020年11月30日

### 1

```python
方法 'PhysicalObject.update()' 的签名与类 'Sprite' 中基本方法的签名不匹配  
 Inspection info: This inspection detects inconsistencies in overriding method signatures.
```

调试 `pyglet` 包的过程中，新建类继承 `pyglet.sprite.Sprite` ，其中一个方法为 `update(self, dt=None)` 覆盖父类的方法，`pycharm`提示警告如下：

![image](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/image.png)

是因为我新建的 `update(self, dt=None)` 参数与父类的`update`函数不同导致的

```python
def update(self, x=None, y=None, rotation=None, scale=None, scale_x=None, scale_y=None):
```

如何修复：

对于这个警告只需要把我们的 `update(self, dt=None)` 方法改为如下即可：

```python
def update(self, dt=None, *args, **kwargs):
```

### 2

```python
import myclass.Point3D
# 可以使用myclass.Point3D.Point3D来进行类的初始化
from myclass.Point3D import Point3D
# 可以直接使用myclass.Point3D来进行初始化
import Point3D
# 虽然会报警告，但是可以正常运行，可以使用Point3D.Point3D来进行类的初始化
```

主要区别在于 `Point3D.py` 是一个文件，里面包含一个 `Point3D` 的类。

### 3

自定义类的对象可以加前缀 `m` 来表示，如 `mData`

## 2020年12月9日

### 1. 用 pytest 测试 python 代码

http://kuanghy.github.io/2018/05/08/pytest

```python
py.test [options] [file_or_dir] [file_or_dir] [...]
```

### 2. 导入模块最好的做法

```python
import modu
x = modu.sqrt(4) # 可以明确的知道sqrt是属于modu模块的
```

- 如果包内的模块和子包没有代码共享的需求，空白的 `__init__.py` 文件是正常甚至好的做法
- 导入深层嵌套的包可用这个方便的语法：`import very.deep.module as mod`。 该语法允许使用 `mod` 替代冗长的 `very.deep.module`。

### 3 仓库样例

https://pythonguidecn.readthedocs.io/zh/latest/writing/structure.html

```python
README.rst
# 许可证
LICENSE
# 打包和发布管理
setup.py
# 开发依赖
requirements.txt
# 核心代码
sample/__init__.py
sample/core.py
sample/helpers.py
# 文档
docs/conf.py
docs/index.rst
# 测试单元
tests/test_basic.py
tests/test_advanced.py
```

