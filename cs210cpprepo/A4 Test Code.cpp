
int main() {
    MinHeap heap(10);

    int values[] = {42, 17, 8, 23, 5, 31, 12};
    for (int v : values) {
        heap.insert(v);
        cout << "Inserted " << v << " -> ";
        heap.print();
    }

    cout << "\nMin (peek): " << heap.peek() << endl;

    cout << "\nExtracting in order: ";
    while (!heap.isEmpty()) {
        cout << heap.extractMin() << " ";
    }
    cout << endl;

    return 0;
}