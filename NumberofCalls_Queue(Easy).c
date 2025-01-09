typedef struct {
    int* requests;
    int count;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* counter = (RecentCounter*)malloc(sizeof(RecentCounter));
    counter->requests = (int*)malloc(1000 * sizeof(int));
    counter->count = 0;
    return counter;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->requests[obj->count++] = t;
    int startTime = t - 3000;
    int validCount = 0;
    for (int i = 0; i < obj->count; i++) {
        if (obj->requests[i] >= startTime) {
            validCount++;
        }
    }

    return validCount;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->requests);
    free(obj);
}