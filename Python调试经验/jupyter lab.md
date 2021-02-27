# jupyter lab

## 安装

```bash
# 安装前先升级下pip
python -m pip install --upgrade pip
# 开始下载安装pip，下载3.0版本，使用清华源
pip install jupyterlab == 3 -i https://pypi.tuna.tsinghua.edu.cn/simple

```

## 运行

![image-20210227102634684](https://cdn.jsdelivr.net/gh/sheng962464/PicGo/img/20210227103949.png)

CMD中输入 `jupyter lab` 即可打开



## 配置

1、修改默认目录

CMD中输入 `jupyter lab --generate-config` 会显示 `config` 文件的路径

打开 `jupyter_lab_config.py` ，搜索 `notebook_dir` 或者 `root_dir`

虽然这个参数已经弃用了，但是我还要要用

`c.ServerApp.notebook_dir = 'E:\\Python Programma\\JupyterNotebook'` 

保存后重启 `jupyter lab` 即可

------

2、设置中文

网上说可以直接 `pip install jupyterlab-language-pack-zh-cn`，但是这个方法我失败了，搜了一下解决方案，可能是现在清华源和阿里源中都没有 `jupyterlab-language-pack-zh-cn` ，原因可能是未正常发布。可以安装缓存的whl包，地址如下：

[jupyter lab 中文语言包](https://jfds-1252952517.cos.ap-chengdu.myqcloud.com/jupyterhub/jupyterlab_language_pack_zh_CN-0.0.1.dev0-py2.py3-none-any.whl)

下载后安装，然后打开 `jupyter lab` 设置中 `language` 选择简体中文。



## 卸载

卸载的时候网上说如下操作：

```bash
pip install pip-autoremove
pip-autoremove jupyter -y
```

`pip-autoremove` 会卸载掉 `package` 和无用的依赖

如果在卸载jupyter时报错，"The jupyter" distribution was not found，但在命令行中输入jupyter仍然存在的情况，是因为系统中装了多个jupyter notebook导致的。

卸载我没试过，等我后面需要卸载了再来更新。