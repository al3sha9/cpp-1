public class MailServer {
    private MailItem[] mailQueue;
    private int mailCount;

    public MailServer() {
        mailQueue = new MailItem[100]; // Assuming a maximum of 100 mails
        mailCount = 0;
    }

    public void sendMail(MailItem mail) {
        if (mailCount < mailQueue.length) {
            mailQueue[mailCount] = mail;
            mailCount++;
            System.out.println("Mail sent to server: " + mail);
        } else {
            System.out.println("Mail queue is full.");
        }
    }

    public MailItem[] receiveMail(String recipient) {
        MailItem[] receivedMails = new MailItem[mailCount];
        int receivedCount = 0;

        for (int i = 0; i < mailCount; i++) {
            if (mailQueue[i].getRecipient().equalsIgnoreCase(recipient)) {
                receivedMails[receivedCount] = mailQueue[i];
                receivedCount++;
                mailQueue[i] = null; // Remove the mail from the queue
            }
        }

        // Compact the mailQueue array
        int newIndex = 0;
        for (int i = 0; i < mailCount; i++) {
            if (mailQueue[i] != null) {
                mailQueue[newIndex] = mailQueue[i];
                newIndex++;
            }
        }
        mailCount = newIndex;

        // Trim the receivedMails array to the actual number of received mails
        MailItem[] trimmedReceivedMails = new MailItem[receivedCount];
        System.arraycopy(receivedMails, 0, trimmedReceivedMails, 0, receivedCount);

        return trimmedReceivedMails;
    }
}

