public class Library {

    Book[] books = new Book[10];
    int count = 0;

    void addbook(Book book) {
        if (count < books.length) {
            books[count] = book;
            count++;
        } else {
            System.out.println("Library is full\n");
        }
    }

    void issueBook(String title) {
        for (int i = 0; i < count; i++) {
            if (books[i].title.equals(title)) {
                books[i].issueBook();
                return;
            }
        }
        System.out.println("Book not found");
    }

    void returnBook(String title) {
        for (int i = 0; i < count; i++) {
            if (books[i].title.equals(title)) {
                books[i].returnBook();
                return;
            }
        }
        System.out.println("Book not found");
    }

    void printAvailableBooks() {
        System.out.println("Available books are:\n");
        for (int i = 0; i < count; i++) {
            if (books[i].isAvailable()) {
                books[i].printBook();
            }
        }
    }
}
