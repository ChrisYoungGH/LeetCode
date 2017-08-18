## 方法1：
存两个map并比较，类似Isomorphic String
- c++ 分割字符串可以用输入流
- c++ map取键的值若不存在初始化为0.

## 方法2：
java, python可以存在一个map里，同时比较

- java Map put(k,v) 返回值为 get(k)
- 往map中要存对象
- python往一个map存要区分字符串与字符相同的情况
