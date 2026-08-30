#include <print>
#include <string>
#include <memory>

constexpr std::string DEFAULT_TITLE = "NO_TITLE";

class Book {
    std::string title;

public:
    Book(const std::string& _title = DEFAULT_TITLE) : title(_title) {}

    void setTitle(const std::string& _title) {
        title = _title;
    }

    const std::string& getTitle() const {
        return title;
    }
};

int main() {
    std::shared_ptr<Book> book1 = std::make_shared<Book>("Winnie-the-Pooh");
    std::shared_ptr<Book> book2 = book1;

    println("{}", book1.use_count());

    book2->setTitle("Little Red Riding Hood");
    println("{}", book2->getTitle());
    println("{}", book1->getTitle());
}