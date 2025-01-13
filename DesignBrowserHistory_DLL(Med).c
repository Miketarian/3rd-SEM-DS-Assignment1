typedef struct tab
{
    char* url;
    struct tab* next;
    struct tab* previous;
} tab;

typedef struct BrowserHistory
{
    tab* current;
} BrowserHistory;

tab* createTab(char* url)
{
    tab* newTab = malloc(sizeof(tab));

    newTab->url = url;
    newTab->next = NULL;
    newTab->previous = NULL;

    return newTab;
}
BrowserHistory* browserHistoryCreate(char* homepage)
{
    BrowserHistory* history = malloc(sizeof(BrowserHistory));
    history->current = createTab(homepage);

    return history;
}

void browserHistoryVisit(BrowserHistory* obj, char* url)
{
    BrowserHistory history = *obj;

    tab* newTab = createTab(url);
    history.current->next = newTab;
    newTab->previous = history.current;
    history.current = newTab;

    *obj = history;
}

char* browserHistoryBack(BrowserHistory* obj, int steps)
{
    BrowserHistory history = *obj;
    int back = 0;

    while(history.current->previous != NULL && back < steps)
    {
        back++;
        history.current = history.current->previous;
    }

    *obj = history;

    return history.current->url;
}

char * browserHistoryForward(BrowserHistory* obj, int steps)
{
    BrowserHistory history = *obj;
    int forward = 0;

    while(history.current->next != NULL && forward < steps)
    {
        forward++;
        history.current = history.current->next;
    }

    *obj = history;

    return history.current->url;
}

void browserHistoryFree(BrowserHistory* obj)
{
    BrowserHistory history = *obj;

    while(history.current->previous != NULL) history.current = history.current->previous;

    while(history.current != NULL)
    {
        tab* current = history.current;
        history.current = history.current->next;
        free(current);
    }

    *obj = history;
    free(obj);
}