## python:
将键盘三行作为三个字符集合，每次将单词作为字符集合与三个集合求交集，若交集仍为单词字符（即单词字符集合是其子集）则满足。

## 其他:
将每个键字符作为key，其行号作为value存入map。对每个单词，先全部变为小写，再依次查看每个字符的行号是否相同。

**注**:
- Python集合求交用&
- java字符串边小写用toLowerCase()
- c++字符串变小写可将每个字符tolower，或用<algorithm>中的transform:
- std::transform(str.begin(), str.end(), str.begin(), ::tolower);
