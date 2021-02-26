#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{

  char testSTR[] = "RA ra RA Malalafalatiko RA ra RA";
  void *handle = NULL;
  int (*StrLen)(char *, char);
  char *error = NULL;

  handle = dlopen("/home/so/Belgeler/C_Programmable/DYN_LIB_STDY/StringLib/libStringlib.so", RTLD_LAZY);
  
  if(!handle)
  {
    fputs(dlerror(), stderr);
    exit (1);
  }
  
  dlerror(); //For cleaning itself
  
  StrLen = dlsym(handle, "numberOfCharactersInString");
  
    if((error = dlerror()) != NULL)
  {
    fputs(dlerror(), stderr);
    exit (1);
  }
  
  printf("The length of %s is:\n%i\nWe call this function with Dynamic Load.\n", testSTR, (*StrLen)(testSTR, 'l'));
  
  dlclose(handle);
  
  return 0;
}
