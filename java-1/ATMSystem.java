class BankAccount {
    private String accountNumber;
    private String accountHolderName;
    private double balance;

    public BankAccount(String accountNumber, String accountHolderName, double initialBalance) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.balance = initialBalance;
    }

    public double getBalance() {
        return balance;
    }

    public boolean withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public String getAccountHolderName() {
        return accountHolderName;
    }
}

class User {
    private String cardNumber;
    private String pin;
    private BankAccount account;

    public User(String cardNumber, String pin, BankAccount account) {
        this.cardNumber = cardNumber;
        this.pin = pin;
        this.account = account;
    }

    public boolean validatePin(String inputPin) {
        return this.pin.equals(inputPin);
    }

    public BankAccount getAccount() {
        return account;
    }
}

class ATM {
    private User currentUser;

    private User[] registeredUsers;

    public ATM(User[] users) {
        this.registeredUsers = users;
    }

    public boolean authenticateUser(String cardNumber, String pin) {
        for (User user : registeredUsers) {
            if (user.getAccount().getAccountNumber().equals(cardNumber)
                && user.validatePin(pin)) {
                this.currentUser = user;
                return true;
            }
        }
        return false;
    }

    public double checkBalance() {
        if (currentUser != null) {
            return currentUser.getAccount().getBalance();
        }
        return -1;
    }

    public boolean withdrawCash(double amount) {
        if (currentUser != null) {
            return currentUser.getAccount().withdraw(amount);
        }
        return false;
    }

    public boolean transferFunds(String recipientAccountNumber, double amount) {
        if (currentUser == null) {
            return false;
        }

        User recipientUser = findUserByAccountNumber(recipientAccountNumber);

        if (recipientUser == null || recipientUser == currentUser) {
            return false;
        }

        if (currentUser.getAccount().withdraw(amount)) {
            recipientUser.getAccount().deposit(amount);
            return true;
        }

        return false;
    }

    private User findUserByAccountNumber(String accountNumber) {
        for (User user : registeredUsers) {
            if (user.getAccount().getAccountNumber().equals(accountNumber)) {
                return user;
            }
        }
        return null;
    }

    public void printReceipt(double amount) {
        if (currentUser != null) {
            System.out.println("--- ATM Receipt ---");
            System.out.println("Account: " + currentUser.getAccount().getAccountNumber());
            System.out.println("Name: " + currentUser.getAccount().getAccountHolderName());
            System.out.println("Withdrawal Amount: PKR" + amount);
            System.out.println("Remaining Balance: PKR" + checkBalance());
            System.out.println("Date: " + new java.util.Date());
            System.out.println("-------------------");
        }
    }

    public void printTransferReceipt(String recipientAccountNumber, double amount) {
        if (currentUser != null) {
            User recipientUser = findUserByAccountNumber(recipientAccountNumber);

            System.out.println("--- Funds Transfer Receipt ---");
            System.out.println("Sender Account: " + currentUser.getAccount().getAccountNumber());
            System.out.println("Sender Name: " + currentUser.getAccount().getAccountHolderName());
            System.out.println("Recipient Account: " + recipientAccountNumber);
            System.out.println("Recipient Name: " + recipientUser.getAccount().getAccountHolderName());
            System.out.println("Transfer Amount: PKR" + amount);
            System.out.println("Sender Remaining Balance: PKR" + checkBalance());
            System.out.println("Date: " + new java.util.Date());
            System.out.println("-------------------");
        }
    }

    public void logout() {
        this.currentUser = null;
    }
}

public class ATMSystem {
    public static void main(String[] args) {
        BankAccount account1 = new BankAccount("1234", "Ali Shan", 1000.00);
        BankAccount account2 = new BankAccount("5678", "Shan Khan", 1500.00);

        User user1 = new User("1234", "1111", account1);
        User user2 = new User("5678", "2222", account2);

        ATM atm = new ATM(new User[]{user1, user2});

        System.out.println("Authenticating User...");
        if (atm.authenticateUser("1234", "1111")) {
            System.out.println("Authentication Successful!");

            System.out.println("Current Balance: PKR" + atm.checkBalance());

            double withdrawAmount = 200.00;
            if (atm.withdrawCash(withdrawAmount)) {
                atm.printReceipt(withdrawAmount);
            } else {
                System.out.println("Withdrawal Failed");
            }

            double transferAmount = 300.00;
            String recipientAccountNumber = "5678";
            if (atm.transferFunds(recipientAccountNumber, transferAmount)) {
                atm.printTransferReceipt(recipientAccountNumber, transferAmount);
            } else {
                System.out.println("Funds Transfer Failed");
            }

            atm.logout();
        } else {
            System.out.println("Authentication Failed");
        }
    }
}