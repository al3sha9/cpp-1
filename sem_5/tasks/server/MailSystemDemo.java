public class MailSystemDemo {
    public static void main(String[] args) {
        MailServer server = new MailServer();

        MailClient client1 = new MailClient("Shan", server);
        MailClient client2 = new MailClient("Ali", server);

        client1.sendMail("Ali", "Lab Task Reminder", "Don't forget about our Lab Task tomorrow.");
        client2.sendMail("Shan", "Lab Task Reminder", "Thanks for the reminder!");

        System.out.println("Shan's Mailbox:");
        client1.receiveMail();

        System.out.println("\nAli's Mailbox:");
        client2.receiveMail();
    }
}

