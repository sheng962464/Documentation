# json 和 pickle 包使用

`json` 和 `pickle` 是用于序列化的两个包

- `json` 用于 python 数据结构和字符串之间的转换
- `pickle` 用于 python 数据结构与 pickle 数据之间的转换


```python
import json,pickle

data = [100, "Python3", {"www": 1, "baidu.com": 2, "Python3": 3}]
savePicklePath = 'D:/pickleString.txt'
saveJsonPath = 'D:/jsonString.txt'
```

两者都提供了四种功能，`dumps`，`dump`，`loads`，`load`。

- `dump` 将 `python` 的数据结构转换为 `json` 或 `pickle` 数据，并保存在文件中，注意一个参数是 `wb` ， 一个是 `w`


```python
with open(savePicklePath, 'wb') as f:
    pickle.dump(data, f)
    
with open(saveJsonPath, 'w') as f:
    json.dump(data, f)
```

- `load` 将读取文件中的 `json` 或 `pickle` 数据，并转换为`python`数据结构，注意一个参数是 `rb` ，一个是 `r`


```python
with open(savePicklePath, 'rb') as f:
    mes = pickle.load(f)
    print('picke_load', type(mes), ':', mes)

with open(saveJsonPath, 'r') as f:
    mes = json.load(f)
    print('json_load:', type(mes), mes)
```

    picke_dumps <class 'list'> : [100, 'Python3', {'www': 1, 'baidu.com': 2, 'Python3': 3}]
    json_dumps: <class 'list'> [100, 'Python3', {'www': 1, 'baidu.com': 2, 'Python3': 3}]
    

- `dumps` 将 `python` 的数据结构转换为 `json` 或 `pickle` 数据


```python
picke_dumps = pickle.dumps(data)
print('picke_dumps', type(picke_dumps), ':', picke_dumps)

json_dumps = json.dumps(data)
print('json_dumps:', type(json_dumps), json_dumps)
```

    picke_dumps <class 'bytes'> : b'\x80\x04\x95/\x00\x00\x00\x00\x00\x00\x00]\x94(Kd\x8c\x07Python3\x94}\x94(\x8c\x03www\x94K\x01\x8c\tbaidu.com\x94K\x02h\x01K\x03ue.'
    json_dumps: <class 'str'> [100, "Python3", {"www": 1, "baidu.com": 2, "Python3": 3}]
    

- `loads` 将 `json` 或 `pickle` 数据转换为`python`的数据结构


```python
pickle_loads = pickle.loads(picke_dumps)
print('pickle_loads:', type(pickle_loads), ':', pickle_loads)

json_loads = json.loads(json_dumps)
print('json_loads', type(json_loads), json_loads)
```

    pickle_loads: <class 'list'> : [100, 'Python3', {'www': 1, 'baidu.com': 2, 'Python3': 3}]
    json_loads <class 'list'> [100, 'Python3', {'www': 1, 'baidu.com': 2, 'Python3': 3}]
    
