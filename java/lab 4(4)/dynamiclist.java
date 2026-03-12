package lab4java;

// Динамический список
public class DynamicList {
    private Node head;
    private int size;

    public DynamicList() {
        head = null;
        size = 0;
    }

    public void add(inter data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node current = head;
            while (current.getNext() != null) {
                current = current.getNext();
            }
            current.setNext(newNode);
        }
        size++;
    }

    public void add(int index, inter data) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }

        Node newNode = new Node(data);
        if (index == 0) {
            newNode.setNext(head);
            head = newNode;
        } else {
            Node current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current.getNext();
            }
            newNode.setNext(current.getNext());
            current.setNext(newNode);
        }
        size++;
    }

    public inter get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }

        Node current = head;
        for (int i = 0; i < index; i++) {
            current = current.getNext();
        }
        return current.getData();
    }

    public inter remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }

        inter removedData;
        if (index == 0) {
            removedData = head.getData();
            head = head.getNext();
        } else {
            Node current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current.getNext();
            }
            removedData = current.getNext().getData();
            current.setNext(current.getNext().getNext());
        }
        size--;
        return removedData;
    }

    public boolean remove(inter data) {
        if (head == null) return false;

        str first = (str) head.getData();
        str searchData = (str) data;
        if (first.getValue().equals(searchData.getValue())) {
            head = head.getNext();
            size--;
            return true;
        }

        Node current = head;
        while (current.getNext() != null) {
            str currentData = (str) current.getNext().getData();
            if (currentData.getValue().equals(searchData.getValue())) {
                current.setNext(current.getNext().getNext());
                size--;
                return true;
            }
            current = current.getNext();
        }
        return false;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        head = null;
        size = 0;
    }

    // Быстрая сортировка
    public void quickSort() {
        if (size <= 1) return;

        inter[] arr = new inter[size];
        Node current = head;
        for (int i = 0; i < size; i++) {
            arr[i] = current.getData();
            current = current.getNext();
        }

        sort(arr, 0, size - 1);

        current = head;
        for (int i = 0; i < size; i++) {
            current.setData(arr[i]);
            current = current.getNext();
        }
    }
//Рекурсивный метод быстрой сортировки
    private void sort(inter[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            sort(arr, low, pi - 1);
            sort(arr, pi + 1, high);
        }
    }
    //Разделение массива относительно опорного элемента
    private int partition(inter[] arr, int low, int high) {
        str pivot = (str) arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            str current = (str) arr[j];
            // Используем метод men (меньше) для сравнения
            str result = (str) current.men(pivot);
            if (result.getValue().equals("true")) {
                i++;
                inter temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        inter temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    @Override
    public String toString() {
        if (head == null) return "[]";

        StringBuilder sb = new StringBuilder("[");
        Node current = head;

        while (current != null) {
            sb.append(current.getData());
            if (current.getNext() != null) {
                sb.append(", ");
            }
            current = current.getNext();
        }

        sb.append("]");
        return sb.toString();
    }
}
