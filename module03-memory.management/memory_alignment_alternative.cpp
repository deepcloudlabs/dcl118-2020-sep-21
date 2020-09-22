int main() {
    auto width = 4073;
    auto height = 5134;

    int **img;
    // memory allocation: 1 + height
    img = new int *[height];
    for (auto i = 0; i < height; ++i)
        img[i] = new int[width];
    // deallocation: 1 + height
    for (auto i = 0; i < height; ++i)
        delete[]img[i];
    delete[] img;
}