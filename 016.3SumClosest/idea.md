类似3sum，依然为三个指针，当前i、左端l，右端r。外层循环移动当前指针i，内部决定是否移动l和r。
- 计算总和，如果等于目标则可以返回，如果小则移动l，大则移动r。
- 如果当前和比历史和更接近目标，则更新。
- 如果有更新，则跳过相同数以减少重复计算。