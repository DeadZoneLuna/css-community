#include "cbase.h"
#include "fmod_filesystem.h"
#include "fmodmanager.h"
#include "filesystem.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

FMOD_RESULT F_CALLBACK USER_FMOD_FILE_OPEN_CALLBACK( const char *name, unsigned int *filesize, void **handle, void *userdata )
{
	FileHandle_t fileHandle = g_pFullFileSystem->Open( name, "rb", nullptr );

	// Same as checking if NULL
	if ( fileHandle == FILESYSTEM_INVALID_HANDLE )
		return CFMODManager::CheckError( FMOD_ERR_FILE_NOTFOUND );

	*handle = fileHandle;
	*filesize = g_pFullFileSystem->Size( fileHandle );

	return FMOD_OK;
}

FMOD_RESULT F_CALLBACK USER_FMOD_FILE_CLOSE_CALLBACK( void *handle, void *userdata )
{
	FileHandle_t fileHandle = handle;
	g_pFullFileSystem->Close( fileHandle );

	return FMOD_OK;
}

FMOD_RESULT F_CALLBACK USER_FMOD_FILE_READ_CALLBACK( void *handle, void *buffer, unsigned int sizebytes, unsigned int *bytesread, void *userdata )
{
	// We shouldn't get to the read callback if the file handle is invalid, so we shouldn't worry about checking it
	FileHandle_t fileHandle = handle;

	*bytesread = ( unsigned int )g_pFullFileSystem->Read( buffer, sizebytes, fileHandle );

	if ( *bytesread == 0 )
		return CFMODManager::CheckError( FMOD_ERR_FILE_EOF );

	return FMOD_OK;
}

FMOD_RESULT F_CALLBACK USER_FMOD_FILE_SEEK_CALLBACK( void *handle, unsigned int pos, void *userdata )
{
	// We shouldn't get to the seek callback if the file handle is invalid, so we shouldn't worry about checking it
	FileHandle_t fileHandle = handle;

	g_pFullFileSystem->Seek( fileHandle, pos, FILESYSTEM_SEEK_HEAD );

	return FMOD_OK;
}