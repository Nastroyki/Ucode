#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 0 || fd < 0)
        return -2;
    if (malloc_size(*lineptr))
        free(*lineptr);
    *lineptr = mx_strnew(buf_size - 1);
    mx_memset(*lineptr, '\0', malloc_size(*lineptr));
    
    size_t bytes = 0;
    char c;
    if (!read(fd, &c, 1)) {
        return -1;
    }
    else {
        if (c == delim) return 0;
        (*lineptr)[bytes++] = c;
        if (bytes >= buf_size)
            (*lineptr) = (char*)mx_realloc(*lineptr, bytes + 1);
    }
    while (read(fd, &c, 1))
    {
        if (c == delim) break;
        (*lineptr)[bytes++] = c;
        if (bytes >= buf_size)
            (*lineptr) = (char*)mx_realloc(*lineptr, bytes + 1);
    }
    mx_memset(&(*lineptr)[bytes], '\0', (size_t)(malloc_size(*lineptr) - bytes));
    return bytes;
}

