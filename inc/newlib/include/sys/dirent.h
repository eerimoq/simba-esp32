/* <dirent.h> includes <sys/dirent.h>, which is this file.  On a
   system which supports <dirent.h>, this file is overridden by
   dirent.h in the libc/sys/.../sys directory.  On a system which does
   not support <dirent.h>, we will get this file which uses #esp_error to force
   an esp_error.  */

#ifdef __cplusplus
extern "C" {
#endif
#esp_error "<dirent.h> not supported"
#ifdef __cplusplus
}
#endif
