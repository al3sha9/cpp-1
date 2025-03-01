class Book {
    String title;
    boolean isIssued;

    Book(String title) {
        this.title = title;
        this.isIssued = false;
    }
}

class Library {
    Book[] books;

    Library() {
        books = new Book[]{
            new Book("Java Programming"),
            new Book("Data Structures"),
            new Book("Operating Systems"),
            new Book("Database Management")
        };
    }

    void issueBook(int index) {
        if (index >= 0 && index < books.length && !books[index].isIssued) {
            books[index].isIssued = true;
            System.out.println(books[index].title + " has been issued.");
        } else {
            System.out.println("Book cannot be issued.");
        }
    }

    void returnBook(int index) {
        if (index >= 0 && index < books.length && books[index].isIssued) {
            books[index].isIssued = false;
            System.out.println(books[index].title + " has been returned.");
        } else {
            System.out.println("Book cannot be returned.");
        }
    }

    void printAvailableBooks() {
        System.out.println("Available Books:");
        for (Book book : books) {
            if (!book.isIssued) {
                System.out.println(book.title);
            }
        }
    }

    void printIssuedBooks() {
        System.out.println("Issued Books:");
        for (Book book : books) {
            if (book.isIssued) {
                System.out.println(book.title);
            }
        }
    }
}

public class LibrarySystem {
    public static void main(String[] args) {
        Library library = new Library();

        library.printAvailableBooks();
        library.issueBook(1);
        library.printIssuedBooks();
        library.returnBook(1);
        library.printAvailableBooks();
    }
}

