#define CFTEST_BUFFER_SIZE 1024


#define PASS_CFEQ(expression, expect, message) \
  { \
    PASS(CFEqual((CFTypeRef)(expression), (CFTypeRef)(expect)) ? YES : NO, message)\
    if (NO == testPassed) \
      { \
        CFStringRef str1; \
        CFStringRef str2; \
        char expected[CFTEST_BUFFER_SIZE] = {0}; \
        char expr[CFTEST_BUFFER_SIZE] = {0}; \
        str1 = CFCopyDescription((CFTypeRef)(expect)); \
        str2 = CFCopyDescription((CFTypeRef)(expression)); \
        CFStringGetCString (str1, expected, CFTEST_BUFFER_SIZE-1, \
          CFStringGetSystemEncoding()); \
        CFStringGetCString (str2, expr, CFTEST_BUFFER_SIZE-1, \
          CFStringGetSystemEncoding()); \
        CFRelease ((CFTypeRef)str1); \
        CFRelease ((CFTypeRef)str2); \
        fprintf (stderr, "Expected %s, but got %s\n", \
          expected, \
          expr); \
      } \
  }

#define PASS_CFNEQ(expression, expect, message) \
  { \
    PASS(CFEqual((CFTypeRef)expression, (CFTypeRef)expect) ? NO : YES, message)\
    if (NO == testPassed) \
      { \
        CFStringRef str1; \
        CFStringRef str2; \
        char expected[CFTEST_BUFFER_SIZE]; \
        char expr[CFTEST_BUFFER_SIZE]; \
        str1 = CFCopyDescription((CFTypeRef)expect); \
        str2 = CFCopyDescription((CFTypeRef)expression); \
        CFStringGetCString (str1, expected, CFTEST_BUFFER_SIZE-1, \
          CFStringGetSystemEncoding()); \
        CFStringGetCString (str2, expr, CFTEST_BUFFER_SIZE-1, \
          CFStringGetSystemEncoding()); \
        CFRelease ((CFTypeRef)str1); \
        CFRelease ((CFTypeRef)str2); \
        fprintf (stderr, "Did not expect %s, got %s\n", \
          expected, \
          expr); \
      } \
  }