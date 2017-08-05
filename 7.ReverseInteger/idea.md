## 方法1
直接反序，每次判断界。每次判断是否在最大值和最小值内，不是则返回0。

## 方法2
判断最高位符号是否相同。有溢出的，符号变化，故只需比较符号位，即都右移31位后判断。

## 方法3
输出到字符串，反序后输入，最后判断界。

## 对于python
正负数应分开，因为负数取模向上取整。先转绝对值，再加上符号，最后判断是否在最大值和最小值范围内。

**注**：中间存数时需使用long(C++是long long)，避免溢出，最终结果再截断为int。

32位整数范围：-2147483648～2147483647
常量：
- python: <font color="red">*sys.max_int(9223372036854775807)*<font>
- java:<font color="red">*Integer.MAX_VALUE*<font>, <font color="red">*Integer.MIN_VALUE*<font>;
- c++: <font color="red">*INT_MAX*<font>, <font color="red">*INT_MIN*<font>
