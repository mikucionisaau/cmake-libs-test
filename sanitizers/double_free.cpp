namespace details
{
void consume(int* pi);
}  // namespace details

int main()
{
    auto* pi = new int[5];
    details::consume(pi);
    delete[] pi;
}

namespace details
{
void consume(int* pi) { delete[] pi; }
}  // namespace details
