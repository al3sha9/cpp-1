public class MailClient {
    private String clientName;
    private MailServer mailServer;

    public MailClient(String clientName, MailServer mailServer) {
        this.clientName = clientName;
        this.mailServer = mailServer;
    }

    public void sendMail(String recipient, String subject, String body) {
        MailItem mail = new MailItem(clientName, recipient, subject, body);
        mailServer.sendMail(mail);
    }

    public void receiveMail() {
        MailItem[] mails = mailServer.receiveMail(clientName);
        boolean hasNewMail = false;

        for (MailItem mail : mails) {
            if (mail != null) {
                hasNewMail = true;
                System.out.println("New Mail Received:");
                System.out.println(mail);
            }
        }

        if (!hasNewMail) {
            System.out.println("No new mails.");
        }
    }
}

