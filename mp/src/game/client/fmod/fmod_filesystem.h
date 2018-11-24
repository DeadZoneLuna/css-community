#ifndef FMOD_FILESYSTEM_H
#define FMOD_FILESYSTEM_H

#include <fmod.hpp>

FMOD_RESULT F_CALLBACK USER_FMOD_FILE_OPEN_CALLBACK( const char *name, unsigned int *filesize, void **handle, void *userdata );
FMOD_RESULT F_CALLBACK USER_FMOD_FILE_CLOSE_CALLBACK( void *handle, void *userdata );
FMOD_RESULT F_CALLBACK USER_FMOD_FILE_READ_CALLBACK( void *handle, void *buffer, unsigned int sizebytes, unsigned int *bytesread, void *userdata );
FMOD_RESULT F_CALLBACK USER_FMOD_FILE_SEEK_CALLBACK( void *handle, unsigned int pos, void *userdata );

#endif // FMOD_FILESYSTEM_H