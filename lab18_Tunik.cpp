#include <vector>
#include <stdexcept>

template <typename T>
class Array {
private:
    std::vector<T> data;

public:
    explicit Array(size_t initialSize = 0) : data(initialSize) {}

    T& at(size_t index) {
        return data.at(index);
    }

    const T& at(size_t index) const {
        return data.at(index);
    }

    void set(size_t index, const T& value) {
        if (index >= data.size()) {
            throw std::out_of_range("Array::set: Index out of bounds");
        }
        data[index] = value;
    }

    size_t size() const {
        return data.size();
    }
};

int main() {

    return 0;
}