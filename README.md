# ExtendDatrie DoubleArrayTrie-MultiValue

在Jianing Yang实现的datrie基础上增加每个键多值支持, 适应我自己的一些使用场景

double array trie,在大规模稀疏数据情况下, 普通的字典树对内存的浪费非常严重, 在某些数据规模的情况下可能失去作用,
Jianing Yang 原本的实现的基础上使得一个key可以存多个值, 基于std::vector容器, 也是因为引入了std::vector, 而resize
函数中使用的realloc函数无法正确的析构,导致了内存泄漏,所以切换回非realloc的实现, 测试通过valgrind 内存测试

