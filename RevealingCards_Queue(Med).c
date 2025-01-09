int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
*returnSize = deckSize;
    int* array = calloc(deckSize, sizeof(int));
    int i, j, key, up = 1, front;
    for (i = 1; i < deckSize; i++) { // Insertion sort
        key = deck[i];
        j = i - 1;
        for (; j >= 0 && deck[j] > key; j--)
            deck[j + 1] = deck[j];
        deck[j + 1] = key;
    }
    for (i = front = 0, up = 1; i < deckSize; front = ++front % deckSize)
        if (!up && !array[front])
            up = !up; // 0 to 1
        else if (up && !array[front]) {
            array[front] = deck[i++];
            up = !up; // 1 to 0;
        }
    return array;
}