1. 反转链表使用三个指针, prev, curr, next. 每次将curr->next指向prev, 然后往前移动.
2. 分组反转, 每次先找到分割点边界, 即反转段的下一个节点.
3. 每次反转完局部分组后需要将上一次反转完的末节点指向当前分组反转完的头节点, 而上一次反转完的末节点即为上一组未反转的头节点, 也就是上一次的分割边界. 而最开始的分割边界在头节点之前. 
4. 每次需要判断剩下的够不够一组, 如果不够则不进行反转. 判断分割点是否为空后再移动到下一节点. 分割点为空则退出循环.