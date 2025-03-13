class Book {
    String title;
    boolean isIssued;

    Book(String title) {
        this.title = title;
        this.isIssued = false;
    }

    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            System.out.println(title + " has been issued.\n");
        } else {
            System.out.println(title + " is already issued.\n");
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            System.out.println(title + " has been returned.\n");
        } else {
            System.out.println(title + " was not issued.\n");
        }
    }
}

class Library {
    Book[] books;

    Library() {
        books = new Book[]{
            new Book("\nJava Programming"),
            new Book("Data Structures"),
            new Book("Operating Systems"),
            new Book("Database Management"),
            new Book("Computer Networks\n")
        };
    }

    void issueBook(String title) {
        for (Book book : books) {
            if (book.title.equals(title)) {
                book.issueBook();
                return;
            }
        }
        System.out.println("Book not found.");
    }

    void returnBook(String title) {
        for (Book book : books) {
            if (book.title.equals(title)) {
                book.returnBook();
                return;
            }
        }
        System.out.println("Book not found.");
    }

    void printAvailableBooks() {
        System.out.println("Available books:");
        for (Book book : books) {
            if (!book.isIssued) {
                System.out.println(book.title);
            }
        }
    }

    void printIssuedBooks() {
        System.out.println("\nIssued books:");
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
        
        library.issueBook("Java Programming");
        library.issueBook("Data Structures\n");
        
        library.printIssuedBooks();
        
        library.returnBook("\nJava Programming");
        
        library.printAvailableBooks();
    }
}
