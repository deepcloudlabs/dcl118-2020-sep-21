int main() {
    auto align = sizeof(void*);
    auto width = 4073;
    auto height = 5134;

    int **img;
    auto memoryAlignment = width % align ;
    auto memoryWidth = memoryAlignment == 0 ? width : width + align - memoryAlignment;
    // allocation : 1 + 1
    img = new int *[height]; // (1)
    img[0] = new int[memoryWidth * height]; // (2)
    for (auto i=1;i<height;++i)
        img[i] = img[i-1] + width;
    // deallocation: 1 + 1
    delete []img[0]; // (2)
    delete []img; // (1)
}