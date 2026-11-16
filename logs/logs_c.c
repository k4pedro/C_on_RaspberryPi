#include <stdio.h>
#include <stdarg.h>
#include <time.h>

typedef enum {
    LOG_DBG,
    LOG_SUCCESS,
    LOG_WARN,
    LOG_ERR,
    LOG_LEVEL_LEN
} LOG_LEVEL;

#ifdef __EMSCRIPTEN
    #define NO_ANSI
#endif

char * type[LOG_LEVEL_LEN] = {
    "DEBUG",
    "SUCCESS",
    "WARN",
    "ERR"
}; 

char * colors[LOG_LEVEL_LEN] = {
    "\x1b[0m",
    "\x1b[32m",
    "\x1b[1;33m",
    "\x1b[31m"
};

time_t current_time;
struct tm * m_time; 

void get_time() {
    time(&current_time);
    m_time = localtime(&current_time);
}

void ulogger_log(LOG_LEVEL level, const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
        get_time();
        #ifndef NO_ANSI 
            printf("%s", colors[level]);
        #endif
        
        printf("[%d/%d/%d -> %d:%d:%d][%s] ", m_time -> tm_mday,
                                        m_time -> tm_mon,
                                        m_time -> tm_year + 1900,
                                        m_time -> tm_hour, 
                                        m_time -> tm_min, 
                                        m_time -> tm_sec,
                                        type[level]); 
        vfprintf(stdout, fmt, args);
        printf("\n%s", colors[LOG_DBG]);
    va_end(args);
}

void ulogger_log(LOG_LEVEL level, const char *fmt, ...);

int main(void)
{
    ulogger_log(LOG_DBG, "Valor lido: %d", 42);
    ulogger_log(LOG_SUCCESS, "Programa iniciado com sucesso");
    ulogger_log(LOG_WARN, "Temperatura alta: %.1f C", 71.5);
    ulogger_log(LOG_ERR, "Nao foi possivel abrir o arquivo: %s", "dados.txt");

    return 0;
}