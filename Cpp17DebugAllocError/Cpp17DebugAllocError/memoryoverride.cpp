#include <iostream>

void *__cdecl operator new(std::size_t size, int blockuse, const char *pszFileName, int lineNum)
{
	auto ptr = malloc(size);
    std::cout << pszFileName << " : " << lineNum << " : " << "unaligned new(" << size << ") = " << ptr << '\n';
    return ptr ? ptr : throw std::bad_alloc{};
}

void __cdecl operator delete(void *ptr, std::size_t size)
{
	std::cout << "unaligned sized delete(" << ptr << ", " << size << ")\n";
    free(ptr);
}

void __cdecl operator delete(void *ptr)
{
	std::cout << "unaligned unsized delete(" << ptr << ")\n";
    free(ptr);
}

void __cdecl operator delete(void *ptr, int blockuse, const char *pszFileName, int lineNum)
{
	std::cout << pszFileName << " : " << lineNum << " : " << "unaligned unsized delete(" << ptr << ")\n";
	free(ptr);
}

// "new" over-aligned overloads
void *__cdecl operator new(std::size_t size, std::align_val_t align) {
    auto ptr = _aligned_malloc(size, static_cast<std::size_t>(align));
    std::cout << "aligned new(" << size << ", " <<
        static_cast<std::size_t>(align) << ") = " << ptr << '\n';
    return ptr ? ptr : throw std::bad_alloc{};
}

void __cdecl operator delete(void* ptr, std::size_t size, std::align_val_t align) {
    std::cout << "aligned sized delete(" << ptr << ", " << size << 
        ", " << static_cast<std::size_t>(align) << ")\n";
    _aligned_free(ptr);
}

void __cdecl operator delete(void* ptr, std::align_val_t align) {
    std::cout << "aligned unsized delete(" << ptr << 
        ", " << static_cast<std::size_t>(align) << ")\n";
    _aligned_free(ptr);
}