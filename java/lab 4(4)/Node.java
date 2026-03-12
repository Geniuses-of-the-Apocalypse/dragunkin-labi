package lab4java;

public class Node {
    private inter data;
    private Node next;

    public Node(inter data) {
        this.data = data;
        this.next = null;
    }

    public inter getData() {
        return data;
    }

    public void setData(inter data) {
        this.data = data;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
