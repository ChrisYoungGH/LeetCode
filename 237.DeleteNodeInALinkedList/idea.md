修改该节点值为下一个节点的值并更新指针

However, this question is INCORRECT for sure, since you don't really "delete" a node, you are replacing the value. In fact, this is a terrible design leading to memory leaks almost for sure.

I wonder what company gives such misleading question. It's better called "modify" a node, instead of "deleting". Deleting means free the memory, and the incorrect description will mislead any person with slight experience on C++.
