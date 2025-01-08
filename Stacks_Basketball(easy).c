int calPoints(char** operations, int operationsSize) {
    int scores[50];
    int Count = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "C") == 0) {
            // Invalidate the last score
            if (Count > 0) {
                Count--;
            }
        } else if (strcmp(operations[i], "D") == 0) {
            // Double the last score
            if (Count > 0) {
                scores[Count] = 2 * scores[Count - 1];
                Count++;
            }
        } else if (strcmp(operations[i], "+") == 0) {
            // Sum of the last two scores
            if (Count > 1) {
                scores[Count] = scores[Count - 1] + scores[Count - 2];
            } else if (Count == 1) {
                scores[Count] = scores[Count - 1];
            }
            Count++;
        } else {
            // It's a number, convert it and add to scores
            scores[Count] = atoi(operations[i]);
            Count++;
        }
    }

    // Calculate the total sum of scores
    int totalSum = 0;
    for (int i = 0; i < Count; i++) {
        totalSum += scores[i];
    }

    return totalSum;
}