/**
 * 转发参数包
 * 
 * 可变参数模板 + forward : 将实参不变地传递给其他函数
 * 
 * forward保持实参的原始类型
 * 
 * void StrVec::emplace_back(Args&&... args) {
 *      chk_n_alloc();
 *      alloc.construct(first_free++, std::forward<Args>(args)...);
 * }
 */ 

