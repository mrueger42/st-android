/* Android  sqConfig.h -- platform identification and configuration */


#if defined(ANDROID)
# if defined(SQ_CONFIG_DONE)
#   error configuration conflict
# endif
#  define DOUBLE_WORD_ALIGNMENT
#  define DOUBLE_WORD_ORDER
#  define SQ_CONFIG_DONE
#endif

#if !defined(SQ_CONFIG_DONE)
# error test for, and describe, your architecture here.
#endif
