public class MailItem {
    private String sender;
    private String recipient;
    private String subject;
    private String body;

    public MailItem(String sender, String recipient, String subject, String body) {
        this.sender = sender;
        this.recipient = recipient;
        this.subject = subject;
        this.body = body;
    }

    public String getSender() {
        return sender;
    }

    public String getRecipient() {
        return recipient;
    }

    public String getSubject() {
        return subject;
    }

    public String getBody() {
        return body;
    }

    @Override
    public String toString() {
        return "From: " + sender + "\nTo: " + recipient + "\nSubject: " + subject + "\nBody: " + body;
    }
}

