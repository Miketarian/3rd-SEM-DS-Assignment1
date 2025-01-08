char* simplifyPath(char* path) {
    char* stack[50]; 
    int top = -1;
    char* token = strtok(path, "/");
    
    while (token != NULL) {
        if (strcmp(token, ".") != 0 && strcmp(token, "") != 0) { 
            if (strcmp(token, "..") == 0) {
                if (top >= 0) {
                    top--;
                }
            } else {
                stack[++top] = token;
            }
        }
        token = strtok(NULL, "/");
    }

    char* simplifiedPath = (char*)malloc(1024);
    simplifiedPath[0] = '\0';

    for (int i = 0; i <= top; i++) {
        strcat(simplifiedPath, "/");
        strcat(simplifiedPath, stack[i]);
    }
    if (top == -1) {
        return strdup("/");
    }

    return simplifiedPath;
}