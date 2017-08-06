## 方法1：
**找规律**：每次把两个1合成一个2，再遍历所有可能组合，得到公式为：  
![](http://latex.codecogs.com/gif.latex?f(n)=\\sum_{i=0}^{{\\lfloor}n/2\\rfloor}\\binom{n-i}{i})  
该方法在java, c++会溢出(计算组合数时积过大)

注：[***Markdown Latex Online***](http://latex.codecogs.com)

## 方法2：
结果其实就是斐波那契数列。一定要用非递归写法，保证不超时。Python有两处语法特点：
- a = b = 1
- a, b = b, a+b
