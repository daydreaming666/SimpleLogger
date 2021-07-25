# SimpleLogger

A pretty simple cpp library to print log.

## usage

```c++
#include "SimpleLogger.hpp"

int main() {
    /*
     * SimpleLogger(FILE, APP_NAME)
     */
    SimpleLogger logger(stderr, "TEST APP");
    
    logger.w("Network", "Test Warn");
    logger.d("Network", "Test Debug");
    logger.e("Network", "Test Error");
    
    /*
     * output:
     * [  WARN] 07-25 14:23:46 1 /TEST APP W/Network: Test Warn 
     * [ DEBUG] 07-25 14:23:46 1 /TEST APP D/Network: Test Debug 
     * [ ERROR] 07-25 14:23:46 1 /TEST APP E/Network: Test Error 
     */
    return 0;
}
```